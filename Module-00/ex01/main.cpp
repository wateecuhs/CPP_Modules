/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:18:17 by panger            #+#    #+#             */
/*   Updated: 2024/03/14 16:32:23 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Phonebook.hpp"
#include <iomanip>

int	main(void)
{
	std::string	input;
	Phonebook	Phonebook;
    int 		number;
	
	std::cout << "Welcome to the phonebook\n";
	std::cout << "You can ADD, SEARCH or EXIT\n";
	std::cout << ">>>";
	while (std::getline(std::cin, input))
	{
		if (std::cin.eof() || input == "EXIT") {
			break ;
		}
		if (input == "ADD") {
			Phonebook.addContact();
		}
		else if (input == "SEARCH") {
			Phonebook.listContact();
			std::cout << "Enter the index of the contact you wish to see\n";
			std::getline(std::cin, input);
			std::istringstream iss(input);
			if (iss >> number) {
				Phonebook.printContactFromIndex(number);
			} else {
				std::cout << "Input is not a number" << std::endl;
			}
		}
		else if (input != "") {
			std::cout << "Invalid command\n";
		}
		std::cout << ">>>";
	}
	if (std::cin.eof())
		std::cout << "\n";
	std::cout << "Goodbye\n";
}
