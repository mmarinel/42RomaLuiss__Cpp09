/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:01:03 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/12 19:58:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

template <typename T>
bool    PMergeMe<T>::isVaildNumberString( const char *numberString )
{
    size_t  i;

    i = 0;
    while (numberString[i])
    {
        if (false == std::isdigit(numberString[i]))
            return (false);
        i++;
    }
    return (true);
}

template <typename T>
PMergeMe<T>::PMergeMe( int argc, char const *argv[] )
{
    size_t  i;

    i = 0;
    while (i < argc)
    {
        if (false == isVaildNumberString(argv[i]))
            throw (PMergeMe<T>::InvalidSequenceException())
        else
        {
            if (i < argc - 1)
                this->vec_pairs.push_back(mis_pair<T>(argv[i], argv[i + 1], false));
            else
                this->vec_pairs.push_back(mis_pair<T>(argv[i], 0, true));
        }
        i += 2;
    }
}

template <typename T>
PMergeMe<T>::PMergeMe( void )
{
}
