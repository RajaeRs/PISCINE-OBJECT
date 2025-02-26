#include "Workshop.hpp"

Workshop::Workshop(int z, int y, int x)
{
    if (z < 0 || y < 0 || x < 0)
        throw "You can't creat a space with negative dimentions." ;
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
    for (int i = 0; i < size.getZ(); i++)
    {
        for (int j = 0; j < size.getY(); j++)
        {
            delete[] this->workignSpace[i][j];
            
        }
        delete[] this->workignSpace[i];
    }
    delete[] this->workignSpace;
}
int Workshop::getAvailablePosition(Worker *w)
{
    int z,y,x;
    for (z = 0; z < size.getZ(); z++)
    {
        for (y = 0; y < size.getY(); y++)
        {
            for (x = 0; x < size.getX(); x++)
            {
                if (workignSpace[z][y][x] == 0)
                {
                    workignSpace[z][y][x] = 1;
                    w->setPosition(x, y, z);
                    return 0;
                }
            }
        }
    }
    std::cout << "there is no available position on workshop." << std::endl;
    return 1;
}
void Workshop::signUpWorkshop(Worker *w)
{
    std::vector<Worker *>::iterator it;
    
    
    for (it = workerList.begin(); it != workerList.end() && *it != w; it++){}
    if (it != workerList.end())
    {
        std::cout << "Worker " <<  w->getName() << " alredy on this workshop." << std::endl;
        return;
    }
    if (getAvailablePosition(w))
        return ;
    this->workerList.push_back(w);
    std::cout << w->getName() << " : added to workshop." << std::endl;
}
void Workshop::leaveWorkshop(Worker *w)
{
    std::vector<Worker *>::iterator it;
    for (it = workerList.begin(); it != workerList.end() && *it != w; it++){}
    if (it != workerList.end())
    {
        Position pos = (*it)->getPosition();
        workignSpace[pos.getZ()][pos.getY()][pos.getX()] = 0;
        workerList.erase(it);
        w->resetPosition();
        std::cout << "Worker `" <<  w->getName() << "` leave the workshop." << std::endl;
        return;
    }
    std::cout << w->getName() << " : theresen't on the workshop." << std::endl;
}

std::vector<Worker *>::iterator Workshop::removeWorkerFromWorkshop(std::vector<Worker *>::iterator it)
{
    Position pos = (*it)->getPosition();
    (*it)->resetPosition();
    workignSpace[pos.getZ()][pos.getY()][pos.getX()] = 0;
    std::cout << "Worker `" <<  (*it)->getName() << "` removed from the workshop cause he has no Tool." << std::endl;
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
    for (it = workerList.begin(); it != workerList.end(); it++)
    {
        if (!(*it)->hasATool())
            it = removeWorkerFromWorkshop(it);
        if ((*it)->hasATool())
            (*it)->work();
    }
    return ;
}