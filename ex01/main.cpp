/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:39:35 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/21 16:20:37 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../colors.hpp"

# include <stack>
# include <cctype>
# include <iostream>
# include <cstdlib>

bool	is_operator(const char c)
{
	return (
		c == '+' || c == '-' || c == '*' || c == '/'
	);
}

void	operator_apply(std::stack<int>& stack, char op)
{
	int		result;
	int		lhs;
	int		rhs;

	rhs = stack.top();
	stack.pop();
	lhs = stack.top();
	stack.pop();
	if ('+' == op)
		result = lhs + rhs;
	if ('-' == op)
		result = lhs - rhs;
	if ('*' == op)
		result = lhs * rhs;
	if ('/' == op)
		result = lhs / rhs;
	stack.push(result);
}

int main( int argc, const char* argv[])
{
	if (2 == argc)
	{
		std::stack<int>	stack;
		int				i;
		int				operands;

		operands = 0;
		i = 0;
		while (argv[1][i])
		{
			if (std::isdigit(argv[1][i]))
			{
				stack.push(std::atoi(argv[1] + i));
				operands += 1;
			}
			else if (is_operator(argv[1][i]))
			{
				if (operands < 2)
				{
					std::cout << BOLDRED << "Error: wrong number of arguments for operator" << RESET << std::endl;
					break ;
				}
				operands -= 1;
				operator_apply(stack, argv[1][i]);
			}
			else if (false == std::isspace(argv[1][i]))
			{
				std::cout << BOLDRED << "Error: wrong symbol found" << RESET << std::endl;
				break ;
			}
			i++;
		}
		if ('\0' == argv[1][i])
		{
			if (stack.size() != 1)
			{
				std::cout << BOLDRED << "Error: invalid inverted Polish mathematical expression" << RESET << std::endl;
			}
			else
				std::cout << BOLDGREEN << stack.top() << RESET << std::endl;
		}
	}
	else
		std::cout << BOLDRED << "Error: Wrong number of arguments" << RESET << std::endl;
	return 0;
}
