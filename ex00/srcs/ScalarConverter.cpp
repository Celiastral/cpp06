/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:34:31 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 17:00:34 by eandre           ###   ########.fr       */
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

static void	convert_char(std::string str)
{
	char	c = str[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;

}

static bool	is_scientific(double d)
{
	std::ostringstream strstream;
	strstream << d;
	std::string str(strstream.str());

	if (d != d || d == std::numeric_limits<float>::infinity() || d == -std::numeric_limits<float>::infinity())
		return (true);
	
	return (str.find(".") == std::string::npos && str.find("e") != std::string::npos);
}

static void	convert_int(std::string str)
{
	long int	tmp_long;
	int			i;
	float		f;
	double		d;

	
	tmp_long = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE || tmp_long > std::numeric_limits<int>::max() || tmp_long < std::numeric_limits<int>::min())
	{
		std::cout << "\033[0;31mError ! Int overflow !\033[0m" << std::endl;
		return ;
	}
	i = static_cast<int>(tmp_long);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	std::cout << "int: " << i << std::endl;

	if (is_scientific(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	if (is_scientific(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

static void	convert_double(std::string str)
{
	double		d;

	d = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "\033[0;31mError ! Double overflow !\033[0m" << std::endl;
		return ;
	}

	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min() || str == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || str == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if ((d > std::numeric_limits<float>::max() || d < std::numeric_limits<float>::min()) && str.find('.') == std::string::npos)
		std::cout << "float: impossible" << std::endl;
	else if (is_scientific(static_cast<float>(d)))
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;

	if (is_scientific(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

static void	convert_float(std::string str)
{
	float	f;
	double	d;
	double	tmp_double;

	tmp_double = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE ||((tmp_double > std::numeric_limits<float>::max() || tmp_double < std::numeric_limits<float>::min()) && str.find('.') == std::string::npos))
	{
		std::cout << "\033[0;31mError ! Float overflow !\033[0m" << std::endl;
		return ;
	}
	f = static_cast<float>(tmp_double);
	d = static_cast<double>(f);

	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min() || str == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || str == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	if (is_scientific(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	if (is_scientific(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;

	return ;
}

static bool	is_pseudo_literal_float(std::string str)
{
	return (str == "+inff" || str == "-inff" || str == "nanf");
}

static bool	is_pseudo_literal_double(std::string str)
{
	return (str == "+inf" || str == "-inf" || str == "nan");
}

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
	convert_funcs[type](str);
}