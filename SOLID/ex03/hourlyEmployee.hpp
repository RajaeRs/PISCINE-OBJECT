#pragma once
#include <iostream>
#include "employee.hpp"

class   TempWorker : public Employee
{
    public:
        TempWorker(int hourlyValue) : Employee(hourlyValue) {}
        void    executeWorkPerHour(int aditional_hours)
        {
            std::cout << "Temp Employee add " << aditional_hours << "H as aditional work." << std::endl;
            total_hours += aditional_hours;
        }
        int     calculateSalary(void)const 
        { 
            int salary = total_hours * hourlyValue;
            std::cout << "Temp Employee salary is: " << salary << "$" << std::endl;
            return salary; 
        }
};
