cmake_minimum_required(VERSION 3.16)
project(PisicaPeLuna CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Căutăm pachetul GTK+-3.0
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED IMPORTED_TARGET gtk+-3.0)

# Căutăm librăria nativă de Thread-uri (necesară pentru std::thread pe Linux)
find_package(Threads REQUIRED)

# Definim executabilul
add_executable(racheta_app main.cpp)

# Linkăm GTK și librăria de Thread-uri la executabilul nostru
target_link_libraries(racheta_app 
    PRIVATE 
        PkgConfig::GTK3
        Threads::Threads
)
