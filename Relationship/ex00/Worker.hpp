#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "Data.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

class Tool;
class Workshop;

typedef struct t_positionOnWorkshop
{
	Position coordonnee;
	Workshop *ws;
}	positionOnWorkshop;	

class   Worker
{
    private:
		std::string name;
		Statistic stat;
        std::vector<Tool *> tools;
		std::vector<positionOnWorkshop> pos;
		void addExp();

	public :
		Worker(std::string name);
		~Worker();
		const std::string & getName(void) const;
		void addWorkshop(Workshop *ws, Position pos);
		void removeWorkshop(Workshop *ws);
		Position getPosition(Workshop *);
		Statistic getStatic(void) const;
        void takeTool(Tool *t);
		void putTool(const Tool *t);
		bool	hasATool(Workshop *ws);
		void	work(Workshop *ws);
		template <typename ToolType>
        ToolType* getTool();
};

std::ostream&   operator<<(std::ostream& stream, const Worker& value);

template <typename ToolType>
ToolType* Worker::getTool()
{
	std::vector<Tool *>::iterator it;
	ToolType* toolNeeded;
	for(it = tools.begin(); it != tools.end(); it++)
	{
		toolNeeded = dynamic_cast<ToolType*>((*it));
		if (toolNeeded)
			return toolNeeded;
	}
	return NULL;
}