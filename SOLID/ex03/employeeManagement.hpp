#pragma once
#include <iostream>
#include <algorithm> 
#include <vector>
#include "employee.hpp"

class   EmployeeManager
{
    private:
        std::vector<Employee *> employees;
    public:
        EmployeeManager(){}
        ~EmployeeManager(){}
        void addEmployee(Employee* e) {employees.push_back(e);}
        void removeEmployee(Employee* e)
        {
            std::vector<Employee *>::iterator it;
            for (it = employees.begin(); it != employees.end(); it++)
            {
                if (*it == e)
                {
                    employees.erase(it);
                    return ;
                }
            }
        }
        void executeWorkday()
        {
            std::vector<Employee *>::iterator it;
            for (it = employees.begin(); it != employees.end(); it++)
                (*it)->executeWorkday();
        }
        void calculatePayroll()
        {
            int payrol = 0;
            for (std::vector<Employee *>::iterator it = employees.begin(); it != employees.end(); it++)
                payrol += (*it)->calculateSalary();
            std::cout << "Payrol : " << payrol << "$" << std::endl;
        }
};