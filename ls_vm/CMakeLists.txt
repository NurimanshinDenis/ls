cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(ls_vm)

add_library(ls_vm OBJECT 
  src/vm/constants.h
  src/vm/mtx.cpp
  src/vm/mtx.h
  src/vm/processor.cpp
  src/vm/processor.h
  src/vm/queue.h
  src/vm/transport.h
  src/vm/types.h
  src/vm/worker_node.cpp
  src/vm/worker_node.h
  src/vm/worker.cpp
  src/vm/worker.h
  src/ls_vm.cpp
)

target_include_directories(ls_vm PUBLIC include/)