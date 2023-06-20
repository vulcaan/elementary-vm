project(controlling)

add_library(${PROJECT_NAME}
                    src/controller.cpp
)

target_include_directories(${PROJECT_NAME}
                    PUBLIC
                        include
)

target_link_libraries(${PROJECT_NAME}
                    PUBLIC
                        reading
                        parsing
)
