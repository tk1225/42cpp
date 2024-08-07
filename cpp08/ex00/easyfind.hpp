#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>

template <typename T>
class EasyFind {
 private:
  T value;
  int find;

 public:
  EasyFind() {};
  EasyFind(const EasyFind<T>& other) {
    this->value = other.value;
    this->find = other.find;
  }
  EasyFind& operator=(const EasyFind& EasyFindClass) {
    if (this != &EasyFindClass) {
      this->value = EasyFindClass.value;
      this->find = EasyFindClass.find;
    }
    return *this;
  }
  ~EasyFind() {}
  EasyFind(const T& val, int s) : value(val), find(s) {}
  void seekInt();
};

#include "EasyFind.tpp"

#endif
