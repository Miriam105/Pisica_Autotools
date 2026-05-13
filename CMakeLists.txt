cmake_minimum_required(VERSION 3.16)
project(PisicaPeLuna CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED IMPORTED_TARGET gtk+-3.0)

find_package(Threads REQUIRED)

add_executable(racheta_app main.cpp)

target_link_libraries(racheta_app 
    PRIVATE 
        PkgConfig::GTK3
        Threads::Threads
)
