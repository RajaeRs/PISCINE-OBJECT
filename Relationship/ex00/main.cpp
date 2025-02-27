#include "Worker.hpp"
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_COORDONNEE 5

int generateRandomNbr(int max, int min)
{
    int random;
    
    do {
        random = rand() % max;
    } while (random == max || random == min);
    return random;
}

class Simulation
{
    private:
        std::vector<Workshop *> ws;
        std::vector<Worker *> wr;
        std::vector<Tool *> t;
    public :
        Simulation()
        {
            setWorkshops(2);
            setWorkers(5);
            setTools(5);
        };
        Simulation(int nbr_worker, int nbr_tool, int nbr_workshop)
        {
            try {
                setWorkshops(nbr_workshop);
                setWorkers(nbr_worker);
                setTools(nbr_tool);
            }
            catch (const char * message)
            {
                std::cerr << "Please don't use a negative Number!" << std::endl;
            }
        }
        void setWorkshops(int nbr_workshop)
        {
            int randomNumber;
            for (int i = 0; i < nbr_workshop; i++)
            {
                int x = generateRandomNbr(MAX_COORDONNEE, 0);
                int y = generateRandomNbr(MAX_COORDONNEE, 0);
                int z = generateRandomNbr(MAX_COORDONNEE, 0);
                Workshop *ws_tmp = new Workshop(x, y, z);
                ws.push_back(ws_tmp);
            }
        }
        void setWorkers(int nbr_worker)
        {
            std::string name("Worker_");
            Worker *w;
            for (int i = 0; i < nbr_worker; i++)
            {
                w = new Worker(name + std::to_string(i));
                wr.push_back(w);
            }
        }
        void setTools(int nbr_tool)
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
        void start()
        {
            int wr_nbr = wr.size();
            int ws_nbr = ws.size();
            int t_nbr = t.size();
            int random;
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
};

int main()
{
        srand(time(0));
    try {
        Simulation sm = Simulation();

        sm.start();

    }
    catch (const char* err)
    {
        std::cerr << err << std::endl;
        return (1);
    }
    return (0);
}