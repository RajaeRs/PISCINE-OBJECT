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
};