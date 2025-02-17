#include "Graph.hpp"

#include <algorithm> // for std::min

Graph::Graph(float width, float height) 
    : size(std::min(width, 10.0f), std::min(height, 10.0f)) {}

void Graph::addPoint(float x, float y)
{
    int uniqe_key;

    uniqe_key = x + y;
    if (x >= 0 && y >= 0 && x < this->size.getX() && y < this->size.getY())
    {
        uniqe_key = generatKey(x, y);
        this->vectorMap.insert(std::pair<int, Vector2>(uniqe_key, Vector2(x,y)));
    }
    else
    {
        throw "Failed Operation: \n\tPlease Add A point in the range : " 
        "[" + std::to_string(this->size.getX()) + " - " + std::to_string(this->size.getY()) + "] " + '\n';
    }
    return ;
}

int Graph::generatKey(int x, int y)
{
    int result ;

    result = 0.5 * (x + y) * (x + y + 1) + y;
    return result;
}

void Graph::printGraph(void)
{
    int key;

    for (float y = size.getY() - 1; y >= 0; --y)
    {
        std::cout << "& " << y << ' ';
        for (float x = 0; x < size.getX(); ++x)
        {
            key = generatKey(x , y);
            if (this->vectorMap.find(key) != this->vectorMap.end())
                std::cout << "X " ;
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
    std::cout << "&  ";
    for (int i = 0 ; i < this->size.getX(); i++)
        std::cout << i << ' ';
}


Graph::~Graph(){}