#include <deque>
#include <iostream>
#include <list>
#include <numeric>
#include <string>

#include "span.hpp"

int main() {
  Span sp = Span(8);
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
  sp.addNumber(1);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  std::vector<int> vec;
  vec.reserve(9999);
  for (int i = 1; i <= 9999; ++i) {  // iotaの代替
    vec.push_back(i);
  }

  Span sp2(10000);
  sp2.insertNumbers(vec);
  sp2.addNumber(10099);

  std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
  return 0;
}
