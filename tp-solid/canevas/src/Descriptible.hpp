#pragma once 
#include <map>
#include <string>
using Description = std::map<std::string, std::string>;

class Descriptible{
    virtual Description toDescription() const = 0;
};

