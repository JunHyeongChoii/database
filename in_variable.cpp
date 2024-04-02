#include <iostream>

void in_variable(std::string &key, std::string &type)
{
    std::cout << "key: ";
    std::cin >> key;

    std::cout << "type (int, double, string, array): ";
    std::cin >> type;
}