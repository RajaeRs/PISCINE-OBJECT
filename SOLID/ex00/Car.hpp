#pragma once
#include <iostream>
#include "Steering.hpp"
#include "BrakeController.hpp"
#include "Transmission.hpp"
#include "Engine.hpp"

class   Car
{
    private:
        float speed;
        BrakeController b;
        Transmission g;
        Steering s;
        Engine e;
    public:
        Car();
        ~Car();
        void    accelerate(float speed);
        void    start();
        void    stop();
        void    shift_gears_up();
        void    shift_gears_down();
        void    reverse();
        void    turn_wheel(float angle);
        void    straighten_wheels();
        void    apply_force_on_brakes(float force);
        void    apply_emergency_brakes();
};