/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:49:25 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 21:48:35 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include "../include/D.hpp"
#include <cstdlib>

//Generate A, B or C with rand
Base *generate()
{
	int i;

	i = std::rand() % 3;

	switch (i)
	{
		case 0:
		{
			std::cout << std::endl << "\033[0;32mGenerating A..\033[0m" << std::endl;
			return (new A);
		}
		case 1:
		{
			std::cout << std::endl << "\033[0;32mGenerating B..\033[0m" << std::endl;
			return (new B);
		}
		default:
		{
			std::cout << std::endl << "\033[0;32mGenerating C..\033[0m" << std::endl;
			return (new C);
		}
	}
}

//Identify A, B or C on base pointer
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;

	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;

	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	
	else
		std::cout << "\033[0;31mError! This is not a normal base!\033[0m" << std::endl;

}

//Identify A, B or C on base reference
void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cout << "\033[0;31mError! This is not a normal base!\033[0m" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	D		d;

	srand(time(NULL));
	std::cout << "\033[0;32m#### NOT NORMAL BASE ####\033[0m" << std::endl;
	identify(&d);
	identify(d);

	if (argc > 1)
	{
		for (int i = 0; i < std::atoi(argv[1]); i++)
		{
			Base	*base;
	
			base = generate();
			std::cout << "Identify pointer: ";
			identify(base);
			std::cout << "Identify reference: ";
			identify(*base);
			delete base;
		}
	}
}