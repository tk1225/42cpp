#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include<string>
#include<iostream>
#include <algorithm>

template <typename T>
class EasyFind {
private:
    T value;
    int find;
public:
    EasyFind(const T& val, int s) : value(val), find(s) {}
    void seekInt();
};

#include "easyfind.tpp"

#endif
