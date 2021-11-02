cmake_minimum_required(VERSION 3.13.4)
project(search_prime_numbers)

include(variables.cmake)

add_definitions(${COMMON_COMPILER_OPTS})

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})

set(MAIN_SRC ${PROJECT_SOURCE_DIR}/main.c)

include_directories(${PROJECT_INCLUDE_PATH})
include_directories(${PROJECT_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${MAIN_SRC})

add_subdirectory(ParametersHandler)
add_subdirectory(SearchPrimeNumbers)
add_subdirectory(Bitset)

target_link_libraries(${PROJECT_NAME} ParametersHandler)
target_link_libraries(${PROJECT_NAME} SearchPrimeNumbers)
target_link_libraries(${PROJECT_NAME} Bitset)
