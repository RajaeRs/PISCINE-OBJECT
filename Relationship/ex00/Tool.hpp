#pragma once
#include <iostream>
#include "Worker.hpp"

class Worker;

class   Tool
{
    protected:
		  int numberOfUses;
		  Worker *usedBy;
    public:
        Tool();
        void setWorker(Worker *w);
        void removeWorker();
        int getNumberOfUse();
        virtual void use() = 0;
        virtual ~Tool();
};