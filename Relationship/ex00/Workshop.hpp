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
        int getAvailablePosition(Worker *w)
        {
            int z,y,x;
            for (z = 0; z < size.getZ(); z++)
            {
                for (y = 0; y < size.getY(); y++)
                {
                    for (x = 0; x < size.getX(); x++)
                    {
                        if (workignSpace[z][y][x] == 0)
                        {
                            workignSpace[z][y][x] = 1;
                            w->setPosition(x, y, z);
                            return 0;
                        }
                    }
                }
            }
            std::cout << "there is no available position on workshop." << std::endl;
            return 1;
        }
        void signUpWorkshop(Worker *w)
        {
            std::vector<Worker *>::iterator it;
            
            
            for (it = workerList->begin(); it != workerList->end() && *it != w; it++){}
            if (it != workerList->end())
            {
                std::cout << "Worker " <<  w->getName() << " alredy on this workshop." << std::endl;
                return;
            }
            if (getAvailablePosition(w));
                return ;
            this->workerList->push_back(w);
            std::cout << w->getName() << " : added to workshop." << std::endl;
        }
        void leaveWorkshop(Worker *w)
        {
            std::vector<Worker *>::iterator it;
            for (it = workerList->begin(); it != workerList->end() && *it != w; it++){}
            if (it != workerList->end())
            {
                workerList->erase(it);
                w->resetPosition();
                std::cout << "Worker " <<  w->getName() << " leave succsesfuly from the workshop." << std::endl;
                return;
            }
            std::cout << w->getName() << " : theresen't on the workshop." << std::endl;
        }
        void executeWorkDay()
        {
            std::vector<Worker *>::iterator it;
            if (workerList->size() == 0)
            {
                std::cout << "there is no worker in this workshop.";
                return ;
            }
            for (it = workerList->begin(); it != workerList->end(); it++)
            {
                if ((*it)->hasATool())
                    (*it)->work();
                else
                    leaveWorkshop(*it);
            }
        }
};