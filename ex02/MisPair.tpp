/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MisPair.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:49:06 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/21 19:29:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIS_PAIR_TPP
# define MIS_PAIR_TPP

#include "MisPair.hpp"

template <typename T>
bool	MisPair<T>:: isUnpaired( void )
{
	return (this->unpaired);
}

template <typename T>
void	MisPair<T>:: sortPair( void )
{
	T	backup;

	if (this->bigger < this->smaller)
	{
		backup = this->bigger;
		this->bigger = this->smaller;
		this->smaller = backup;
	}
}


template <typename T>
bool    MisPair<T>::operator<(const MisPair<T>& other) const
{
    return (this->bigger < other.bigger);
}

template <typename T>
bool    MisPair<T>::operator<=(const MisPair<T>& other) const
{
    return (this->bigger <= other.bigger);
}

template <typename T>
bool    MisPair<T>::operator>(const MisPair<T>& other) const
{
    return (this->bigger > other.bigger);
}

template <typename T>
bool    MisPair<T>::operator>=(const MisPair<T>& other) const
{
    return (this->bigger >= other.bigger);
}

template <typename T>
bool    MisPair<T>::operator==(const MisPair<T>& other) const
{
    return (
        this->bigger == other.bigger &&
        this->smaller == other.smaller
    );
}


template <typename T>
MisPair<T>::MisPair( T smaller, T bigger, bool unpaired )
{
    this->smaller = smaller;
    this->bigger = bigger;
    this->unpaired = unpaired;
}

template <typename T>
MisPair<T>::MisPair( void )
{
    this->smaller = T();
    this->bigger = T();
    this->unpaired = false;
}

template <typename T>
MisPair<T>::MisPair(const MisPair<T>& copy)
{
    *this = copy;
}

template <typename T>
MisPair<T>& MisPair<T>::operator=(const MisPair<T>& copy)
{
    this->smaller = copy.smaller;
    this->bigger = copy.bigger;
    this->unpaired = copy.unpaired;

    return (*this);
}

template  <typename T>
MisPair<T>::~MisPair( void )
{
    //* intentionally left blank
}

template  <typename T>
const T&	MisPair<T>::getSmaller( void ) const
{
	return (this->smaller);
}

template  <typename T>
const T&	MisPair<T>::getBigger( void ) const
{
	return (this->bigger);
}

#endif