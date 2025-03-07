#include "Graph.hpp"

int main()
{
    try{
        Graph surface(10, 10);

        surface.addPoint(0, 5.96);
        surface.addPoint(0, 1);
        surface.addPoint(8, 7);
        surface.addPoint(5, 6);
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