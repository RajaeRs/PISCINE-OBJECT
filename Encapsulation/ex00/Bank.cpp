#include "Bank.hpp"
#include <iomanip>

const double Bank::commission = 0.05;

Bank::Bank(){this->liquidity = 0; this->lastId = 0; }
Bank::Bank(const double liquidity){this->liquidity = liquidity; this->lastId = 0; }
Bank::~Bank()
{
    std::map<int, Account*>::iterator it;
    for (it = this->customers.begin(); it != this->customers.end(); it++)
        delete it->second;
}

const Account* Bank::openAccount(const double& amount)
{
    Account* newAccount;
    double revenue;

    if (amount <= 0)
        throw "Operation Failed : \n    [!] You can't create an account with negative amount";

    revenue = amount * this->commission;
    newAccount = new Account(++this->lastId, (amount - revenue));
    
    this->customers[this->lastId] = newAccount;
    this->liquidity += revenue;

    return newAccount;
};

void Bank::displayAccount(const int& id) const
{
    if (this->customers.find(id) == this->customers.end())
        throw "Operation Failed : \n    [!] no costomer with this ID.";
    std::cout << "Operation Success :" << std::endl;
    std::cout << "  ID :" << id << std::endl;
    std::cout << "  Amount :" << this->customers.find(id)->second->amount << std::endl;
    return;
}

void Bank::closeAccount(const int& id)
{
    if (this->customers.find(id) == this->customers.end())
        throw "Operation Failed : \n    [!] no costomer with this ID.";
    delete this->customers.find(id)->second;
    this->customers.erase(id);
    std::cout << "Operation Success : \n    Account closed succesfuly." << std::endl;
    return;
}

void Bank::makeDeposit(const int& id, const double& amount)
{
    double revenue;

    if (this->customers.find(id) == this->customers.end())
        throw "Operation Failed : \n    [!] no costomer with this ID.";
    if (amount <= 0)
        throw "Operation Failed : \n    [!] You can't make a negative Desposit.";
    revenue = amount * this->commission;
    this->customers.find(id)->second->amount += (amount - revenue);
    this->liquidity += revenue;
    return;
}

void Bank::makeWithdrawal(const int& id, const double& amount)
{
    double revenue;

    if (this->customers.find(id) == this->customers.end())
        throw "Operation Failed : \n    [!] no costomer with this ID.";
    if (amount <= 0)
        throw "Operation Failed : \n    [!] You can't make a negative Withdrawal.";
    revenue = amount * this->commission;
    this->customers.find(id)->second->amount -= amount + revenue;
    this->liquidity += revenue;
    return;
}

void Bank::requestLoan(const int& id, const double& amount)
{
    double revenue;

    if (this->customers.find(id) == this->customers.end())
        throw "Operation Failed : \n    [!] no costomer with this ID.";
    if (amount <= 0)
        throw "Operation Failed : \n    [!] You can't request a negative Loan.";
    if (this->liquidity < amount)
        throw "Operation Failed : \n    [!] We apologize for the inconvenience.\n    The bank doesn't have sufficient funds available at the moment. Please try again later.\n    Thank you for your understanding.";

    revenue = amount * this->commission;
    this->liquidity -= amount;
    this->customers.find(id)->second->amount -= amount + revenue;
    this->liquidity += revenue;
    return;
}

void Bank::showCostummers(void) const
{
    std::map<int, Account*>::const_iterator it;

    std::cout << std::left << std::setw(30) << "\nBank Status :"<< "Liqudity Amount: " << this->liquidity << std::endl;
    std::cout << "   Total of Client : " << this->customers.size()  <<'\n' << std::endl;

    std::cout << std::left << std::setw(7) << "ID" << "Amount" << std::endl;
    std::cout << "----------------------" << std::endl;

    for (it = this->customers.begin(); it != this->customers.end(); it++){
        std::cout << std::left << std::setw(5) << it->first << "| " << it->second->amount << std::endl;
    }
}