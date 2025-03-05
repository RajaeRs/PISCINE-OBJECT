#pragma once 
#include <iostream>
#include <vector>
#include "Worker.hpp"

class Worker;

class Workshop
{
    private:
        std::string requiredTool;
        std::vector<Worker *> workerList;
        int ***workignSpace;
        Position size;
    public:
        Workshop(int z, int y, int x, std::string tool);
        ~Workshop();
        int getAvailablePosition(Worker *w);
        std::string getRequiredTool(void) const;
        std::vector<Worker *>::iterator removeWorkerFromWorkshop(std::vector<Worker *>::iterator it, std::string message);
        void showWorkingSpace(void);
        void signUpWorkshop(Worker *w);
        std::vector<Worker *>::iterator leaveWorkshop(Worker *w, Position pos);
        void executeWorkDay();
};