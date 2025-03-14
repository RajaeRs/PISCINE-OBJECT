#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main() {
    EmployeeManager manager;
    
    TempWorker *t = new TempWorker(25);
    ContractEmployee *c = new ContractEmployee(20);
    Apprentice *a = new Apprentice(15);

    
    manager.addEmployee(t);
    manager.addEmployee(c);
    manager.addEmployee(a);
    
    for (int i = 0; i <= 30; i++)
    {
        manager.executeWorkday();
        if (i % 6 == 0)
            t->executeWorkPerHour(i / 4 + 1);
        if (i % 15 == 0)
            c->takeLeave(6);
        if (i % 5 == 0)
            a->registerHourOfSchool(i / 4 + 1);
        if (i % 18 == 0)
            a->takeLeave(7);
    }
    
    manager.calculatePayroll();
    
    return 0;
}
