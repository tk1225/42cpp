#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& RPNClass) { *this = RPNClass; }

RPN& RPN::operator=(const RPN& RPNClass) {
  if (this != &RPNClass) {
  }
  return *this;
}

int RPN::evaluateRPN(const std::string& expression) {
  std::stack<int> stack;
  std::istringstream tokens(expression);
  std::string token;

  while (tokens >> token) {
    if (isdigit(token[0])) {
      stack.push(std::stoi(token));
    } else {
      if (stack.size() < 2) {
        throw std::runtime_error("Invalid expression: not enough operands.");
      }
      int b = stack.top();
      stack.pop();
      int a = stack.top();
      stack.pop();

      if (token == "+") {
        stack.push(a + b);
      } else if (token == "-") {
        stack.push(a - b);
      } else if (token == "*") {
        stack.push(a * b);
      } else if (token == "/") {
        if (b == 0) {
          throw std::runtime_error("Division by zero.");
        }
        stack.push(a / b);
      } else {
        throw std::invalid_argument("Invalid operator: " + token);
      }
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Invalid expression: too many operands.");
  }

  return stack.top();
}
