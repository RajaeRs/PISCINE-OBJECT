#include "Hammer.hpp"

Hammer::Hammer()
{
}
Hammer::~Hammer(){}
void Hammer::use(){ numberOfUses++; ; std::cout << "this Hammer Used " << numberOfUses << " time." << std::endl;}