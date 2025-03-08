#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <deque>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& PmergeMeClass);
  PmergeMe& operator=(const PmergeMe& PmergeMeClass);
  ~PmergeMe();

  void sortWithDeque(std::deque<int>& arr);

 private:
  struct Pair {
    int small;
    int large;
    Pair(int a, int b) : small(a), large(b) {}
  };

  void createPairs(std::deque<int>& arr, std::deque<std::deque<int> >& pairs,
                   std::deque<int>& leftovers);
  void sortLargeValues(std::deque<std::deque<int> >& pairs);
};

struct ComparePairs {
    bool operator()(const std::deque<int>& a, const std::deque<int>& b) const;
};

#endif
