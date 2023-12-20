#include "plugin_mgr.hpp"
#include "plugin_mgr_impl.hpp"

plugin_mgr_impl g_impl;

PLUGIN_API bool load_plugins(const char* plugins_dir) {
    return g_impl.load_plugins(plugins_dir);
}

PLUGIN_API plugin* get_plugin(const char* plugin_name) {
    return g_impl.get_plugin(plugin_name);
}

