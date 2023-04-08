/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_pmerge.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:16:29 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/07 19:30:31 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmerge.hpp"

static void	mergeInsert_rec(
	std::vector<int>::iterator begin, std::vector<int>::iterator end
	);
static void	merge(
	std::vector<int>::iterator begin, std::vector<int>::iterator mid,
	std::vector<int>::iterator end
	);
//*		end of static declarations

void	mergeInsert_vector(const std::string& args)
{
	std::clock_t		before;
	std::clock_t		after;
	std::vector<int>	seq;
	const char*			_args;

	_args = args.c_str();
	while (*_args)
	{
		while (std::isspace(*_args))
			_args++;
		if (*_args)
			seq.push_back(std::atoi(_args));
		while (std::isdigit(*_args))
			_args++;
	}
	//*	DEBUG printVector(seq);
	before = std::clock();
	mergeInsert_rec(seq.begin(), seq.end());
	after = std::clock();
	std::cout
		<< "Time to process a range of "
		<< seq.size()
		<< " elements with std::vector : "
		<< (double)(after - before) / CLOCKS_PER_SEC
		<< std::endl;
}

static void	mergeInsert_rec(
	std::vector<int>::iterator begin, std::vector<int>::iterator end
	)
{
	std::vector<int>::difference_type	mid;

	if (end - begin <= THRESHOLD)
	{
		//TODO:		insertion sort
	}
	else
	{
		mid = (end - begin) / 2;
		mergeInsert_rec(begin, begin + mid);
		mergeInsert_rec(begin + mid, end);
		merge(begin, begin + mid, end);
	}
}

static void	merge(
	std::vector<int>::iterator begin, std::vector<int>::iterator mid,
	std::vector<int>::iterator end
	)
{
	std::vector<int>	left(begin, mid);
	std::vector<int>	right(mid, end);

	while ()
	{
		/* code */
	}
	
}
