/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:58:57 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/23 17:14:11 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
# define BTC_HPP

//*		INCLUDES
#include <list>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstring>
#include "../colors.hpp"

//*		TYPEDEFs
typedef struct s_db_entry
{
	unsigned long long	intDate;
	float				exch_rate;

	bool				operator<(const struct s_db_entry other) const
	{
		return (this->intDate < other.intDate);
	}
}	t_db_entry;

//*		GLOBALS
extern std::list<t_db_entry>		db;
extern const float 					max_precision;

//*		Function Prototypes
void				load_db( void );
void				read_input_and_print(const char* path);
unsigned long long	date_as_integral(const std::string date);

#endif