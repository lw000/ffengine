cmake_minimum_required (VERSION 3.8)

aux_source_directory(. DIR_PACKET_SRCS)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(packet ${DIR_PACKET_SRCS})