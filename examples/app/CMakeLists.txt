project(app CXX)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(app ${SOURCES})

target_link_libraries(app PRIVATE plugin)
target_link_libraries(app PRIVATE plugin_interface) 
target_link_libraries(app PRIVATE plugin_mgr)

set_target_properties(app PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties(app PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_target_properties(app PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set_target_properties(app PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set_target_properties(app PROPERTIES FOLDER "examples")

add_custom_command(TARGET app POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:app>/plugins
                    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:plugin1> $<TARGET_FILE_DIR:app>/plugins/
                    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:plugin2> $<TARGET_FILE_DIR:app>/plugins/)
