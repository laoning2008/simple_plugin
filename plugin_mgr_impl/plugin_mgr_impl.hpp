#pragma once
#include <plugin_mgr.hpp>
#include <unordered_map>
#include <string>

class plugin_mgr_impl final {
public:
    bool load_plugins(const char* plugins_dir);
    plugin* get_plugin(const char* plugin_name);
private:
    std::unordered_map<std::string, plugin*> m_plugins;
};
