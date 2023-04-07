/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:34:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/16 19:08:27 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

/**
 * @brief initializes stack as empty
 * 
 * @tparam T 
 */
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

/**
 * @brief initializes stack as having [size] elements default initialized
 * 
 * @tparam T 
 * @param size 
 */
template <typename T>
MutantStack<T>::MutantStack( size_t size ) : std::stack<T>() {
	for (size_t i = 0; i < size; i++)
		this->c.push_back(T());
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& copy ) {
	*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack<T>() {
	// this->c.erase(this->c.begin(), this->c.end());
	// while (false == this->c.empty())
	// 	this->c.pop_back();
	// __SIZE_TYPE__	stack_size;

	// stack_size = this->c.size();
	// for (size_t i = 0; i < stack_size; i++)
	// 	this->c.pop_back();
}

template <typename T>
const MutantStack<T>&	MutantStack<T>::operator=( const MutantStack<T>& assign ) {
	// this->~MutantStack();
	this->c = assign.c;

	return (*this);
}

template <typename T>
const T&	MutantStack<T>::top( void ) const {
	return (this->c.back());
}

template <typename T>
bool	MutantStack<T>::empty( void ) const {
	return (this->c.empty());
}

template <typename T>
__SIZE_TYPE__	MutantStack<T>::size( void ) const {
	return (this->c.size());
}

template <typename T>
void	MutantStack<T>::push( T el ) {
	this->c.push_back(el);
}

template <typename T>
void	MutantStack<T>::pop( void ) {
	this->c.pop_back();
}

/**
 * @brief this function returns an iterator
 * pointing to the first element of the mutant stack.
 * 
 * @tparam T 
 * @return MutantStack<T>::iterator 
 */
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return (iterator(this->c.begin()));
}

/**
 * @brief this function returns an iterator
 * pointing past the last element of the mutant stack.
 * 
 * @tparam T 
 * @return MutantStack<T>::iterator 
 */
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return (iterator(this->c.end()));
}

template <typename T>
std::ostream& operator<<( std::ostream &stream, const MutantStack<T> &mut_stack ) {
	//* we need copy because begin is not a const function, so we cannot call it on mut_stack
	MutantStack<T>						copy = mut_stack;
	typename MutantStack<T>::iterator	it;
	typename MutantStack<T>::iterator	begin = copy.begin();
	typename MutantStack<T>::iterator	end = copy.end();

	for (it = begin; it < end; it++)
		stream << it -  begin << "th element: " << *it << std::endl;

	return (stream);
}

#endif