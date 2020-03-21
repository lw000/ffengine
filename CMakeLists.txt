# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("ffengine")

include_directories(
	ffengine
	network
	luaengine
	lua
	logger
	common
	hooks
	packet
	libghttp
)

set(CMAKE_CXX_STANDARD 11)

# 包含子项目。
add_subdirectory(ffengine)
add_subdirectory(network)
add_subdirectory(luaengine)
add_subdirectory(lua)
add_subdirectory(common)
add_subdirectory(logger)
add_subdirectory(hooks)
add_subdirectory(packet)
add_subdirectory(libghttp)