cmake_minimum_required(VERSION 3.25)
project(misc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-g)

aux_source_directory(. src_list)
foreach(src ${src_list})
    string(REPLACE "./" "" src ${src})
    string(REPLACE ".cpp" "" exe ${src})
    message(STATUS ${exe} ${src})
    add_executable(${exe} ${src})
endforeach()
