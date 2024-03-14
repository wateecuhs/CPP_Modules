/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:18:52 by panger            #+#    #+#             */
/*   Updated: 2024/03/14 11:31:32 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class Phonebook
{
private:
	Contact Contacts[8];
	int		contactCount;
public:
	Phonebook();
	~Phonebook();
	Contact	getContact(int index);
	int		getContactCount();
	void	listContact();
	void	addContact();
	void	printContactFromIndex(int index);
};


#endif