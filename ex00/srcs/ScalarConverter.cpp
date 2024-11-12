/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:34:31 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 18:32:40 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"


//=== Orthodox class mandatory ===


ScalarConverter::ScalarConverter()
{
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other_ScalarConverter)
{
	(void)other_ScalarConverter;
	
	std::cout << "Copy ScalarConverter constructor called" << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other_ScalarConverter)
{
	(void)other_ScalarConverter;

	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Default ScalarConverter destructor called" << std::endl;
}

//=== Converter ===

void ScalarConverter::convert(std::string str)
{
	t_type	type;
	void (*convert_funcs[4])(std::string str) = 
	{
		&convert_char,
		&convert_int,
		&convert_float,
		&convert_double
	};


	if (str.empty())
	{
		std::cout << "\033[0;31mError ! String is empty !\033[0m" << std::endl;
		return ;
	}

	type = detect_type(str);
	if (type == UNDEFINED)
	{
		if (is_pseudo_literal_double(str))
			type = DOUBLE;
		else if (is_pseudo_literal_float(str))
			type = FLOAT;
		else
		{
			std::cout << "\033[0;31mError ! Type is undefined !\033[0m" << std::endl;
			return ;
		}
	}

	errno = 0;
	convert_funcs[type](str);
}


//=== Detect type ===


t_type	detect_type(std::string str)
{
	int	sign = 0;
	int	digit = 0;
	int	dot = 0;
	
	if (str.length() == 1 && isprint(str[0]) && (str[0] < '0' || str[0] > '9'))
		return (CHAR);
	
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == '-' || *it == '+')
			sign++;
		else if ((*it == '.' && (it) == str.begin()) || (sign == 1 && *it == '.' && (it - 1) == str.begin())
			|| (*it == '.' && (it + 1) == str.end()) || (*it == '.' && (it + 2) == str.end() && *(it + 1) == 'f'))
			return (UNDEFINED);
		else if (*it == '.')
			dot++;
		else if (*it >= '0' && *it <= '9')
			digit++;
		else if (!(dot == 1 && *it == 'f' && ((it + 1) == str.end())))
			return (UNDEFINED);
	}

	if (sign > 1 || dot > 1 || (sign == 1 && str[0] != '-' && str[0] != '+'))
		return (UNDEFINED);

	if ((dot == 1 && str[str.length() - 1] == 'f'))
		return (FLOAT);
	else if (dot == 1)
		return (DOUBLE);
	
	if (digit == 0)
		return (UNDEFINED);

	return (INT);
}