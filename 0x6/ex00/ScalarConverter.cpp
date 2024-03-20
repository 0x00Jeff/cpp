/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:17:14 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/20 16:57:48 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScalarConverter.hpp"
#include<sstream>

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

	t.value.c = c;
}

void ScalarConverter::isInt(std::string input, t_types &t)
{
	std::stringstream ss;
	if (!input.size() || input.find_first_not_of("0123456789") != std::string::npos)
		throw ScalarConverter::InvalidInt();
	ss << input;
	ss >> t.value.d;
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
	std::cout << "kek : " << t.value.f << std::endl;
	std::cout << "kek : " << static_cast<float>(t.value.placeholder);
}

// class functionalities : display
void ScalarConverter::typeDisplayer(t_types &t)
{
	ScalarConverter::displayChar(static_cast<char>(t.value.c), t.special_case);
	ScalarConverter::displayInt(static_cast<int>(t.value.d), t.special_case);
	ScalarConverter::displayFloat(static_cast<float>(t.value.f), t.special_case);
	ScalarConverter::displayDouble(static_cast<double>(t.value.ff), t.special_case);
}

void ScalarConverter::displayChar(long long c, int special_case)
{
	if (special_case != SPECIAL_CASE_NONE)
	{
		std::cout << "char: impossible" << c << std::endl;
		return;
	}
	std::cout << c << std::endl;
	std::cout << "char: " ;
	if (c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << c << std::endl;
}

void ScalarConverter::displayInt(long long d, int special_case)
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
			std::cout << static_cast<float>(f) << std::endl;
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
			std::cout << static_cast<double>(ff) << std::endl;
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
