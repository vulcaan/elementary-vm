project(parsing)

add_library(${PROJECT_NAME}
                src/cli/parser.cpp
                src/cli/commands.cpp
                src/instruction/parser.cpp
                src/instruction/commands.cpp
                src/instruction/creator.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME}
                            PUBLIC
                                reading
                                operands
)
