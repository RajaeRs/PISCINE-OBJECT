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
};