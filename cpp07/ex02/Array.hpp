#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Array {
 private:
  T* arr;
  unsigned int len;

 public:
  Array() : len(0) { arr = new T[0]; }
  Array(unsigned int n) : len(n) { arr = new T[len]; }

  Array(const Array<T>& other) : len(other.len) {
    arr = new T[len];
    for (int i = 0; i < len; ++i) {
      arr[i] = other.arr[i];
    }
  }

  Array& operator=(const Array& ArrayClass) {
    if (this != &ArrayClass) {
      this->arr = ArrayClass.arr;
      this->len = ArrayClass.len;
    }
    return *this;
  }

  ~Array() { delete[] arr; }

  T& operator[](int index) {
    if (index < 0 || index >= len) {
      throw std::out_of_range("Index out of range");
    }
    return arr[index];
  }

  unsigned int size() const { return this->len; }
};
