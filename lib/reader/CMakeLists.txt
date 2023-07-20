project(reading)

add_library(${PROJECT_NAME}
                src/console_reader.cpp
                src/file_reader.cpp
)
target_include_directories(${PROJECT_NAME}
                    PUBLIC
                        include
)
