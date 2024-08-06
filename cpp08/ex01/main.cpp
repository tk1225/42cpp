#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <string>

#include "span.hpp"

int main() {
  Span sp = Span(7);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  sp.addNumber(12);
  sp.addNumber(27);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::vector<int> vec(9999);
  std::iota(vec.begin(), vec.end(), 1);
  Span sp2 = Span(10000);
  sp2.insertNumbers(vec);
  sp2.addNumber(10099);

  std::cout << sp2.shortestSpan() << std::endl;
  std::cout << sp2.longestSpan() << std::endl;
  return 0;
}
