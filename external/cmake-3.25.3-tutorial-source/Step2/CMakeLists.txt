cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Tutorial VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)

# TODO 8: Use list() and APPEND to create a list of optional libraries
# called  EXTRA_LIBS and a list of optional include directories called
# EXTRA_INCLUDES. Add the MathFunctions library and source directory to
# the appropriate lists.
#
# Only call add_subdirectory and only add MathFunctions specific values
# to EXTRA_LIBS and EXTRA_INCLUDES if USE_MYMATH is true.
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    list(APPEND EXTRA_INCLUDES ${PROJECT_SOURCE_DIR}/MathFunctions)
endif()
# add the executable
add_executable(Tutorial tutorial.cxx)

# TODO 9: Use EXTRA_LIBS instead of the MathFunctions specific values
# in target_link_libraries.
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(Tutorial PUBLIC
                           ${PROJECT_BINARY_DIR}
                           ${EXTRA_INCLUDES}
                           )
