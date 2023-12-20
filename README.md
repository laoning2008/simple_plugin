# simple_plugin
simple plugin framework.

## Integration
you can use CMake to integrate the asyncmsg into your project. Here is an example CMakeLists.txt file that demonstrates how to do this:

```cmake
cmake_minimum_required(VERSION 3.5)
project(my_project)

add_subdirectory(simple_plugin)

project(app CXX)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(app ${SOURCES})

target_link_libraries(app PRIVATE plugin)
target_link_libraries(app PRIVATE plugin_interface) 
target_link_libraries(app PRIVATE plugin_mgr)
```

## Example

```cpp
#include <plugin_mgr.hpp>
#include <plugin1.hpp>
#include <plugin2.hpp>
#include <filesystem>

int main(int argc, char** argv) {
    std::filesystem::path plugin_path(argv[0]);
    plugin_path = plugin_path.parent_path();
    plugin_path.append("plugins");
    
    load_plugins(plugin_path.string().c_str());
    auto p1 = get_plugin_t<plugin1>("plugin1");
    p1->say_hello();
    
    return 0;
}
```