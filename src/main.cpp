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
    std::string synth_top_level = dep.get_synth_tl();
    std::string sim_top_level = dep.get_sim_tl();
    std::vector<std::string> synth_add = dep.get_additional_synth_modules();
    std::vector<std::string> sim_add = dep.get_additional_sim_modules();
    std::vector<Script> scripts = dep.get_scripts();

    Dependency_resolver resolver(synth_top_level, d_store);
    resolver.set_excluded_modules(dep.get_excluded_modules());
    std::vector<std::string> synth_deps = resolver.get_dependencies();
    return 0;
}