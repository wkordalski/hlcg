project(HLCG)
cmake_minimum_required(VERSION 2.6)

set(SOURCES
  assembly/assembly.cpp
  
  node/module.cpp
  node/select.cpp
  node/template.cpp

  plugin/manager.cpp
  plugin/plugin.cpp
)

add_definitions(-std=c++11)

#
# LLVM package
#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/share/llvm/cmake/)

find_package(LLVM REQUIRED)
include(HandleLLVMOptions)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
set(LLVM_LIBRARIES /usr/lib64/llvm/libLLVM-3.4.so )

#
# HLCG library
#

add_library(hlcg ${SOURCES})
target_link_libraries(hlcg ${LLVM_LIBRARIES})

#
# Testing the library
#

add_executable(test test/main.cpp)
target_link_libraries(test hlcg)
