#pragma once
#include <iostream>

class Steering
{
    public:
        Steering();
        ~Steering();
        void turn_wheel(float angle);
        void straighten_wheels();
};