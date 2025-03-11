#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"

void print(std::string shape_name, Shape *s)
{
    std::cout << shape_name << " :" << std::endl;
    std::cout << "  " << s->calculat_perimeter() << "m." << std::endl;
    std::cout << "  " << s->calculat_area() << "m²." << std::endl;
    delete s;
}

int main()
{
    print (std::string("Rectangle"), new Rectangle(2, 5));
    print (std::string("Triangle"),new Triangle(6.0, 4.0, 3.0, 5.0));
    print (std::string("Circle"),new Circle(5));
    return 0;
}