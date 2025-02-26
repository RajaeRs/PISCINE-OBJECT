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
        // void assigneTo(Worker *work){
			  //   if (this->usedBy != NULL)
			  //   	this->usedBy->removeTool();
			  //   this->usedBy = work;
		    // }
        virtual void use() = 0;
        virtual ~Tool();
};