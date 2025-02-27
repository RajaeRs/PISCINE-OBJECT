#include "Worker.hpp"

Worker::Worker(std::string name)
{
	this->name = name; coordonnee.setPosition(-1, -1, -1);
	std::cout << "Worker " << this->name << " is created." << std::endl;	
}
Worker::~Worker()
{
	std::vector<Workshop *>::iterator it;
	for (it = workshops.begin(); it != workshops.end(); it++)
		(*it)->leaveWorkshop(this);
}
const std::string & Worker::getName(void) const { return name ;}
void Worker::setPosition(int x, int y, int z){this->coordonnee.setPosition(x, y, z);}
void Worker::resetPosition(void){this->coordonnee.resetPosition();}
void Worker::addExp()
{
	this->stat.addExp(50);
	if(this->stat.getExp() % 100 == 0)
		this->stat.addLevel();
}
 void Worker::takeTool(Tool *t)
 {
	if (t)
	{
     	this->tools.push_back(t);
     	t->setWorker(this);
	 	std::cout << name << ": has a tool now" << std::endl;
	}
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
	{
		std::cout << name << " in position " << coordonnee << " start working." << std::endl;
		this->addExp();
	}
	else 
		std::cout << name << " : i can't work, I don't have any tool" << std::endl;
}

Position Worker::getPosition(void) const
{
	Position pos(coordonnee.getX(),coordonnee.getY(),coordonnee.getZ());
	return pos;
}

Statistic Worker::getStatic(void) const
{
	Statistic st(stat.getLevel(), stat.getExp());
	return st;
}

std::ostream&   operator<<(std::ostream& stream, const Worker& value)
{
	stream << value.getName() << " in position : " << value.getPosition()
	<< " And has " << value.getStatic();
	return stream;
}