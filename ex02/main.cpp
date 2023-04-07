/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/16 19:08:50 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include "templates.hpp"
# include "Awesome.hpp"

# include <algorithm>
# include <vector>
# include <list>

# include <iostream>
# include <string>

# include <cstdlib>
# include <time.h>

static void	subject_tests( void );
static inline int	random_int( int limit );
static inline std::string	random_string( int len );
static inline Awesome	random_awesome( int nbr );
//* end of static declarations

int main(int argc, char const *argv[])
{
	if (argc == 3)
	{
		{
			std::cout << GREEN "|||| int tests" RESET << std::endl;
			//* ************************************************
			
			const size_t		CONTAINER_SIZE = std::atoi(argv[1]);
			const size_t		RAND_LIMIT = std::atoi(argv[2]);
			MutantStack<int>	stack(CONTAINER_SIZE);
			s_elRandom<int>		randomer = s_elRandom<int>(RAND_LIMIT, &random_int);
			
			srand(time(NULL));
			std::for_each(stack.begin(), stack.end(), randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<int>();
		}
		{
			std::cout << GREEN "||| std::string tests" RESET << std::endl;
			//* ************************************************
			
			const size_t				CONTAINER_SIZE = std::atoi(argv[1]);
			const size_t				RAND_LIMIT = std::atoi(argv[2]);
			MutantStack<std::string>	stack(CONTAINER_SIZE);
			s_elRandom<std::string>		randomer = s_elRandom<std::string>(RAND_LIMIT, &random_string);
			
			srand(time(NULL));
			std::for_each(stack.begin(), stack.end(), randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<std::string>();
		}
		{
			std::cout << GREEN "||| Awesome class tests" RESET << std::endl;
			//* ************************************************
			
			const size_t				CONTAINER_SIZE = std::atoi(argv[1]);
			const size_t				RAND_LIMIT = std::atoi(argv[2]);
			MutantStack<Awesome>		stack(CONTAINER_SIZE);
			s_elRandom<Awesome>			randomer = s_elRandom<Awesome>(RAND_LIMIT, &random_awesome);
			
			srand(time(NULL));
			std::for_each(stack.begin(), stack.end(), randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<Awesome>();
		}
	}
	else
	{
			//*				SUBJECT TESTS
			//* ************************************************

			subject_tests();
	}
	return 0;
}

static void	subject_tests( void ) {
	{
		std::cout << GREEN "||| testing with MutantStack" RESET << std::endl;
		//* ************************************************
			
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	
	}
	{
		std::cout << GREEN "||| testing with std::list" RESET << std::endl;
		//* ************************************************
			
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
}

static inline int	random_int( int limit ) {
	return ( std::rand() % (limit + 1) );
}

static inline std::string	random_string( int len ) {
	std::string		str;
	size_t			real_len;
	const size_t	STR_MAX_LEN = 50;

	real_len = std::min<size_t>(len, STR_MAX_LEN);
	str = std::string(real_len, '\0');
	for ( size_t i = 0; i < real_len; i++) {
		do {
			str[i] = static_cast<char>(rand() % std::numeric_limits<char>::max());
		} while (false == std::isprint(str[i]));
	}

	return (str);
}

static inline Awesome	random_awesome( int nbr ) {
	return (Awesome( std::rand() % (nbr + 1)));
}
