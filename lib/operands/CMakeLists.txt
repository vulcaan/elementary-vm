project(operands)

add_library(${PROJECT_NAME}
                src/creator.cpp
                src/operand_parser.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
