#include "Bank_bonus.hpp"

int main()
{
    try {
        Bank b = Bank(20000);

        int a = b.openAccount(2000);
        int c = b.openAccount(1000);
        int d = b.openAccount(5000);
        (void)d;
        (void)a;
        (void)c;

        int negative = b.openAccount(0);
        b.requestLoan(negative, 1000);
        b.showCostummers();
    }
    catch (const char * message){
        std::cerr << message << std::endl;
    }

}