#include <plugin_creator.hpp>
#include <plugin2.hpp>
#include <iostream>

class plugin2_impl : public plugin2 {
public:
    ~plugin2_impl() {
        
    }
    
    const char* name() override {
        return "plugin2";
    }
    
    const char* version() override {
        return "1.0.1";
    }
    
    
    void say_hello() override {
        std::cout << "say hello from plugin2" << std::endl;
    }
};

PLUGIN_API plugin* create_plugin() {
    return new plugin2_impl;
}

PLUGIN_API void destroy_plugin(plugin* p) {
    delete p;
}
