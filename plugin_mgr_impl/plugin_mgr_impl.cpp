#include "plugin_mgr_impl.hpp"
#include "dylib.hpp"
#include <filesystem>
#include <iostream>

constexpr static char* create_plugin_func_name = (char*)"create_plugin";
constexpr static char* destroy_plugin_func_name = (char*)"destroy_plugin";
typedef plugin*(*create_plugin_func_type)();
typedef void(*destroy_plugin_func_type)(plugin*);


bool plugin_mgr_impl::load_plugins(const char* plugins_dir) {
    const std::filesystem::path plugin_path{plugins_dir};
    if (!std::filesystem::is_directory(plugin_path)) {
        return false;
    }
    
    for (auto const& dir_entry : std::filesystem::directory_iterator{plugin_path}) {
        if (!dir_entry.is_regular_file()) {
            continue;
        }
        
        auto lib_handle = dylib::load_library({}, dir_entry.path());
        if (lib_handle == nullptr) {
            std::cout << "load library failed, path = " << dir_entry.path() << ", err = " << dylib::get_error_description() << std::endl;
            continue;
        }

        auto create_plugin_func = (create_plugin_func_type)dylib::get_symbol(lib_handle, create_plugin_func_name);
        if (create_plugin_func == nullptr) {
            std::cout << "get create function failed, path = " << dir_entry.path() << ", err = " << dylib::get_error_description() << std::endl;
            continue;
        }
        
        auto plugin = create_plugin_func();
        if (plugin == nullptr) {
            continue;
        }
        
        std::string name = plugin->name();
        m_plugins[name] = plugin;
    }
    
    return true;
}


plugin* plugin_mgr_impl::get_plugin(const char* plugin_name) {
    auto it = m_plugins.find(plugin_name);
    return (it != m_plugins.end()) ? it->second : nullptr;
}
