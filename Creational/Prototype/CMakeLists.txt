cmake_minimum_required(VERSION 3.31.3)
project(check)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp prototype.cpp)