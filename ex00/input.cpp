/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:14:07 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/23 17:31:26 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

bool	parse_val_part(std::string& val_part)
{

	std::string::iterator	spacesBegin = std::remove(val_part.begin(), val_part.end(), ' ');
	val_part.erase(spacesBegin, val_part.end());

	return (
		val_part.find_first_not_of("0123456789.") == std::string::npos &&
		std::find_if(val_part.begin(), val_part.end(), ::isdigit) != val_part.end() &&
		std::atof(val_part.c_str()) < 1000.0f
	);
}

bool	parse_date_part(std::string& date_part)
{
	typedef struct s_date_part
	{
		std::string		as_str;
		int				as_int;
	}	t_date_part;

	std::stringstream	stream(date_part);
	t_date_part			year;
	t_date_part			month;
	t_date_part			day;

	std::getline(stream, year.as_str, '-');
	std::getline(stream, month.as_str, '-');
	std::getline(stream, day.as_str, '-');//* inutile specificare '-'
	year.as_int = std::atoi(year.as_str.c_str());
	month.as_int = std::atoi(month.as_str.c_str());
	day.as_int = std::atoi(day.as_str.c_str());
	if (
		year.as_int < 2009 ||
		(month.as_int < 1 || month.as_int > 12) ||
		(day.as_int < 1 || day.as_int > 31)
	)
	{
		// std::cout << "date part parse failed\n";
		return (false);
	}
	else
		return (true);
}

bool	parse_line(const std::string line, std::string *buffer)
{
	std::stringstream	stream(line);

	if (NULL == std::strchr(line.c_str(), '|'))
		return (false);
	std::getline(stream, buffer[1], '|');
	std::getline(stream, buffer[2]);

	return (parse_date_part(buffer[1]) && parse_val_part(buffer[2]));
}

void	read_input_and_print(const char* path)
{
	std::ifstream	input(path);

	if (false == input.is_open())
	{
		std::cout << RED << "Error: could not open file" << RESET << std::endl;
		exit(1);
	}
	else
	{
		std::string	buffer[3];

		std::getline(input, buffer[0]);
		buffer[0].erase(buffer[0].begin(), buffer[0].end());
		while (input.good())
		{
			std::getline(input, buffer[0]);
			if (parse_line(buffer[0], buffer))
			{
				unsigned long long	dateAsInt = date_as_integral(buffer[1]);
				std::list<t_db_entry>::iterator back;

				back = db.begin();
				for (std::list<t_db_entry>::iterator it = db.begin(); it != db.end(); it++)
				{
					if ( (*it).intDate > dateAsInt )
					{
						std::cout << buffer[1] << " ==> " << buffer[2] << " = " << (*back).exch_rate * std::atof(buffer[2].c_str()) << std::endl;
						break;
					}
					back = it;
				}
				//TODO converti in int la data e cerca la lower one nel db
			}
			else
				std::cout << "Error: " << RED << "wrong format for line" << RESET << std::endl;
			buffer[0].erase(buffer[0].begin(), buffer[0].end());
			buffer[1].erase(buffer[1].begin(), buffer[1].end());
			buffer[2].erase(buffer[2].begin(), buffer[2].end());
		}
		if (input.bad())
		{
			std::cout << RED << "Error: file corrupted during I/O operation" << std::endl;
			exit(1);
		}
	}
}
