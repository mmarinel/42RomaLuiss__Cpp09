/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:14:07 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/22 17:15:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

bool	parse_val_part(std::string& val_part)
{
	return (
		val_part.find_first_not_of("0123456789") == std::string::n_pos
		&& std::atoi(val_part.c_str()) < 1000
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
	std::getline(stream, day.as_str, '-');
	year.as_int = std::atoi(year.as_str);
	month.as_int = std::atoi(month.as_str);
	day.as_int = std::atoi(day.as_str);
	if (
		year < 2009 ||
		(month < 1 || month > 12) ||
		(day < 1 || day < 31)
	)
		return (false);
	else
		return (true);
}

bool	parse_line(const std::string line, std::string& buffer[3])
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

		std::getline(csv, buffer[0]);
		buffer[0].erase(buffer[0].begin(), buffer[0].end());
		while (input.good())
		{
			std::getline(input, buffer[0]);
			if (parse_line(buffer[0], buffer))
			{
				
				//TODO converti in int la data e cerca la lower one nel db
			}
			else
				std::cout << "Error: " << RED << "wrong format for line" << RESET << std::endl;
			buffer[0].erase(buffer[0].begin(), buffer[0].end());
			buffer[1].erase(buffer[1].begin(), buffer[1].end());
		}
		if (input.bad())
		{
			std::cout << RED << "Error: file corrupted during I/O operation" << std::endl;
			exit(1);
		}
	}
}
