/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:22:41 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/22 12:33:15 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include "../colors.hpp"

std::list<t_db_entry>			db;
const float 					max_precision = std::numeric_limits<float>::digits10 + 1;

typedef struct s_db_entry
{
	unsigned long long	intDate;
	float				exch_rate;

	bool				operator<(const struct s_db_entry other)
	{
		return (this->intDate < other.intDate);
	}
}	t_db_entry;

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
	// std::cout << as_string << std::endl;

	return (std::atol(as_string.c_str()));
}

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
			// std::cout << date_as_integral(buffer[0]) << std::endl;
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
			return (false);
		}
		else
			return (true);
	}
}


int	main(int argc, char* argv[])
{(void)argc; (void)argv;

	load_db();
	// db.sort(db_entry_less_than);
	db.sort();
	for (std::list<t_db_entry>::iterator it = db.begin(); it != db.end(); it++)
		std::cout << std::setprecision(max_precision) << (*it).intDate << ", " << (*it).exch_rate << std::endl;
	std::cout << std::endl;

	return (0);
}