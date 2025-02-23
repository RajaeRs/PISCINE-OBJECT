#pragma once

#include <iostream>
#include <vector>
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"

class Tool;

class   Worker
{
    private:
		std::string name;
		Position coordonnee;
		Statistic stat;
        std::vector<Tool *> tools;
		std::vector<Workshop *> workshops;

	public :
		Worker(std::string name){this->name = name; coordonnee.setPosition(-1, -1, -1);}
		~Worker(){}
		const std::string & getName(void) const { return name ;}
		void setPosition(int x, int y, int z){this->coordonnee.setPosition(x, y, z);}
		void resetPosition(void){this->coordonnee.resetPosition();}
		void addExp()
		{
			this->stat.addExp(20);
			if(this->stat.getExp() % 100 == 0)
				this->stat.addLevel();
		}
        void takeTool(Tool *t)
        {
            this->tools.push_back(t);
            t->setWorker(this);
        }
		void putTool(const Tool *t)
		{
			std::vector<Tool *>::iterator it;
			for (it = this->tools.begin(); it != this->tools.end(); it++)
			{
				if (*it == t)
				{
					this->tools.erase(it);
					std::cout << name << " : put tool down." << std::endl;
					break;
				}
			}
			if (it == this->tools.end())
				std::cout << name << " : i don't have this tool" << std::endl;
			if (tools.size() == 0)
			{
				std::vector<Workshop *>::iterator it;
				for(it = workshops.begin(); it != workshops.end(); it++)
					(*it)->leaveWorkshop(this);
			}
			return ;
		}
		bool	hasATool(void){
			if (this->tools.size() != 0)
				return true;
			return false;
		}
		void	work()
		{
			if (this->hasATool())
				std::cout << name << " in position " << coordonnee << " start working." << std::endl;
			else 
				std::cout << name << " : i can't work, I don't have any tool" << std::endl;
		}
};