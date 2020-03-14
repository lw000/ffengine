cmake_minimum_required(VERSION 3.8)

# aux_source_directory(. DIR_LOGGER_SCRS)
# add_library(logger ${DIR_LOGGER_SCRS})
set(LOGGER_SCRS
	logger.cpp
)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_library(logger ${LOGGER_SCRS})