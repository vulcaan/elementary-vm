project(operands)

add_library(${PROJECT_NAME}
                src/creator.cpp
                src/int8.cpp
                src/int16.cpp
                src/int32.cpp
                src/int64.cpp
                src/float32.cpp
                src/float64.cpp
                src/operand_parser.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
