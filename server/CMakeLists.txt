CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(GPIO_SERVER)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./bin/")

INCLUDE_DIRECTORIES(
  gpio/include
  )


FILE(GLOB_RECURSE all_files
  gpio/include/*.h
  gpio/source/*.cpp
  main.cpp
  )


ADD_EXECUTABLE(gpio_server ${all_files})
  


