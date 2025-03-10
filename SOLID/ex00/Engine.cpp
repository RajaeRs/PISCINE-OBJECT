#include "Engine.hpp"

Engine::Engine() : running(false) {}
Engine::~Engine(){}

void    Engine::start()
{
    if (!running)
    {
        running = true;
        std::cout << "Engine started !" << std::endl;
    }
}
void    Engine::stop()
{
    if (running)
    {
        running = false;
        std::cout << "Engine stoped !" << std::endl;
    }
}
bool Engine::status() {return running;}