#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {

  ConvertFunc converfunc[] = {
      &ScalarConverter::convertChar, &ScalarConverter::convertInt,
      &ScalarConverter::convertFloat, &ScalarConverter::convertDouble};

  LiteralType literalType = GetLiteralType(literal);
  if (literalType == LiteralType::INVALID) {
    std::cout << "Error: Invalid literal" << std::endl;
    return;
  } else if (literalType == LiteralType::PSEUDO_LITERAL) {
    std::cout << "Pseudo-literal detected: " << literal << std::endl;
    // Handle pseudo-literals separately if needed
    return;
  }
  (ScalarConverter().*converfunc[static_cast<int>(literalType)])(literal);
}

// Get literal type
ScalarConverter::LiteralType
ScalarConverter::GetLiteralType(const std::string &literal) {
  LiteralType type;

  type = Ispseudo_literals(literal);
  if (type != LiteralType::SKIP)
    return type;

  type = IsChar_literals(literal);
  if (type != LiteralType::SKIP)
    return type;

  type = IsInt_literals(literal);
  if (type != LiteralType::SKIP)
    return type;

  type = Isfloat_literals(literal);
  if (type != LiteralType::SKIP)
    return type;

  type = IsDoublet_literals(literal);
  if (type != LiteralType::SKIP)
    return type;

  return LiteralType::INVALID;
}

// pseudo literals
ScalarConverter::LiteralType
ScalarConverter::Ispseudo_literals(const std::string &literal) {
  if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
      literal == "nanf" || literal == "+inff" || literal == "-inff")
    return LiteralType::PSEUDO_LITERAL;

  return LiteralType::SKIP;
}

// char literals
ScalarConverter::LiteralType
ScalarConverter::IsChar_literals(const std::string &literal) {
  if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    return LiteralType::CHAR;
  return LiteralType::SKIP;
}

// int literals
ScalarConverter::LiteralType
ScalarConverter::IsInt_literals(const std::string &literal) {
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+')
    i++;
  while (i < literal.length()) {
    if (!isdigit(literal[i]))
      return LiteralType::SKIP;
    i++;
  }
  return LiteralType::INT;
}

// float literals
ScalarConverter::LiteralType
ScalarConverter::Isfloat_literals(const std::string &literal) {
  size_t i = 0;
  bool dot_found = false;
  if (literal[i] == '-' || literal[i] == '+')
    i++;
  while (i < literal.length()) {
    if (literal[i] == '.') {
      if (dot_found)
        return LiteralType::SKIP;
      dot_found = true;
    } else if (literal[i] == 'f' && i == literal.length() - 1) {
      return dot_found ? LiteralType::FLOAT : LiteralType::SKIP;
    } else if (!isdigit(literal[i])) {
      return LiteralType::SKIP;
    }
    i++;
  }
  return LiteralType::FLOAT;
}

// double literals
ScalarConverter::LiteralType
ScalarConverter::IsDoublet_literals(const std::string &literal) {
  size_t i = 0;
  bool dot_found = false;
  if (literal[i] == '-' || literal[i] == '+')
    i++;
  while (i < literal.length()) {
    if (literal[i] == '.') {
      if (dot_found)
        return LiteralType::SKIP;
      dot_found = true;
    } else if (!isdigit(literal[i])) {
      return LiteralType::SKIP;
    }
    i++;
  }
  return LiteralType::DOUBLE;
}

// ------------ Conversion functions ------------

void ScalarConverter::convertChar(const std::string &literal) {
  char c = literal[1];
  int i = static_cast<int>(c);
  float f = static_cast<float>(c);
  double d = static_cast<double>(c);

  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertInt(const std::string &literal) {
  int i = std::stoi(literal);
  char c = static_cast<char>(i);
  float f = static_cast<float>(i);
  double d = static_cast<double>(i);

  if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal) {
  float f = std::stof(literal);
  char c = static_cast<char>(f);
  int i = static_cast<int>(f);
  double d = static_cast<double>(f);

  if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal) {
  double d = std::stod(literal);
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);
  float f = static_cast<float>(d);

  if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

// pseudo literals
void ScalarConverter::convertPseudoLiteral(const std::string &literal) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  if (literal == "nan" || literal == "nanf") {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (literal == "+inf" || literal == "+inff") {
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else if (literal == "-inf" || literal == "-inff") {
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  }
}
