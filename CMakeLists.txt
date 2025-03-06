## 
# mkdir build-debug
# cd build-debug
# cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
# mingw32-make

# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.5)
#项目名称, 参数值是 main, 该命令表示项目的名称是 main
project(main)

# 设置默认构建类型为 Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# 添加源文件目录
aux_source_directory(src DIR_SRC_SRCS)

# 显示指定使用的C编译器 
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 配置不同构建类型的编译选项
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG")

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRC_SRCS})
# 为不同的构建类型设置不同的输出文件名
set_target_properties(${PROJECT_NAME} PROPERTIES
    DEBUG_POSTFIX "_debug"
    RELEASE_POSTFIX "_release"
)
