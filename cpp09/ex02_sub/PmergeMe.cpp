#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& PmergeMeClass) { *this = PmergeMeClass; }

PmergeMe& PmergeMe::operator=(const PmergeMe& PmergeMeClass) {
  if (this != &PmergeMeClass) {
  }
  return *this;
}

void PmergeMe::createPairs(std::deque<int>& arr, std::deque< std::deque<int> >& pairs, std::deque<int>& leftovers) {
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        std::deque<int> pair(2);
        int a = arr[i];
        int b = arr[i + 1];
        if (a < b) {
            pair[0] = a;
            pair[1] = b;
        } else {
            pair[0] = b;
            pair[1] = a;
        }
        pairs.push_back(pair);
    }

    // 奇数個の要素がある場合、最後の要素を残す
    if (arr.size() % 2 != 0) {
        leftovers.push_back(arr.back());
    }
}

void PmergeMe::sortLargeValues(std::deque< std::deque<int> >& pairs) {
    // 大きい値を基準にペアをソート
    std::sort(pairs.begin(), pairs.end(), ComparePairs());
}

bool ComparePairs::operator()(const std::deque<int>& a, const std::deque<int>& b) const {
    return a[1] < b[1]; // 2つ目の要素（大きい方）でソート
}

void PmergeMe::sortWithDeque(std::deque<int>& arr) {
    if (arr.size() < 2) {
        // 要素が1個以下ならソート不要
        return;
    }

    // 1. ペアを作成
    std::deque< std::deque<int> > pairs;
    std::deque<int> leftovers;
    createPairs(arr, pairs, leftovers);

    // 2. ペアの大きい値のグループをソート
    sortLargeValues(pairs);

    // 3. ソートされた結果を出力
    std::cout << "Sorted pairs (by large values):" << std::endl;
    for (size_t i = 0; i < pairs.size(); ++i) {
        std::cout << "(" << pairs[i][0] << ", " << pairs[i][1] << ") ";
    }
    std::cout << std::endl;

    // 残った値を出力（奇数個の要素の場合）
    if (!leftovers.empty()) {
        std::cout << "Leftover: " << leftovers.front() << std::endl;
    }
}

