#pragma once
#include "Command.hpp"

class   PackageReductionDiscount : public Command
{
    public :
        PackageReductionDiscount(int id, std::string date, std::string client_name) : Command(id, date, client_name){}
        float get_discount(float total)
        {
            if (total > 150)
            {
                std::cout << "[!] You gain a discount of 10euros ^_^ " << std::endl;
                return 10;
            }
            return 0;
        }
        ~PackageReductionDiscount(){}
};