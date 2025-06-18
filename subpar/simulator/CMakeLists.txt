cmake_minimum_required(VERSION 3.10)
project(SubparDronePluginProject LANGUAGES CXX)

# Vind de benodigde Gazebo Sim- en transport-/msgs-/math-packages
find_package(gz-sim9        REQUIRED)   # core simulation
find_package(gz-transport12 REQUIRED)   # advertise/subscribe API
find_package(gz-msgs11      REQUIRED)   # alle protobuf‐factories
find_package(gz-math7       REQUIRED)   # wiskundige hulpfuncties (M_PI, etc)
find_package(gz-plugin3     REQUIRED)   # plugin‐registry

# Maak de shared library van je plugin
add_library(SubparDronePlugin SHARED
  plugins/SubparDronePlugin.cc
)

# Zorg dat we C++17 gebruiken
set_target_properties(SubparDronePlugin PROPERTIES
  CXX_STANDARD           17
  POSITION_INDEPENDENT_CODE ON
)

# Link tegen de geïmporteerde Gazebo‐targets
target_link_libraries(SubparDronePlugin PRIVATE
  gz-sim9::gz-sim9
  gz-transport12::gz-transport12
  gz-msgs11::gz-msgs11
  gz-math7::gz-math7
  gz-plugin3::gz-plugin3
)

# (optioneel) installeer de plugin
install(TARGETS SubparDronePlugin
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
