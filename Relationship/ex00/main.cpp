#include "Worker.hpp"
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"


int main()
{
    Workshop ws(1,1,1);
    Worker w("worker1");
    ws.signUpWorkshop(&w);
    ws.executeWorkDay();
}