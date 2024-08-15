# 设置CMake的最小版本要求
cmake_minimum_required(VERSION 3.28)

# 获取当前源目录的名称，并将其作为项目ID
get_filename_component(ProjectName ${CMAKE_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectName ${ProjectName})
project(${ProjectId} C)


## 设置C语言标准为C11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 添加包含目录
include_directories(include)

## 源文件所在的目录
file(GLOB SOURCE_FILES src/*.c)

file(GLOB TEST_FILES test/*.c)
foreach (file ${TEST_FILES})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file} ${SOURCE_FILES})
endforeach ()


