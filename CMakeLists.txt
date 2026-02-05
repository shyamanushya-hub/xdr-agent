cmake_minimum_required(VERSION 3.21)
project(xdr_agent LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(XDR_BUILD_TESTS "Build tests" OFF)

add_subdirectory(common)
add_subdirectory(agent)
