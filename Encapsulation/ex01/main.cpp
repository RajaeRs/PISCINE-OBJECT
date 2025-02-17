#include "Graph.hpp"

int main()
{
    try{
        Graph surface(50000000, 500000);

        surface.addPoint(0, 3);
        surface.addPoint(1, 2);
        surface.addPoint(0, 1);
        surface.addPoint(0, 70);
        surface.addPoint(4, 3);
        surface.addPoint(2, 3);

        surface.printGraph();
    }
    catch (std::string error)
    {
        std::cerr << error ;
    }
    return(0);
}