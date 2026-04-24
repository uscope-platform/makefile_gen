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
        bool generate_sim_script = false;
        bool generate_synth_script = false;
        bool generate_app_definition = false;
        bool generate_periph_definition = false;
        bool generate_lattice = false;
        bool synth_design = false;
        bool dump_ast = false;
        bool keep_makefile = false;
        std::string get_setting;
        std::string set_setting;
        std::string new_app_name;
        std::string new_app_lang;
        std::vector<std::string> parse_targets;
        bool measure_runtime = true;
        bool no_cache = false;
        bool trace = false;
        bool no_open = false;
        bool clear_cache = false;
        bool refresh_cache = false;
        std::string cache_dir = std::string(std::getenv("HOME")) + "/.ananke_store";
        bool wait_profiler = false;
    } CLI_opt;

    CLI_opt opts;

    CLI::App app("Ananke FPGA build system version 2.0");

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
    app.add_flag("--clear-cache",opts.clear_cache, "Clear HDL cache");
    app.add_flag("--wait_profiler", opts.wait_profiler, "Wait for the profiler to be ready before executing");
    app.add_flag("--trace", opts.trace, "Enable extended internal state tracing");
    app.add_option("--cache_dir", opts.cache_dir, "Specify a non-default repository cache file");
    app.add_flag("--no_open", opts.no_open, "Do not open the generated project");
    app.add_flag("--sim_script", opts.generate_sim_script, "Generate simulation script for the chosen platform");
    app.add_flag("--synth_script", opts.generate_synth_script, "Generate Synthesis script for the chosen platform");
    app.add_flag("--dump_ast", opts.dump_ast, "Dump AST to /tmp/ast.json");
    app.add_option("--parse",opts.parse_targets, "Specify a list of files to parse");

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

    if(opts.clear_cache) {
        data_store::clear_cache(opts.cache_dir);
        s_store->remove_setting("cache_dump");
        s_store->flush();
        exit(0);
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

    if (!opts.parse_targets.empty()) {
        for (auto &target :opts.parse_targets) {
            if (!std::filesystem::exists(target)) {
                std::cout << "Target: " << target << " not found" << std::endl;
                return 50;
            }
            std::unique_ptr<std::istream> is = std::make_unique<std::ifstream>(target);
            try {
                sv_analyzer analyzer(target, is);
                auto resources = analyzer.analyze();
            } catch (std::runtime_error &err) {
                std::cout << err.what();
                return 51;
            }

        }
        return 0;
    }

    std::shared_ptr<data_store> d_store = std::make_shared<data_store>(opts.no_cache, opts.cache_dir);

    // analyze repository content and update cache
    Repository_walker walker(s_store, d_store, opts.no_cache, s_store->get_setting_list("excluded_paths"));

    if(opts.refresh_cache) {
        return 0;
    }


    // Parse depfile
    if(opts.target.empty()) opts.target = std::filesystem::current_path().string() + "/Depfile";
    if(std::filesystem::exists(opts.target)) {
        Depfile dep(opts.target);

        // Resolve auxiliary files (scripts and constraints)
        Auxiliary_resolver aux_resolver(d_store);


        auto scripts = dep.get_scripts();

        python_script_runner py_runner;
        py_runner.run_python_scripts(aux_resolver.get_python_objects(scripts));
        auto script_deps = aux_resolver.get_tcl_script_paths(scripts);

        auto additional_script_deps = py_runner.get_script_dependencies();
        script_deps.insert(script_deps.end(), additional_script_deps.begin(), additional_script_deps.end());

        std::set<std::string> additional_constr_deps = py_runner.get_constraints_dependencies();
        std::unordered_set<std::string> constr_deps = aux_resolver.get_constraints(dep.get_constraints());
        constr_deps.insert(additional_constr_deps.begin(), additional_constr_deps.end());

        walker.analyze_dir();


        // BUILD ASTs FOR TOP LEVEL AND ADDITIONAL MODULES
        HDL_ast_builder_v2 b(s_store, d_store, dep);
        auto synth_ast = b.build_ast(std::vector({dep.get_synth_tl()}))[0];
        auto additional_synth_modules = b.build_ast(dep.get_additional_synth_modules());
        additional_synth_modules.insert(additional_synth_modules.end(), synth_ast);

        auto sim_ast = b.build_ast(std::vector({dep.get_sim_tl()}))[0];
        auto additional_sim_modules = b.build_ast(dep.get_additional_sim_modules());
        additional_sim_modules.insert(additional_sim_modules.end(), sim_ast);


        // RESOLVE DEPENDENCIES
        Dependency_resolver_v2 synth_r(additional_synth_modules, d_store);
        auto synth_sources = synth_r.get_dependencies();
        auto synth_packages = synth_r.get_packages();
        auto synth_data = synth_r.get_data();

        Dependency_resolver_v2 sim_r(additional_sim_modules, d_store);
        auto sim_sources = sim_r.get_dependencies();
        auto sim_packages = sim_r.get_packages();
        auto sim_data = sim_r.get_data();

        // BUS MAPPING

        control_bus_analysis bus_analyzer(dep);
        bus_analyzer.analyze_bus(synth_ast);

        proxy_bus_analysis proxy_analyzer(s_store, d_store, dep);
        proxy_analyzer.analyze(synth_ast);
        //Generate makefile
        if(opts.generate_xilinx){

            xilinx_project_generator generator(s_store);

            project_data data;

            data.name = dep.get_project_name();
            data.synth_sources = synth_sources;
            data.package_synth_sources = synth_packages;
            data.data_synth_sources = synth_data;
            data.sim_sources = sim_sources;
            data.package_sim_sources = sim_packages;
            data.data_sim_sources = sim_data;
            data.scripts = script_deps;
            data.constraints_sources = constr_deps;
            data.tb_tl = dep.get_sim_tl();
            data.synth_tl = dep.get_synth_tl();
            data.commons_dir = dep.get_include_directories();
            data.repo_dir = std::filesystem::current_path();
            data.target_part = dep.get_target();
            if(dep.has_board_def()){
                data.board_part = dep.get_board_def();
            }

            generator.set_data(data);


            if (opts.generate_sim_script) {
                std::ofstream simfile("sim.sh");
                generator.generate_sim_script(simfile);
                if (!std::filesystem::exists("sim.tcl")) {
                    std::ofstream ofs("sim.tcl");

                    generator.write_sim_control_script(ofs);
                }
            } else if (opts.generate_synth_script) {
                std::ofstream simfile("synth.tcl");
                generator.generate_synth_script(simfile);
            } else {
                std::ofstream makefile("makefile.tcl");
                generator.write_makefile(makefile);


                Vivado_manager manager(s_store, !opts.keep_makefile, dep.get_project_name());
                manager.create_project("makefile.tcl",  !opts.no_open);
            }
        }

        if(opts.generate_lattice){
            lattice_project_generator generator(s_store);
            project_data data;

            data.name = dep.get_project_name();
            data.synth_sources = synth_sources;
            data.package_synth_sources = synth_packages;
            data.data_synth_sources = synth_data;
            data.sim_sources = sim_sources;
            data.package_sim_sources = sim_packages;
            data.data_sim_sources = sim_data;
            data.scripts = script_deps;
            data.constraints_sources = constr_deps;
            data.tb_tl = dep.get_sim_tl();
            data.synth_tl = dep.get_sim_tl();

            std::ofstream makefile("makefile.tcl");
            generator.write_makefile(makefile);

            Radiant_manager manager(s_store, !opts.keep_makefile, dep.get_project_name());
            manager.create_project("makefile.tcl",  !opts.no_open);
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
        if (opts.dump_ast) {
            auto ast_dump = synth_ast->dump().dump(4);
            std::ofstream ast_file("/tmp/ast.json");
            ast_file << ast_dump;
            ast_file.close();
        }
    }

    if(opts.measure_runtime){
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms_double = t2 - t1;
        spdlog::info("The Program runtime was : {} ms", std::to_string(ms_double.count()));
    }
    return 0;
}