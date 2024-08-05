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

  Array<double>* tmp2 = new Array<double>(3);
  for (unsigned int i = 0; i < 3; ++i) {
    (*tmp2)[i] = i * 10;
  }
  for (unsigned int i = 0; i < 3; ++i) {
    std::cout << (*tmp2)[i] << " ";
  }
  std::cout << std::endl;

  try {
    (*tmp2)[4];
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  delete tmp2;

  return 0;
}
