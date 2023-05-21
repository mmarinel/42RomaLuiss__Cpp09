/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/21 14:40:25 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"
#include <time.h>

int main(int argc, char const *argv[])
{
	struct timespec	before_vec;
	struct timespec	after_vec;
	long			before_vec_us;
	long			after_vec_us;
	struct timespec	before_deq;
	struct timespec	after_deq;
	long			before_deq_us;
	long			after_deq_us;

	try
	{
		PMergeMe<int>	pMergeMe(argc, argv);

		//*	Measuring time with std::vector
		clock_gettime(CLOCK_BOOTTIME, &before_vec);
		pMergeMe.sortVec();
		clock_gettime(CLOCK_BOOTTIME, &after_vec);

		//*	Measuring time with std::deque
		clock_gettime(CLOCK_BOOTTIME, &before_deq);
		pMergeMe.sortDeq();
		clock_gettime(CLOCK_BOOTTIME, &after_deq);

		//*	accounting times
		before_vec_us = (before_vec.tv_sec * pow(10, 9)) + before_vec.tv_nsec;
		after_vec_us = (after_vec.tv_sec * pow(10, 9)) + after_vec.tv_nsec;
		before_deq_us = (before_deq.tv_sec * pow(10, 9)) + before_deq.tv_nsec;
		after_deq_us = (after_deq.tv_sec * pow(10, 9)) + after_deq.tv_nsec;

		//*	printing test results
		std::cout << pMergeMe << std::endl;
		std::cout
			<< "Time to process a range of "
			<< argc - 1
			<< " elements with std::vector<int> : "
			<< (after_vec_us - before_vec_us)
			<< " us, "
			<< (after_vec_us - before_vec_us) / pow(10, 9)
			<< " s"
			<< std::endl;
		std::cout
			<< "Time to process a range of "
			<< argc - 1
			<< " elements with std::deque<int> : "
			<< (after_deq_us - before_deq_us)
			<< " us, "
			<< (after_deq_us - before_deq_us) / pow(10, 9)
			<< " s"
			<< std::endl;
	}
	catch (const PMergeMe<int>:: InvalidSequenceException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
