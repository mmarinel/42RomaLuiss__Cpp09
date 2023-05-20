/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMerge_deq.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:28:19 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/20 15:30:08 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_DEQ_TPP
# define PMERGE_DEQ_TPP

#include "PMergeMe.hpp"

template <typename T>
void	PMergeMe<T>:: _bs_insert( std::deque<T>& deq, T el )
{
	int	middle;
	int	deq_start, deq_end;

	deq_start = 0;
	deq_end = deq.size() - 1;
	while (deq_start <= deq_end)
	{
		middle = std::floor((deq_end + deq_start) / 2.0f);

		if (el > deq[middle])
			deq_start = middle + 1;
		else
			deq_end = middle - 1;		
	}
	if (deq_end != middle)
	{
	//before pos;
		if (deq.begin() == deq.begin() + middle)
			deq.push_front(el);
		else
			deq.insert(deq.begin() + middle, el);
	}
	else
	{
	//after pos;
		if (deq.end() == deq.begin() + middle + 1)
			deq.push_back(el);
		else
			deq.insert(deq.begin() + middle + 1, el);
	}
}

//************************************************************************** //


//*		UTILITIES

template <typename T>
void	PMergeMe<T>:: _add_deq_pair( size_t pos, size_t argc, char const *argv[] )
{
	if (pos < argc - 1)
	this->deque_pairs.push_back(
		mis_pair<T>(
			std::atoi( argv[pos]), std::atoi(argv[pos + 1]), false )
		);
	else
		this->deque_pairs.push_back(
			mis_pair<T>( std::atoi(argv[pos]), 0, true )
		);
}

#endif