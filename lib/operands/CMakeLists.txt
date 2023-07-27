project(operands)

add_library(${PROJECT_NAME}
                src/operand_creator.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
