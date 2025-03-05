#include "Worker.hpp"
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
#include <cstdlib>
#include <ctime>
#include "Simulation.hpp"



int main()
{
    srand(time(0));
    try {

        Simulation sm = Simulation(5 , 50, 100);

        sm.start();

    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
    }
    return (0);
}