cmake_minimum_required (VERSION 3.8)

aux_source_directory(. DIR_HOOKS_SCRS)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(hooks ${DIR_HOOKS_SCRS})