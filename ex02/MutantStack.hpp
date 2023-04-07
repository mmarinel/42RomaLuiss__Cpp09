/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:08:47 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 20:19:46 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>
# include <stdexcept>

# include "../colors.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::deque<T>::iterator	iterator;
		
		// Constructors
		MutantStack();
		MutantStack( size_t size );
		MutantStack( const MutantStack &copy );
		
		// Destructor
		~MutantStack();
		
		// Operators
		const MutantStack& operator=( const MutantStack &assign );
		
		//* Logic
		const T&		top( void ) const;
		bool			empty( void ) const;
		__SIZE_TYPE__	size( void ) const;
		void			push( T el );
		void			pop( void );
		
		//* iterators
		iterator	begin( void );
		iterator	end( void );
};

// Stream operators
template <typename T>
std::ostream& operator<<( std::ostream &stream, const MutantStack<T> &mut_stack );

# include "MutantStack.tpp"

#endif