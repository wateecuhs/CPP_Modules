/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:32:57 by panger            #+#    #+#             */
/*   Updated: 2024/03/14 16:22:28 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

std::string	getInput(std::string prefix)
{
	std::string input;
	while (input == "")
	{
		std::cout << prefix;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << "\n";
			return NULL;
		}
	}
	return (input);
}

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

std::string	Contact::getLastName()
{
	return (this->lastName);
}

std::string	Contact::getNickName()
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkestSecret);
}


void	Contact::printContact()
{
	if (this->firstName.length() > 10){
		std::cout << std::setfill(' ') << std::setw(9);
		std::cout << this->firstName.substr(0, 8) << ".|";
	}
	else {
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << this->firstName << "|";
	}
	if (this->lastName.length() > 10) {
		std::cout << std::setfill(' ') << std::setw(9);
		std::cout << this->lastName.substr(0, 8) << ".|";
	}
	else {
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << this->lastName << "|";
	}
	if (this->nickName.length() > 10) {
		std::cout << this->nickName.substr(0, 8) << ".|\n";
		std::cout << std::setfill(' ') << std::setw(9);
	}
	else {
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << this->nickName << "|\n";
	}
}

void	Contact::setValues(void)
{
	std::string input;

	input = getInput("Enter first name: ");
	this->firstName = input;
	input = getInput("Enter last name: ");
	this->lastName = input;
	input = getInput("Enter nickname: ");
	this->nickName = input;
	input = getInput("Enter phone number: ");
	this->phoneNumber = input;
	input = getInput("Enter darkest secret: ");
	this->darkestSecret = input;
}

void	Contact::printInfos()
{
	std::cout << "First name: " << this->firstName << "\n";
	std::cout << "Last name: " << this->lastName << "\n";
	std::cout << "Nickname: " << this->nickName << "\n";
	std::cout << "Phone number: " << this->phoneNumber << "\n";
	std::cout << "Darkest secret: " << this->darkestSecret << "\n";
}