#include "PmergeMe.hpp"

#include <cstdlib>
#include <iostream>
#include <sstream>

int count = 0;

long PmergeMe::jacobsthal_recursive(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  return jacobsthal_recursive(n - 1) + 2 * jacobsthal_recursive(n - 2);
}

void PmergeMe::vectorFordJohnsonSort(std::vector<int>& vec) {
  if (vec.size() <= 1) return;

  std::vector<int> winners;
  std::vector<int> losers;

  for (size_t i = 0; i < vec.size(); i += 2) {
    // std::cout << "Count: " << count << std::endl;

    if (i + 1 < vec.size()) {
      if (vec[i] < vec[i + 1]) {
        winners.push_back(vec[i + 1]);
        losers.push_back(vec[i]);
      } else {
        winners.push_back(vec[i]);
        losers.push_back(vec[i + 1]);
      }
      //   count++;
    } else {
      winners.push_back(vec[i]);
    }
  }

  vectorFordJohnsonSort(winners);

  for (size_t i = losers.size(); i-- > 0;) {
    int value = losers[i];

    // print *************************
    // std::cout << "***********************************" << std::endl;
    // std::cout << "insert val " << value << std::endl;
    // std::cout << "***********************************" << std::endl;
    // std::cout << "losers vec: " << std::endl;
    // for (size_t j = 0; j < losers.size(); ++j) {
    //   std::cout << losers[j] << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "winners vec: " << std ::endl;
    // for (size_t k = 0; k < winners.size(); ++k) {
    //   std::cout << winners[k] << " ";
    // }
    // std::cout << std::endl;
    // print *************************

    size_t left = 0;
    size_t right = jacobsthal_recursive(_vec_merge_count);

    // std::cout << "jacob::  " << right << std::endl;

    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (value < winners[mid])
        right = mid;
      else
        left = mid + 1;
      //   count++;
      //   std::cout << "Count: " << count << std::endl;
    }
    winners.insert(winners.begin() + left, value);
  }
  vec = winners;
  _vec_merge_count++;
}

void PmergeMe::dequeFordJohnsonSort(std::deque<int>& deq) {
  if (deq.size() <= 1) return;

  std::deque<int> winners;
  std::deque<int> losers;

  for (size_t i = 0; i < deq.size(); i += 2) {
    if (i + 1 < deq.size()) {
      if (deq[i] < deq[i + 1]) {
        winners.push_back(deq[i + 1]);
        losers.push_back(deq[i]);
      } else {
        winners.push_back(deq[i]);
        losers.push_back(deq[i + 1]);
      }
      count++;
    } else {
      winners.push_back(deq[i]);
    }
  }

  dequeFordJohnsonSort(winners);

  for (size_t i = losers.size(); i-- > 0;) {
    int value = losers[i];
    size_t left = 0;
    size_t right = jacobsthal_recursive(_deq_merge_count);
    while (left < right) {
      size_t mid = left + (right - left) / 2;
      if (value < winners[mid])
        right = mid;
      else
        left = mid + 1;
      count++;
      std::cout << "Count: " << count << std::endl;
    }
    winners.insert(winners.begin() + left, value);
  }
  deq = winners;
  _deq_merge_count++;
}

PmergeMe::PmergeMe() {
  _vec_merge_count = 0;
  _deq_merge_count = 0;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::initContainers(int argc, char** argv) {
  for (int i = 1; i < argc; ++i) {
    std::string token(argv[i]);
    if (token.empty() ||
        token.find_first_not_of("0123456789") != std::string::npos ||
        token == "0") {
      return false;
    }
    int num = std::atoi(token.c_str());
    _vec.push_back(num);
    _deq.push_back(num);
  }
  return true;
}

std::string PmergeMe::getUnsortedSequence() const {
  std::ostringstream oss;
  for (size_t i = 0; i < _vec.size(); ++i) oss << _vec[i] << " ";
  return oss.str();
}

std::string PmergeMe::getSortedSequenceVector() const {
  std::ostringstream oss;
  for (size_t i = 0; i < _vec.size(); ++i) oss << _vec[i] << " ";
  return oss.str();
}

std::string PmergeMe::getSortedSequenceDeque() const {
  std::ostringstream oss;
  for (size_t i = 0; i < _deq.size(); ++i) oss << _deq[i] << " ";
  return oss.str();
}

void PmergeMe::sortVector() { vectorFordJohnsonSort(_vec); }

void PmergeMe::sortDeque() { dequeFordJohnsonSort(_deq); }

size_t PmergeMe::getSize() const { return _vec.size(); }
