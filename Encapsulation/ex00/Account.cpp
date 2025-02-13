#include "Account.hpp"

Account::Account (){this->id = -1; this->amount = 0;}
Account::Account (const int& id, const double& amount){this->id = id;this->amount = amount;}
Account::~Account(void){};

const int& Account::getId(void) const { return this->id; }

const double& Account::getAmount(void) const { return this->amount; }
