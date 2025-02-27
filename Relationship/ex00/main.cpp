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

        Simulation sm = Simulation(1 , 20, 30);

        sm.start();

    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
        return (1);
    }
    return (0);
}