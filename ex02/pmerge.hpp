/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pmerge.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:16:42 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/07 19:18:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <vector>
# include <deque>

# include <iostream>
# include <cstdlib>
# include <string>
# include <unistd.h>

# include "../colors.hpp"

# define THRESHOLD 16

//*		function prototypes
void	mergeInsert_vector(const std::string& args);
void	printVector(const std::vector<int>& vec);

#endif