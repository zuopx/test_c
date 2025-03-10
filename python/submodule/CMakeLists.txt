cmake_minimum_required(VERSION 3.10)

# 设置项目名称和语言
project(parent LANGUAGES C)

# 查找 Python 解释器
find_package(PythonInterp REQUIRED)

# 查找 Python 开发包
find_package(PythonLibs REQUIRED)

# 设置包含目录
message(STATUS "Python include dirs: ${PYTHON_INCLUDE_DIRS}")
include_directories(${PYTHON_INCLUDE_DIRS})

# 创建共享库
set(SOURCES parent.c child.c)
add_library(parent MODULE ${SOURCES})

# 链接 Python 库
message(STATUS "Python libraries: ${PYTHON_LIBRARIES}")
target_link_libraries(parent ${PYTHON_LIBRARIES})

# 设置库输出目录和名称
set_target_properties(parent PROPERTIES
    SUFFIX ".so"  # 对于 Linux/macOS，Windows 上使用 ".pyd"
    PREFIX ""     # 不添加前缀
    OUTPUT_NAME "parent"  # 输出文件名
)

# 处理 Python 版本
message(STATUS "Python version: ${PYTHON_VERSION_STRING}")
if(PYTHON_VERSION_STRING VERSION_LESS "3.0")
    message(FATAL_ERROR "Python version must be 3.0 or higher")
endif()

# 设置编译选项以启用调试信息
if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)  # 如果未指定构建类型，则设置为 Debug
endif()

# 关闭编译优化
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")  # 添加 -O0 选项以关闭优化
