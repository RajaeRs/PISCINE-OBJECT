#pragma once

#include <iostream>
#include <vector>
#include "Data.hpp"
#include "Tool.hpp"
#include "Workshop.hpp"

class Tool;
class Workshop;

class   Worker
{
    private:
		std::string name;
		Position coordonnee;
		Statistic stat;
        std::vector<Tool *> tools;
		std::vector<Workshop *> workshops;

	public :
		Worker(std::string name);
		~Worker();
		const std::string & getName(void) const;
		void setPosition(int x, int y, int z);
		Position getPosition(void) const;
		void resetPosition(void);
		void addExp();
        void takeTool(Tool *t);
		void putTool(const Tool *t);
		bool	hasATool(void);
		void	work();
};