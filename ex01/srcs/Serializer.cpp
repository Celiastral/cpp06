/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:37 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 20:45:03 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"


//=== Orthodox class mandatory ===


Serializer::Serializer()
{
	std::cout << "Default Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other_Serializer)
{
	(void)other_Serializer;
	
	std::cout << "Copy Serializer constructor called" << std::endl;
}

Serializer	&Serializer::operator=(const Serializer &other_Serializer)
{
	(void)other_Serializer;

	std::cout << "Serializer Copy assignment operator called" << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Default Serializer destructor called" << std::endl;
}


//=== Serialize and Deserialize ===


uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
