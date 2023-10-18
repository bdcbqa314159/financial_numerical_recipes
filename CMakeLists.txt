cmake_minimum_required(VERSION 3.22...3.27)

project(Advanced_qf_book VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_DATES my_lib_dates)


set(EXECUTABLE_DATES executable_dates)

add_subdirectory(src)
add_subdirectory(app)
# add_subdirectory(tests)
