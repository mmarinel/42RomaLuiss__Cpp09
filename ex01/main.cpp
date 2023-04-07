/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:39:35 by mmarinel          #+#    #+#             */
/*   Updated: 2023/04/07 13:18:40 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../colors.hpp"

# include <stack>
# include <cctype>
# include <iostream>

bool	is_operator(const char c)
{
	return (
		c == '+' || c == '-' || c == '*' || c == '/'
	);
}

void	operator_apply(std::stack<std::string>& stack, char op)
{
	int		result;
	int		lhs;
	int		rhs;

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
		int						i;
		int						operands;

		operands = 0;
		i = 0;
		while (argv[1][i])
		{
			if (std::isdigit(argv[1][i]))
			{
				stack.push(std::string(1, argv[1][i]));
				operands += 1;
			}
			else if (is_operator(argv[1][i]))
			{
				if (operands < 2)
				{
					std::cout
					<< BOLDRED
					<< "Error: wrong number of arguments for operator"
					<< RESET
					<< std::endl;
					exit(1);
				}
				operands -= 1;
				operator_apply(stack, argv[1][i]);
			}
			else if (false == std::isspace(argv[1][i]))
			{
				std::cout << BOLDRED << "Error: wrong symbol found" << RESET << std::endl;
				exit(1);
			}
			i++;
		}
		if (stack.size() != 1)
		{
			std::cout
			<< BOLDRED
			<< "Error: invalid inverted Polish mathematical expression"
			<< RESET
			<< std::endl;
			std::cout << "size: " << stack.size() << std::endl;
			std::cout << "top: " << stack.top() << std::endl;
			stack.pop();
			std::cout << "second: " << stack.top() << std::endl;
			exit(1);
		}
		std::cout << BOLDGREEN << stack.top() << RESET << std::endl;
	}
	else
		std::cout << BOLDRED << "Error: Wrong number of arguments" << RESET << std::endl;
	return 0;
}
