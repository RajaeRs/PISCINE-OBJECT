#include "iLogger.hpp"
#include "streamLogger.hpp"
#include "fileLoger.hpp"
#include "dateHeaderProvider.hpp"
#include "defaultHeaderProvider.hpp"
#include <vector>

int main()
{
    try
    {
        std::ofstream t("file_1.txt");
        std::ofstream a("file_2.txt");
        std::ofstream s("file_3.txt");

        DateHeaderProvider *dateHeader = new DateHeaderProvider();
        DefaultHeaderProvider *defaultHeader = new DefaultHeaderProvider("LOG_INFO");
        std::vector<ILogger *> col_header;
        std::string logs[] = {"first log", "second log", "third log"};

        col_header.push_back(new FileLogger(defaultHeader));
        col_header.push_back(new FileLogger(dateHeader));
        col_header.push_back(new FileLogger());
        col_header.push_back(new StreamLogger(t, defaultHeader));
        col_header.push_back(new StreamLogger(a, dateHeader));
        col_header.push_back(new StreamLogger(s));

        for (int i = 0; i < 3; i++)
        {
            for (std::vector<ILogger *>::iterator it = col_header.begin(); it != col_header.end(); it++)
                (*it)->write(logs[i]);
        }
        std::string acction;
        while (1)
        {
            std::cin >> acction;
            if (acction == "exit")
                break;
        }
        for (std::vector<ILogger *>::iterator it = col_header.begin(); it != col_header.end(); it++)
            delete (*it);
    }
    catch (const std::runtime_error &message)
    {
        std::cerr << message.what() << std::endl;
    }
}