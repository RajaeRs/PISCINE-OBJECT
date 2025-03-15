#pragma once
#include <iostream>
#include <fstream>
#include <string>

class ILogger
{
    public:
        virtual void write(const std::string& message)  = 0;
        virtual ~ILogger() = 0;
};

inline ILogger::~ILogger() {}