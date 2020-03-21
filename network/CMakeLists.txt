cmake_minimum_required(VERSION 3.8)

aux_source_directory(. DIR_NETWORK_SCRS)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_compile_options(-std=c++11)

#add_library(network SHARED ${DIR_NETWORK_SCRS})
add_library(network ${DIR_NETWORK_SCRS})