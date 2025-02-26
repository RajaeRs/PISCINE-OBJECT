#include "Hammer.hpp"

Hammer::Hammer()
{
    std::cout << "Hammer created" << std::endl;

}
Hammer::~Hammer(){}
void Hammer::use(){ numberOfUses++; }