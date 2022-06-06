cmake_minimum_required(VERSION 3.22)
project(project)

set(CMAKE_CXX_STANDARD 23)

add_executable(project main.cpp tictactoe.cpp tictactoe.h numberguesser.cpp numberguesser.h rps.cpp rps.h)
