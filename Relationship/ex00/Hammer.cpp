#include "Hammer.hpp"

Hammer::Hammer() : Tool(){}
Hammer::~Hammer(){}
void Hammer::use(){ numberOfUses++; }