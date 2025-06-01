cmake_minimum_required(VERSION 3.10)
project(SubparDronePluginProject)

find_package(gz-sim9 REQUIRED)
find_package(gz-plugin3 REQUIRED)

add_library(SubparDronePlugin SHARED
  plugins/SubparDronePlugin.cc
)

target_link_libraries(SubparDronePlugin
  gz-sim9::gz-sim9
  gz-plugin3::gz-plugin3
)
