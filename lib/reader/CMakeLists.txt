project(reader)

add_library(${PROJECT_NAME} src/reader.cpp)
target_include_directories(${PROJECT_NAME}
                    PUBLIC
                        include
)
