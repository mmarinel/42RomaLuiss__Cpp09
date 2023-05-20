/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:01:03 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/20 15:33:03 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

#include "PMergeMe.hpp"


//*		UTILITIES
template <typename T>
PMergeMe<T>::PMergeMe( size_t argc, char const *argv[] )
{
	size_t  i;

	this->vec_pairs.reserve(argc / 2);
	this->ordered_vec.reserve(argc);
	i = 1;
	while (i < argc)
	{
		if (
			false == isVaildNumberString(argv[i]) ||
			( i < argc - 1 && false == isVaildNumberString(argv[i + 1]) )
			)
			throw (PMergeMe<T>::InvalidSequenceException());
		else
		{
			_add_vec_pair(i, argc, argv);
			_add_deq_pair(i, argc, argv);
		}
		i += 2;
	}
}

template <typename T>
void	PMergeMe<T>::sortVec ( void )
{
	_order_pairs(this->vec_pairs);
	_merge_pairs(this->vec_pairs, this->ordered_vec);
}

template <typename T>
void	PMergeMe<T>::sortDeq ( void )
{
	_order_pairs(this->deque_pairs);
	_merge_pairs(this->deque_pairs, this->ordered_deque);
}

template <typename T>
template <typename C>
void	PMergeMe<T>::_order_pairs( C& collection )
{
	size_t			i;
	int				j;
	mis_pair<T>		backup;

	for (i = 0; i < collection.size(); i++)
		collection[i].sortPair();
	for (i = 0; i < collection.size(); i++)
	{
		backup = collection[i];
		j = i - 1;
		for (; j >= 0; j--)
		{
			if (collection[j] > backup)
				collection[j + 1] = collection[j];
			else
				break ;
		}
		collection[j + 1] = backup;
	}

}

template <typename T>
template <typename CPair, typename C>
void	PMergeMe<T>::_merge_pairs( CPair& cpairs, C& collection )
{
	size_t	offset;
	size_t	group_size;

	collection.push_back(cpairs[0].getSmaller());
	for (int i = 0; i < (int) cpairs.size(); i++)
		if (false == cpairs[i].isUnpaired())
			collection.push_back(cpairs[i].getBigger());
	offset = 1;
	group_size = 2;
	for (int i = 1; ; i++)
	{
		if (offset > cpairs.size() - 1)
			break ;
		for (
			int j = offset + group_size - 1 > cpairs.size() - 1
				? cpairs.size() - 1
				: offset + group_size - 1;
			j >= (int) offset;
			j --)
			_bs_insert(collection, cpairs[j].getSmaller());
		offset = offset + group_size;
		group_size = pow(2, i + 1) - group_size;
	}
}

//************************************************************************** //


//*		UTILITIES
template <typename T>
void    PMergeMe<T>::debug( void )
{
    size_t  j;

	sortVec();
	sortDeq();

	std::cout << "Ad std::vector" << std::endl;
	for (j = 0; j < this->ordered_vec.size(); j++)
	{
		std::cout << this->ordered_vec[j] << std::endl;
	}
	std::cout << std::endl << std::endl;

	std::cout << "Ad std::deque" << std::endl;
	for (j = 0; j < this->ordered_deque.size(); j++)
	{
		std::cout << this->ordered_deque[j] << std::endl;
	}
	std::cout << std::endl << std::endl;
}

template <typename T>
const char* PMergeMe<T>::InvalidSequenceException::what( void ) const throw()
{
    return ("err: invalid input sequence");
}

template <typename T>
bool    PMergeMe<T>::isVaildNumberString( const char *numberString )
{
    size_t  i;

    i = 0;
    while (numberString[i])
    {
        if (0 == std::isdigit(numberString[i]))
            return (false);
        i++;
    }
    return (true);
}
//************************************************************************** //


//*		CANONICAL FORM
template <typename T>
PMergeMe<T>::PMergeMe( void )
{
}

template <typename T>
PMergeMe<T>::PMergeMe( const PMergeMe<T>& copy )
{
    *this = copy;
}

template <typename T>
PMergeMe<T>&    PMergeMe<T>::operator=( const PMergeMe<T>& copy )
{
    this->vec_pairs = copy.vec_pairs;
    this->list_pairs = copy.list_pairs;
    this->ordered_vec = copy.ordered_vec;
    this->ordered_list = copy.ordered_list;

    return (*this);
}

template <typename T>
PMergeMe<T>::~PMergeMe( void )
{
}
//************************************************************************** //

#endif