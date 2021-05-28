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

    Repository_walker walker;

    std::string input_file = "/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv";

    sv_analyzer file_processor(input_file);
    file_processor.cleanup_content("`(.*)");
    file_processor.parse();

    std::unordered_map<std::string,sv_feature> declared_features = file_processor.get_declared_features();
    std::unordered_map<std::string,sv_feature> instantiated_features = file_processor.get_instantiated_features();

    return 0;
}