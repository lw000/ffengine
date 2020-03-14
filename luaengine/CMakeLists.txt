cmake_minimum_required (VERSION 3.8)

aux_source_directory(. DIR_LUAENGINT_SRCSS)
aux_source_directory(./gfunction DIR_LUAENGINT_SRCSS)
aux_source_directory(./coremodule DIR_LUAENGINT_SRCSS)


SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_compile_options(-std=c++11)

add_library(luaengine ${DIR_LUAENGINT_SRCSS})
target_link_libraries(luaengine common)
