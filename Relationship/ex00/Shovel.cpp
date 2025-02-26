#include "Shovel.hpp"

Shovel::Shovel() : Tool(){}
Shovel::~Shovel()
{

}
void Shovel::use(){ numberOfUses++; }