#include "PmergeMe.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>

int vec_count = 0;
int deq_count = 0;

size_t tmp = 21;

static unsigned long jacobsthal(unsigned int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  unsigned long j0 = 0, j1 = 1, j2 = 0;
  unsigned int i;
  for (i = 2; i <= n; i++) {
    j2 = j1 + 2 * j0;
    j0 = j1;
    j1 = j2;
  }
  return j2;
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

size_t PmergeMe::binarySearchInsertPosition(const std::vector<int>& sorted,
                                            int value, int minus) {
  size_t left = 0, right = sorted.size() - minus;
  while (left < right) {
    size_t mid = (left + right) / 2;
    if (value < sorted[mid])
      right = mid;
    else
      left = mid + 1;
    // deq_count++;
    vec_count++;
    std::cout << "compare" << value << "vs" << sorted[mid] << std::endl;
    std::cout << vec_count << std::endl;
    // std::cout << deq_count << std::endl;
  }
  return left;
}

std::vector<size_t> PmergeMe::computeInsertionOrder(size_t losersCount) {
  std::vector<size_t> order;
  if (losersCount <= 1) return order;
  size_t s = losersCount;

  std::vector<size_t> J;
  {
    unsigned long prev = 0;
    unsigned int n = 3;
    while (true) {
      unsigned long cur = jacobsthal(n);
      if (cur <= prev) {
        n++;
        continue;
      }
      if (cur > s) break;
      J.push_back(cur);
      prev = cur;
      n++;
    }
  }

  size_t prevBound = 1;
  size_t i;
  for (i = 0; i < J.size(); i++) {
    size_t curBound = J[i];
    size_t j;
    for (j = curBound; j > prevBound; j--) {
      order.push_back(j);
    }
    prevBound = curBound;
  }

  if (prevBound < s) {
    size_t j;
    for (j = s; j > prevBound; j--) {
      order.push_back(j);
    }
  }
  return order;
}

void PmergeMe::vectorFordJohnsonSort(std::vector<int>& before_w,
                                     std::vector<int>& before_l) {
  if (before_w.size() <= 1) return;
  (void)before_l;

  std::vector<int> winners;
  std::vector<int> losers;
  for (size_t i = 0; i < before_w.size(); i += 2) {
    if (i + 1 < before_w.size()) {
      if (before_w[i] < before_w[i + 1]) {
        winners.push_back(before_w[i + 1]);
        losers.push_back(before_w[i]);
      } else {
        winners.push_back(before_w[i]);
        losers.push_back(before_w[i + 1]);
      }
      vec_count++;
    } else {
      losers.push_back(before_w[i]);
    }
    // std::cout << vec_count << std::endl;
  }

  vectorFordJohnsonSort(winners, losers);

  std::vector<size_t> insertionOrder = computeInsertionOrder(losers.size());

  std::cout << "Insertion Order: ";
  for (size_t i = 0; i < insertionOrder.size(); ++i) {
    std::cout << insertionOrder[i] << " ";
  }

  std::cout << std::endl;
  ;

  std::cout << "Loser: ";
  for (size_t i = 0; i < losers.size(); ++i) {
    std::cout << losers[i] << " ";
  }

  std::cout << std::endl;
  ;

  std::cout << "winner: ";
  for (size_t i = 0; i < winners.size(); ++i) {
    std::cout << winners[i] << " ";
  }
  std::cout << std::endl;
  ;

  std::cout << "*************" << std::endl;

  if (!losers.empty()) winners.insert(winners.begin(), losers[0]);

  for (size_t j = 0; j < insertionOrder.size(); j++) {
    size_t idx = insertionOrder[j] - 1;
    if (idx < losers.size()) {
      int value = losers[idx];

      std::cout << "insert" << value << std::endl;

      size_t pos = binarySearchInsertPosition(winners, value, j + 1);
      winners.insert(winners.begin() + pos, value);
    }
  }

  std::vector<int> copy_before_l = before_l;
  // std::vector<int> copy_before_w = before_w;

  std::cout << "*************" << std::endl;

  for (size_t i = 0; i < winners.size(); ++i) {
    std::cout << winners[i] << " ";
  }

  std::cout << std::endl;

  for (size_t i = 0; i < before_w.size(); ++i) {
    std::cout << before_w[i] << " ";
  }

  // loser sort
  if (winners.size() == tmp) {
    before_w = winners;
    return;
  }
  for (size_t i = 0; i < winners.size(); ++i) {
    // winners[i];
    std::cout << "*************" << std::endl;

    for (size_t j = 0; j < before_w.size(); ++j) {
      std::cout << "*************" << std::endl;

      if (winners[i] == before_w[j]) {
        before_l[i] = copy_before_l[j];
      }
    }
  }

  before_w = winners;
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
      deq_count++;
    } else {
      losers.push_back(deq[i]);
    }
  }

  dequeFordJohnsonSort(winners);

  if (!losers.empty()) winners.insert(winners.begin(), losers[0]);

  std::vector<size_t> insertionOrder = computeInsertionOrder(losers.size());
  std::vector<int> winnersVec(winners.begin(), winners.end());
  for (size_t j = 0; j < insertionOrder.size(); j++) {
    size_t idx = insertionOrder[j] - 1;
    if (idx < losers.size()) {
      int value = losers[idx];
      size_t pos = binarySearchInsertPosition(winnersVec, value, j + 1);
      winnersVec.insert(winnersVec.begin() + pos, value);
    }
  }
  deq.assign(winnersVec.begin(), winnersVec.end());
}
