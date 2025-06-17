cmake_minimum_required(VERSION 3.10)
project(SubparDronePluginProject)

# Policies
cmake_policy(SET CMP0100 NEW)

# Dependencies
find_package(gz-sim9 REQUIRED)
find_package(gz-plugin3 REQUIRED)
pkg_check_modules(GZ_TRANSPORT REQUIRED gz-transport12)
pkg_check_modules(GZ_MSGS REQUIRED gz-msgs9)
pkg_check_modules(GZ_MATH REQUIRED gz-math7)

# Plugin: SubparDronePlugin
add_library(SubparDronePlugin SHARED
  plugins/SubparDronePlugin.cc
)

target_include_directories(SubparDronePlugin PRIVATE
  ${GZ_TRANSPORT_INCLUDE_DIRS}
  ${GZ_MSGS_INCLUDE_DIRS}
  ${GZ_MATH_INCLUDE_DIRS}
)

target_link_libraries(SubparDronePlugin
  gz-sim9::gz-sim9
  gz-plugin3::gz-plugin3
  ${GZ_TRANSPORT_LIBRARIES}
  ${GZ_MSGS_LIBRARIES}
  ${GZ_MATH_LIBRARIES}
)

# (optioneel) install
install(TARGETS SubparDronePlugin LIBRARY DESTINATION lib)
