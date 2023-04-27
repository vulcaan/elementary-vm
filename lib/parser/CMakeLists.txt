project(parser)

add_library(${PROJECT_NAME} src/parser.cpp)
target_include_directories(${PROJECT_NAME}
                    PUBLIC
                        include
)
