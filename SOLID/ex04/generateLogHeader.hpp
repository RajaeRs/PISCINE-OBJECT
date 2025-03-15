#pragma once
#include <iostream>
#include <ctime>
#include <sstream>

class generateLogHeader
{
    public:
        generateLogHeader(){};
        static std::string generateHeader(void)
        {
            std::time_t now = std::time(0);
            std::tm* localTime = std::localtime(&now);
            std::ostringstream timeStream;
            timeStream << (localTime->tm_year + 1900)
               << (localTime->tm_mon + 1)
               << localTime->tm_mday << "_"
               << localTime->tm_hour
               << localTime->tm_min
               << localTime->tm_sec ;
            return timeStream.str();
        }
        ~generateLogHeader(){};
};
