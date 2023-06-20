project(parsing)

add_library(${PROJECT_NAME}
                src/cli_parser.cpp
                src/cli_commands.cpp
                src/instruction_tokenizer.cpp
                src/instruction_parser.cpp
                src/instruction_commands.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME}
                            PUBLIC
                                reading
)
