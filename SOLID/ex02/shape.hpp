#pragma once
#include <iostream>

class Shape
{
public:
    Shape() {};
    virtual double calculat_area() = 0;
    virtual double calculat_perimeter() = 0;
    virtual ~Shape() {};
};