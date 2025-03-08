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
      double price = 0;
      try {
        price = stringToDouble(elem[1]);
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
  int year, month, day;

  if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
    return false;
  }
  if (month < 1 || month > 12) {
    return false;
  }
  if (day > 31) {
    return false;
  }
  return true;
}

double BitcoinExchange::stringToDouble(const std::string& str) {
  double value = 0;
  try {
    value = std::stod(str);
  } catch (const std::invalid_argument& e) {
    throw std::invalid_argument("Invalid input: " + str +
                                " is not a valid number.");
  } catch (const std::out_of_range& e) {
    throw std::out_of_range("Input is out of range for double.");
  }
  if (value < 0) {
    throw std::invalid_argument("Error: not a positive number.");
  }
  if (value > 2147483647.0) {
    throw std::out_of_range("Error: too large a number.");
  }
  return value;
}

double BitcoinExchange::searchPrice(const std::string& date) {
  std::map<std::string, double>::iterator it = price_data.upper_bound(date);

  if (it != price_data.begin()) {
    --it;
  }
  return it->second;
}

void BitcoinExchange::displayPrice(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;

  if (file.is_open()) {
    getline(file, line);
    while (getline(file, line)) {
      line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

      std::stringstream ss(line);
      std::string value;
      unsigned int line_size = 0;
      std::string elem[2];

      while (getline(ss, value, '|')) {
        if (line_size < 2) {
          elem[line_size] = value;
        }
        line_size++;
      }
      if (line_size != 2 || !isValidDate(elem[0])) {
        std::cerr << "Error: bad input " << line << std::endl;
        continue;
      }
      double btc = 0;
      try {
        btc = stringToDouble(elem[1]);
      } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        continue;
      }
      double price = this->searchPrice(elem[0]);
      if (price > DBL_MAX / btc) {
        std::cerr << "Error: potential overflow in calculation." << std::endl;
        continue;
      }
      double asset_price = price * btc;
      std::cout << elem[0] << " => " << elem[1] << " = " << asset_price
                << std::endl;
    }
    file.close();
  } else {
    std::cerr << "Error: could not open file." << std::endl;
    std::exit(1);
  }
}
