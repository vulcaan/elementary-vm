cmake_minimum_required(VERSION 3.10)

project(elementary_vm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

add_subdirectory(lib/reader)

target_link_libraries(${PROJECT_NAME}
                    PUBLIC
                    reader
)
