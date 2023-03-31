/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:39:35 by mmarinel          #+#    #+#             */
/*   Updated: 2023/03/31 13:12:45 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../colors.hpp"

# include <stack>
# include <cctype>
# include <iostream>

void	operator_apply(std::stack<std::string>& stack, char op)
{
	int	result;
	int	lhs;
	int	rhs;

	rhs = std::atoi(stack.top().c_str());
	stack.pop();
	lhs = std::atoi(stack.top().c_str());
	stack.pop();
	if ('+' == op)
		result = lhs + rhs;
	if ('-' == op)
		result = lhs - rhs;
	if ('*' == op)
		result = lhs * rhs;
	if ('/' == op)
		result = lhs / rhs;
	stack.push(std::to_string(result));
}

int main( int argc, const char* argv[])
{
	if (2 == argc)
	{
		std::stack<std::string>	stack;
		int				i;

		i = 0;
		while (argv[1][i])
		{
			if (std::isdigit(argv[1][i]))
			{
				std::cout << "is digit" << std::endl;
				// exit(0);
				stack.push(std::string(1, argv[1][i]));
			}
			else
			{
				std::cout << "is opr" << std::endl;
				// exit(0);
				operator_apply(stack, argv[1][i]);
			}
			i++;
			std::cout << "iteration n• " << i << std::endl;
		}
		std::cout << stack.top() << std::endl;
	}
	else
		std::cout << "Error: Wrong number of arguments" << std::endl;
	std::cout << std::endl;
	return 0;
}
