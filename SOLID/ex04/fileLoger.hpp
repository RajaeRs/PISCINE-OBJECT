#pragma once
#include <fstream>
#include <iostream>
#include <memory>
#include "iLogger.hpp"
#include "generateLogHeader.hpp"
#include "iHeaderProvider.hpp"
#include <ctime>
#include <sstream>

class   FileLogger : public ILogger
{
    private:
        std::string file_name;
        IHeaderProvider *headerProvider;
        std::ofstream file;
    public :
        FileLogger(IHeaderProvider *headerProvider = 0)
            : headerProvider(headerProvider) {
            int number = rand();
            std::stringstream ss;
            ss << number;
            std::string str = ss.str(); 
            file_name = generateLogHeader::generateHeader() + "_" + str + ".txt";
            file.open(file_name, std::ios::app);
            if (!file.is_open()) {
                throw std::runtime_error("Failed to open file: " + file_name);
            }
            std::cout << "Log file with the name " << file_name << " created succsesfuly" << std::endl;
        }
        void    write(const std::string& log_message) 
        {
            if (headerProvider)
            {
                std::string header = headerProvider->getHeader();
                if (!header.empty())
                    file << header << " ";
            }
            file << log_message << std::endl;
        }
        ~FileLogger()
        {
            if (std::remove(file_name.c_str()) == 0) {
                std::cout << "Log file deleted successfully.\n";
            } else {
                throw "Closing: Error deleting file!\n";
            }
        }
};