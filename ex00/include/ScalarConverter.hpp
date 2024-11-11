/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:29:22 by eandre            #+#    #+#             */
/*   Updated: 2024/11/11 18:25:44 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

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