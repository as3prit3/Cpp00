/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadhadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:29:47 by hhadhadi          #+#    #+#             */
/*   Updated: 2024/11/28 16:33:50 by hhadhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phone.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string str)
{
	firstName = str;
}

void	Contact::setLastName(std::string str)
{
	lastName = str;
}

void	Contact::setNickName(std::string str)
{
	nickName = str;
}

void	Contact::setPhoneNumber(std::string str)
{
	phoneNumber = str;
}

void	Contact::setDarkestSecret(std::string str)
{
	darkestSecret = str;
}

std::string	Contact::getFirstName()
{
	return (firstName);
}

std::string	Contact::getLastName()
{
	return (lastName);
}

std::string	Contact::getNickName()
{
	return (nickName);
}

std::string	Contact::getPhoneNumber()
{
	return (phoneNumber);
}

std::string	Contact::getDarkestSecret()
{
	return (darkestSecret);
}

void	Contact::displayContact()
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickName << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

PhoneBook::PhoneBook()
{
	contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

int	FillInput(std::string text, Contact &contact)
{
	std::string str;
	std::cout << text;
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << "\nInput interrupted." << std::endl;
		std::cin.ignore();
		std::cin.clear();
		return 0;
	}
	if (text == "Enter first name: ")
		contact.setFirstName(str);
	else if (text == "Enter last name: ")
		contact.setLastName(str);
	else if (text == "Enter nickname: ")
		contact.setNickName(str);
	else if (text == "Enter phone number: ")
		contact.setPhoneNumber(str);
	else if (text == "Enter darkest secret: ")
		contact.setDarkestSecret(str);
	return 1;
}

Contact	saveContact()
{
	Contact contact;
	if (!FillInput("Enter first name: ", contact) || !FillInput("Enter last name: ", contact) \
		|| !FillInput("Enter nickname: ", contact) || !FillInput("Enter phone number: ", contact) \
		|| !FillInput("Enter darkest secret: ", contact))
		return contact;
	return contact;
}

bool isNumeric(std::string str)
{
	if (str.length() != 10)
		return false;
	for (size_t i = 0; i < str.length(); i++)
		if (!isdigit(str[i]))
			return false;
    return true;
}

bool	isAlpha(std::string str)
{
	if (str[0] == ' ')
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((!isalpha(str[i]) && str[i] != ' ') || (str[i] == ' ' && str[i + 1] == ' '))
			return false;

	}
	return true;
}

void	PhoneBook::addContact()
{
	Contact contact = saveContact();
	if (contact.getFirstName().empty() || contact.getLastName().empty() \
		|| contact.getNickName().empty() || contact.getPhoneNumber().empty() \
		|| contact.getDarkestSecret().empty() || !isNumeric(contact.getPhoneNumber())
		|| !isAlpha(contact.getFirstName()) || !isAlpha(contact.getLastName()))
	{
		std::cout << "Can't save contact" << std::endl;
		return ;
	}
	if (contactCount == 8)
	{
		static int i = 0;
		contacts[i] = contact;
		i = (i + 1) % 8;
	}
	else
	{
		contacts[contactCount] = contact;
		contactCount++;
	}
}

void	PhoneBook::searchContact()
{
	if (contactCount == 0)
	{
		displayContacts();
		return ;
	}
	displayContacts();
	std::string str;
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cin.ignore();
		std::cin.clear();
		return ;
	}
	if (str.length() > 1 || str[0] < '0' || str[0] > '7')
	{
		std::cout << "Invalid index" << std::endl;
		return ;
	}
	int index = str[0] - '0';
	contacts[index].displayContact();
}

std::string formatColumn(const std::string &text, size_t width) {
	if (text.length() > width)
		return text.substr(0, width - 1) + ".";
	else
		return text;
}

void	PhoneBook::displayContacts()
{

	std::cout << std::setw(10) << "Index"  << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nick Name" << "|" << std::endl;
	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << formatColumn(contacts[i].getNickName(), 10) << "|" << std::endl;
	}
}
