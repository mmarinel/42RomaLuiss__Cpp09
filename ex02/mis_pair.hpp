/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_pair.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:39:57 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/20 11:28:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIS_PAIR_HPP
# define MIS_PAIR_HPP

# include <ostream>
# include <cstdlib>

template <typename T>
class mis_pair
{
private:
    T		        smaller;
    T		        bigger;
    bool	        unpaired;
public:
	bool			isUnpaired( void );
	void			sortPair( void );

    bool            operator<(const mis_pair& other) const;
    bool            operator<=(const mis_pair& other) const;
    bool            operator>(const mis_pair& other) const;
    bool            operator>=(const mis_pair& other) const;
    bool            operator==(const mis_pair& other) const;

                    mis_pair(T smaller, T bigger, bool last_not_used);
                    mis_pair();
                    mis_pair(const mis_pair& copy);
    mis_pair&       operator=(const mis_pair& copy);
                    ~mis_pair();
    
    const T&        getSmaller( void ) const ;
    const T&        getBigger( void ) const;
};

template  <typename T>
std::ostream&	operator<<( std::ostream& stream, const mis_pair<T>& pair )
{
    stream << "(" << pair.getSmaller() << ", " << pair.getBigger() << ")";

    return (stream);
}

# include "mis_pair.tpp"

#endif