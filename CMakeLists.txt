cmake_minimum_required(VERSION 3.10)
project(CornFieldVisibility)

set(CMAKE_CXX_STANDARD 11)

add_executable(CornFieldVisibility main.cpp FileReader.cpp Field.cpp)
