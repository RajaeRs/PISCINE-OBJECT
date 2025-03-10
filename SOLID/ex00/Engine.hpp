#pragma once
#include <iostream>

class   Engine
{
    private:
        bool running;
    public:
        Engine();
        ~Engine();
        void    start();
        void    stop();
        bool status();
};