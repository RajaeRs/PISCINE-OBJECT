#pragma once
#include <iostream>
#include "Worker.hpp"
#include "Tool.hpp"

class Hammer : public Tool
{
    public :
        Hammer();
		~Hammer();
		void use();
		// void assigneTo(Worker *work){
		// 	if (this->usedBy != NULL)
		// 		this->usedBy->removeHammer();
		// 	this->usedBy = work;
		// }
};