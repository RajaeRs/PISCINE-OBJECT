#pragma once
#include <iostream>
#include "employee.hpp"

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(int hourlyValue) : Employee(hourlyValue) {}
    void takeLeave(int hours) 
    { 
        std::cout << "Contract Employee take " << hours << "H, for a leave." << std::endl;
        total_hours -= hours; 
    }
};

class ContractEmployee : public SalariedEmployee
{
public:
    ContractEmployee(int hourlyValue) : SalariedEmployee(hourlyValue) {}
    int calculateSalary(void) const 
    { 
        int salary = total_hours * hourlyValue;
            std::cout << "Contract Employee salary is: " << salary << "$" << std::endl;
        return salary;
    }
};

class Apprentice : public SalariedEmployee
{
private:
    int school_hour;

public:
    Apprentice(int hourlyValue) : SalariedEmployee(hourlyValue), school_hour(0) {}
    void registerHourOfSchool(int hours) 
    { 
        std::cout << "Apprentice take " << hours << "H for school presence" << std::endl;
        school_hour += hours; 
    }
    int calculateSalary(void) const 
    {
         int salary = total_hours * hourlyValue + (school_hour * hourlyValue) / 2;
            std::cout << "Apprentice Employee salary is: " << salary << "$" << std::endl;
        return (salary); 
    }
};