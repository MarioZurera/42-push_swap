cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_C_STANDARD 11)

target_sources(GLOB SOURCES "src/*.c" "test/*.c")
add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(includes)