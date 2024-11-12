/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:29:24 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 17:55:55 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"


//=== Utils ===


//This function is used to check floats/doubles scientific writing, using double because double is bigger.
bool	is_scientific(double d)
{
	std::ostringstream strstream;
	strstream << d;
	std::string str(strstream.str());

	//checking for nan and then +inf/-inf
	if (d != d || d == std::numeric_limits<float>::infinity() || d == -std::numeric_limits<float>::infinity())
		return (true);
	
	//checking for powers
	return (str.find(".") == std::string::npos && str.find("e") != std::string::npos);
}

bool	is_pseudo_literal_float(std::string str)
{
	return (str == "+inff" || str == "-inff" || str == "nanf");
}

bool	is_pseudo_literal_double(std::string str)
{
	return (str == "+inf" || str == "-inf" || str == "nan");
}