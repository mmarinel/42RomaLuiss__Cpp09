/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_pair.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:49:06 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/12 19:58:03 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mis_pair.hpp"

template <typename T>
bool    mis_pair<T>::operator<(const mis_pair<T>& other)
{
    return (this->bigger < other.bigger);
}

template <typename T>
bool    mis_pair<T>::operator>(const mis_pair<T>& other)
{
    return (this->bigger > other.bigger);
}

template <typename T>
bool    mis_pair<T>::operator==(const mis_pair<T>& other)
{
    return (this->bigger == other.bigger);
}


template <typename T>
mis_pair<T>::mis_pair( T smaller, T bigger, bool last_not_used )
{
    this->smaller = smaller;
    this->bigger = bigger;
    this->last_not_used = last_not_used;
}

template <typename T>
mis_pair<T>::mis_pair( void )
{
    this->smaller = T();
    this->bigger = T();
    this->last_not_used = false;
}

template <typename T>
mis_pair<T>::mis_pair(const mis_pair<T>& copy)
{
    *this = copy;
}

template <typename T>
mis_pair<T>& mis_pair<T>::operator=(const mis_pair<T>& copy)
{
    this->smaller = copy.smaller;
    this->bigger = copy.bigger;
    this->last_not_used = copy.last_not_used;
}

template  <typename T>
mis_pair<T>::~mis_pair( void )
{
    //* intentionally left blank
}
