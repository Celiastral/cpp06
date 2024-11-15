/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:30 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 19:10:34 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <stdint.h>

class Data
{
	public:
	
		//=== Orthodox class mandatory ===

		Data();
		Data(std::string data);
		Data(const Data &other_Data);
		~Data();
	
		Data				&operator=(const Data &other_Data);

		//=== Getter ===

		std::string		getData() const;
	
	private:

		std::string		data;
};

#endif