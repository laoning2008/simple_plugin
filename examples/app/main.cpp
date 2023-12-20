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
