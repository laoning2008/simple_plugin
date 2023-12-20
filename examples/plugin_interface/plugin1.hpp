#pragma once
#include <plugin.hpp>

class plugin1 : public plugin {
public:
    virtual void say_hello() = 0;
};
