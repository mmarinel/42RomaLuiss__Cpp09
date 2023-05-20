/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/20 12:43:32 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int argc, char const *argv[])
{
	try
	{
		PMergeMe<int>	pMergeMe(argc, argv);
		
		pMergeMe.debug();
	}
	catch (const PMergeMe<int>:: InvalidSequenceException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
