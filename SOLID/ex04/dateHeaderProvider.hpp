#pragma once
#include <iostream>
#include "iHeaderProvider.hpp"
#include "generateLogHeader.hpp"

class DateHeaderProvider : public IHeaderProvider {
    private:
        std::string header;
    public:
        DateHeaderProvider(){}
        std::string getHeader()  
        {
            header = generateLogHeader::generateHeader();
            return header;
        }
};