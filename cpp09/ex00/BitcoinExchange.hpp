#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cstdio>

#define DEFAULT_FILENAME "data.csv"

class BitcoinExchange {
 private:
  std::map<std::string, double> price_data;
  bool isValidDate(const std::string& date);
  double stringToDouble(const std::string& str);

 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& BitcoinExchangeClass);
  BitcoinExchange& operator=(const BitcoinExchange& BitcoinExchangeClass);
  ~BitcoinExchange();
  double searchPrice(const std::string& date);
  void displayPrice(const std::string& filename);
};

#endif
