#pragma once
#include <iostream>
#include <map>

class   Command
{
    protected:
        int id;
        std::string date;
        std::string client;
        std::multimap<std::string, std::pair<int, float> > articles;
    public:
        Command(int id, std::string date, std::string client_name);
        virtual ~Command();
        void add_article(std::string name,int quentity, float price);
        virtual float get_discount(float total){(void)total ; return 0;};
        float   get_total_price();
        void   show_command();
};
