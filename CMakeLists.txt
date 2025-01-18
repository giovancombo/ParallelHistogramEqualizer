cmake_minimum_required(VERSION 3.10)
project(2_finalterm)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(OpenMP REQUIRED)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
endif()

add_executable(2_finalterm
        src/main.cpp
        src/equalizer.cpp
        src/equalizer.hpp
)

target_link_libraries(2_finalterm PRIVATE OpenMP::OpenMP_CXX)