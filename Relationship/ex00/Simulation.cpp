#include "Simulation.hpp"

Simulation::Simulation()
{
    setWorkshops(2);
    setWorkers(20);
    setTools(20);
};

Simulation::Simulation(int nbr_workshop, int nbr_worker, int nbr_tool)
{
    if (nbr_workshop < 1 || nbr_worker < 1 || nbr_tool < 1)
        throw "Please don't use a negative Number!";
    if (nbr_workshop > 20 || nbr_worker > 100 || nbr_tool > 100)
    {
        std::cout << "You can't create this large number of Component !\n";
        nbr_worker = nbr_worker < 100 ? nbr_worker : 100;
        nbr_workshop = nbr_workshop < 20 ? nbr_workshop : 20;
        nbr_tool = nbr_tool < 100 ? nbr_tool : 100;
    }
    try {
        setWorkshops(nbr_workshop);
        setWorkers(nbr_worker);
        setTools(nbr_tool);
    }
    catch (const char * message)
    {
        std::cerr << "Please don't use a negative Number!\n" << message << std::endl;
    }
    std::cout << "Workshop simulation created with : " 
    << nbr_workshop << " Workshop, " 
    << nbr_worker << " Worker, "
    << nbr_tool << " Tool."
    << std::endl;
}

void Simulation::setWorkshops(int nbr_workshop)
{
    for (int i = 0; i < nbr_workshop; i++)
    {
        int x = generateRandomNbr(MAX_COORDONNEE, 0);
        int y = generateRandomNbr(MAX_COORDONNEE, 0);
        int z = generateRandomNbr(MAX_COORDONNEE, 0);
        Workshop *ws_tmp = new Workshop(x, y, z, (i % 2 == 0) ? "Hammer" : "Shovel");
        ws.push_back(ws_tmp);
    }
}
void Simulation::setWorkers(int nbr_worker)
{
    std::string name("Worker_");
    Worker *w;
    for (int i = 0; i < nbr_worker; i++)
    {
        w = new Worker(name + std::to_string(i));
        wr.push_back(w);
    }
}
void Simulation::setTools(int nbr_tool)
{
    int randomNumber;
    for (int i = 0; i < nbr_tool; i++)
    {
        Tool *t_tmp;
        randomNumber = generateRandomNbr(MAX_COORDONNEE, -1);
        if (randomNumber % 2 == 0)
            t_tmp = new Shovel();
        else
            t_tmp = new Hammer();
        t.push_back(t_tmp);
    }
}
void Simulation::start()
{
    int ws_nbr = ws.size();
    int t_nbr = t.size();
    std::vector<Worker *>::iterator it;
    for (it = wr.begin(); it != wr.end(); it++)
    {
        int tn = generateRandomNbr(t_nbr, -1);
        (*it)->takeTool(t[tn]);
        int wn = generateRandomNbr(ws_nbr, -1);
        ws[wn]->signUpWorkshop(*it);
    }
    std::vector<Workshop *>::iterator itt;
    int i = 0;
    for(itt = ws.begin() ; itt != ws.end(); itt++)
    {
        i++;
        std::cout << "Workshop : "<< i << std::endl;
        (*itt)->showWorkingSpace();
        (*itt)->executeWorkDay();
    }
}
Simulation::~Simulation()
{
    std::vector<Workshop *>::iterator ws_it;
    std::vector<Worker *>::iterator wr_it;
    std::vector<Tool *>::iterator t_it;

    for (ws_it = ws.begin(); ws_it != ws.end(); ws_it++)
        delete *ws_it;
    for (t_it = t.begin(); t_it != t.end(); t_it++)
        delete *t_it;
    for (wr_it = wr.begin(); wr_it != wr.end(); wr_it++)
        delete *wr_it;
    std::cout << "\nSimulation Clean up successfuly!" << std::endl;
    return ;
}

int generateRandomNbr(int max, int min)
{
    int random;
    
    do {
        random = rand() % max;
    } while (random == max || random == min);
    return random;
}