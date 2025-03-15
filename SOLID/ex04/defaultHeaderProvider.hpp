#pragma once
#include <iostream>
#include "iHeaderProvider.hpp"

class DefaultHeaderProvider : public IHeaderProvider {
    private:
        std::string header;
    public:
        DefaultHeaderProvider(const std::string& h) : header(h) {}

        std::string getHeader()  {
            return header;
        }
};
