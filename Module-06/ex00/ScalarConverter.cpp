#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {

  ConvertFunc converfunc[] = {
      &ScalarConverter::convertChar, &ScalarConverter::convertInt,
      &ScalarConverter::convertFloat, &ScalarConverter::convertDouble,
      &ScalarConverter::convertPseudoLiteral};

  ScalarConverter::LiteralType literalType = GetLiteralType(literal);
  std::cout << "Detected literal type: ";
  switch (literalType) {
  case CHAR:
    std::cout << "CHAR" << std::endl;
    break;
  case INT:
    std::cout << "INT" << std::endl;
    break;
  case FLOAT:
    std::cout << "FLOAT" << std::endl;
    break;
  case DOUBLE:
    std::cout << "DOUBLE" << std::endl;
    break;
  case PSEUDO_LITERAL:
    std::cout << "PSEUDO_LITERAL" << std::endl;
    break;
  default:
    break;
  }
  if (literalType == ScalarConverter::INVALID) {
    std::cout << "Error: Invalid literal" << std::endl;
    return;
  }
  (ScalarConverter().*converfunc[static_cast<int>(literalType)])(literal);
}

// Get literal type
ScalarConverter::LiteralType
ScalarConverter::GetLiteralType(const std::string &literal) {
  ScalarConverter::LiteralType type;

  type = Ispseudo_literals(literal);
  if (type != ScalarConverter::SKIP)
    return type;

  type = IsChar_literals(literal);
  if (type != ScalarConverter::SKIP)
    return type;

  type = IsInt_literals(literal);
  if (type != ScalarConverter::SKIP)
    return type;

  type = Isfloat_literals(literal);
  if (type != ScalarConverter::SKIP)
    return type;

  type = IsDoublet_literals(literal);
  if (type != ScalarConverter::SKIP)
    return type;

  return ScalarConverter::INVALID;
}

// pseudo literals
ScalarConverter::LiteralType
ScalarConverter::Ispseudo_literals(const std::string &literal) {
  if (literal == "nan" || literal == "+inf" || literal == "-inf" ||
      literal == "nanf" || literal == "+inff" || literal == "-inff")
    return ScalarConverter::PSEUDO_LITERAL;

  return ScalarConverter::SKIP;
}

// char literals
ScalarConverter::LiteralType
ScalarConverter::IsChar_literals(const std::string &literal) {
  if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
    return ScalarConverter::CHAR;
  return ScalarConverter::SKIP;
}

// int literals
ScalarConverter::LiteralType
ScalarConverter::IsInt_literals(const std::string &literal) {
  size_t i = 0;
  if (literal[i] == '-' || literal[i] == '+')
    i++;
  while (i < literal.length()) {
    if (!isdigit(literal[i]))
      return ScalarConverter::SKIP;
    i++;
  }
  return ScalarConverter::INT;
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
        return ScalarConverter::SKIP;
      dot_found = true;
    } else if (literal[i] == 'f' && i == literal.length() - 1) {
      return dot_found ? ScalarConverter::FLOAT : ScalarConverter::SKIP;
    } else if (!isdigit(literal[i])) {
      return ScalarConverter::SKIP;
    }
    i++;
  }
  return ScalarConverter::SKIP;
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
        return ScalarConverter::SKIP;
      dot_found = true;
    } else if (!isdigit(literal[i])) {
      return ScalarConverter::SKIP;
    }
    i++;
  }
  return ScalarConverter::DOUBLE;
}

// ------------ Conversion functions ------------

void ScalarConverter::convertChar(const std::string &literal) {
  char c = literal[1];
  int i = static_cast<int>(c);
  float f = static_cast<float>(c);
  double d = static_cast<double>(c);

  std::cout << "char: '" << c << "'" << std::endl;
  std::cout << "int: " << i << std::endl;

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertInt(const std::string &literal) {
  int i = std::atoi(literal.c_str());
  char c = static_cast<char>(i);
  float f = static_cast<float>(i);
  double d = static_cast<double>(i);

  if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  std::cout << "int: " << i << std::endl;
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal) {
  float f = std::atof(literal.c_str());
  char c = static_cast<char>(f);
  int i = static_cast<int>(f);
  double d = static_cast<double>(f);

  if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  std::cout << "int: " << i << std::endl;

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << f << "f" << std::endl;
  std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal) {
  double d = std::strtod(literal.c_str(), NULL);
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);
  float f = static_cast<float>(d);

  if (isprint(c))
    std::cout << "char: '" << c << "'" << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;

  std::cout << "int: " << i << std::endl;

  std::cout << std::fixed << std::setprecision(1);
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
