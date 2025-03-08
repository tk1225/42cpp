#include <iostream>
#include <string>

int main() {
  std::string str = "-1";
  double value = std::stod(str);

  std::cout << "Converted value: " << value << std::endl;
  if (value < 0) {
    throw std::invalid_argument(
        "Negative value cannot be converted to positive double.");
  }
  return 0;
}
