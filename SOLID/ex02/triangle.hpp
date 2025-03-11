#pragma once
#include <iostream>
#include "shape.hpp"

class Triangle : public Shape
{
private:
    double height;
    double base;
    double first_side;
    double second_side;

public:
    Triangle(double height, double base, double first_side, double second_side) : height(height), base(base), first_side(first_side), second_side(second_side) {}
    ~Triangle() {}
    double calculat_area()
    {
        double area;
        area = (height * base) / 2;
        return area;
    }
    double calculat_perimeter()
    {
        double perimeter;
        perimeter = base + first_side + second_side;
        return perimeter;
    }
};