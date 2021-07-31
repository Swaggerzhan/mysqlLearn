cmake_minimum_required(VERSION 3.19)
project(mysqlLearn)

set(CMAKE_CXX_STANDARD 14)


include_directories(/usr/local/include/hiredis)

link_directories(/usr/local/lib)

add_executable(mysqlLearn main.cpp)


target_link_libraries(mysqlLearn hiredis)