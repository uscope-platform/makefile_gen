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


    typedef struct __CLI_opt{
        std::string target;
        bool generate_xilinx = false;
        bool generate_app_definition = false;
        bool generate_periph_definition = false;
        bool generate_lattice = false;
        bool synth_design = false;
        bool keep_makefile = false;
        std::string get_setting;
        std::string set_setting;
        std::string new_app_name;
        std::string new_app_lang;
        bool measure_runtime = true;
        bool no_cache = false;
        bool trace = false;
        bool refresh_cache = false;
        std::string cache_dir = std::string(std::getenv("HOME")) + "/.makefilegen_store";
        bool wait_profiler = false;
    } CLI_opt;

    CLI_opt opts;

    CLI::App app("Makefile_gen FPGA build system version 2.0");

    app.add_option("-D,--depfile", opts.target, "Target Depfile")->check(CLI::ExistingFile);
    app.add_flag("--X",opts.generate_xilinx,"Generate Xilinx Makefile");
    app.add_flag("--A",opts.generate_app_definition,"Generate application definition file");
    app.add_flag("--P",opts.generate_periph_definition,"Generate Peripherals definition file");
    app.add_flag("--L",opts.generate_lattice,"Generate Lattice Makefile");
    app.add_flag("--S",opts.synth_design,"synthetize design");
    app.add_flag("--k",opts.keep_makefile, "if set to true does not remove the makefile after use");
    app.add_option("--get_setting",opts.get_setting, "Print the value of a cached user setting");
    app.add_option("--set_setting",opts.set_setting, "Modify the value of a cached user setting");
    app.add_option("--new_app",opts.new_app_name, "Setup a new blank application");
    app.add_option("--lang",opts.new_app_lang, "Specify the language for the new app");
    app.add_flag("--measure-runtime",opts.measure_runtime, "Measure the runtime of the current program invocation");
    app.add_flag("--no-cache",opts.no_cache, "Run the program without touching the repository cache");
    app.add_flag("--refresh-cache",opts.refresh_cache, "Refresh the repository cache and exit");
    app.add_flag("--wait_profiler", opts.wait_profiler, "Wait for the profiler to be ready before executing");
    app.add_flag("--trace", opts.trace, "Enable extended internal state tracing");
    app.add_option("--cache_dir", opts.cache_dir, "Specify a non-default repository cache file");

    CLI11_PARSE(app, argc, argv);

    if(opts.trace) {
        spdlog::set_level(spdlog::level::trace);
    } else {
        spdlog::set_level(spdlog::level::info);
    }

    if(opts.wait_profiler){
        spdlog::info("Press ANY key to continue");
        getchar();
    }


    auto t1 = std::chrono::high_resolution_clock::now();

    // Setup caches
    std::shared_ptr<settings_store>  s_store = std::make_shared<settings_store>(false, opts.cache_dir);
    if(!opts.get_setting.empty()){
        spdlog::info(s_store->get_setting(opts.get_setting));
    }

    if(!opts.set_setting.empty()){
        std::string line;
        std::istringstream ss(opts.set_setting);
        std::vector<std::string> setting;
        while(std::getline(ss,line,'=')) setting.push_back(line);
        s_store->set_setting(setting[0], setting[1]);
    }

    if(!opts.new_app_name.empty()){
        std::string lang = "sv";
        if(!opts.new_app_lang.empty()){
            if(opts.new_app_lang == "vlog")
                lang = "v";
            else if(opts.new_app_lang == "sv"|| opts.new_app_lang == "vhdl")
                lang = opts.new_app_lang;
            else{
                spdlog::error("Unknown language option: ", opts.new_app_lang);
                exit(1);
            }
        }
        new_app_generator gen(opts.new_app_name, lang);
        return 0;
    }

    if(opts.refresh_cache) {
        exit(0);
    }

    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(opts.no_cache, opts.cache_dir);


    // analyze repository content and update cache
    Repository_walker walker(s_store, d_store, opts.no_cache);

    d_store->lock_resources();

    // Parse depfile
    if(opts.target.empty()) opts.target = std::filesystem::current_path().string() + "/Depfile";
    if(!std::filesystem::exists(opts.target)){
        spdlog::error("Depfile not found: {} does not exist", opts.target);
        exit(1);
    }

    Depfile dep(opts.target);

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

    control_bus_analysis bus_analyzer(dep);
    bus_analyzer.analyze_bus(synth_ast);

    proxy_bus_analysis proxy_analyzer(s_store, d_store, dep);
    proxy_analyzer.analyze(synth_ast);

        //Generate makefile
    if(opts.generate_xilinx){
        xilinx_project_generator generator;
        generator.set_project_name(dep.get_project_name());

        generator.set_directories(s_store->get_setting("hdl_store"), dep.get_include_directories());
        generator.set_synth_sources(synth_sources);
        generator.set_sim_sources(sim_sources);
        generator.set_script_sources(script_deps);
        generator.set_constraint_sources(constr_deps);
        generator.set_sim_tl(dep.get_sim_tl());
        if(dep.has_board_def()){
            generator.set_board_part(dep.get_board_def());
        }
        generator.set_synth_tl(dep.get_synth_tl());
        std::ofstream makefile("makefile.tcl");
        generator.write_makefile(makefile);

        Vivado_manager manager(s_store, !opts.keep_makefile, dep.get_project_name());
        manager.create_project("makefile.tcl",  true);
    }

    if(opts.generate_lattice){
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

        Radiant_manager manager(s_store, !opts.keep_makefile, dep.get_project_name());
        manager.create_project("makefile.tcl",  true);
    }

    peripheral_definition_generator periph_def_gen(d_store, synth_ast);
    application_definition_generator app_def_gen(
            synth_ast,
            periph_def_gen.get_peripheral_definitions(),
            periph_def_gen.get_alias_map(),
            periph_def_gen.get_variant_peripherals()
            );

    data_acquisition_analysis daq_analyzer(true);
    daq_analyzer.analyze(synth_ast);
    app_def_gen.add_datapoints(daq_analyzer.get_datapoints());
    app_def_gen.add_channel_groups(daq_analyzer.get_channel_groups());
    app_def_gen.add_scope(daq_analyzer.get_scope_data());

    app_def_gen.construct_application(dep.get_project_name());


    if(opts.generate_periph_definition){
        periph_def_gen.write_definition_file(dep.get_project_name() + "_periph_def.json");
    }

    if(opts.generate_app_definition){
        app_def_gen.write_definition_file(dep.get_project_name() + "_app_def.json");
    }



    if(opts.measure_runtime){
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        spdlog::info("The Program runtime was : {} ms", std::to_string(ms_double.count()));
    }

    return 0;
}