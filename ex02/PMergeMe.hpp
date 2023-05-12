/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:49:00 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/12 19:48:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <cctype>

# include "mis_pair.hpp"

template <typename T>
class PMergeMe
{
private:
	std::vector<mis_pair<T>>	vec_pairs;
	std::list<mis_pair<T>>		list_pairs;
	std::vector<T>				ordered_vec;
	std::list<T>				ordered_list;
private:
	void					makeVecPairs( void );
	void					makeListPairs( void );
	bool					isVaildNumberString( const char *numberString );
public:
	const std::vector<T>&	sortVec( void );
	const std::list<T>&		sortList( void );

            				PMergeMe( int argc, char const *argv[] );
            				PMergeMe( void );
            				PMergeMe( const PMergeMe& copy );
    bool    				operator=( const PMergeMe& copy );
            				~PMergeMe();

	class					InvalidSequenceException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

#endif