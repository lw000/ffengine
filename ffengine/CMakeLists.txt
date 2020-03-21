# CMakeList.txt: ffengine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

set(SOURCE_FILES ffengine.cpp)

# 将源代码添加到此项目的可执行文件。
add_executable (ffengine ${SOURCE_FILES})

#link_directories(${PROJECT_SOURCE_DIR}/lib) #添加动态连接库的路径

target_link_libraries(ffengine ghttp network luaengine logger lua common hooks packet)

# TODO: 如有需要，请添加测试并安装目标。
