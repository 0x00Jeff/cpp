/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:14 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/20 21:17:16 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"
#include<sstream>
#include <iomanip>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter( ScalarConverter const &){}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const &) { return *this; }
ScalarConverter::~ScalarConverter(){}

// class functionalities : detection
void ScalarConverter::typeDetector(std::string input, t_types &t)
{
	try
	{
		ScalarConverter::isChar(input, t);
		t.valid = true;
	}
	catch(...) { }

	try
	{
		ScalarConverter::isInt(input, t);
		t.valid = true;
	}
	catch(...) { }

	try
	{
		ScalarConverter::isFloat(input, t);
		t.valid = true;
	}
	catch(...) {}

	try
	{
		ScalarConverter::isDouble(input, t);
		t.valid = true;
	}
	catch(...) {}

	if (t.valid == false)
		throw InvalidInput();

}

void ScalarConverter::isChar(std::string input, t_types &t)
{
	int c;
	if (input.size() != 3)
		throw ScalarConverter::InvalidChar();

	if (input[0] != '\'' || input[2] != '\'')
		throw ScalarConverter::InvalidChar();

	c = static_cast<int>(input[1]);
	if (c < 32 || c > 126)
		throw ScalarConverter::InvalidChar();

	t.value.placeholder = c;
}

void ScalarConverter::isInt(std::string input, t_types &t)
{
	std::stringstream ss;
	if (!input.size() || input.find_first_not_of("0123456789") != std::string::npos)
		throw ScalarConverter::InvalidInt();
	ss << input;
	ss >> t.value.placeholder;
}

void ScalarConverter::isDouble(std::string input, t_types &t)
{
	std::stringstream ss;
	unsigned long pos;
	pos = input.find('.');

	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		t.special_case = SPECIAL_CASE_NAN;
		if (input == "-inf")
			t.special_case = SPECIAL_CASE_NIG;
		else if (input == "+inf")
			t.special_case = SPECIAL_CASE_POS;
		return;
	}

	if (!input.size() || pos == std::string::npos)
		throw ScalarConverter::InvalidDouble();

	ss << input;
	input.erase(pos, 1);

	ScalarConverter::isInt(input, t);
	ss >> t.value.ff;
}

void ScalarConverter::isFloat(std::string input, t_types &t)
{
	std::stringstream ss;
	if (!input.size() || input.back() != 'f')
		throw ScalarConverter::InvalidFloat();

	input = input.substr(0, input.size()-1);
	ss << input;

	ScalarConverter::isDouble(input, t);
	ss >> t.value.f;
}

// class functionalities : display
void ScalarConverter::typeDisplayer(t_types &t)
{
	ScalarConverter::displayChar(static_cast<char>(t.value.placeholder), t.special_case);
	ScalarConverter::displayInt(static_cast<int>(t.value.placeholder), t.special_case);
	ScalarConverter::displayFloat(static_cast<float>(t.value.placeholder), t.special_case);
	ScalarConverter::displayDouble(static_cast<double>(t.value.placeholder), t.special_case);
}

void ScalarConverter::displayChar(char c, int special_case)
{
	if (special_case != SPECIAL_CASE_NONE)
	{
		std::cout << "char: impossible" << std::endl;
		return;
	}
	std::cout << "char: " ;
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::displayInt(int d, int special_case)
{
	if (special_case == SPECIAL_CASE_NONE)
		std::cout << "int: " << d << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::displayFloat(float f, int special_case)
{
	std::cout << "float: ";
	switch (special_case)
	{
		case SPECIAL_CASE_NAN:
			std::cout << "nanf" << std::endl;
			break;
		case SPECIAL_CASE_NIG:
			std::cout << "-inff" << std::endl;
			break;
		case SPECIAL_CASE_POS:
			std::cout << "+inff" << std::endl;
			break;
		default:
			std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	}
}

void ScalarConverter::displayDouble(double ff, int special_case)
{
	std::cout << "double: ";
	switch (special_case)
	{
		case SPECIAL_CASE_NAN:
			std::cout << "nan" << std::endl;
			break;
		case SPECIAL_CASE_NIG:
			std::cout << "-inf" << std::endl;
			break;
		case SPECIAL_CASE_POS:
			std::cout << "+inf" << std::endl;
			break;
		default:
			std::cout << ff << std::endl;
	}
}

// exceptions
const char *ScalarConverter::InvalidChar::what() const throw()
{
	return "Invalid char!";
}

const char *ScalarConverter::InvalidInt::what() const throw()
{
	return "Invalid int!";
}

const char *ScalarConverter::InvalidFloat::what() const throw()
{
	return "Invalid float!";
}

const char *ScalarConverter::InvalidDouble::what() const throw()
{
	return "Invalid double!";
}

const char *ScalarConverter::InvalidInput::what() const throw()
{
	return "Invalid input!";
}
