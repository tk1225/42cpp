#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void vectorFordJohnsonSort(std::vector<int>& w, std::vector<int>& l);
    void dequeFordJohnsonSort(std::deque<int>& deq);

private:
    size_t binarySearchInsertPosition(const std::vector<int>& sorted, int value, int minus);

    std::vector<size_t> computeInsertionOrder(size_t losersCount);
};

#endif
