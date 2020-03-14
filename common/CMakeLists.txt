cmake_minimum_required(VERSION 3.8)

aux_source_directory(. DIR_COMMON_SRCS)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(common ${DIR_COMMON_SRCS})