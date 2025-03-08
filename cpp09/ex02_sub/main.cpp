#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>"
              << std::endl;
    return 1;
  }

  std::vector<int> numbers;
  for (int i = 1; i < argc; ++i) {
    int j = std::atoi(argv[i]);
    if (j < 0) {
      std::cerr << "negative number is forbidden";
      std::exit(1);
    }
    numbers.push_back(j);
  }

  std::cout << "Before: ";
  for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::vector<int> sorted_numbers1 = numbers;

  struct timespec start, end;
  // const int iterations = 100000;

  clock_gettime(CLOCK_MONOTONIC, &start);

  clock_gettime(CLOCK_MONOTONIC, &end);

  std::cout << "After: ";
  for (std::vector<int>::iterator it = sorted_numbers1.begin();
       it != sorted_numbers1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  long seconds = end.tv_sec - start.tv_sec;
  long nanoseconds = end.tv_nsec - start.tv_nsec;
  double elapsed_time_microseconds = (seconds * 1e9 + nanoseconds) / 1000.0;

  // double average_time_per_sort = elapsed_time_microseconds / iterations;

  std::cout << "Time to process a range of " << sorted_numbers1.size()
            << " elements with std::sort: " << elapsed_time_microseconds
            << " us" << std::endl;

  PmergeMe sorter;

  std::deque<int> arr;
  arr.push_back(3);
  arr.push_back(5);
  arr.push_back(9);
  arr.push_back(7);
  arr.push_back(4);
  arr.push_back(8);
  arr.push_back(1);
  arr.push_back(19);

  // ソートを実行
  sorter.sortWithDeque(arr);
  return 0;
}
