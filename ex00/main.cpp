/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:22:41 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/21 19:03:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "../colors.hpp"

std::map<std::string, float>	db;

bool	load_db( void )
{
	std::ifstream	csv ("data.csv");

	if (false == csv.is_open())
	{
		std::cout << RED << "Error: could not open file" << RESET << std::endl;
		return (false);
	}
	else
	{
		std::string	buffer[2];

		std::getline(csv, buffer[0]);
		buffer[0].erase(buffer[0].begin(), buffer[0].end());
		while (csv.good())
		{
			std::getline(csv, buffer[0], ',');
			std::getline(csv, buffer[1]);
			db.insert(std::pair<std::string, float>(buffer[0], std::atof(buffer[1].c_str())));
			buffer[0].erase(buffer[0].begin(), buffer[0].end());
			buffer[1].erase(buffer[1].begin(), buffer[1].end());
		}
		if (csv.bad())
		{
			std::cout << RED << "Error: file corrupted during I/O operation" << std::endl;
			return (false);
		}
		else
			return (true);
	}
}


int	main(int argc, char* argv[])
{(void)argc; (void)argv;

	load_db();
	for (std::map<std::string, float>::iterator it = db.begin(); it != db.end(); it++)
		std::cout << (*it).first << ", " << (*it).second << std::endl;
	std::cout << std::endl;

	return (0);
}