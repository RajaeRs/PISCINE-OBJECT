#include "Worker.hpp"
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"
#include <cstdlib>
#include <ctime>

#define MAX_COORDONNEE 5

int generateRandomNbr(int max, int min);

class Simulation
{
    private:
        std::vector<Workshop *> ws;
        std::vector<Worker *> wr;
        std::vector<Tool *> t;
    public :
        Simulation();
        Simulation(int nbr_workshop, int nbr_worker, int nbr_tool);
        void setWorkshops(int nbr_workshop);
        void setWorkers(int nbr_worker);
        void setTools(int nbr_tool);
        void start();
        ~Simulation();
};