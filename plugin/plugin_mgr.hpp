#pragma once
#include <symbol_visibility.hpp>
#include <plugin.hpp>

PLUGIN_API bool load_plugins(const char* plugins_dir);
PLUGIN_API plugin* get_plugin(const char* plugin_name);


template<typename T>
T* get_plugin_t(const char* plugin_name) {
    return dynamic_cast<T*>(get_plugin(plugin_name));
}
