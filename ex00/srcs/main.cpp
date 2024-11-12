/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eandre <eandre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:33:12 by eandre            #+#    #+#             */
/*   Updated: 2024/11/12 20:43:38 by eandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	// ScalarConverter	convert_;

	if (argc > 1)
	{
		std::cout << "\033[0;32m#### ARG TESTS ####\033[0m" << std::endl;
		ScalarConverter::convert(argv[1]);
	}


	std::cout << std::endl << "\033[0;32m#### REGULAR CHAR ####\033[0m" << std::endl;
	ScalarConverter::convert("o");


	std::cout << std::endl << "\033[0;32m#### REGULAR INT ####\033[0m" << std::endl;
	ScalarConverter::convert("42");


	std::cout << std::endl << "\033[0;32m#### REGULAR FLOAT ####\033[0m" << std::endl;
	ScalarConverter::convert("42.0f");


	std::cout << std::endl << "\033[0;32m#### REGULAR DOUBLE ####\033[0m" << std::endl;
	ScalarConverter::convert("42.0");


	std::cout << std::endl << "\033[0;32m#### NAN ####\033[0m" << std::endl;
	ScalarConverter::convert("nan");


	std::cout << std::endl << "\033[0;32m#### NANF ####\033[0m" << std::endl;
	ScalarConverter::convert("nanf");


	std::cout << std::endl << "\033[0;32m#### +INFF ####\033[0m" << std::endl;
	ScalarConverter::convert("+inff");


	std::cout << std::endl << "\033[0;32m#### -INFF ####\033[0m" << std::endl;
	ScalarConverter::convert("-inff");


	std::cout << std::endl << "\033[0;32m#### +INF ####\033[0m" << std::endl;
	ScalarConverter::convert("+inf");


	std::cout << std::endl << "\033[0;32m#### -INF ####\033[0m" << std::endl;
	ScalarConverter::convert("-inf");


	std::cout << std::endl << "\033[0;32m#### NON EXISTING ####\033[0m" << std::endl;
	ScalarConverter::convert("aaaaaaaaa");


	std::cout << std::endl << "\033[0;32m#### NON EXISTING (dot version) ####\033[0m" << std::endl;
	ScalarConverter::convert("1.");

}