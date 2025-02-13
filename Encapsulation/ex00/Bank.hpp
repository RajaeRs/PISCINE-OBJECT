#pragma once
#include <iostream>
#include <map>

#include "Account.hpp"

class Account;

class Bank
{
    private:
        int lastId;
        static const double commission;
        static const int max_client = 200;
        double liquidity;
        std::map<int, Account* > customers;
    public:
        Bank();
        Bank(const double liquidity);
        const Account* openAccount(const double& amount);
        void displayAccount(const int& id) const; //should be remouved
        void closeAccount(const int& id);
        void makeDeposit(const int& id, const double& amount);
        void makeWithdrawal(const int& id, const double& amount);
        void requestLoan(const int& id, const double& amount);
        void showCostummers() const; 
        ~Bank();
};

