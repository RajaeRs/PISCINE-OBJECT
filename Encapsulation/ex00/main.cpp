#include "Bank.hpp"
#include "Account.hpp"
#include <vector>

int main()
{
    try
    {
        Bank a;
        const Account *A;
        const Account *B;
        const Account *C;

        A = a.openAccount(1000);
        B = a.openAccount(2000);
        
        a.closeAccount(A->getId());

        C = a.openAccount(2000);

        a.showCostummers();
    }
    catch (char const *message)
    {
        std::cout << message << std::endl;
    }
    return (0);
}