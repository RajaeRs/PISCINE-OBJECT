#include "Worker.hpp"

Worker::Worker(std::string name)
{
	this->name = name; coordonnee.setPosition(-1, -1, -1);
	std::cout << "Worker " << this->name << " is created." << std::endl;	
}
Worker::~Worker(){}
const std::string & Worker::getName(void) const { return name ;}
void Worker::setPosition(int x, int y, int z){this->coordonnee.setPosition(x, y, z);}
void Worker::resetPosition(void){this->coordonnee.resetPosition();}
void Worker::addExp()
{
	this->stat.addExp(20);
	if(this->stat.getExp() % 100 == 0)
		this->stat.addLevel();
}
 void Worker::takeTool(Tool *t)
 {
     this->tools.push_back(t);
     t->setWorker(this);
	 std::cout << name << ": has a tool now" << std::endl;
 }
void Worker::putTool(const Tool *t)
{
	std::vector<Tool *>::iterator it;
	for (it = this->tools.begin(); it != this->tools.end(); it++)
	{
		if (*it == t)
		{
			this->tools.erase(it);
			std::cout << name << " : put tool down." << std::endl;
			return ;
		}
	}
	if (it == this->tools.end())
		std::cout << name << " : i don't have this tool" << std::endl;
	// if (tools.size() == 0)
	// {
	// 	std::vector<Workshop *>::iterator it;
	// 	for(it = workshops.begin(); it != workshops.end(); it++)
	// 		(*it)->leaveWorkshop(this);
	// }
	return ;
}
bool	Worker::hasATool(void){
	if (this->tools.size() != 0)
		return true;
	return false;
}
void	Worker::work()
{
	if (this->hasATool())
		std::cout << name << " in position " << coordonnee << " start working." << std::endl;
	else 
		std::cout << name << " : i can't work, I don't have any tool" << std::endl;
}

Position Worker::getPosition(void) const
{
	Position pos(coordonnee.getX(),coordonnee.getY(),coordonnee.getZ());
	return pos;
}