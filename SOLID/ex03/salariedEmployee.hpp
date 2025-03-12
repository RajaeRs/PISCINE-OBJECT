#pragma once
#include <iostream>
#include "employee.hpp"

class   SalariedEmployee : public Employee
{
    public:
        void executeWorkday(){ total_hours += 7; }
        void removeHoursFromWork(int hours){ total_hours -= hours;}
};

class ContractEmployee : public SalariedEmployee
{
    public:
        int calculateSalary(void) { return(total_hours * hourlyValue); }
};

class   Apprentice : public SalariedEmployee
{
    private:
        int school_hour;
    public:
        Apprentice() : school_hour(0) {}
        void registerHourOfSchool(int hours){school_hour += hours;}
        int calculateSalary(void) { return (total_hours * hourlyValue + (school_hour * hourlyValue)/2 ); }
};