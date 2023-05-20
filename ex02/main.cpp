/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/20 17:35:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <time.h>

int main(int argc, char const *argv[])
{
	struct timespec	before;
	struct timespec	after;
	long		before_ns;
	long		after_ns;

	try
	{
		PMergeMe<int>	pMergeMe(argc, argv);

		clock_gettime(CLOCK_BOOTTIME, &before);
		pMergeMe.sortVec();
		clock_gettime(CLOCK_BOOTTIME, &after);
		before_ns = (before.tv_sec * pow(10, 9)) + before.tv_nsec;
		after_ns = (after.tv_sec * pow(10, 9)) + after.tv_nsec;
		std::cout << "elapsed time [us]: " << (after_ns - before_ns) << std::endl;
		std::cout << "elapsed time [s]: " << (after_ns - before_ns) / pow(10, 9) << std::endl;
	}
	catch (const PMergeMe<int>:: InvalidSequenceException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
