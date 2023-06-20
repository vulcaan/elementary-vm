cmake_minimum_required(VERSION 3.10)

project(elementary_vm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(lib/reader)
add_subdirectory(lib/parser)
add_subdirectory(lib/controller)
add_subdirectory(apps)
