#include "Shovel.hpp"

Shovel::Shovel()
{
}
Shovel::~Shovel()
{

}
void Shovel::use(){ numberOfUses++; std::cout << "This Shovel Used " << numberOfUses << " time."<< std::endl;;}