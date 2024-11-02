#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> numbers;
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);
  EasyFind(numbers, 3);

  std::list<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  EasyFind(list, 3);

  std::deque<int> deque;
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  EasyFind(deque, 3);
}
