/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:33:53 by mmarinel          #+#    #+#             */
/*   Updated: 2023/05/12 17:47:42 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "insertion.hpp"

static void	vector_insertion_sort(std::vector<int>& vec, int start, int end);
//* end of static declarations

static void	vector_insertion_sort(std::vector<int>& vec, int start, int end)
{
    int i;
    int selected;
    int selected_val;

	for (selected = start; selected <= end; selected++)
	{
        selected_val = vec[selected];
        i = selected - 1;
        while (i >= start && vec[i] > selected_val)
		{
            vec[i + 1] = vec[i];
            i --;
        }
        vec[i + 1] = selected_val;
    }
}

int main(void)
{
    std::vector<int>    vec;

    vec.push_back(80);
    vec.push_back(10);
    vec.push_back(2);
    vec.push_back(16);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(9);

    vector_insertion_sort(vec, 0, vec.size() - 1);
    for (iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
