#include "Command.hpp"

Command::Command(int id, std::string date, std::string client_name): id(id), date(date), client(client_name){}
Command::~Command(){}

void Command::add_article(std::string name, int quentity, float price)
{
    this->articles.insert(std::make_pair(name, std::make_pair(quentity, price)));
}   

float   Command::get_total_price()
{
    float total = 0;
    std::multimap<std::string, std::pair<int, float> >::iterator it;
    
    for (it = articles.begin(); it != articles.end(); it++)
        total += static_cast<float>(it->second.first) * it->second.second;

    return total - get_discount(total);
}

void   Command::show_command()
{
    float total_price;
    std::cout << "Command ID : " << id << std::endl; 
    std::cout << "Client Name : " << client << std::endl; 
    std::cout << "Date : " << date << std::endl;
    std::cout << "Number of articles : " << articles.size() << std::endl;
    for (std::multimap<std::string, std::pair<int, float> >::iterator it = articles.begin(); it != articles.end(); it++)
        std::cout << "  " << it->first << " : " << it->second.first << "x , " << it->second.second << " euro." << std::endl;
    total_price = get_total_price();
    std::cout << "Total Price : " << total_price << " euros" << std::endl; 
}