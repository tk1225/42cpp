#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    std::ostringstream ossBefore;
    
    // 引数チェック：正の整数のみを受け付ける
    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);
        // 数字以外が含まれている、もしくは "0" の場合はエラー
        if (token.empty() || token.find_first_not_of("0123456789") != std::string::npos || token == "0") {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int num = std::atoi(token.c_str());
        vec.push_back(num);
        deq.push_back(num);
        ossBefore << num << " ";
    }
    
    std::cout << "Before: " << ossBefore.str() << std::endl;
    
    // vector 用ソートの時間計測
    std::vector<int> vecCopy = vec;
    clock_t start_vector = clock();
    PmergeMe sorter;
    sorter.vectorFordJohnsonSort(vecCopy);
    clock_t end_vector = clock();
    double duration_vector = (double)(end_vector - start_vector) * 1000000.0 / CLOCKS_PER_SEC;
    
    // deque 用ソートの時間計測
    // std::deque<int> deqCopy = deq;
    // clock_t start_deque = clock();
    // sorter.dequeFordJohnsonSort(deqCopy);
    // clock_t end_deque = clock();
    // double duration_deque = (double)(end_deque - start_deque) * 1000000.0 / CLOCKS_PER_SEC;
    
    // ソート後の数列を表示（vector版とdeque版は同じ結果になるはず）
    std::ostringstream ossAfter;
    for (size_t i = 0; i < vecCopy.size(); i++) {
        ossAfter << vecCopy[i] << " ";
    }
    std::cout << "After: " << ossAfter.str() << std::endl;
    
    std::cout << "Time to process a range of " << vec.size() 
              << " elements with std::vector : " << duration_vector << " us" << std::endl;
    // std::cout << "Time to process a range of " << deq.size() 
    //           << " elements with std::deque  : " << duration_deque << " us" << std::endl;
    
    return 0;
}
