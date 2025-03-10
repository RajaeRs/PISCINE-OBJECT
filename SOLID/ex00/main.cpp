#include "Car.hpp"

int main()
{
    Car c = Car();
    float speed = 10.2;
    float angle = 20.3;
    float force = 1.2;


    c.start();
    c.accelerate(speed);
    c.shift_gears_up();
    c.shift_gears_down();
    c.reverse();
    c.turn_wheel(angle);
    c.straighten_wheels();
    c.apply_force_on_brakes(force);
    c.apply_emergency_brakes();
    c.stop();
}