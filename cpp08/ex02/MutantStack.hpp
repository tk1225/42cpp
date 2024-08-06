#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

template <typename T>
class MutantStack {
 private:
  std::stack<T> st;

 public:
  MutantStack() {};

  MutantStack(const MutantStack<T>& other) { this->st = other.st; }

  MutantStack& operator=(const MutantStack& MutantStackClass) {
    if (this != &MutantStackClass) {
      this->st = MutantStackClass.st;
    }
    return *this;
  }

  ~MutantStack() {}

  unsigned int size() const { return this->st.size(); }
  void push(T elem) { this->st.push(elem); }
  void pop() { this->st.pop(); }
  bool empty() { return this->st.empty(); }
  T top() { return this->st.top(); }
};
