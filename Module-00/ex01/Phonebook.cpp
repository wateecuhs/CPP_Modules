/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:49:46 by panger            #+#    #+#             */
/*   Updated: 2024/03/14 16:35:42 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "Phonebook.hpp"
#include <iostream>

Phonebook::Phonebook()
{
	this->contactCount = 0;
}

Phonebook::~Phonebook() {}

void	Phonebook::addContact()
{
	this->Contacts[this->contactCount % 8].setValues();
	this->contactCount++;
}

Contact	Phonebook::getContact(int index)
{
	return (this->Contacts[index]);
}

int	Phonebook::getContactCount(void)
{
	return (this->contactCount);
}


void	Phonebook::listContact(void)
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "index" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "first name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "last name" << "|";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << "nickname" << "|" << "\n";
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setfill(' ') << std::setw(10);
		std::cout << i + 1 << "|";
		this->getContact(i).printContact();
	}
}

void	Phonebook::printContactFromIndex(int index)
{
	if (index >= 1 && index <= 8 && index <= this->contactCount)
	{
		this->getContact(index - 1).printInfos();
	}
	else
		std::cout << "Invalid index value\n";
}