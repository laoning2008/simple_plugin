cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(simple_plugin CXX)

option(BUILD_EXAMPLES "build examples" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugin)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/plugin_mgr_impl)

if(${BUILD_EXAMPLES})
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/examples)
endif(${BUILD_EXAMPLES})
