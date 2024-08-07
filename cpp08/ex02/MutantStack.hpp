#include <deque>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
 public:
  MutantStack() {};
  MutantStack(const MutantStack<T>& other) { (void)other; }
  MutantStack& operator=(const MutantStack& MutantStackClass) {
    (void)MutantStackClass;
    return *this;
  }
  ~MutantStack() {}

  typedef typename Container::iterator iterator;

  iterator begin() { return this->c.begin(); }
  iterator end() { return this->c.end(); }
};
