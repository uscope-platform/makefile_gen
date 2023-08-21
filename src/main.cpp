// Copyright 2021 University of Nottingham Ningbo China
// Author: Filippo Savi <filssavi@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "main.hpp"

int main(int argc, char *argv[]){

    // Command line interface

    CLI::App app("Makefile_gen FPGA build system version 2.0");

    std::string target;
    app.add_option("-D,--depfile", target, "Target Depfile")->check(CLI::ExistingFile);

    bool generate_xilinx = false;
    app.add_flag("--X",generate_xilinx,"Generate Xilinx Makefile");

    bool generate_app_definition = false;
    app.add_flag("--A",generate_app_definition,"Generate application definition file");

    bool generate_periph_definition = false;
    app.add_flag("--P",generate_periph_definition,"Generate Peripherals definition file");

    bool generate_lattice = false;
    app.add_flag("--L",generate_lattice,"Generate Lattice Makefile");

    bool synth_design = false;
    app.add_flag("--S", synth_design,"synthetize design");

    bool keep_makefile = false;
    app.add_flag("--k", keep_makefile, "if set to true does not remove the makefile after use");

    std::string get_setting;
    app.add_option("--get_setting", get_setting, "Print the value of a cached user setting");

    std::string set_setting;
    app.add_option("--set_setting", set_setting, "Modify the value of a cached user setting");

    std::string new_app_name;
    app.add_option("--new_app", new_app_name, "Setup a new blank application");

    std::string new_app_lang;
    app.add_option("--lang", new_app_lang, "Specify the language for the new app");

    bool measure_runtime;
    app.add_flag("--measure-runtime", measure_runtime, "Measure the runtime of the current program invocation");

    bool no_cache = false;
    app.add_flag("--no-cache", no_cache, "Run the program without touching the repository cache");

    std::string cache_dir = std::string(std::getenv("HOME")) + "/.makefilegen_store";
    app.add_option("--cache_dir", cache_dir, "Run the program without touching the repository cache");

    bool wait_profiler = false;
    app.add_flag("--wait_profiler", wait_profiler, "Wait for the profiler to be ready before executing");

    CLI11_PARSE(app, argc, argv);

    if(wait_profiler){
        std::cout << "Press ANY key to continue\n";
        getchar();
    }


    auto t1 = std::chrono::high_resolution_clock::now();

    // Setup caches
    std::shared_ptr<settings_store>  s_store = std::make_shared<settings_store>(false, cache_dir);
    if(!get_setting.empty()){
        std::cout << s_store->get_setting(get_setting)<<std::endl;
    }

    if(!set_setting.empty()){
        std::string line;
        std::istringstream ss(set_setting);
        std::vector<std::string> setting;
        while(std::getline(ss,line,'=')) setting.push_back(line);
        s_store->set_setting(setting[0], setting[1]);
    }

    if(!new_app_name.empty()){
        std::string lang = "sv";
        if(!new_app_lang.empty()){
            if(new_app_lang == "vlog")
                lang = "v";
            else if(new_app_lang == "sv"|| new_app_lang == "vhdl")
                lang = new_app_lang;
            else{
                std::cout<< "ERROR: Unknown language option: " + new_app_lang << std::endl;
                exit(1);
            }
        }
        new_app_generator gen(new_app_name, lang);
        return 0;
    }


    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(no_cache, cache_dir);

    // analyze repository content and update cache
    Repository_walker walker(s_store, d_store, no_cache);

    // Parse depfile
    if(target.empty()) target = std::filesystem::current_path().string() + "/Depfile";
    if(!std::filesystem::exists(target)){
        std::cout << "ERROR: Depfile " + target + " does not exist" << std::endl;
        exit(1);
    }
    Depfile dep(target);

    // Resolve auxiliary files (scripts and constraints)
    Auxiliary_resolver aux_resolver(d_store);

    python_script_runner py_runner;
    py_runner.run_python_scripts(aux_resolver.get_python_objects(dep.get_scripts()));
    std::unordered_set<std::string> script_deps = aux_resolver.get_tcl_script_paths(dep.get_scripts());

    std::set<std::string> additional_script_deps = py_runner.get_script_dependencies();
    script_deps.insert(additional_script_deps.begin(), additional_script_deps.end());

    std::set<std::string> additional_constr_deps = py_runner.get_constraints_dependencies();
    std::unordered_set<std::string> constr_deps = aux_resolver.get_constraints(dep.get_constraints());
    constr_deps.insert(additional_constr_deps.begin(), additional_constr_deps.end());

    walker.analyze_dir();


    // BUILD ASTs FOR TOP LEVEL AND ADDITIONAL MODULES
    HDL_ast_builder b(s_store, d_store, dep);
    auto synth_ast = b.build_ast(dep.get_synth_tl(), {});
    auto additional_synth_modules = b.build_ast(dep.get_additional_synth_modules(), {});
    additional_synth_modules.insert(additional_synth_modules.end(), synth_ast);

    auto sim_ast = b.build_ast(dep.get_sim_tl(), {});
    auto additional_sim_modules = b.build_ast(dep.get_additional_sim_modules(), {});
    additional_sim_modules.insert(additional_sim_modules.end(), sim_ast);


    // RESOLVE DEPENDENCIES
    Dependency_resolver_v2 synth_r(additional_synth_modules, d_store);
    auto synth_sources = synth_r.get_dependencies();

    Dependency_resolver_v2 sim_r(additional_sim_modules, d_store);
    auto sim_sources = sim_r.get_dependencies();

    // BUS MAPPING

    bus_analysis bus_analyzer(s_store, d_store, dep);
    bus_analyzer.analyze_bus(synth_ast);

    //Generate makefile
    if(generate_xilinx){
        xilinx_project_generator generator;
        generator.set_project_name(dep.get_project_name());

        generator.set_directories(s_store->get_setting("hdl_store"), dep.get_include_directories());
        generator.set_synth_sources(synth_sources);
        generator.set_sim_sources(sim_sources);
        generator.set_script_sources(script_deps);
        generator.set_constraint_sources(constr_deps);
        generator.set_sim_tl(dep.get_sim_tl());
        generator.set_synth_tl(dep.get_synth_tl());
        std::ofstream makefile("makefile.tcl");
        generator.write_makefile(makefile);

        Vivado_manager manager(s_store, !keep_makefile, dep.get_project_name());
        manager.create_project("makefile.tcl",  true);
    }

    if(generate_lattice){
        lattice_project_generator generator;
        generator.set_project_name(dep.get_project_name());

        generator.set_directories(s_store->get_setting("hdl_store"), dep.get_include_directories());
        generator.set_synth_sources(synth_sources);
        generator.set_sim_sources(sim_sources);
        generator.set_script_sources(script_deps);
        generator.set_constraint_sources(constr_deps);
        generator.set_sim_tl(dep.get_sim_tl());
        generator.set_synth_tl(dep.get_synth_tl());
        std::ofstream makefile("makefile.tcl");
        generator.write_makefile(makefile);

        Radiant_manager manager(s_store, !keep_makefile, dep.get_project_name());
        manager.create_project("makefile.tcl",  true);
    }

    if(generate_app_definition || generate_periph_definition){
        bus_mapper mapper(s_store, d_store, d_store->get_HDL_resource(dep.get_bus_defining_package()));
        mapper.map_bus(dep.get_bus_section(), "control",dep.get_synth_tl());
        if(generate_app_definition){
            application_definition_generator app_def_gen(mapper.get_leaves());
            auto cores = synth_r.get_processors();
            app_def_gen.add_cores(cores);
            app_def_gen.construct_application(dep.get_project_name());
            app_def_gen.write_definition_file(dep.get_project_name() + "_app_def.json");
        }
        if(generate_periph_definition){
            std::shared_ptr<bus_crossbar> xbar = std::static_pointer_cast<bus_crossbar>(d_store->get_HDL_resource(dep.get_bus_defining_package()).get_bus_roots()[0]);
            peripheral_definition_generator periph_def_gen(d_store, mapper.get_leaves());
            periph_def_gen.write_definition_file(dep.get_project_name() + "_periph_def.json");
        }
    }

    if(measure_runtime){

        auto t2 = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> ms_double = t2 - t1;

        std::cout<< "The Program runtime was : " + std::to_string(ms_double.count()) + " ms";
    }

    return 0;
}