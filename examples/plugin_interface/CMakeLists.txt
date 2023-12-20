project(plugin_interface CXX)
add_library(plugin_interface INTERFACE)

target_include_directories(plugin_interface INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}) 
target_link_libraries(plugin_interface INTERFACE plugin)   
set_target_properties(plugin_interface PROPERTIES FOLDER "examples")