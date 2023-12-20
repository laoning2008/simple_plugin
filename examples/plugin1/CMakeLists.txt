project(plugin1 CXX)

add_library(plugin1 SHARED ${CMAKE_CURRENT_SOURCE_DIR}/plugin1.cpp)

target_link_libraries(plugin1 PRIVATE plugin plugin_interface)
target_compile_definitions(plugin1 PRIVATE BUILDING_PLUGIN_API=1)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")

set_target_properties(plugin1 PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties(plugin1 PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties(plugin1 PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set_target_properties(plugin1 PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set_target_properties(plugin1 PROPERTIES FOLDER "examples")
