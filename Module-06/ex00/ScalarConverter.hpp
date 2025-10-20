#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class ScalarConverter {
public:
  static void convert(const std::string &literal);

private:
  typedef enum {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO_LITERAL,
    INVALID,
    SKIP
  } LiteralType;

  static LiteralType Ispseudo_literals(const std::string &literal);
  static LiteralType IsChar_literals(const std::string &literal);
  static LiteralType IsInt_literals(const std::string &literal);
  static LiteralType Isfloat_literals(const std::string &literal);
  static LiteralType IsDoublet_literals(const std::string &literal);

  void convertChar(const std::string &literal);
  void convertInt(const std::string &literal);
  void convertFloat(const std::string &literal);
  void convertDouble(const std::string &literal);
  void convertPseudoLiteral(const std::string &literal);

  typedef void (ScalarConverter::*ConvertFunc)(const std::string &literal);

  static LiteralType GetLiteralType(const std::string &literal);
};

#endif
