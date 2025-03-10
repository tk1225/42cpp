#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();

    void vectorFordJohnsonSort(std::vector<int>& w, std::vector<int>& l);
    void dequeFordJohnsonSort(std::deque<int>& before_w, std::deque<int>& before_l);
    void setSize(size_t size);

   private:

    std::vector<size_t> computeInsertionOrder(size_t losersCount);

    size_t _size;
};

#endif
