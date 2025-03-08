#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
 public:
  PmergeMe();
  ~PmergeMe();

  bool initContainers(int argc, char** argv);

  std::string getUnsortedSequence() const;

  std::string getSortedSequenceVector() const;

  std::string getSortedSequenceDeque() const;

  void sortVector();

  void sortDeque();

  size_t getSize() const;

  long jacobsthal_recursive(int n);

  void vectorFordJohnsonSort(std::vector<int>& vec);

  void dequeFordJohnsonSort(std::deque<int>& deq);

 private:
  std::vector<int> _vec;
  std::deque<int> _deq;

  int _vec_merge_count;
  int _deq_merge_count;
};

#endif
