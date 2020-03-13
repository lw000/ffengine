cmake_minimum_required (VERSION 3.8)

aux_source_directory(. DIR_LUAENGINT_SRCSS)
aux_source_directory(./gfunction DIR_LUAENGINT_SRCSS)
aux_source_directory(./coremodule DIR_LUAENGINT_SRCSS)

add_compile_options(-std=c++11)

add_library(luaengine ${DIR_LUAENGINT_SRCSS})
