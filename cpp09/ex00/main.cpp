#include <iostream>

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
  std::string filename;
  if (argc >= 2) {
    filename = argv[1];
  }
  BitcoinExchange btc = BitcoinExchange();
  btc.displayPrice(filename);
  return 0;
}
