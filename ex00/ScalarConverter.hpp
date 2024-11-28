#pragma once

#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <sstream>

enum Type { CHAR, INT, FLOAT, DOUBLE, SPECIAL, UNKNOWN };

class ScalarConverter {

	private:
		ScalarConverter(void);
		~ScalarConverter(void);
		ScalarConverter& operator=(const ScalarConverter& rhs);
		ScalarConverter(const ScalarConverter& cpy);


	public:
		static void convert(const std::string literal);

		static bool isCharLiteral(const std::string literal);
		static bool isIntLiteral(const std::string literal);
		static bool isFloatLiteral(const std::string literal);
		static bool isDoubleLiteral(const std::string literal);
		static Type getType(std::string literal);
		static void convertFromChar(char c);
		static void convertFromInt(int i);
		static void convertFromFloat(std::string literal);
		static void convertFromDouble(std::string literal);

		static char strToChar(const std::string literal);
		static int strToInt(const std::string literal);
		static float strToFloat(const std::string literal);
		static double strToDouble(const std::string literal);
};
