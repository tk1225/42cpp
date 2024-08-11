#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
  std::ifstream file(DEFAULT_FILENAME);
  std::string line;

  if (file.is_open()) {
    getline(file, line);
    while (getline(file, line)) {
      std::stringstream ss(line);
      std::string value;
      unsigned int line_size = 0;
      std::string elem[2];

      while (getline(ss, value, ',')) {
        if (line_size < 2) {
          elem[line_size] = value;
        }
        line_size++;
      }
      if (line_size != 2) {
        std::cerr << "Error: line size is invalid in " << line << std::endl;
        std::exit(1);
      }
      if (!isValidDate(elem[0])) {
        std::cerr << "Error: date format is invalid in " << line << std::endl;
        std::exit(1);
      }
      unsigned int price = 0;
      try {
        price = stringToUnsignedInt(elem[1]);
      } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        std::exit(1);
      }
      price_data[elem[0]] = price;
    }

    file.close();
  } else {
    std::cout << "ファイルを開けませんでした。" << std::endl;
  }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& BitcoinExchangeClass) {
  *this = BitcoinExchangeClass;
}

BitcoinExchange& BitcoinExchange::operator=(
    const BitcoinExchange& BitcoinExchangeClass) {
  if (this != &BitcoinExchangeClass) {
  }
  return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) {
  if (date.length() != 10) {
    return false;
  }
  if (date[4] != '-' || date[7] != '-') {
    return false;
  }
  for (std::string::size_type i = 0; i < date.length(); ++i) {
    if (i == 4 || i == 7) {
      continue;
    }
    if (!std::isdigit(date[i])) {
      return false;
    }
  }
  return true;
}

unsigned int BitcoinExchange::stringToUnsignedInt(const std::string& str) {
  try {
    int value = std::stoi(str);

    if (value < 0) {
      throw std::invalid_argument(
          "Negative value cannot be converted to unsigned int.");
    }
    return static_cast<unsigned int>(value);

  } catch (const std::invalid_argument& e) {
    throw std::invalid_argument("Invalid input: " + str +
                                " is not a valid integer.");
  } catch (const std::out_of_range& e) {
    throw std::out_of_range("Input is out of range for int.");
  }
}

unsigned int BitcoinExchange::searchPrice(const std::string& date) {
  std::map<std::string, unsigned int>::iterator it = price_data.upper_bound(date);

  if (it != price_data.begin()) {
    --it;
    std::cout << "Closest past date to " << date << ": " << it->first << "->" << it->second
              << std::endl;
  } else {
    std::cout << "No earlier dates found." << std::endl;
  }
  return it->second;
}
