cmake_minimum_required(VERSION 3.22...3.27)

project(Advanced_qf_book VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LIBRARY_RANDOM my_lib_random)
set(LIBRARY_LINEAR_ALGEBRA my_linear_algebra)
set(LIBRARY_EQ my_lib_equity)
set(LIBRARY_FX my_lib_fx)
set(LIBRARY_IR my_lib_ir)
set(LIBRARY_CREDIT my_lib_credit)

set(EXECUTABLE_EQ executable_equity)
set(EXECUTABLE_FX executable_fx)
set(EXECUTABLE_IR executable_ir)
set(EXECUTABLE_CREDIT executable_credit)


add_subdirectory(src)
add_subdirectory(app)
# add_subdirectory(tests)
