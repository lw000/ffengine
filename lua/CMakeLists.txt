cmake_minimum_required(VERSION 3.8)

aux_source_directory(. DIR_LUA_SCRS)
add_library(lua ${DIR_LUA_SCRS})