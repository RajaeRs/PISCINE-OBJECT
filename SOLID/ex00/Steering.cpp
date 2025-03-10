#include "Steering.hpp"

Steering::Steering() {}
Steering::~Steering() {}
void Steering::turn_wheel(float angle){std::cout << "Wheel turned to " << angle << "°" << std::endl;}
void Steering::straighten_wheels(){std::cout << "Wheels straightened ." << std::endl;}