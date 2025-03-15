#pragma once
#include "iLogger.hpp"
#include "iHeaderProvider.hpp"

class   StreamLogger : public ILogger
{
    private:
        std::ostream& file;
        IHeaderProvider *headerProvider;
    public :
        StreamLogger(std::ostream& file_name, IHeaderProvider* headerProvider = 0) : file(file_name), headerProvider(headerProvider) {}
        void write(const std::string& log_message)
        {
            if (headerProvider)
            {
                std::string header = headerProvider->getHeader();
                if (!header.empty())
                    file << header << " ";
            }
            file << log_message << std::endl;
        }
        ~StreamLogger(){}
};