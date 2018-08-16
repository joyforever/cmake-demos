cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_STANDARD 11)

# Prebuilt Libraries.
add_library(ev STATIC IMPORTED)
set_target_properties(ev PROPERTIES IMPORTED_LOCATION
    "${CMAKE_SOURCE_DIR}/deps/libev-4.24/lib/libev.a")
set_target_properties(ev PROPERTIES INTERFACE_INCLUDE_DIRECTORIES
    "${CMAKE_SOURCE_DIR}/deps/libev-4.24/include")

# Header-Only Libraries.
add_library(json INTERFACE)
target_include_directories(json INTERFACE
    "${CMAKE_SOURCE_DIR}/deps/json-3.1.2/include")

add_executable(demo demo.cpp)
target_link_libraries(demo ev json)
