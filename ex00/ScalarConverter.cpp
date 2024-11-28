#include "ScalarConverter.hpp"
#include "Printer.hpp"

/*********************************	main	   ****************************************/

void ScalarConverter::convert(std::string literal) {
	Type type = getType(literal);

	switch (type) {
		case CHAR: {
			convertFromChar(strToChar(literal));
			break;
	}
	case INT: {
		convertFromInt(strToInt(literal));
		break;
	}
	case FLOAT: {
		convertFromFloat(literal);
		break ;
	}
	case DOUBLE: {
		convertFromDouble(literal);
		break;
	}
	default:
		std::cout << "Invalid or unknown literal.\n";
	}
}

/********************************* identify type ****************************************/

bool ScalarConverter::isCharLiteral(const std::string literal) {
	return literal.size() == 1 && !isdigit(literal[0]);
}

bool ScalarConverter::isIntLiteral(const std::string literal) {
	std::istringstream s(literal);
	int i = 0;
	return (s >> i) && (s.eof());
}

bool ScalarConverter::isFloatLiteral(const std::string literal) {
	std::istringstream s(literal);
	float i = 0;
	return (s >> i) && (s.eof());
}

bool ScalarConverter::isDoubleLiteral(const std::string literal) {
	std::istringstream s(literal);
	double i = 0;
	return (s >> i) && (s.eof());
}

Type ScalarConverter::getType(const std::string literal) {
	if (isCharLiteral(literal)) return CHAR;
	if (isIntLiteral(literal)) return INT;
	if (isFloatLiteral(literal)) return FLOAT;
	if (isDoubleLiteral(literal)) return DOUBLE;
	return UNKNOWN;
}

/*********************************   str to type   ****************************************/

char ScalarConverter::strToChar(const std::string literal) {
	if (literal.size() == 1) {
		return literal[0];
	}
	return 0;
}

int ScalarConverter::strToInt(const std::string literal) {
	std::istringstream s(literal);
	int i = 0;
	s >> i;

	return (i);
}

float ScalarConverter::strToFloat(const std::string literal) {
	std::istringstream s(literal);
	float f = 0;
	s >> f;

	return f;
}

double ScalarConverter::strToDouble(const std::string literal) {
	std::istringstream s(literal);
	double d = 0;
	s >> d;

	return d;
}

/*********************************   convertor   ****************************************/

void ScalarConverter::convertFromChar(char c) {
	if (c == 0)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		Printer::printChar(c);
	Printer::printInt(static_cast<int>(c));
	Printer::printFloat(static_cast<float>(c));
	Printer::printDouble(static_cast<double>(c));
}

void ScalarConverter::convertFromInt(int i) {
	if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
		std::cout << "int: impossible" << std::endl;
    } else {
        char c = static_cast<char>(i);
        if (!std::isprint(c)) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: " << c << std::endl;
        }

        std::cout << "int: " << i << std::endl;

        float f = static_cast<float>(i);
        std::cout << "float: " << f << "f" << std::endl;

        double d = static_cast<double>(i);
        std::cout << "double: " << d << std::endl;
    }
}

void ScalarConverter::convertFromFloat(std::string literal) {
	 float f = strToFloat(literal);

    if (std::isnan(f)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    char c = static_cast<char>(f);
    if (!std::isprint(c)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << c << std::endl;
    }

    int i = static_cast<int>(f);
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << i << std::endl;
    }

    std::cout << "float: " << f << "f" << std::endl;

    double d = static_cast<double>(f);
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromDouble(std::string literal) {
	  double d = strToDouble(literal);

    if (std::isnan(d)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }

    char c = static_cast<char>(d);
    if (!std::isprint(c)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: " << c << std::endl;
    }

    int i = static_cast<int>(d);
    if (i < std::numeric_limits<int>::min() || i > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << i << std::endl;
    }

    float f = static_cast<float>(d);
    std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}
