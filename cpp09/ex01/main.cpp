#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include "RPN.hpp"

int main(int argc, char* argv[]) {
  std::string expression;
  if (argc >= 2) {
    expression = argv[1];
  } else {
    std::cerr << "Error: invalid arg" << std::endl;
    std::exit(1);
  }

  try {
    int result = RPN::evaluateRPN(expression);
    std::cout << "Result: " << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
