project(parsing)

add_library(${PROJECT_NAME} src/command_parser.cpp
                            src/arg_parser.cpp
                            src/cli_commands.cpp
)
target_include_directories(${PROJECT_NAME}
                    PUBLIC
                        include
)
