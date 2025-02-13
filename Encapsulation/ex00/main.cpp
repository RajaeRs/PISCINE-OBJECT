#include "Bank.hpp"
#include "Account.hpp"

int main()
{
    try
    {
        Bank a;
        for (int i = 1; i< 100000; i++)
            a.openAccount(1);
        a.showCostummers();
    }
    catch (char const *message)
    {
        std::cout << message << std::endl;
    }
    return (0);
}