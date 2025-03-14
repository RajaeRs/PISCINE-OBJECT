#pragma once
#include <iostream>

class   Employee
{
    protected:
        int hourlyValue;
        int total_hours;
    public:
        Employee(){}
        Employee(int hourlyValue) : hourlyValue(hourlyValue), total_hours(0){}
        void executeWorkday() { total_hours += 7; };
        virtual int calculateSalary(void) const = 0;
        virtual ~Employee(){};
};



