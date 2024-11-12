/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:27 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 20:42:21 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	public :

		//=== Serialize and Deserialize ===

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private :
	
		//=== Orthodox class mandatory ===

		Serializer();
		Serializer(const Serializer &other_Serializer);
		~Serializer();
	
		Serializer				&operator=(const Serializer &other_Serializer);

};

#endif