#include "easyfind.hpp"
#include<string>
#include<iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);
    EasyFind<std::vector<int> > c1(numbers, 3);
    c1.seekInt();
}
