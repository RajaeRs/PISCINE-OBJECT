#pragma once
#include <iostream>

class   Employee
{
    protected:
        std::string name;
        int hourlyValue;
        int total_hours;
    public:
        Employee(){}
        Employee(std::string name, int hourlyValue) : name(name), hourlyValue(hourlyValue), total_hours(0){}
        const std::string& getName() const {return name;}
        virtual void executeWorkday() = 0;
        virtual int calculateSalary(void) const = 0;
        virtual ~Employee() = default;
};



