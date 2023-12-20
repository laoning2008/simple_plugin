#include <plugin_creator.hpp>
#include <plugin1.hpp>
#include <iostream>

class plugin1_impl : public plugin1 {
public:
    ~plugin1_impl() {
        
    }
    
    const char* name() override {
        return "plugin1";
    }
    
    const char* version() override {
        return "1.0.0";
    }
    
    void say_hello() override {
        std::cout << "say hello from plugin1" << std::endl;
    }
};

PLUGIN_API plugin* create_plugin() {
    auto p = new plugin1_impl;
    return p;
}

PLUGIN_API void destroy_plugin(plugin* p) {
    delete p;
}
