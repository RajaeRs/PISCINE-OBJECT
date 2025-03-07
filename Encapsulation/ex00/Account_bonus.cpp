#include "Bank_bonus.hpp"

Bank::Account::Account (){this->id = -1; this->amount = 0;}
Bank::Account::Account (const int& id, const double& amount){this->id = id;this->amount = amount;}
Bank::Account::~Account(void){};

const int& Bank::Account::getId(void) const { return this->id; }

const double& Bank::Account::getAmount(void) const { return this->amount; }
