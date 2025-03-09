#include "PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>

int count = 0;

static unsigned long jacobsthal(unsigned int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    unsigned long j0 = 0, j1 = 1, j2 = 0;
    unsigned int i;
    for(i = 2; i <= n; i++) {
        j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    return j2;
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

size_t PmergeMe::binarySearchInsertPosition(const std::vector<int>& sorted, int value, int minus) {
    size_t left = 0, right = sorted.size() - minus;
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (value < sorted[mid])
            right = mid;
        else
            left = mid + 1;
        count++;
        std::cout << "compare" << value << "vs" << sorted[mid] << std::endl;
        std::cout << count << std::endl;
    }
    return left;
}

// ヘルパー関数：敗者リスト（losers）のうち、最初の要素は既に main chain にあるため、
// 残りの要素の「正しい挿入順序」を返す（例：b₃, b₂, b₅, b₄, …）
// ※ここでは、0-based の losers インデックスで、losers[0] は既に使用済みとし、
// 残り losers[1]～を、2要素ずつ入れ替えるシンプルな例とする。
std::vector<size_t> PmergeMe::computeInsertionOrder(size_t losersCount) {
    std::vector<size_t> order;
    if (losersCount <= 1)
        return order;
    // losers[0] は既に使用済みなので、対象は 1 から losersCount-1（を s とする）
    size_t s = losersCount;

    // まず、重複しないヤコブスタール数を 3 以上 s 以下について列挙する
    // 例：s = 4 の場合、得られる値は {3}（J(3)=3, J(4)=5 は s を超えるので除外）
    std::vector<size_t> J;
    {
        unsigned long prev = 0;      // 直前の distinct 値
        unsigned int n = 3;          // ここでは n=3 から開始
        while (true) {
            unsigned long cur = jacobsthal(n);
            if (cur <= prev) { // 重複する場合はスキップ
                n++;
                continue;
            }
            if (cur > s)
                break;
            J.push_back(cur);
            prev = cur;
            n++;
        }
    }
    // 次に、ヤコブスタール数によるブロック分割を行う
    // 各ブロック k（k=0 から J.size()-1）について、ブロックの範囲は
    //    start = (k == 0 ? 2 : J[k-1] + 1)  〜  end = J[k]
    // とし、そのブロック内のインデックスを降順に order に追加する
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
    // もし最後の境界が s より小さい場合、残り [prevBound+1, s] を降順に追加
    if (prevBound < s) {
        size_t j;
        for (j = s; j > prevBound; j--) {
            order.push_back(j);
        }
    }
    // order の内容は losers[1]～losers[s]（1-indexed）に対応する挿入順序となる
    return order;
}


// Ford–Johnson ソート（std::vector 用）
// 再帰的に main chain (winners) をソートし、losers を正しい順序で挿入する
void PmergeMe::vectorFordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;
    // if (vec.size() == 2) {
        // if (vec[0] > vec[1])
        //     std::swap(vec[0], vec[1]);
            // count++;
            // std::cout << count << std::endl;
        // return;
    // }
    
    std::vector<int> winners;
    std::vector<int> losers;
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (i + 1 < vec.size()) {
            if (vec[i] < vec[i + 1]) {
                winners.push_back(vec[i + 1]); // 大きい方
                losers.push_back(vec[i]);      // 小さい方
            } else {
                winners.push_back(vec[i]);
                losers.push_back(vec[i + 1]);
            }
          count++;

        } else {
            losers.push_back(vec[i]);
        }
        std::cout << count << std::endl;
    }
    
    // 最初の敗者 (b₁) を main chain の先頭に追加
    // if (!losers.empty())
    //     winners.insert(winners.begin(), losers[0]);
    
    // winners を再帰的にソート
    vectorFordJohnsonSort(winners);

    
    // losers[1] 以降を、正しい挿入順序で winners に挿入
    std::vector<size_t> insertionOrder = computeInsertionOrder(losers.size());

    std::cout << "Insertion Order: ";
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        std::cout << insertionOrder[i] << " ";
    }

    std::cout << std::endl;;


    std::cout << "Loser: ";
    for (size_t i = 0; i < losers.size(); ++i) {
        std::cout << losers[i] << " ";
    }

    std::cout << std::endl;;

    std::cout << "winner: ";
    for (size_t i = 0; i < winners.size(); ++i) {
      std::cout << winners[i] << " ";
    }
    std::cout << std::endl;;

    std::cout << "*************" << std::endl;

    if (!losers.empty())
        winners.insert(winners.begin(), losers[0]);

    // std::cout << "first loser insert" << std::endl;

    std::cout << "winner: ";
    for (size_t i = 0; i < winners.size(); ++i) {
      std::cout << winners[i] << " ";
    }
    std::cout << std::endl;;
    std::cout << "*************" << std::endl;


    for (size_t j = 0; j < insertionOrder.size(); j++) {
        size_t idx = insertionOrder[j] - 1;
        if (idx < losers.size()) {
            int value = losers[idx];

            std::cout << "insert" << value << std::endl;

            size_t pos = binarySearchInsertPosition(winners, value, j + 1);
            winners.insert(winners.begin() + pos, value);
        }
    }
    vec = winners;
}

// Ford–Johnson ソート（std::deque 用）
// std::vector 用と同様のアルゴリズムを、std::deque に対して実装
void PmergeMe::dequeFordJohnsonSort(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;
    if (deq.size() == 2) {
        if (deq[0] > deq[1])
            std::swap(deq[0], deq[1]);
        return;
    }
    
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
        } else {
            winners.push_back(deq[i]);
        }
    }
    
    // if (!losers.empty())
    //     winners.push_front(losers.front());
    
    dequeFordJohnsonSort(winners);
    
    std::vector<size_t> insertionOrder = computeInsertionOrder(losers.size());
    // winners を一旦 std::vector に変換して二分探索で挿入位置を求める
    std::vector<int> winnersVec(winners.begin(), winners.end());
    for (size_t j = 0; j < insertionOrder.size(); j++) {
        size_t idx = insertionOrder[j];
        if (idx < losers.size()) {
            // int value = losers[idx];
            // size_t pos = binarySearchInsertPosition(winnersVec, value);
            // winnersVec.insert(winnersVec.begin() + pos, value);
        }
    }
    deq.assign(winnersVec.begin(), winnersVec.end());
}
