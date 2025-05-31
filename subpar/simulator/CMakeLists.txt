cmake_minimum_required(VERSION 3.10)
project(subpar_plugin)

find_package(gz-sim REQUIRED)

add_library(SubparDronePlugin SHARED SubparDronePlugin.cc)
target_link_libraries(SubparDronePlugin gz-sim::gz-sim)
