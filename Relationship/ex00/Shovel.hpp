#pragma once
#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"

class   Shovel : public Tool
{
	public:
		Shovel();
		~Shovel();
		void use();
		// void assigneTo(Worker *work){
		// 	if (this->usedBy != NULL)
		// 		this->usedBy->removeShovel();
		// 	this->usedBy = work;
		// }

};