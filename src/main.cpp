//
// Created by fils on 27/05/2021.
//

#include "main.hpp"



int main(int argc, char *argv[]){
    CLI::App app("Makefile_gen FPGA build system version 2.0");
    std::string target;
    app.add_option("-D,--depfile", target, "Target Depfile")->check(CLI::ExistingFile);
    bool generate_xilinx;
    app.add_flag("--X",generate_xilinx,"Generate Xilinx Makefile");
    bool generate_lattice;
    app.add_flag("--L",generate_lattice,"Generate Lattice Makefile");
    bool synth_design;
    app.add_flag("--S", synth_design,"synthetize design");
    bool keep_makefile;
    app.add_flag("--d", keep_makefile, "if set to true does not remove the makefile after use");
    bool reindex;
    app.add_flag("--re-map", "reindex HDL repository");

    CLI11_PARSE(app, argc, argv);

    std::shared_ptr<settings_store>  s_store = std::make_shared<settings_store>();
    std::shared_ptr<data_store> d_store = std::make_shared<data_store>();
    Repository_walker walker(s_store, d_store);

    if(target.empty()) target = std::filesystem::current_path().string() + "/Depfile";

    Depfile dep(target);

    std::vector<std::string> synth_add = dep.get_additional_synth_modules();
    std::vector<std::string> sim_add = dep.get_additional_sim_modules();

    // Get resolve synthesis dependencies
    Dependency_resolver synth_resolver(dep.get_synth_tl(), d_store);
    synth_resolver.set_excluded_modules(dep.get_excluded_modules());

    // Get resolve simulation dependencies
    Dependency_resolver sim_resolver(dep.get_sim_tl(), d_store);
    sim_resolver.set_excluded_modules(dep.get_excluded_modules());

    Auxiliary_resolver aux_resolver(d_store);


    xilinx_project_generator generator;
    generator.set_project_name(dep.get_project_name());


    generator.set_directories(s_store->get_setting("hdl_store"), dep.get_include_directories());
    generator.set_synth_sources(synth_resolver.get_dependencies());
    generator.set_sim_sources(sim_resolver.get_dependencies());
    generator.set_script_sources(aux_resolver.get_tcl_scripts(dep.get_scripts()));
    generator.set_constraint_sources(aux_resolver.get_constraints(dep.get_constraints()));
    generator.set_sim_tl(dep.get_sim_tl());
    generator.set_synth_tl(dep.get_synth_tl());
    std::ofstream makefile("test_makefile.tcl");
    generator.write_makefile(makefile);
    
    return 0;
}