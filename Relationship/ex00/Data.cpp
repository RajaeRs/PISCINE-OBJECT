#include "Data.hpp"

Position::Position(){x = 0; y = 0; z = 0; }
Position::Position(int x, int y, int z){this->x = x; this->y = y; this->z = z;}
void Position::setPosition(int x, int y, int z){this->x = x; this->y = y; this->z = z;}
void Position::resetPosition(void){this->x = -1; this->y = -1; this->z = -1;}
const int& Position::getX(void) const {return this->x;}
const int& Position::getY(void) const {return this->y;}
const int& Position::getZ(void) const {return this->z;}
Position::~Position(){}

std::ostream&   operator<<(std::ostream& stream, const Position& value)
{
    stream << '(' << value.getX() << ", " << value.getY() << ", " << value.getZ() << ')';
    return stream;
}


Statistic::Statistic(){level = 0; exp = 0;}
Statistic::~Statistic(){}
void Statistic::addLevel(void) {this->level++;}
void Statistic::addExp(int exp) {this->exp += exp;}
const int& Statistic::getLevel(void) const {return this->level;}
const int& Statistic::getExp(void) const {return this->exp;}