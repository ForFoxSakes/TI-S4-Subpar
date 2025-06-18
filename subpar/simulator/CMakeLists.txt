cmake_minimum_required(VERSION 3.10)
project(SubparDronePluginProject LANGUAGES CXX)

# Vind de benodigde Gazebo Sim- en transport-/msgs-/math-packages
find_package(gz-sim9        REQUIRED)
find_package(gz-transport14 REQUIRED)
find_package(gz-msgs11      REQUIRED)
find_package(gz-math8       REQUIRED)
find_package(gz-plugin3     REQUIRED)

# Plugin: Publisher (control)
add_library(SubparDronePlugin SHARED
  plugins/SubparDronePlugin.cc
)
set_target_properties(SubparDronePlugin PROPERTIES
  CXX_STANDARD           17
  POSITION_INDEPENDENT_CODE ON
)
target_link_libraries(SubparDronePlugin PRIVATE
  gz-sim9::gz-sim9
  gz-transport14::gz-transport14
  gz-msgs11::gz-msgs11
  gz-math8::gz-math8
  gz-plugin3::gz-plugin3
)

# Plugin: Stabilizer (PID control)
add_library(SubparStabilizerPlugin SHARED
  plugins/SubparStabilizerPlugin.cc
)
set_target_properties(SubparStabilizerPlugin PROPERTIES
  CXX_STANDARD           17
  POSITION_INDEPENDENT_CODE ON
)
target_link_libraries(SubparStabilizerPlugin PRIVATE
  gz-sim9::gz-sim9
  gz-transport14::gz-transport14
  gz-msgs11::gz-msgs11
  gz-plugin3::gz-plugin3
)
# Subscriber executable
add_executable(subscriber
  subscriber/subscriber.cc
)
set_target_properties(subscriber PROPERTIES
  CXX_STANDARD           17
  POSITION_INDEPENDENT_CODE ON
)
target_link_libraries(subscriber PRIVATE
  gz-transport14::gz-transport14
  gz-msgs11::gz-msgs11
)
# (optioneel) installeer de plugins
install(TARGETS SubparDronePlugin SubparStabilizerPlugin
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)
