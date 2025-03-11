#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include <vector>

int main()
{
    std::vector<Shape *> shapes;
    shapes.push_back(new Rectangle(2, 5));
    shapes.push_back(new Triangle(6.0, 4.0, 3.0, 5.0));
    shapes.push_back(new Circle(5));

    for (std::vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        std::cout << " ----------------------- " << std::endl;
        std::cout << "  " << (*it)->calculat_perimeter() << "m." << std::endl;
        std::cout << "  " << (*it)->calculat_area() << "m²." << std::endl;
    }
    for (std::vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); it++)
        delete (*it);

    return 0;
}