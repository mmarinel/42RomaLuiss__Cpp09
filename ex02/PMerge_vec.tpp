/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMerge_vec.tpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:25 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/21 19:34:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_VEC_TPP
# define PMERGE_VEC_TPP

#include "PMergeMe.hpp"

template <typename T>
void	PMergeMe<T>:: _bs_insert( std::vector<T>& vec, T el )
{
	int	middle;
	int	vec_start, vec_end;

	vec_start = 0;
	vec_end = vec.size() - 1;
	while (vec_start <= vec_end)
	{
		middle = std::floor((vec_end + vec_start) / 2.0f);

		if (el > vec[middle])
			vec_start = middle + 1;
		else
			vec_end = middle - 1;		
	}
	if (vec_end != middle)
	//before pos;
		vec.insert(vec.begin() + middle, el);
	else
	{
	//after pos;
		if (vec.end() == vec.begin() + middle + 1)
			vec.push_back(el);
		else
			vec.insert(vec.begin() + middle + 1, el);
	}
}

//************************************************************************** //


//*		UTILITIES

template <typename T>
void	PMergeMe<T>:: _add_vec_pair( size_t pos, size_t argc, char const *argv[] )
{
	if (pos < argc - 1)
	this->vec_pairs.push_back(
		MisPair<T>(
			std::atoi( argv[pos]), std::atoi(argv[pos + 1]), false )
		);
	else
		this->vec_pairs.push_back(
			MisPair<T>( std::atoi(argv[pos]), 0, true )
		);
}

#endif