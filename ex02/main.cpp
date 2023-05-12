/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/07 19:19:42 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pmerge.hpp"

static void	mergeInsert_vector(const std::string& args);
static void	vector_insertion_sort(iterator begin, iterator end);
//*		end of static declarations

int main(int argc, char const *argv[])
{
	std::string	args;

	//*		setting argv in one std::string
	for (int i = 1; i < argc; i++)
		args += std::string(argv[i]) + std::string(" ");
	
	//*		printing unsorted sequence
	std::cout << "Before: " << args << std::endl;

	//*		sorting with vector
	mergeInsert_vector(args);

	//*		sorting with deque
		//TODO

	return 0;
}

void	printVector(const std::vector<int>& vec)
{
	std::cout << BOLDGREEN << "Printing Vector" << RESET << std::endl;
	for (std::vector<int>::const_iterator it = vec.cbegin(); it < vec.cend(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	vector_insertion_sort(iterator begin, iterator end)
{
	for (iterator selected = begin; selected != end; selected++)
		for (iterator it = selected + 1; it != end; it++)
			if (*it < *selected)
				ft_swap(*it, *selected);
}