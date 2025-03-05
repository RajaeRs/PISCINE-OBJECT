#include "Worker.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

Worker::Worker(std::string name)
{
	this->name = name;
}
Worker::~Worker()
{
	std::vector<positionOnWorkshop>::iterator it;
	std::vector<Tool *>::iterator tool_it;

	for (it = pos.begin(); it != pos.end(); it++)
	{
		(*it).ws->leaveWorkshop(this, (*it).coordonnee);
		std::cout << "`" << name << "` removed from position : " << (*it).coordonnee << std::endl;
	}
	for (tool_it = tools.begin(); tool_it != tools.end();)
	{
		(*tool_it)->removeWorker();
		if (tool_it != tools.end())
			tool_it++;
	}
}

const std::string & Worker::getName(void) const { return name ;}


Position Worker::getPosition(Workshop *ws)
{
	Position poss(-1, -1, -1);
	std::vector<positionOnWorkshop>::iterator it;
	for (it = this->pos.begin(); it != this->pos.end(); it++)
	{
		if ((*it).ws == ws)
		{
			poss.setPosition((*it).coordonnee.getX(), (*it).coordonnee.getY(), (*it).coordonnee.getZ());
			return (poss);
		}
	}
	return poss;
}


void Worker::addWorkshop(Workshop *ws, Position pos)
{
	positionOnWorkshop newWorkshop;
	newWorkshop.ws = ws;
	newWorkshop.coordonnee = pos;
	this->pos.push_back(newWorkshop);
}

void Worker::removeWorkshop(Workshop *ws)
{
	std::vector<positionOnWorkshop>::iterator it;
	for (it = pos.begin(); it != pos.end(); it++)
	{
		if ((*it).ws == ws)
		{
			pos.erase(it);
			return ;
		}
	}
}


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
bool	Worker::hasATool(Workshop *ws){
	bool hasRequiredTool = 
        (this->getTool<Hammer>() && ws->getRequiredTool() == "Hammer") || 
        (this->getTool<Shovel>() && ws->getRequiredTool() == "Shovel");
	if (this->tools.size() != 0 && hasRequiredTool)
		return true;
	return false;
}
void	Worker::work(Workshop *ws)
{
	if (this->hasATool(ws))
	{
		std::cout << name << " in position " << this->getPosition(ws) << " start working." << std::endl;
		this->addExp();
		Tool *t;
		if (ws->getRequiredTool() == "Hammer")
			t = this->getTool<Hammer>();
		else
			t = this->getTool<Shovel>();
		t->use();
	}
	else 
		std::cout << name << " : i can't work, I don't have any tool" << std::endl;
}

Statistic Worker::getStatic(void) const
{
	Statistic st(stat.getLevel(), stat.getExp());
	return st;
}

std::ostream&   operator<<(std::ostream& stream, const Worker& value)
{
	
	stream << value.getName() << " has " << value.getStatic();
	return stream;
}