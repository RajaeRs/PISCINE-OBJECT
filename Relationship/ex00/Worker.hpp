#pragma once

#include <iostream>
#include <vector>
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

class Tool;

class   Worker
{
    private:
		Position coordonnee;
		Statistic stat;
        std::vector<Tool *> Tools;

	public :
		Worker(){}
		~Worker(){}
		void setPosition(int x, int y, int z){this->coordonnee.setPosition(x, y, z);}
		void addExp()
		{
			this->stat.addExp(20);
			if(this->stat.getExp() % 100 == 0)
				this->stat.addLevel();
		}
        void takeTool(Tool *t)
        {
            this->Tools.push_back(t);
            t->setWorker(this);
        }
		void putTool(const Tool *t)
		{
			std::vector<Tool *>::iterator it;
			for (it = this->Tools.begin(); it != this->Tools.end(); it++)
			{
				if (*it == t)
				{
					this->Tools.erase(it);
					break;
				}
			}
			if (it == this->Tools.end())
				std::cout << "[!] this worker doesn't has this tool" << std::endl;
			return ;
		}
};