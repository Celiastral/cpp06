/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:37:32 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 20:44:22 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

int	main(int argc, char **argv)
{
	// Serializer	serial_;

	if (argc > 1)
	{
		std::cout << "\033[0;32m#### ARG TESTS ####\033[0m" << std::endl;

		Data 		D(argv[1]);
		Data		D_deserialize;
		uintptr_t	Dataptr;
		std::string Data_value;

		Data_value = D.getData();
		std::cout << "Start value: " << Data_value << std::endl;
	
		Dataptr = Serializer::serialize(&D);
		D_deserialize = *Serializer::deserialize(Dataptr);
	
		Data_value = D_deserialize.getData();
		std::cout << "End value: " << Data_value << std::endl;

		if (D.getData() != D_deserialize.getData())
			std::cout << "\033[0;31mDATA IS WRONG 😡\033[0m" << std::endl;
		else
			std::cout << "\033[0;32mDATA IS GOOD 😄\033[0m" << std::endl;
	}


	std::cout << std::endl << "\033[0;32m#### DATA PTR IS NULL ####\033[0m" << std::endl;


	uintptr_t	Dataptr;

	Dataptr = Serializer::serialize(NULL);
	if (Serializer::deserialize(Dataptr) != NULL)
		std::cout << Serializer::deserialize(Dataptr)->getData() << std::endl;
	else
		std::cout << "\033[0;31mWARNING ! Dataptr is NULL\033[0m" << std::endl;
	

	std::cout << std::endl << "\033[0;32m#### UINT PTR IS EQUAL TO 0 ####\033[0m" << std::endl;


	Data		*D_deserialize;

	D_deserialize = Serializer::deserialize(0);
	if (D_deserialize != NULL)
		std::cout << Serializer::deserialize(Dataptr)->getData() << std::endl;
	else
		std::cout << "\033[0;31mWARNING ! UINT ptr is equal to 0\033[0m" << std::endl;
	delete D_deserialize;
}