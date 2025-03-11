#pragma once
#include <iostream>
#include "shape.hpp"
#include <cmath>

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double radius) : radius(radius) {}
    ~Circle() {}
    double calculat_area()
    {
        double area;
        area = pow(radius, 2) * M_PI;
        return area;
    }
    double calculat_perimeter()
    {
        double perimeter;
        perimeter = radius * 2 * M_PI;
        return perimeter;
    }
};