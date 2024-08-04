#include "Array.hpp"

int main(void) {
  Array<int>* tmp = new Array<int>(3);
  for (unsigned int i = 0; i < 3; ++i) {
    (*tmp)[i] = i * 10;
  }
  for (unsigned int i = 0; i < 3; ++i) {
    std::cout << (*tmp)[i] << " ";
  }
  std::cout << std::endl;

  delete tmp;
  return 0;
}
