cmake_minimum_required(VERSION 3.8)
project(DBSCAN)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -fopenmp -lstdc++fs)
endif()

include_directories(${DBSCAN_SOURCE_DIR}/src)

add_executable(test src/main.cpp src/dbscan.cpp src/dbscan.cpp)
