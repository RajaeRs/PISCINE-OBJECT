#pragma once
#include <iostream>
#include <map>

class Bank
{
    public:
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
        Bank();
        Bank(const double liquidity);
        const int& openAccount(const double& amount);
        void displayAccount(const int& id) const;
        void closeAccount(const int& id);
        void makeDeposit(const int& id, const double& amount);
        void makeWithdrawal(const int& id, const double& amount);
        void requestLoan(const int& id, const double& amount);
        void showCostummers() const; 
        const Account* operator[](int id);
        ~Bank();
    private:
        int lastId;
        static const double commission;
        static const int max_client = 200;
        double liquidity;
        std::map<int, Account* > customers;
};


