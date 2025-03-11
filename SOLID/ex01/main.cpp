#include "Command.hpp"
#include "PackageReductionDiscount.hpp"
#include "ThuesdayDiscount.hpp"

int main()
{

    Command *c0 = new Command(0, "Sunday", "Yassmin");
    c0->add_article("orange", 2, 5);
    c0->add_article("banana", 3, 15);
    c0->add_article("appel", 5, 12.5);
    c0->add_article("kiwi", 1, 25.5);
    c0->add_article("avocado", 1, 30);

    c0->show_command();

    std::cout << "------------------------------------------------\n";


    Command *c1 = new PackageReductionDiscount(1, "Monday", "Karima");
    c1->add_article("orange", 2, 5);
    c1->add_article("banana", 3, 15);
    c1->add_article("appel", 5, 12.5);
    c1->add_article("kiwi", 1, 25.5);
    c1->add_article("avocado", 1, 30);

    c1->show_command();

    std::cout << "------------------------------------------------\n";
    Command *c2 = new ThuesdayDiscountCommand(2, "Thursday", "Lamyae");
    c2->add_article("orange", 2, 5);
    c2->add_article("banana", 3, 15);
    c2->add_article("appel", 5, 12.5);
    c2->add_article("kiwi", 1, 25.5);
    c2->add_article("avocado", 1, 30);

    c2->show_command();
}