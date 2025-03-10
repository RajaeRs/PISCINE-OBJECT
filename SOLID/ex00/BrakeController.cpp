#include "BrakeController.hpp"

BrakeController::BrakeController(){}
BrakeController::~BrakeController(){}
void    BrakeController::apply_force_on_brakes(float force)
{
    std::cout << "Applying " << force << "% braking force." << std::endl;
}
void    BrakeController::apply_emergency_brakes(){std::cout << "Emergency brakes applied! Car stopped immediately." << std::endl;}