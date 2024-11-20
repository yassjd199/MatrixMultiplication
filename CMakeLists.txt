cmake_minimum_required(VERSION 3.10)

# Project name
project(MatrixMultiplication)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
add_executable(MatrixMultiplication
    src/main.cpp
    src/Matrix.cpp
    src/MatrixMultiplication.cpp
)
