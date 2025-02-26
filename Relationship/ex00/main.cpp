#include "Worker.hpp"
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
#include <cstdlib> // Required for rand() and srand()
#include <ctime>   // Required for time()


void CreateSimulation(Workshop& ws1, Workshop& ws2, std::vector<Worker*> *w, std::vector<Tool*> *t)
{
    srand(time(0));
    std::string wn = "worker_";
    int randomNumber;
    std::vector<Worker *>::iterator it;
    for (int i = 0; i < 10; i++)
    {
        std::string name = wn + std::to_string(i);
        Worker *wr = new Worker(name);
        w->push_back(wr);
    }
    for (int i = 0; i < 10; i++)
    {
        Tool *tl;
        randomNumber = 1 + (rand() % (50 - 1 + 1));
        if (randomNumber % 2 == 0)
            tl = new Shovel();
        else
            tl = new Hammer();
        t->push_back(tl);
    }
    std::cout << w->size() << std::endl;
    for (it = w->begin(); it != w->end(); it++)
    {
        if (*it != nullptr)
        {
            randomNumber = 1 + (rand() % (9 - 1 + 1));
            std::cout << randomNumber << "   ";
            ((*it))->takeTool((*t)[randomNumber]);

        }
    }
}


int main()
{
    try {
        Workshop ws(1,4,2);
        Workshop ws2(2,4,10);
        std::vector<Worker*> *Workers = new std::vector<Worker *>(1);
        std::vector<Tool*> *tools = new std::vector<Tool *>(1);

        CreateSimulation(ws, ws2, Workers, tools);





        // Worker *w1, *w2;
        // Tool *sh1, *sh2;
        // sh1 = new Shovel();
        // sh2 = new Hammer();
        // w1 = new Worker("w1");
        // w1->takeTool(sh1);
        // w2 = new Worker("w2");
        // w2->takeTool(sh2);
        // ws.signUpWorkshop(w1);
        // ws2.signUpWorkshop(w1);
        // ws.signUpWorkshop(w2);
        // ws.executeWorkDay();
        // ws2.executeWorkDay();
        // ws2.executeWorkDay();
        // ws.showWorkingSpace();
        // ws2.showWorkingSpace();
        // std::cout << *w1 << " \n" << *w2 << std::endl;

    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
        return (1);
    }
    return (0);
}