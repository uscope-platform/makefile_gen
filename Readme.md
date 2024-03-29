# Makefile_gen

Makefile_gen is a build system for FPGA HDL development, it allows the developer to structure their
IP repository in the most logical way, without having to conform to the one required by the toolchain vendor.

The tool analyzes all the HDL files in the repository, figuring out the dependencies between modules, and can automatically generate 
a working project in the vendor IDE of choice through a templated tcl-script.

Upon the first run the software will prompt the user for the HDL repository base directory path, and it will start analyzing its content.
It should be noted that while the step is multi-threaded, it is computationally intensive, and could take up to few minutes for very large repositories.
Any subsequent run will be nearly instant as only the modified files will be scanned again.

Several mechanisms are available to exclude sub-directories from the analysis:

- **.mkinclude**: Directories containing a .mkinclude file (it only needs to exist) will be skipped
- **IDE projects**: Directories containing an IDE project file (like .xpr for Xilinx Vivado) will be ignored
- **.git**: git source control hidden directories will be ignored

## Toolchain support

The following toolchains are supported:

- Xilinx Vivado
- Lattice Radiant

### Limitations

- Include directories need to be set up manually in Lattice Radiant as the feature is not exposed through tcl scripting

## Supported platform

- Linux (developed and tested on debian based distro)

## Depfile

A Depfile is a JSON file used to define how a specific project should be set up by the tool, the following fields are
required by the tool

```json
{
    "general":{
        "project_name":"Test",
        "target_part":"xc7z020clg400",
	    "synth_modules":[
          "first_additional_synth_module", 
          "second_additional_synth_module"
        ],
        "synth_tl": "synth_tl_module",
        "sym_modules":[
          "first_additional_sim_module",
          "second_additional_sim_module"
        ],
        "sim_tl":"sim_tl_module",
        "include_paths":[
            "first_include_dir",
            "second_include_dir"
        ]
    },
    "scripts":[
        {
            "name":"set_properties.tcl",
            "type": "tcl",
            "arguments":[]
        },
        {
            "name":"zynqAxiStreamBd.tcl",
            "type": "py",
            "arguments":[
              "first_arg",
              "second_arg"
            ],
            "product_include":true,
            "product_type":"tcl"
        }
    ],
    "excluded_modules":[
       "excluded_module_1",
       "excluded_module_2"
    ],
    "constraints": [
        "constraints.xdc"
    ]
}
```

### General section
This section of the file contains general information needed to create the output project

- **project name**: Field specifying the name of the output project -- MANDATORY
- **target_part**: String identifying the target part/board -- RESERVED FOR FUTURE DEVELOPMENT
- **synth_tl**: Name of the synthesis top level module. -- MANDATORY
- **synth_modules**: List of additional HDL module names to add to the project, for synthesis, that can not be automatically discovered starting from the top level -- OPTIONAL
- **sim_tl**: Name of the simulation top level module. -- MANDATORY
- **sim_modules**: List of additional HDL module names to add to the project,  for simulation, that can not be automatically discovered starting from the top level -- OPTIONAL
- **include_paths**: List of paths (relative to the repository base), that contain Verilog and System Verilog include files -- OPTIONAL

### Scripts section
This section contains a list of script objects that need to be invoked prior or during the project generation step, with each script containing the following fields

- **name**: Name of the script to invoke (comprising of eventual file extension)
- **type**: Type of the script (supported types TCL and python)
- **arguments**: List of arguments to pass to the script (Leave empty if no arguments are needed) 
- **product_include**: Flag that indicated whether the file generated by the script should be added (if not present it is assumed to be false)
- **product_type**: Type of the file generated by the script (tcl, hdl or xdc)

### Other sections

- **excluded_modules**: List of HDL module names that do not need to be added to the project even if they are dependencies (ie. Xilinx IPI block diagrams)
- **constraints**: List of constraint files that need to be added to the project


# Development

## Dependencies

The only runtime dependency needed by the makefile_gen tool is the pthread library, which should be already available in any modern Linux distribution.
All other libraries are statically linked during compilation to ease deployment.


## Building from source

When building from source the following additional dependencies are necessary

- Cmake
- OpenSSL
- Gtest library

To install on Ubuntu (22.04) use
```shell
sudo apt install libssl-dev libgtest-dev build-essential pkg-config uuid-dev libgmock-dev python3-jinja2
```

To build from source the following command can be used:

```shell
cd makefile_gen
mkdir build && cd build
cmake ..
cmake --build . --parallel 4
sudo cmake --install .
```
To generate a distributable DEB package use the following command:

```shell
cpack -G DEB
```
