cmake_minimum_required(VERSION 3.10)
project(SubparDronePluginProject)
cmake_policy(SET CMP0100 NEW)

# Sim & Plugin deps
find_package(gz-sim9 REQUIRED)
find_package(gz-plugin3 REQUIRED)
get_target_property(GZ_SIM_INCLUDE_DIRS gz-sim9::gz-sim9 INTERFACE_INCLUDE_DIRECTORIES)

# Transport & Messages
find_package(PkgConfig REQUIRED)
pkg_check_modules(GZ_TRANSPORT REQUIRED gz-transport12)
pkg_check_modules(GZ_MSGS REQUIRED gz-msgs9)
pkg_check_modules(GZ_MATH REQUIRED gz-math7)

# Qt + GUI plugin
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Quick)
find_package(gz-gui7 REQUIRED)

# ✅ SubparDronePlugin
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

# Qt + GUI plugin
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Quick)
find_package(gz-gui7 REQUIRED)

# ✅ GUI Plugin resources
qt5_add_resources(QT_RESOURCES
  plugins/SubparKeyGuiPlugin.qrc
)

# ✅ SubparKeyGuiPlugin library
add_library(SubparKeyGuiPlugin SHARED
  plugins/SubparKeyGuiPlugin.cc
  ${QT_RESOURCES}
)

target_include_directories(SubparKeyGuiPlugin PRIVATE
  ${GZ_TRANSPORT_INCLUDE_DIRS}
  ${GZ_MSGS_INCLUDE_DIRS}
  ${GZ_MATH_INCLUDE_DIRS}
  ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(SubparKeyGuiPlugin
  gz-sim9::gz-sim9
  gz-plugin3::gz-plugin3
  gz-gui7::gz-gui7
  ${GZ_TRANSPORT_LIBRARIES}
  ${GZ_MSGS_LIBRARIES}
  ${GZ_MATH_LIBRARIES}
  Qt5::Widgets
  Qt5::Quick
)
