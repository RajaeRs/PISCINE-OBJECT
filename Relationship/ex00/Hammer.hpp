#pragma once
#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"

class Hammer : public Tool
{
    public :
        Hammer() : Tool(){}
		~Hammer(){}
		void use(){ numberOfUses++; }
		// void assigneTo(Worker *work){
		// 	if (this->usedBy != NULL)
		// 		this->usedBy->removeHammer();
		// 	this->usedBy = work;
		// }
};