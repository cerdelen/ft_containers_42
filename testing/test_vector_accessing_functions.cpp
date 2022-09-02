/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_accessing_functions.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 13:42:26 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/30 15:54:16 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_front(scope_diff *vars)
{
	small_test_header("Testing front()");
	int	max_size = 20;
	std::vector<int>	source;
	source.reserve(max_size);
	for (size_t i = 0; i < max_size; i++)
	{
		source.push_back(i);
	}
	ft::vector<int>	source2;
	source2.reserve(max_size);
	for (size_t i = 0; i < max_size; i++)
	{
		source2.push_back(i);
	}
	
	{
		std::vector<int>	og(12, 12);
		ft::vector<int>		my(12, 12);

		compare_ints_with_message(og.front(), my.front(), "front() on equal valid vectors", vars);
		check_scope_diff(vars, "Differences with front on equal valid vectors");
	}
	{
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		compare_ints_with_message(og.front(), my.front(), "front() on equal valid vectors", vars);
		check_scope_diff(vars, "Differences with front on equal valid vectors");
	}
	{
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		og.erase(og.begin());
		my.erase(my.begin());

		compare_ints_with_message(og.front(), my.front(), "front() on equal valid vectors", vars);
		check_scope_diff(vars, "Differences with front on equal valid vectors");
	}
	{
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		og.clear();
		my.clear();

		bool	my_try = false;
		try
		{
			my.front();
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (my_try == true)
			std::cout << "front() called on an cleared vector" << GREEN_COL << " throws an exception" << DEFAULT_COL << std::endl;
		else
		{
			std::cout << "front() called on an cleared vector" << RED_COL << " does not throw an exception" << DEFAULT_COL << std::endl;
			vars->curr_scope++;
		}
		check_scope_diff(vars, "Differences with front on cleared vectors");
	}
	{
		ft::vector<int>		my;

		bool	my_try = false;
		try
		{
			my.front();
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (my_try == true)
			std::cout << "front() called on an empty vector" << GREEN_COL << " throws an exception" << DEFAULT_COL << std::endl;
		else
		{
			std::cout << "front() called on an empty vector" << RED_COL << " does not throw an exception" << DEFAULT_COL << std::endl;
			vars->curr_scope++;
		}
		check_scope_diff(vars, "Differences with front() on empty vectors");
	}
}

void	test_back(scope_diff *vars)
{
	small_test_header("Testing back()");
	int	max_size = 20;
	std::vector<int>	source;
	source.reserve(max_size);
	for (size_t i = 0; i < max_size; i++)
	{
		source.push_back(i);
	}
	ft::vector<int>	source2;
	source2.reserve(max_size);
	for (size_t i = 0; i < max_size; i++)
	{
		source2.push_back(i);
	}
	
	{
		std::vector<int>	og(12, 12);
		ft::vector<int>		my(12, 12);

		compare_ints_with_message(og.back(), my.back(), "back() on equal valid vectors", vars);
		check_scope_diff(vars, "Differences with back on equal valid vectors");
	}
	{
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		compare_ints_with_message(og.back(), my.back(), "back() on equal valid vectors", vars);
		check_scope_diff(vars, "Differences with back on equal valid vectors");
	}
	{
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		og.erase(og.begin());
		my.erase(my.begin());

		compare_ints_with_message(og.back(), my.back(), "back() on equal valid vectors", vars);
		check_scope_diff(vars, "Differences with back on equal valid vectors");
	}
	{
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		og.clear();
		my.clear();

		bool	my_try = false;
		try
		{
			my.back();
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (my_try == true)
			std::cout << "back() called on an cleared vector" << GREEN_COL << " throws an exception" << DEFAULT_COL << std::endl;
		else
		{
			std::cout << "back() called on an cleared vector" << RED_COL << " does not throw an exception" << DEFAULT_COL << std::endl;
			vars->curr_scope++;
		}
		check_scope_diff(vars, "Differences with back on cleared vectors");
	}
	{
		ft::vector<int>		my;

		bool	my_try = false;
		try
		{
			my.back();
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (my_try == true)
			std::cout << "back() called on an empty vector" << GREEN_COL << " throws an exception" << DEFAULT_COL << std::endl;
		else
			std::cout << "back() called on an empty vector" << RED_COL << " does not throw an exception" << DEFAULT_COL << std::endl;
	}
}

void	test_data(scope_diff *vars)
{
	
}

void	test_accessing_functions(scope_diff *vars)
{
	big_test_header("Accessing functions");
	test_front(vars);
	test_back(vars);
	test_data(vars);
}