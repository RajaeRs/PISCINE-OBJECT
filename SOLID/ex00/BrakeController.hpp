#pragma once
#include <iostream>

class   BrakeController
{
    public :
        BrakeController();
        ~BrakeController();
        void    apply_force_on_brakes(float force);
        void    apply_emergency_brakes();
};