# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.5)
#项目名称, 参数值是 main, 该命令表示项目的名称是 main
project(main)
# 添加源文件目录
aux_source_directory(src DIR_SRC_SRCS)

# 显示指定使用的C编译器 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRC_SRCS})
