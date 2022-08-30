/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_range_constructor.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:20:09 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/30 13:16:07 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_range_constructor(scope_diff *vars)
{
	big_test_header("Testing Range Constructor");
	
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
		small_test_header("Standard Range Constructor");
		std::vector<int>	og(source.begin(), source.end());
		ft::vector<int>		my(source2.begin(), source2.end());

		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after Range Constructor", vars);
		}
		check_scope_diff(vars, "Differences after Range Constructor");
		check_cap_and_size(&og, &my, "Testing Range Constructor", vars);
		check_scope_diff(vars, "Differences in size or capacity Testing Range Constructor");
	}

	{
		small_test_header("Range Constructor with swapped iterators");
		bool	og_try = false;
		bool	my_try = false;
		try
		{
			std::vector<int>	og(source.end(), source.begin());
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			ft::vector<int>	my(source2.end(), source2.begin());
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "Calling Range Constructor with swapped iterators"))
			vars->curr_scope++;
		check_scope_diff(vars, "Throwing exception calling Range Constructor with swapped iterators");
	}
	{
		small_test_header("Range Constructor with identical iterators");
		bool	og_try = false;
		bool	my_try = false;
		try
		{
			std::vector<int>	og(source.begin(), source.begin());
			ft::vector<int>		my(source2.begin(), source2.begin());
			check_cap_and_size(&og, &my, "Testing Range Constructor with identical iterators", vars);
			check_scope_diff(vars, "Differences in size or capacity Testing Range Constructor with identical iterators");
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		if (og_try)
		{
			og_try = false;
			try
			{
				std::vector<int>	og(max_size, 10);
			}
			catch(const std::exception& e)
			{
				og_try = true;
			}
			try
			{
				ft::vector<int>		my(max_size, 10);
			}
			catch(const std::exception& e)
			{
				my_try = true;
			}
		}
		if (!check_try_counts(og_try, my_try, "Calling Range Constructor with identical iterators"))
			vars->curr_scope++;
		check_scope_diff(vars, "Throwing exception calling Range Constructor with identical iterators");
	}
}