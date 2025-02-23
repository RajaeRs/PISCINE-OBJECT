#pragma once
#include <iostream>
#include <Worker.hpp>

class   Tool
{
    protected:
		  int numberOfUses;
		  Worker *usedBy;
    public:
        Tool(){numberOfUses = 0; usedBy = NULL;}
        void setWorker(Worker *w){
          if (this->usedBy != NULL)
			      this->usedBy->putTool(this);
			    this->usedBy = w;
          return ;
        }
        void removeWorker() {
          this->usedBy->putTool(this); 
          this->usedBy = NULL;
          return ;
        }
        // void assigneTo(Worker *work){
			  //   if (this->usedBy != NULL)
			  //   	this->usedBy->removeTool();
			  //   this->usedBy = work;
		    // }
        virtual void use() = 0;
        virtual ~Tool(){}
};