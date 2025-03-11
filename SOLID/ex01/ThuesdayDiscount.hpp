#pragma once
#include "Command.hpp"

class   ThuesdayDiscountCommand : public Command
{
    public :
        ThuesdayDiscountCommand(int id, std::string date, std::string client_name) : Command(id, date, client_name){}
        float get_discount(float total)
        {
            if (date == "Thursday")
            {
                std::cout << "[!] You gain a discount of 10% ^_^ " << std::endl;
                return total * 0.1;
            }
            return 0.0;
        }
        ~ThuesdayDiscountCommand(){}
};