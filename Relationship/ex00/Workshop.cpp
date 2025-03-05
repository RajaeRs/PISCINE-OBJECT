#include "Workshop.hpp"
#include "Hammer.hpp"
#include "Shovel.hpp"

Workshop::Workshop(int z, int y, int x, std::string tool)
{
    if (z < 0 || y < 0 || x < 0)
        throw "You can't create a space with negative dimentions." ;
    this->size.setPosition(x, y, z);
    this->workignSpace = new int**[z];
    for (int i = 0; i < z; i++)
    {
        this->workignSpace[i] = new int*[y];
        for (int j = 0; j < y; j++)
        {
            this->workignSpace[i][j] = new int[x];
            for (int k = 0; k < x; k++)
                this->workignSpace[i][j][k] = 0;
        }
    }
    requiredTool = tool;
}


void Workshop::showWorkingSpace(void)
{
    for(int z = size.getZ() - 1; z >= 0 ; z--)
    {
        std::cout << "-- < " << z << " > --" << std::endl;
        for (int y = size.getY() -1 ; y >= 0; y--)
        {
            std::cout << y << " | " ;
            for (int x = size.getX() - 1; x >= 0; x--)
                std::cout << workignSpace[z][y][x] << ' ';
            std::cout << std::endl;
        }
    }
}

Workshop::~Workshop()
{
    std::vector<Worker *>::iterator it;
    for (it = workerList.begin(); it != workerList.end();)
        it = this->removeWorkerFromWorkshop(it, "");
    for (int i = 0; i < size.getZ(); i++)
    {
        for (int j = 0; j < size.getY(); j++)
            delete[] this->workignSpace[i][j];
        delete[] this->workignSpace[i];
    }
    delete[] this->workignSpace;
}

int Workshop::getAvailablePosition(Worker *w)
{
    int z,y,x;
    Position pos;
    for (z = 0; z < size.getZ(); z++)
    {
        for (y = 0; y < size.getY(); y++)
        {
            for (x = 0; x < size.getX(); x++)
            {
                if (workignSpace[z][y][x] == 0)
                {
                    workignSpace[z][y][x] = 1;
                    pos.setPosition(x, y, z);
                    w->addWorkshop(this, pos);
                    return 0;
                }
            }
        }
    }
    std::cout << "There are no available positions in the workshop." << std::endl;
    return 1;
}

std::string Workshop::getRequiredTool(void) const{ return requiredTool; }

void Workshop::signUpWorkshop(Worker *w)
{
    std::vector<Worker *>::iterator it;
    
    if (std::find(workerList.begin(), workerList.end(), w) != workerList.end())
    {
        std::cout << "Worker " <<  w->getName() << " is already in this workshop." << std::endl;
        return;
    }

    bool hasRequiredTool = 
        (w->getTool<Hammer>() && requiredTool == "Hammer") || 
        (w->getTool<Shovel>() && requiredTool == "Shovel");

    if (!hasRequiredTool) 
    {
        std::cout << "The worker `" << w->getName() << "` can't be added to the workshop because they lack the required tool." << std::endl;
        return;
    }
    if (getAvailablePosition(w) == 0)
    {
        this->workerList.push_back(w);
        std::cout << w->getName() << "  in pos : " << w->getPosition(this) << " : added to workshop." << std::endl;
    }
}
std::vector<Worker *>::iterator Workshop::leaveWorkshop(Worker *w, Position pos)
{
    std::vector<Worker *>::iterator it;
    it = std::find(workerList.begin(), workerList.end(), w);
    if (it != workerList.end())
    {
        workignSpace[pos.getZ()][pos.getY()][pos.getX()] = 0;
        it = workerList.erase(it);
        std::cout << "Worker `" <<  w->getName() << "` leave the workshop." << std::endl;
        return it;
    }
    std::cout << w->getName() << " : theresen't on the workshop." << std::endl;
    return it;
}

std::vector<Worker *>::iterator Workshop::removeWorkerFromWorkshop(std::vector<Worker *>::iterator it , std::string message)
{
    Position pos = (*it)->getPosition(this);
    if (pos.getX() == -1)
        throw "there is an error there !!!";
    workignSpace[pos.getZ()][pos.getY()][pos.getX()] = 0; 
    std::cout << "`" <<  (*it)->getName() << "` was removed from the workshop" << message << std::endl;
    (*it)->removeWorkshop(this);
    return workerList.erase(it);
}

void Workshop::executeWorkDay()
{
    std::vector<Worker *>::iterator it;
    if (workerList.size() == 0)
    {
        std::cout << "there is no worker in this workshop." << std::endl;
        return ;
    }
    for (it = workerList.begin(); it != workerList.end();)
    {
        if (!(*it)->hasATool(this))
        {
            std::string message("due to a lack of the required tool.");
            it = removeWorkerFromWorkshop(it, message);
        }
        else
        {
            (*it)->work(this);
            ++it;
        }
    }
    return ;
}