#include "Iter.hpp"

int main(void) {
  int intArray[] = {1, 2, 3, 4, 5};
  int intLength = sizeof(intArray) / sizeof(intArray[0]);

  std::cout << "Printing integer array elements:" << std::endl;
  iter(intArray, intLength, printElement<int>);
  std::cout << std::endl;

  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  int doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

  std::cout << "Printing double array elements:" << std::endl;
  iter(doubleArray, doubleLength, printElement<double>);
  std::cout << std::endl;

  return 0;
}
