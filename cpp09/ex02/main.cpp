#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Error" << std::endl;
    return 1;
  }

  std::vector<int> vec;
  std::deque<int> deq;
  std::ostringstream ossBefore;

  size_t size = 0;

  for (int i = 1; i < argc; ++i) {
    std::string token(argv[i]);
    if (token.empty() ||
        token.find_first_not_of("0123456789") != std::string::npos ||
        token == "0") {
      std::cerr << "Error" << std::endl;
      return 1;
    }
    int num = std::atoi(token.c_str());
    vec.push_back(num);
    deq.push_back(num);
    ossBefore << num << " ";
    size++;
  }

  std::cout << "Before: " << ossBefore.str() << std::endl;

  std::vector<int> vecCopy = vec;
  std::vector<int> vecL;
  clock_t start_vector = clock();
  PmergeMe sorter;

  sorter.setSize(size);
  sorter.vectorFordJohnsonSort(vecCopy, vecL);
  clock_t end_vector = clock();
  double duration_vector =
      (double)(end_vector - start_vector) * 1000000.0 / CLOCKS_PER_SEC;

  std::deque<int> decL;
  std::deque<int> deqCopy = deq;
  clock_t start_deque = clock();
  sorter.dequeFordJohnsonSort(deqCopy, decL);
  clock_t end_deque = clock();
  double duration_deque =
      (double)(end_deque - start_deque) * 1000000.0 / CLOCKS_PER_SEC;

  std::ostringstream ossAfterVec, ossAfterDeq;
  for (size_t i = 0; i < vecCopy.size(); i++) {
    ossAfterVec << vecCopy[i] << " ";
  }
  for (size_t i = 0; i < deqCopy.size(); i++) {
    ossAfterDeq << deqCopy[i] << " ";
  }

  std::cout << "After : " << ossAfterVec.str() << std::endl;
  std::cout << "After (deque) : " << ossAfterDeq.str() << std::endl;

  std::cout << "Time to process a range of " << vec.size()
            << " elements with std::vector : " << duration_vector << " us"
            << std::endl;
  std::cout << "Time to process a range of " << deq.size()
            << " elements with std::deque  : " << duration_deque << " us"
            << std::endl;

  return 0;
}
