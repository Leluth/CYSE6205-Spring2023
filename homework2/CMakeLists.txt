cmake_minimum_required(VERSION 3.0.0)
project(homework2 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
include(CTest)
enable_testing()

aux_source_directory(. source_list)

add_executable(homework2 ${source_list})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
