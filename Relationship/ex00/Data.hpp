#pragma once
#include <iostream>

class   Position
{
    private:
        int x;
        int y;
        int z;
    public:
        Position(){x = 0; y = 0; z = 0; }
        void setPosition(int x, int y, int z){this->x = x; this->y = y; this->z = z;}
        void resetPosition(void){this->x = -1; this->y = -1; this->z = -1;}
        const int& getX(void) const {return this->x;}
        const int& getY(void) const {return this->y;}
        const int& getZ(void) const {return this->z;}
        ~Position(){}
};

std::ostream&   operator<<(std::ostream& stream, const Position& value)
{
    stream << '(' << value.getX() << ", " << value.getY() << ", " << value.getZ() << ')';
    return stream;
}

class Statistic
{
    private: 
        int level;
        int exp;
    public:
        Statistic(){level = 0; exp = 0;}
        ~Statistic(){}
        void addLevel(void) {this->level++;}
        void addExp(int exp) {this->exp += exp;}
        const int& getLevel(void) const {return this->level;}
        const int& getExp(void) const {return this->exp;}
};