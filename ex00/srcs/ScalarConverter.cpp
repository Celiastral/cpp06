/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:34:31 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 18:24:07 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

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


static void ScalarConverter::convert(std::string str)
{
	str.
}