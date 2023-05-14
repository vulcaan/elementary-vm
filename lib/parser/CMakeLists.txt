project(parsing)

add_library(${PROJECT_NAME} src/command_parser.cpp)
target_include_directories(${PROJECT_NAME}
                    PUBLIC
                        include
)
