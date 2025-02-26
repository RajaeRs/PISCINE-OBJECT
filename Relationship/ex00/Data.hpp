#pragma once
#include <iostream>

class   Position
{
    private:
        int x;
        int y;
        int z;
    public:
        Position();
        Position(int x, int y, int z);
        void setPosition(int x, int y, int z);
        void resetPosition(void);
        const int& getX(void) const ;
        const int& getY(void) const ;
        const int& getZ(void) const ;
        ~Position();
};

std::ostream&   operator<<(std::ostream& stream, const Position& value);


class Statistic
{
    private: 
        int level;
        int exp;
    public:
        Statistic();
        ~Statistic();
        void addLevel(void);
        void addExp(int exp);
        const int& getLevel(void) const;
        const int& getExp(void) const;
};