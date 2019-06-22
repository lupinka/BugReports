cmake_minimum_required(VERSION 3.14)
project(BugReports C)

set(CMAKE_C_STANDARD 99)

add_library(BugReports library.c library.h)