/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:22:41 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/22 16:14:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

std::list<t_db_entry>			db;
const float 					max_precision = std::numeric_limits<float>::digits10 + 1;


int	main(int argc, char* argv[])
{(void)argv;

	if (2 == argc)
	{
		load_db();
		// db.sort(db_entry_less_than);
		db.sort();
		// for (std::list<t_db_entry>::iterator it = db.begin(); it != db.end(); it++)
		// 	std::cout << std::setprecision(max_precision) << (*it).intDate << ", " << (*it).exch_rate << std::endl;
		// std::cout << std::endl;
		read_input_and_print(argv[1])
	}
	else
		std::cout << "Error: " << RED << "wrong number of arguments " << RESET << "(1 needed)" << std::endl;

	return (0);
}


















