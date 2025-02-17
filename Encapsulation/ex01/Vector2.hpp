#pragma once
#include <iostream>
#include <utility>

class   Vector2
{
    private:
        float x, y;
    public:
        Vector2(float x, float y);
        const float& getX(void);
        const float& getY(void);
        ~Vector2();
};