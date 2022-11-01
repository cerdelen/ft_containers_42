/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:54:10 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:13:24 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../namespace.hpp"
#include <stack>
#include "colours.h"

template <class T>
void	check_if_equal(std::string test_case, T my_value, T og_value)
{
	if (my_value == og_value)
		std::cout << test_case << GREEN_COL << " returns same value!" << std::endl;
	else
		std::cout << test_case << RED_COL << " returns different value!" << std::endl;
	std::cout << DEFAULT_COL << std::endl;
}


int main()
{
	ft::stack<size_t>		my_stacky;
	ft::stack<size_t>		my_stacky2;
	std::stack<size_t>		og_stacky;
	std::stack<size_t>		og_stacky2;

	for (size_t i = 0; i < 10; i++)
	{
		my_stacky.push(i);
		og_stacky.push(i);
	}
	
	check_if_equal("Top after pushing()", my_stacky.top(), og_stacky.top());

	{
		my_stacky2 = my_stacky;
		og_stacky2 = og_stacky;
		check_if_equal("top() after equal sign operator", my_stacky2.top(), og_stacky2.top());
		og_stacky2.pop();
		og_stacky2.pop();
		my_stacky2.pop();
		my_stacky2.pop();
		check_if_equal("top() after pop()", my_stacky2.top(), og_stacky2.top());
		for (size_t i = 0; i < 8; i++)
		{
			og_stacky2.pop();
			my_stacky2.pop();
		}
		bool	try_res = false;
		try
		{
			check_if_equal("top() after pop() more often then there are elements", my_stacky2.top(), og_stacky2.top());
		}
		catch(const std::exception& e)
		{
			try_res = true;
		}
		std::cout << "calling top() on empty stack";
		if (try_res)
			std::cout << GREEN_COL << " did throw an exeption!";
		else
			std::cout << RED_COL << " did not throw an exeption!";
		std::cout << DEFAULT_COL << std::endl << std::endl;
		my_stacky2.pop();
		my_stacky2.pop();
		my_stacky2.pop();
		my_stacky2.pop();
		my_stacky2.pop();
		
		std::cout << GREEN_COL << "If this prints calling pop() on empty container does not segfault/throw exception!" << std::endl << std::endl;
	}
	
}