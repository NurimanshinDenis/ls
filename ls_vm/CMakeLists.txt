cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(ls_vm)

add_library(ls_vm OBJECT 
  src/ls_vm.cpp
)

target_include_directories(ls_vm PUBLIC include/)