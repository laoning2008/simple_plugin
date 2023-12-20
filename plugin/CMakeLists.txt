project(plugin CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(plugin INTERFACE)

target_include_directories(plugin INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}) 