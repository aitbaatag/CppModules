#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &dataFile) {
  loadExchangeRates(dataFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  exchangeRates = other.exchangeRates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    exchangeRates = other.exchangeRates;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates(const std::string &dataFile) {
  std::ifstream file(dataFile.c_str());
  if (!file.is_open()) {
    throw std::runtime_error("Error: could not open data file.");
  }

  std::string line;
  std::getline(file, line); // Skip header

  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string date;
    std::string rateStr;

    if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
      char *end;
      double rate = std::strtod(rateStr.c_str(), &end);
      if (*end != '\0')
        throw std::runtime_error("Error: invalid rate format in data file.");
      if (!isValidDate(date))
        throw std::runtime_error("Error: invalid date format in data file.");
      exchangeRates[date] = rate;
    }
  }
  file.close();
}

double BitcoinExchange::getExchangeRate(const std::string &date) const {
  std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
  if (it != exchangeRates.end())
    return it->second;

  it = exchangeRates.lower_bound(date);
  if (it == exchangeRates.begin()) {
    throw std::runtime_error("Error: no earlier exchange rate available for " +
                             date);
  }
  --it;
  return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    return false;

  int year = std::atoi(date.substr(0, 4).c_str());
  int month = std::atoi(date.substr(5, 2).c_str());
  int day = std::atoi(date.substr(8, 2).c_str());

  if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
    return false;

  return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr,
                                   double &value) const {
  char *end;
  value = std::strtod(valueStr.c_str(), &end);

  if (*end != '\0')
    return false;

  if (value < 0) {
    std::cerr << "Error: not a positive number." << std::endl;
    return false;
  }
  if (value > 1000) {
    std::cerr << "Error: too large a number." << std::endl;
    return false;
  }
  return true;
}

void BitcoinExchange::processInputFile(const std::string &inputFile) {
  std::ifstream file(inputFile.c_str());
  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  std::string line;
  std::getline(file, line); // Skip header line

  while (std::getline(file, line)) {
    if (line.empty())
      continue;

    std::istringstream ss(line);
    std::string date, valueStr;
    char separator;

    if (!(ss >> date >> separator) || separator != '|' || !(ss >> valueStr)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }

    if (!isValidDate(date)) {
      std::cerr << "Error: bad input => " << date << std::endl;
      continue;
    }

    double value;
    if (!isValidValue(valueStr, value))
      continue;

    try {
      double rate = getExchangeRate(date);
      double result = value * rate;
      std::cout << date << " => " << value << " = " << result << std::endl;
    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  file.close();
}
