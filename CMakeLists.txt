cmake_minimum_required(VERSION 3.25)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(fmt-10.0.0)

find_package(Qt6 REQUIRED COMPONENTS
        Core
        )


find_package(fmt)

add_executable(untitled main.cpp)

target_link_libraries(untitled PRIVATE fmt::fmt Qt6::Core)
