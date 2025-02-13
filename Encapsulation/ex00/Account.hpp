#pragma once
#include <iostream>
#include "Bank.hpp"

class Bank;

class Account
{
    private:
        int id;
        double amount;
        Account();
        Account(const int& id, const double& amount);
        friend class Bank;

    public:
        const int &getId(void) const;
        const double &getAmount(void) const;
        ~Account();
};