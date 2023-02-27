cmake_minimum_required(VERSION 3.10)

project(Exercise4)

add_executable(SCVP.Exercise4
    main.cpp
)

target_include_directories(SCVP.Exercise4
    PRIVATE $ENV{SYSTEMC_HOME}/include/
)

find_library(SYSTEMC_LIBRARY 
    NAMES systemc
    PATHS $ENV{SYSTEMC_HOME}/lib-$ENV{SYSTEMC_TARGET_ARCH}/
)

target_link_libraries(SCVP.Exercise4
    PRIVATE ${SYSTEMC_LIBRARY}
)
