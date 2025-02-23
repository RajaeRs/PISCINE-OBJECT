#pragma once 
#include <iostream>
#include <vector>
#include "Worker.hpp"


class Workshop
{
    private:
        std::vector<Worker *> *workerList;
        int ***workignSpace;
        Position size;
    public:
        Workshop(int x, int y, int z)
        {
            this->size.setPosition(x, y, z);
            this->workignSpace = new int**[z];
            for (int i = 0; i < z; i++)
            {
                this->workignSpace[i] = new int*[y];
                for (int j = 0; j < y; j++)
                {
                    this->workignSpace[i][j] = new int[x];
                    for (int k = 0; k < x; k++)
                        this->workignSpace[i][j][k] = 0;
                }
            }
        }
        ~Workshop()
        {
            for (int i = 0; i < size.getZ(); i++)
            {
                for (int j = 0; j < size.getY(); j++)
                {
                    delete[] this->workignSpace[i][j];
                    
                }
                delete[] this->workignSpace[i];
            }
            delete[] this->workignSpace;
        }
        void signUpWorkshop(Worker *w);
        void leaveWorkshop(Worker *w);
        void executeWorkDay();
};