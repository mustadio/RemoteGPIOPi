CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(GPIO_SERVER)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin/")

INCLUDE_DIRECTORIES(
  gpio/include
  )

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11" )

FILE(GLOB_RECURSE all_files
  gpio/include/*.h
  gpio/source/*.cpp
  main.cpp
  )


ADD_EXECUTABLE(gpio_server ${all_files})
  


