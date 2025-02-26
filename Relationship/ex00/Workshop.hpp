#pragma once 
#include <iostream>
#include <vector>
#include "Worker.hpp"

class Worker;

class Workshop
{
    private:
        std::vector<Worker *> workerList;
        int ***workignSpace;
        Position size;
    public:
        Workshop(int z, int y, int x);
        ~Workshop();
        int getAvailablePosition(Worker *w);
        std::vector<Worker *>::iterator removeWorkerFromWorkshop(std::vector<Worker *>::iterator it);
        void showWorkingSpace(void);
        void signUpWorkshop(Worker *w);
        void leaveWorkshop(Worker *w);
        void executeWorkDay();
};