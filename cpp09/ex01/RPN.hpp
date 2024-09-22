#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN {
 public:
  RPN();
  RPN(const RPN& RPNClass);
  RPN& operator=(const RPN& RPNClass);
  ~RPN();
  static int evaluateRPN(const std::string& expression);
};

#endif
