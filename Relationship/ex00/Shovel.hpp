#pragma once
#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"

class   Shovel : public Tool
{
	public:
		Shovel() : Tool(){}
		~Shovel(){}
		void use(){ numberOfUses++; }
		// void assigneTo(Worker *work){
		// 	if (this->usedBy != NULL)
		// 		this->usedBy->removeShovel();
		// 	this->usedBy = work;
		// }

};