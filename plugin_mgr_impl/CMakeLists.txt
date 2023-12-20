cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(plugin_mgr CXX)

set(SOURCES 
        ${CMAKE_CURRENT_SOURCE_DIR}/dylib.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin_mgr_api_impl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin_mgr_impl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/plugin_mgr_impl.hpp)

add_library(plugin_mgr SHARED ${SOURCES})

target_link_libraries(plugin_mgr PRIVATE plugin)
target_compile_definitions(plugin_mgr PRIVATE BUILDING_PLUGIN_API=1)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

set_target_properties(plugin_mgr PROPERTIES OUTPUT_NAME "plugin_mgr")
set_target_properties(plugin_mgr PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties(plugin_mgr PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties(plugin_mgr PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set_target_properties(plugin_mgr PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
