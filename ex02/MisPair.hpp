/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MisPair.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:39:57 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/21 19:29:28 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIS_PAIR_HPP
# define MIS_PAIR_HPP

# include <ostream>
# include <cstdlib>

template <typename T>
class MisPair
{
private:
    T		        smaller;
    T		        bigger;
    bool	        unpaired;
public:
	bool			isUnpaired( void );
	void			sortPair( void );

    bool            operator<(const MisPair& other) const;
    bool            operator<=(const MisPair& other) const;
    bool            operator>(const MisPair& other) const;
    bool            operator>=(const MisPair& other) const;
    bool            operator==(const MisPair& other) const;

                    MisPair(T smaller, T bigger, bool last_not_used);
                    MisPair();
                    MisPair(const MisPair& copy);
    MisPair&       operator=(const MisPair& copy);
                    ~MisPair();
    
    const T&        getSmaller( void ) const ;
    const T&        getBigger( void ) const;
};

template  <typename T>
std::ostream&	operator<<( std::ostream& stream, const MisPair<T>& pair )
{
    stream << "(" << pair.getSmaller() << ", " << pair.getBigger() << ")";

    return (stream);
}

# include "MisPair.tpp"

#endif