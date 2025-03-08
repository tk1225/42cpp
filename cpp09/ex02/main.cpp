#include <ctime>
#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  PmergeMe sorter;
  if (!sorter.initContainers(argc, argv)) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  std::cout << "Before: " << sorter.getUnsortedSequence() << std::endl;

  std::clock_t startVector = std::clock();
  sorter.sortVector();
  std::clock_t endVector = std::clock();
  double durationVector =
      1000000.0 * (endVector - startVector) / CLOCKS_PER_SEC;

  std::clock_t startDeque = std::clock();
  sorter.sortDeque();
  std::clock_t endDeque = std::clock();
  double durationDeque = 1000000.0 * (endDeque - startDeque) / CLOCKS_PER_SEC;

  std::cout << "After: " << sorter.getSortedSequenceVector() << std::endl;
  std::cout << "Time to process a range of " << sorter.getSize()
            << " elements with std::vector : " << durationVector << " us"
            << std::endl;
  std::cout << "After: " << sorter.getSortedSequenceDeque() << std::endl;
  std::cout << "Time to process a range of " << sorter.getSize()
            << " elements with std::deque : " << durationDeque << " us"
            << std::endl;

  return 0;
}
