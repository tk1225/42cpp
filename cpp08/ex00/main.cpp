#include "easyfind.hpp"
#include<string>
#include<iostream>

int main()
{
    EasyFind<double> c1(3.14, 10);
    c1.seekInt();
    std::cout << "ok" << std::endl;
}
