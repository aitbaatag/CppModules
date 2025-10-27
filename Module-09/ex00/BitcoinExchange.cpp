#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange(const std::string &dataFile) {
  loadExchangeRates(dataFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  exchangeRates = other.exchangeRates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    exchangeRates = other.exchangeRates;
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates(const std::string &dataFile) {
  std::ifstream file(dataFile);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open data file: " + dataFile);
  }

  std::string line;
  std::getline(file, line); // Skip header line
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date;
    double rate;
    char comma;

    if (ss >> date >> comma >> rate) {
      exchangeRates[date] = rate;
    }
  }
  file.close();
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
  std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
  if (it != exchangeRates.end()) {
    return it->second;
  }

  it = exchangeRates.lower_bound(date);
  if (it == exchangeRates.begin()) {
    throw std::runtime_error("No exchange rate available for date: " + date);
  }
  --it;
  return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
    return false;
  }
  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (month < 1 || month > 12 || day < 1 || day > 31) {
    return false;
  }
  return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr,
                                   double &value) const {
  value = std::strtod(valueStr.c_str(), NULL);
  if (value < 0 || value > 1000) {
    return false;
  }
  return true;
}

void BitcoinExchange::processInputFile(const std::string &inputFile) {
  std::ifstream file(inputFile);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open input file: " + inputFile);
  }

  std::string line;
  std::getline(file, line); // Skip header line
  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date, valueStr;
    char separator;

    if (ss >> date >> separator >> valueStr) {
      if (!isValidDate(date)) {
        std::cerr << "Error: Invalid date format => " << date << std::endl;
        continue;
      }

      double value;
      if (!isValidValue(valueStr, value)) {
        std::cerr << "Error: Invalid value => " << valueStr << std::endl;
        continue;
      }

      try {
        double rate = getExchangeRate(date);
        double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
      } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
      }
    }
  }
  file.close();
}
