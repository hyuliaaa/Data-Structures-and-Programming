cmake_minimum_required(VERSION 3.15)
project(DBS)

set(CMAKE_CXX_STANDARD 14)

add_executable(DBS main.cpp Column.h IntColumn.cpp IntColumn.h DoubleColumn.cpp DoubleColumn.h StringColumn.cpp StringColumn.h BoolColumn.cpp BoolColumn.h Table.cpp Table.h DatabaseSystem.cpp DatabaseSystem.h)