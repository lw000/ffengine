cmake_minimum_required(VERSION 3.8)

aux_source_directory(. DIR_NETWORK_SCRS)
add_library(network ${DIR_NETWORK_SCRS})

add_compile_options(-std=c++11)