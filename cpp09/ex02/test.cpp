#include <iostream>
#include <vector>

// ヤコブスタール数を計算する関数
static unsigned long jacobsthal(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned long j0 = 0, j1 = 1, j2 = 0;
    for (unsigned int i = 2; i <= n; i++) {
        j2 = j1 + 2 * j0;
        j0 = j1;
        j1 = j2;
    }
    return j2;
}

// PmergeMe クラスの定義
class PmergeMe {
public:
    PmergeMe() {}
    ~PmergeMe() {}

    // 敗者リストの正しい挿入順序を計算する関数
    std::vector<size_t> computeInsertionOrder(size_t losersCount);
};

std::vector<size_t> PmergeMe::computeInsertionOrder(size_t losersCount) {
    std::vector<size_t> order;
    if (losersCount <= 1)
        return order;
    // losers[0] は既に使用済みなので、対象は 1 から losersCount-1（を s とする）
    size_t s = losersCount - 1;

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

// computeInsertionOrder 関数の実装
// std::vector<size_t> PmergeMe::computeInsertionOrder(size_t losersCount) {
//     std::vector<size_t> order;
//     if (losersCount <= 1)
//         return order;
//     // losers[0] は既に使用済みなので、対象は 1 から losersCount-1（を s とする）
//     size_t s = losersCount - 1;

//     // まず、重複しないヤコブスタール数を 1 以上 s 以下について列挙する
//     // 例：s = 4 の場合、得られる値は {1, 3}（J(1)=1, J(3)=3, J(4)=5 は s を超えるので除外）
//     std::vector<size_t> J;
//     {
//         unsigned long prev = 0;      // 直前の distinct 値
//         unsigned int n = 1;          // ヤコブスタール数の計算を n=1 から開始
//         while (true) {
//             unsigned long cur = jacobsthal(n);
//             if (cur > s)
//                 break;
//             if (cur > prev) { // 重複しない場合のみ追加
//                 J.push_back(cur);
//                 prev = cur;
//             }
//             n++;
//         }
//     }

//     // 次に、ヤコブスタール数によるブロック分割を行う
//     // 各ブロック k（k=0 から J.size()-1）について、ブロックの範囲は
//     //    start = (k == 0 ? 1 : J[k-1] + 1)  〜  end = J[k]
//     // とし、そのブロック内のインデックスを降順に order に追加する
//     size_t prevBound = 0;
//     for (size_t i = 0; i < J.size(); i++) {
//         size_t curBound = J[i];
//         for (size_t j = curBound; j > prevBound; j--) {
//             order.push_back(j);
//         }
//         prevBound = curBound;
//     }
//     // もし最後の境界が s より小さい場合、残り [prevBound+1, s] を降順に追加
//     if (prevBound < s) {
//         for (size_t j = s; j > prevBound; j--) {
//             order.push_back(j);
//         }
//     }
//     // order の内容は losers[1]～losers[s]（1-indexed）に対応する挿入順序となる
//     return order;
// }

// テスト関数
void testComputeInsertionOrder(size_t losersCount) {
    PmergeMe pmergeMe;
    std::vector<size_t> order = pmergeMe.computeInsertionOrder(losersCount);

    std::cout << "Losers count: " << losersCount << std::endl;
    std::cout << "Insertion order: ";
    for (size_t i = 0; i < order.size(); i++) {
        std::cout << order[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

// メイン関数
int main() {
    // テストケース
    testComputeInsertionOrder(1);
    testComputeInsertionOrder(2);
    testComputeInsertionOrder(3);
    testComputeInsertionOrder(4);
    testComputeInsertionOrder(5);
    testComputeInsertionOrder(6);
    testComputeInsertionOrder(7);
    testComputeInsertionOrder(8);
    testComputeInsertionOrder(9);
    testComputeInsertionOrder(10);

    return 0;
}
