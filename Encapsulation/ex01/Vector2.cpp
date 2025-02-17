#include "Vector2.hpp"

Vector2::~Vector2(){};
Vector2::Vector2(float x, float y) : x(x), y(y){}
const float& Vector2::getX(void) {return x;}
const float& Vector2::getY(void) {return y;}
