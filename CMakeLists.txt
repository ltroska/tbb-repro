cmake_minimum_required(VERSION 3.15...4.0)
project(repro LANGUAGES CXX)

set(PYBIND11_FINDPYTHON ON)
find_package(pybind11 CONFIG REQUIRED)

find_package(TBB REQUIRED)

pybind11_add_module(repro repro.cpp)
install(TARGETS repro DESTINATION .)

target_link_libraries(repro PRIVATE TBB::tbb)

add_library(foo SHARED "foo.cpp")
target_link_libraries(foo PRIVATE TBB::tbb)

add_executable(main "main.cpp")
target_link_libraries(main PRIVATE TBB::tbb)
