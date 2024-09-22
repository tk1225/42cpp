#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

int evaluateRPN(const std::string& expression) {
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

int main(int argc, char* argv[]) {
  std::string expression;
  if (argc >= 2) {
    expression = argv[1];
  } else {
    std::cerr << "Error: invalid arg" << std::endl;
    std::exit(1);
  }

  try {
    int result = evaluateRPN(expression);
    std::cout << "Result: " << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
