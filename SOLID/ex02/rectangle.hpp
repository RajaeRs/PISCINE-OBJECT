#pragma once
#include <iostream>
#include "shape.hpp"

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double length, double width) : length(length), width(width) {}
    ~Rectangle() {}
    double calculat_area()
    {
        double area;
        area = length * width;
        return area;
    }
    double calculat_perimeter()
    {
        double perimeter;
        perimeter = (length + width) * 2;
        return perimeter;
    }
};