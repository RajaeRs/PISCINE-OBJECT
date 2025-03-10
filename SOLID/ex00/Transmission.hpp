#pragma once
#include <iostream>

class   Transmission
{
    private: 
        int gear;
        int max_gear;
    public :
        Transmission();
        ~Transmission();
        void    shift_gears_up();
        void    shift_gears_down();
        void    reverse();
}; 