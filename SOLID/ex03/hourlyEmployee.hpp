#pragma once
#include <iostream>
#include "employee.hpp"

class   TempWorker : public Employee
{
    public:
        void executeWorkday() { total_hours += 7;}
        void    executeWorkPerHour(int aditional_hours){total_hours += aditional_hours;}
};
