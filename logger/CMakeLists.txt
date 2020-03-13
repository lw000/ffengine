cmake_minimum_required(VERSION 3.8)

aux_source_directory(. DIR_LOGGER_SCRS)
add_library(logger ${DIR_LOGGER_SCRS})