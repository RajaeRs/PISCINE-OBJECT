#pragma once
#include <iostream>

class IHeaderProvider {
public:
    virtual std::string getHeader() = 0;
    virtual ~IHeaderProvider() {}
};