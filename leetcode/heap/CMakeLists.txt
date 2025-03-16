cmake_minimum_required(VERSION 3.25)
project(misc)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(-g)

aux_source_directory(. src_list)
foreach(src ${src_list})
    string(REPLACE "./" "" src ${src})
    string(REPLACE ".cpp" ".out" exe ${src})
    message(STATUS ${src} " ==> " ${exe})
    add_executable(${exe} ${src})
endforeach()

# message(STATUS ${PROJECT_SOURCE_DIR})
# file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
# foreach(src ${SOURCES})
#     message(STATUS ${src})
# endforeach()

# function(find_files_in_directory dir)
#     file(GLOB files "${dir}/*")
#     foreach(file ${files})
#         if(IS_DIRECTORY ${file})
#             find_files_in_directory(${file})  # 递归调用
#         else()
#             message(STATUS "Found file: ${file}")
#             list(APPEND all_files ${file})  # 收集文件
#         endif()
#     endforeach()
# endfunction()

# set(all_files "")
# find_files_in_directory(${CMAKE_SOURCE_DIR}/src)
