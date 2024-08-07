#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "EasyFind.hpp"

int main() {
  std::vector<int> numbers;
  numbers.push_back(1);
  numbers.push_back(2);
  numbers.push_back(3);
  numbers.push_back(4);
  numbers.push_back(5);
  EasyFind<std::vector<int> > c1(numbers, 3);
  c1.seekInt();

  std::list<int> list;
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);
  list.push_back(5);
  EasyFind<std::list<int> > c2(list, 3);
  c2.seekInt();

  std::deque<int> deque;
  deque.push_back(1);
  deque.push_back(2);
  deque.push_back(3);
  deque.push_back(4);
  deque.push_back(5);
  EasyFind<std::deque<int> > c3(deque, 3);
  c3.seekInt();
}
