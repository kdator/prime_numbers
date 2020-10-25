cmake_minimum_required(VERSION 3.13.4)
project (ParametersHandler)

include(${CMAKE_CURRENT_SOURCE_DIR}/../variables.cmake)

add_definitions(${COMPILER_OPTS})
 
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

set(PROJECT_SRCS ${PROJECT_SOURCE_DIR}/ParametersHandler.c)

include_directories(${PROJECT_INCLUDE_PATH})
include_directories(${PROJECT_INCLUDE_DIR})

add_library(${PROJECT_NAME} SHARED ${PROJECT_SRCS})
