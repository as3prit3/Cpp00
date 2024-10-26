/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhadhadi <marvin@42>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:29:43 by hhadhadi          #+#    #+#             */
/*   Updated: 2024/09/30 13:49:55 by hhadhadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Phone.hpp"

int		main()
{
	PhoneBook	phoneBook;
	std::string	str;

	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, str);
		if (str == "ADD")
			phoneBook.addContact();
		else if (str == "SEARCH")
			phoneBook.searchContact();
		else if (str == "EXIT" || std::cin.eof())
			break ;
		std::cin.clear();
	}
	return (0);
}