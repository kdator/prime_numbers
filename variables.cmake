cmake_minimum_required(VERSION 3.13.4)

set (COMMON_COMPILER_OPTS -Wall)

set (CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set (CMAKE_CXX_FLAGS_RELEASE "-O2 -g")

set (CMAKE_USE_RELATIVE_PATHS true)

get_filename_component(PATH_TO_VARIABLES_FILE
                       ${CMAKE_CURRENT_LIST_FILE} PATH)

set (PROJECT_INCLUDE_PATH "${PATH_TO_VARIABLES_FILE}/include")
