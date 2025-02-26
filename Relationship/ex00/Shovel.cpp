#include "Shovel.hpp"

Shovel::Shovel()
{
    std::cout << "Shovel created" << std::endl;
}
Shovel::~Shovel()
{

}
void Shovel::use(){ numberOfUses++; }