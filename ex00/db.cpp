/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:58:25 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/22 16:12:05 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

static unsigned long long	date_as_integral(const std::string date);
//*		end of static declarations

void	load_db( void )
{
	std::ifstream	csv ("data.csv");

	if (false == csv.is_open())
	{
		std::cout << RED << "Error: could not open file" << RESET << std::endl;
		exit(1);
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
			db.push_back(
				(t_db_entry){
					date_as_integral(buffer[0]),
					(float)std::atof(buffer[1].c_str())
					});
			buffer[0].erase(buffer[0].begin(), buffer[0].end());
			buffer[1].erase(buffer[1].begin(), buffer[1].end());
		}
		if (csv.bad())
		{
			std::cout << RED << "Error: file corrupted during I/O operation" << std::endl;
			exit(1);
		}
	}
}

unsigned long long	date_as_integral(const std::string date)
{
	std::stringstream	stream(date);
	std::string			as_string;
	std::string			year;
	std::string			month;
	std::string			day;

	std::getline(stream, year, '-');
	std::getline(stream, month, '-');
	std::getline(stream, day, '-');

	as_string = year + month + day;

	return (std::atol(as_string.c_str()));
}
