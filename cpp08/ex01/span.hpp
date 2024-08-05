#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <limits> 

class Span {
 private:
  std::vector<int> store;
  unsigned int len;

 public:
  Span();
  Span(unsigned int store_len);
  Span(const Span& SpanClass);
  Span& operator=(const Span& SpanClass);
  ~Span();
  void addNumber(int n);
  unsigned int shortestSpan();
  unsigned int longestSpan();
};

#endif
