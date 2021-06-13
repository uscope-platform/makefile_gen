//
// Created by fils on 28/05/2021.
//

#ifndef MAKEFILEGEN_V2_DATA_STORE_H
#define MAKEFILEGEN_V2_DATA_STORE_H

#include <unordered_map>
#include <filesystem>
#include <utility>
#include <set>
#include <fstream>

#include "HDL_Resource.h"
#include "Script.h"
#include "Constraints.h"

class data_store {
public:
     data_store();
     std::shared_ptr<HDL_Resource> get_HDL_resource(const std::string& name);
     void store_hdl_entity(const std::shared_ptr<HDL_Resource>& entity);
     void store_hdl_entity(const std::vector<std::shared_ptr<HDL_Resource>> & vect);

    std::shared_ptr<Script> get_script(std::string& name);
    void store_script(const std::shared_ptr<Script>& entity);
    void store_script(const std::vector<std::shared_ptr<Script>> & vect);

    std::shared_ptr<Constraints> get_constraint(std::string& name);
    void store_constraint(const std::shared_ptr<Constraints>& entity);
    void store_constraint(const std::vector<std::shared_ptr<Constraints>> & vect);

    void remove_stale_info(const std::filesystem::path& p);
    bool is_primitive(const std::string &name);
    ~data_store();
private:

    void clean_up_caches();
    void load_entities_cache();
    void store_entities_cache();

    void load_scripts_cache();
    void store_scripts_cache();

    void load_constraints_cache();
    void store_constraints_cache();

    std::unordered_map<std::string, std::shared_ptr<HDL_Resource>> hdl_resources_cache;
    std::unordered_map<std::string, std::shared_ptr<Script>> scripts_cache;
    std::unordered_map<std::string, std::shared_ptr<Constraints>> constraints_cache;
    std::string  store_path;
    std::string entities_file;
    std::string scripts_file;
    std::string constraints_file;

    std::set<std::string> xilinx_primitives = {
            "xpm_cdc_array_single", "xpm_cdc_async_rst", "xpm_cdc_gray", "xpm_cdc_handshake", "xpm_cdc_pulse", "xpm_cdc_single",
            "xpm_cdc_sync_rst", "xpm_fifo_async", "xpm_fifo_axis", "xpm_fifo_axif", "xpm_fifo_axil", "xpm_fifo_sync", "xpm_memory_dpdistram",
            "xpm_memory_dprom", "xpm_memory_sdpram", "xpm_memory_spram", "xpm_memory_sprom", "xpm_memory_tdpram", "BRAM_SDP_MACRO",
            "BRAM_SINGLE_MACRO", "BRAM_TDP_MACRO", "ADDMACC_MACRO", "ADDSUB_MACRO", "COUNTER_LOAD_MACRO", "COUNTER_TC_MACRO",
            "EQ_COMPARE_MACRO", "MACC_MACRO", "MULT_MACRO", "FIFO_DUALCLOCK_MACRO", "FIFO_SYNC_MACROv", "BSCANE2", "BUFG",
            "BUFGCE", "BUFGCE_1", "BUFGCTRL", "BUFGMUX", "BUFGMUX_1", "BUFGMUX_CTRL", "BUFH", "BUFHCE", "BUFIO", "BUFMR",
            "BUFMRCE", "BUFR", "CAPTUREE2", "CARRY4", "CFGLUT5", "DCIRESET", "DNA_PORT", "DSP48E1", "EFUSE_USR", "FDCE",
            "FDPE", "FDRE", "FDSE", "FIFO18E1", "FIFO36E1", "FRAME_ECCE2", "IBUF", "IBUF_IBUFDISABLE", "IBUF_INTERMDISABLE",
            "IBUFDS", "IBUFDS_DIFF_OUT", "IBUFDS_DIFF_OUT_IBUFDISABLE", "IBUFDS_DIFF_OUT_INTERMDISABLE", "IBUFDS_GTE2", "IBUFDS_IBUFDISABLE",
            "IBUFDS_INTERMDISABLE", "ICAPE2", "IDDR", "IDDR_2CLK", "IDELAYCTRL", "IDELAYE2", "IN_FIFO","IOBUF", "IOBUF_DCIEN",
            "IOBUF_INTERMDISABLE", "IOBUFDS", "IOBUFDS_DCIEN", "IOBUFDS_DIFF_OUT", "IOBUFD S_DIFF_OUT_DCIEN",
            "IOBUFDS_DIFF_OUT_INTERMDISABLE", "IOBUFDS_INTERMDISABLE", "ISERDESE2", "KEEPER", "LDCE", "LDPE", "LUT1",
            "LUT2", "LUT3", "LUT4", "LUT5", "LUT6", "LUT6_2", "MMCME2_ADV", "MMCME2_BASE", "MUXF7", "MUXF8", "OBUF", "OBUFDS",
            "OBUFT", "OBUFTDS", "ODDR", "ODELAYE2", "OSERDESE2", "OUT_FIFO", "PLLE2_ADV", "PLLE2_BASE", "PULLDOWN", "PULLUP",
            "RAM128X1D", "RAM128X1S", "RAM256X1S", "RAM32M", "RAM32X1D", "RAM32X1S", "RAM32X1S_1", "RAM32X2S", "RAM64M",
            "RAM64X1D", "RAM64X1S", "RAM64X1S_1", "RAMB18E1", "RAMB36E1", "ROM128X1", "ROM256X1", "ROM32X1", "ROM64X1",
            "SRL16E", "SRLC32E", "STARTUPE2", "USR_ACCESSE2", "XADC"
    };
};





#endif //MAKEFILEGEN_V2_DATA_STORE_H
