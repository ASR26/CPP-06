/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asolano- <asolano-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:44:50 by asolano-          #+#    #+#             */
/*   Updated: 2023/11/14 11:53:07 by asolano-         ###   ########.fr       */
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
		return convertChar(input);
	if ()

}

void ScalarConverter::convertChar(std::string)
{
	
}

void ScalarConverter::convertInt(std::string)
{
	
}

void ScalarConverter::convertFloat(std::string)
{
	
}

void ScalarConverter::convertDouble(std::string)
{
	
}



ScalarConverter::~ScalarConverter()
{
}