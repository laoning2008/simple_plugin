#pragma once

class plugin {
public:
    virtual ~plugin() {}
    virtual const char* name() = 0;
    virtual const char* version() = 0;
};
