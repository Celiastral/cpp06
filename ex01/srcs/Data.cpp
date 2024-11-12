/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:34 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 19:10:45 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"


//=== Orthodox class mandatory ===


Data::Data() : data("Default Data")
{
	std::cout << "Default Data constructor called" << std::endl;
}

Data::Data(std::string data) : data(data)
{
	std::cout << "Default Data constructor called" << std::endl;
}

Data::Data(const Data &other_Data)
{
	*this = other_Data;
	
	std::cout << "Copy Data constructor called" << std::endl;
}

Data	&Data::operator=(const Data &other_Data)
{
	data = other_Data.getData();

	std::cout << "Data Copy assignment operator called" << std::endl;
	return (*this);
}

Data::~Data()
{
	std::cout << "Default Data destructor called" << std::endl;
}


//=== Getter ===


std::string		Data::getData() const
{
	return (data);
}