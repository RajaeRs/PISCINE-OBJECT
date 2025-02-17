#pragma once
#include "Vector2.hpp"
#include <map>

class   Graph
{
    private:
        Vector2 size;
        std::map<int ,Vector2> vectorMap;
    public:
        Graph(float width, float height);
        void	addPoint(float x, float y);
        int		generatKey(int x, int y);
        void	printGraph(void);
        ~Graph();
};