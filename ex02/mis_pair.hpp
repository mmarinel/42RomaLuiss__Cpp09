/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mis_pair.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:39:57 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/13 13:12:08 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIS_PAIR_HPP
# define MIS_PAIR_HPP

# include <cstdlib>

template <typename T>
class mis_pair
{
private:
    T		smaller;
    T		bigger;
    bool	last_not_used;
public:
    bool        operator<(const mis_pair& other);
    bool        operator>(const mis_pair& other);
    bool        operator==(const mis_pair& other);

                mis_pair(T smaller, T bigger, bool last_not_used);
                mis_pair();
                mis_pair(const mis_pair& copy);
    mis_pair&   operator=(const mis_pair& copy);
                ~mis_pair();
};

# include "mis_pair.tpp"

#endif