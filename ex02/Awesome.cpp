/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:53:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 13:08:01 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Awesome.hpp"

//*...... Constructor
Awesome::Awesome( void ) : __n(42) {}
Awesome::Awesome( int el ) : __n(el) {}

//*........ Getters and Setters
int	Awesome::get( void ) const {
	return (this->__n);
}

//*.......... Operators
std::ostream&	operator<<( std::ostream& o, Awesome const & rhs ) {
	o << rhs.get();

	return (o);
}
