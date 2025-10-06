cmake_minimum_required(VERSION 3.20)

project(forward-list)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "*.cpp")

add_executable(forward-list ${SOURCES})