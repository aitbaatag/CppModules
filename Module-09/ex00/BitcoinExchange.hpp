#ifndef BUITCOINEXCHANGE_HPP
#define BUITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

class BitcoinExchange {
private:
  std::map<std::string, double> exchangeRates;
  void loadExchangeRates(const std::string &dataFile);
  double getExchangeRate(const std::string &date) const;
  bool isValidDate(const std::string &date) const;
  bool isValidValue(const std::string &valueStr, double &value) const;

public:
  BitcoinExchange(const std::string &dataFile);
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);
  ~BitcoinExchange();

  void processInputFile(const std::string &inputFile);
};

#endif
