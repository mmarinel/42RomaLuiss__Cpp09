/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:13:25 by earendil          #+#    #+#             */
/*   Updated: 2023/04/23 17:14:23 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btc.hpp"

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
