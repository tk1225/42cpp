#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

#define DEFAULT_FILENAME "data.csv"

class BitcoinExchange {
 private:
  std::map<std::string, unsigned int> price_data;
  bool isValidDate(const std::string& date);
  unsigned int stringToUnsignedInt(const std::string& str);

 public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& BitcoinExchangeClass);
  BitcoinExchange& operator=(const BitcoinExchange& BitcoinExchangeClass);
  ~BitcoinExchange();
  unsigned int searchPrice(const std::string& date);
};

#endif
