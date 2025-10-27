#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  const std::string dataFile = "data.csv";
  const std::string inputFile = argv[1];

  try {
    BitcoinExchange bitcoinExchange(dataFile);
    // bitcoinExchange.processInputFile(inputFile);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
