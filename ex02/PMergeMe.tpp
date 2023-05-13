/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:01:03 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/13 17:08:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
# define PMERGEME_TPP

#include "PMergeMe.hpp"

template <typename T>
PMergeMe<T>::PMergeMe( size_t argc, char const *argv[] )
{
    size_t  i;

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
            if (i < argc - 1)
                this->vec_pairs.push_back(mis_pair<T>(std::atoi(argv[i]), std::atoi(argv[i + 1]), false));
            else
                this->vec_pairs.push_back(mis_pair<T>(std::atoi(argv[i]), 0, true));
        }
        i += 2;
    }
}

template <typename T>
void    PMergeMe<T>::debug( void )
{
    size_t  j;

    for (j = 0; j < this->vec_pairs.size(); j++)
    {
        std::cout << this->vec_pairs[j] << std::endl;
    }
}

template <typename T>
const char* PMergeMe<T>::InvalidSequenceException::what( void ) const throw()
{
    return ("invalid input sequence");
}

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

#endif