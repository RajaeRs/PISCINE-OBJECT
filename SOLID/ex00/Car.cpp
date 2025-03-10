#include "Car.hpp"

Car::Car() : speed(0), b(BrakeController()), g(Transmission()), s(Steering()), e(Engine()){}
Car::~Car(){}
void    Car::accelerate(float speed)
{
    if (e.status())
        this->speed += speed;
    else
        std::cout << "the Enging not started yet!" << std::endl;
}
void    Car::start()
{
    e.start();
}
void    Car::stop()
{
    e.stop();
}

void    Car::shift_gears_up()
{
    g.shift_gears_up();
}
void    Car::shift_gears_down()
{
    g.shift_gears_down();
}
void    Car::reverse()
{
    g.reverse();
}
void    Car::turn_wheel(float angle)
{
    s.turn_wheel(angle);
}
void    Car::straighten_wheels()
{
    s.straighten_wheels();
}
void    Car::apply_force_on_brakes(float force)
{
    b.apply_force_on_brakes(force);
}
void    Car::apply_emergency_brakes()
{
    b.apply_emergency_brakes();
}