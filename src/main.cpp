//
// Created by fils on 27/05/2021.
//

#include "../includes/main.hpp"



int main(int argc, char *argv[]){
    std::string input_file = "/home/fils/git/uscope_hdl/Components/signal_chain/multiphase_reference_generator/rtl/multiphase_reference_generator.sv";

    frontend file_processor(input_file);
    file_processor.cleanup_content("`(.*)");
    file_processor.parse();


    std::unordered_map<std::string,sv_feature> declared_features = file_processor.get_declared_features();
    std::unordered_map<std::string,sv_feature> instantiated_features = file_processor.get_instantiated_features();

    return 0;
}