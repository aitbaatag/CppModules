
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Error: could not open file." << std::endl;
    return 1;
  }

  const std::string dataFile = "data.csv";
  const std::string inputFile = argv[1];

  try {
    BitcoinExchange btc(dataFile);
    btc.processInputFile(inputFile);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
