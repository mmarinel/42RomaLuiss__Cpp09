/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:58:57 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/22 16:13:40 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
# define BTC_HPP

//*		INCLUDES
#include <list>
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

	bool				operator<(const struct s_db_entry other)
	{
		return (this->intDate < other.intDate);
	}
}	t_db_entry;

//*		GLOBALS
extern std::list<t_db_entry>		db;
extern const float 					max_precision;

//*		Function Prototypes
void	load_db( void );

#endif