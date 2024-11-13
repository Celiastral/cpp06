/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:29:22 by eandre            #+#    #+#             */
/*   Updated: 2024/11/13 09:14:27 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <cerrno>
#include <limits>

class ScalarConverter
{
	public :

		//=== Converter ===

		static void convert(std::string str);

	private :
	
		//=== Orthodox class mandatory ===

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other_ScalarConverter);
		~ScalarConverter();
	
		ScalarConverter				&operator=(const ScalarConverter &other_ScalarConverter);
	
};

//=== Detect type ===

typedef enum e_type
{
	UNDEFINED = -1,
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3
}	t_type;

t_type	detect_type(std::string str);

//=== Convert by type ===

void	convert_char(std::string str);
void	convert_int(std::string str);
void	convert_float(std::string str);
void	convert_double(std::string str);

//=== Utils ===

bool	hasnt_dot(double d);
bool	is_pseudo_literal_float(std::string str);
bool	is_pseudo_literal_double(std::string str);

#endif