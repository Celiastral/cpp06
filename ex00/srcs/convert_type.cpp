/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_type.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:30:19 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 18:32:23 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"


//=== Convert by type ===


//Convert char will convert the string using static_cast, this one is by far the easiest because it doesnt requires much effort to parse potential errors.
void	convert_char(std::string str)
{
	char	c = str[0];


	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

//Convert int will also convert the string using static_cast, but this time we need to handle more errors.
void	convert_int(std::string str)
{
	long int	tmp_long = 0;
	int			i = 0;
	float		f = 0;
	double		d = 0;

	
	//convert string to long to avoid annoying int overflows (and also because atoi doesnt use errno)
	tmp_long = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE || tmp_long > std::numeric_limits<int>::max() || tmp_long < std::numeric_limits<int>::min())
	{
		std::cout << "\033[0;31mError ! Int overflow !\033[0m" << std::endl;
		return ;
	}

	//usual static_cast
	i = static_cast<int>(tmp_long);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	//check for char overflow, then for printability
	if (i > std::numeric_limits<char>::max() || i < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(i)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;

	//int doesnt need check on this part because it was done before
	std::cout << "int: " << i << std::endl;

	//check if float is in scientific writing, to avoid puting .0f after a power of 10
	if (is_scientific(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	//check if double is in scientific writing, to avoid puting .0 after a power of 10
	if (is_scientific(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

//Convert float will also convert the string using static_cast, but this time we need to handle more errors too.
void	convert_float(std::string str)
{
	float	f = 0;
	double	d = 0;
	double	tmp_double = 0;

	//convert string to double because there is no method for converting in floats (even atof doesn't really convert to float and also doesn't use errno)
	tmp_double = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "\033[0;31mError ! Float overflow !\033[0m" << std::endl;
		return ;
	}

	//usual static_cast
	f = static_cast<float>(tmp_double);
	d = static_cast<double>(f);

	//check for char overflow, then for printability, but keeping in mind nanf exist for the floats
	if (f > std::numeric_limits<char>::max() || f < std::numeric_limits<char>::min() || str == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

	//check for int overflow and nanf to avoid problems
	if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || str == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;

	//check if float is in scientific writing, to avoid puting .0f after a power of 10 or in case of inff/nanf
	if (is_scientific(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	//check if double is in scientific writing, to avoid puting .0 after a power of 10 or in case of inf/nan
	if (is_scientific(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

void	convert_double(std::string str)
{
	double		d = 0;
	float		f = 0;

	//convert string to double
	d = std::strtod(str.c_str(), NULL);
	if (errno == ERANGE)
	{
		std::cout << "\033[0;31mError ! Double overflow !\033[0m" << std::endl;
		return ;
	}

	//usual static_cast
	f = static_cast<float>(d);

	//check for char overflow, then for printability, but keeping in mind nan exist for the doubles
	if (d > std::numeric_limits<char>::max() || d < std::numeric_limits<char>::min() || str == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

	//check for int overflow and nan to avoid problems
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || str == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;

	if (is_scientific(f))
		std::cout << "float: " << f << "f" << std::endl;
	else
		std::cout << "float: " << f << ".0f" << std::endl;

	//check if double is in scientific writing, to avoid puting .0 after a power of 10 or in case of inf/nan
	if (is_scientific(d))
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}