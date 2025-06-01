cmake_minimum_required(VERSION 3.10)
project(SubparTransport)

find_package(gz-transport14 REQUIRED)
find_package(gz-msgs11 REQUIRED)

add_executable(subscriber subscriber.cc)
add_executable(publisher publisher.cc)

target_link_libraries(subscriber gz-transport14 gz-msgs11)
target_link_libraries(publisher gz-transport14 gz-msgs11)
