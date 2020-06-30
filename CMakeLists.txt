cmake_minimum_required (VERSION 3.8)
SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
project ("word-find")
add_executable(word-find "main.cpp" "wordSort.h" "wordSort.cpp")

