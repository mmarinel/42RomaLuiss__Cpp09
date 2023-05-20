/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:49:00 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/20 15:31:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <cctype>
# include <cstdlib>
# include <iostream>
# include <math.h>

# include "mis_pair.hpp"

template <typename T>
class PMergeMe
{
private:
	std::vector< mis_pair<T> >	vec_pairs;
	std::deque< mis_pair<T> >	deque_pairs;
	std::vector<T>				ordered_vec;
	std::deque<T>				ordered_deque;
public:
	void					sortVec( void );
	void					sortDeq( void );

            				PMergeMe( size_t argc, char const *argv[] );
            				PMergeMe( void );
            				PMergeMe( const PMergeMe& copy );
    PMergeMe<T>&    		operator=( const PMergeMe& copy );
            				~PMergeMe();

	void					debug ( void );

	class					InvalidSequenceException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
private:
	template <typename C>
	void					_order_pairs( C& collection );
	template <typename CPair, typename C>
	void					_merge_pairs( CPair& cpairs, C& collection );
	void					_bs_insert( std::vector<T>& vec, T el );
	void					_bs_insert( std::deque<T>& vec, T el );

	void					_add_vec_pair( size_t pos, size_t argc, char const *argv[] );
	void					_add_deq_pair( size_t pos, size_t argc, char const *argv[] );
	bool					isVaildNumberString( const char *numberString );
};

# include "PMergeMe.tpp"
# include "PMerge_vec.tpp"
# include "PMerge_deq.tpp"

#endif