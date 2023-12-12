/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:44:50 by asolano-          #+#    #+#             */
/*   Updated: 2023/12/12 10:08:53 by asolano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void)copy;
}

void ScalarConverter::convert(std::string input)
{
	if (input.size() == 1 && !isdigit(input[0]))
		return convertChar(input[0]);
	if (input.find_first_not_of("0123456789") == std::string::npos || (input.find_first_not_of("-0123456789") == std::string::npos && input.find_first_of("-") == 0 && input.find_last_of("-") == 0))
		return (convertInt(input));
	if (input == "nan" || input == "+inf" || input == "-inf" || (input.find_first_not_of("0123456789.") == std::string::npos && input.find_first_of(".") != std::string::npos && input.find_first_of(".") == input.find_last_of("."))
	|| (input.find_first_not_of("0123456789.-") == std::string::npos && input.find_first_of("-") == 0 && input.find_last_of("-") == 0 && input.find_first_of(".") != std::string::npos && input.find_first_of(".") == input.find_last_of(".")))
		return (convertDouble(input));
	if (input == "nanf" || input == "+inff" || input == "-inff" || (input.find_first_not_of("0123456789.f") == std::string::npos && input.find_first_of("f") == input.size() - 1 && input.find_first_of(".") != std::string::npos && input.find_first_of(".") == input.find_last_of("."))
	|| (input.find_first_not_of("0123456789.-") == std::string::npos && input.find_first_of("f") == input.size() - 1 && input.find_first_of("-") == 0 && input.find_last_of("-") == 0 && input.find_first_of(".") != std::string::npos && input.find_first_of(".") == input.find_last_of(".")))
		return (convertFloat(input));
	std::cout << "Invalid argument" << std::endl;
}

void ScalarConverter::convertChar(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertInt(std::string input)
{
	double d = atof(input.c_str());
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
	{
		std::cout << "Invalid integer literal" << std::endl;
		return ;
	}
	int i = atoi(input.c_str());
	switch (i)
	{
	case 0 ... 31:
		std::cout << "char: Not displayable" << std::endl;
		break;
	case 32 ... 126:
		std::cout << "char: " << static_cast<char>(i) << std::endl;
		break;
	case 127 ... 255:
		std::cout << "char: Not displayable" << std::endl;
		break;
	default:
		std::cout << "char: Impossible" << std::endl;
		break;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void ScalarConverter::convertFloat(std::string input)
{
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		return ;
	}
	double d = atof(input.c_str());
	if ((d > 0 && d > std::numeric_limits<float>::max()) || (d < 0 && (d < std::numeric_limits<float>::min())))
	{
		std::cout << "Invalid float literal" << std::endl;
		return ;
	}
	int c = 0;
	if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		c = 1;
	switch (c)
	{
		case 0:
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			break;
		case 1:
			int i = static_cast<int>(d);
			switch(i)
			{
				case 0 ... 31:
					std::cout << "char: Not displayable" << std::endl;
					break;
				case 32 ... 126:
					std::cout << "char: " << static_cast<char>(i) << std::endl;
					break;
				case 127 ... 255:
					std::cout << "char: Not displayable" << std::endl;
					break;
				default:
					std::cout << "char: Impossible" << std::endl;
					break;
			}
			std::cout << "int: " << i << std::endl;
			break;
	}
	std::string ext;
	if (d == floor(d))
		ext = ".f";
	else
		ext = "f";
	std::cout << "float: " << static_cast<float>(d) << ext << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertDouble(std::string input)
{
	if (input == "nan" || input == "+inf" || input == "-inf")
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
		std::cout << "float: " << input + "f"<< std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}
	double d = atof(input.c_str());
	int c = 0;
	if (d <= std::numeric_limits<int>::max() && d >= std::numeric_limits<int>::min())
		c = 1;
	switch (c)
	{
		case 0:
			std::cout << "char: Impossible" << std::endl;
			std::cout << "int: Impossible" << std::endl;
			break;
		case 1:
			int i = static_cast<int>(d);
			switch(i)
			{
				case 0 ... 31:
					std::cout << "char: Not displayable" << std::endl;
					break;
				case 32 ... 126:
					std::cout << "char: " << static_cast<char>(i) << std::endl;
					break;
				case 127 ... 255:
					std::cout << "char: Not displayable" << std::endl;
					break;
				default:
					std::cout << "char: Impossible" << std::endl;
					break;
			}
			std::cout << "int: " << i << std::endl;
			break;
	}
	std::string ext;
	if (d == floor(d))
		ext = ".f";
	else
		ext = "f";
	std::cout << "float: " << static_cast<float>(d) << ext << std::endl;
	std::cout << "double: " << d << std::endl;
}



ScalarConverter::~ScalarConverter()
{
}