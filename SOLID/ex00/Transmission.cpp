#include "Transmission.hpp"

Transmission::Transmission() : gear(0), max_gear(5){}
Transmission::~Transmission(){}
void    Transmission::shift_gears_up()
{
    if (gear < max_gear)
        gear++;
    std::cout << "Shifted up to gear " << gear << std::endl;
}
void    Transmission::shift_gears_down()
{
    if (gear > 0)
        gear--;
    std::cout << "Shifted down to gear " << gear << std::endl;
}
void    Transmission::reverse()
{
    gear = -1;
    std::cout << "the car is in reverse." << std::endl;
}