#include <iostream>
#include <string>

template <typename T>
class Array {
 private:
  T* arr;
  unsigned int size;

 public:
  Array() : size(0) { arr = new T[]; }
  Array(unsigned int n) : size(n) { arr = new T[size]; }

  Array(const Array<T>& other) : size(other.size) {
    arr = new T[size];
    for (int i = 0; i < size; ++i) {
      arr[i] = other.arr[i];
    }
  }

  ~Array() { delete[] arr; }

  T& operator[](int index) {
    if (index < 0 || index >= size) {
      throw std::exception;
    }
    return arr[index];
  }

  unsigned int size() { return this->size; }
};
