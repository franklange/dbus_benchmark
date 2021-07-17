cmake_minimum_required(VERSION 3.10)
project(dbus_benchmark)

find_package(nlohmann_json REQUIRED)
find_package(sdbus-c++ REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build Type" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

add_subdirectory(common)
add_subdirectory(server)
add_subdirectory(client)
