/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:29:22 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 16:02:27 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <cerrno>
#include <sstream>
#include <limits>

typedef enum e_type
{
	UNDEFINED = -1,
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3
}	t_type;

class ScalarConverter
{
	public :

		static void convert(std::string str);

	private :
	
		//=== Orthodox class mandatory ===

		ScalarConverter();
		ScalarConverter(const ScalarConverter &other_ScalarConverter);
		~ScalarConverter();
	
		ScalarConverter				&operator=(const ScalarConverter &other_ScalarConverter);
	
};

#endif