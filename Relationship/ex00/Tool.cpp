#include "Tool.hpp"

Tool::Tool(){numberOfUses = 0; usedBy = NULL;}

void Tool::setWorker(Worker *w){
  if (this->usedBy != NULL)
  {
    std::cout << "worker `"<< w->getName() << "` taking the tool from `" << usedBy->getName() << '`' << std::endl; 
	  this->usedBy->putTool(this);
  }
	this->usedBy = w;
  return ;
}

int Tool::getNumberOfUse()
{
  return this->numberOfUses;
}

void Tool::removeWorker() {
  this->usedBy->putTool(this); 
  this->usedBy = NULL;
  return ;
}

Tool::~Tool(){
    removeWorker();
    std::cout << "this Tool was destroyed." << std::endl;
}