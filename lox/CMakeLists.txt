cmake_minimum_required(VERSION 4.0)
project(lox)

set(C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

ADD_EXECUTABLE(
    lox
    source/c/main.c
)

TARGET_COMPILE_OPTIONS(lox PRIVATE
    -std=c11
    -g
    -Wall
    -Wextra
    -static
)

TARGET_LINK_LIBRARIES(lox PRIVATE
    # glad
    # glfw
)

TARGET_INCLUDE_DIRECTORIES(lox PRIVATE
    # ${CMAKE_SOURCE_DIR}/include
)

TARGET_COMPILE_DEFINITIONS(lox PRIVATE
    # GLFW_INCLUDE_NONE
)

add_custom_target(run
    COMMAND lox
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    DEPENDS lox
    COMMENT "running lox from root directory"
)

