#include "Worker.hpp"
#include "Data.hpp"
#include "Tool.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"
#include "Workshop.hpp"


int main()
{
    Workshop ws(-1,4,2);
    Worker *w1;
    Worker *w2;
    Shovel *sh1;
    Hammer *sh2;
    sh1 = new Shovel();
    sh2 = new Hammer();
    ws.showWorkingSpace();
    w1 = new Worker("w1");
    w1->takeTool(sh1);
    w2 = new Worker("w2");
    w2->takeTool(sh2);
    ws.signUpWorkshop(w1);
    ws.signUpWorkshop(w2);
    ws.leaveWorkshop(w1);
    delete sh1;
    ws.executeWorkDay();
    ws.showWorkingSpace();
}