/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_asign.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:57:40 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/30 19:04:32 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_assign_without_range(scope_diff *vars)
{
	big_test_header("Testing assign() with count and val");
	int max_size;
	int assign_size;
	int value;
	{
		small_test_header("assign with with smaller count and a val");
		max_size = 10;
		value = 10;
		assign_size = 10;
		std::vector<int>	og(max_size, value);
		ft::vector<int>		my(max_size, value);

	
		og.assign(assign_size, 12);
		my.assign(assign_size, 12);
		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after assign with smaller count and a val", vars);
		}
		check_scope_diff(vars, "Differences after assign with smaller count and a val");
		check_cap_and_size(&og, &my, "Testing assign with smaller count and val", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with smaller count and a val");
	}
	{
		small_test_header("assign with with bigger count and a val");
		max_size = 1;
		value = 1;
		assign_size = 12;
		std::vector<int>	og(max_size, value);
		ft::vector<int>		my(max_size, value);

	
		og.assign(assign_size, 12);
		my.assign(assign_size, 12);
		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after assign with bigger count and a val", vars);
		}
		check_scope_diff(vars, "Differences after assign with bigger count and a val");
		check_cap_and_size(&og, &my, "Testing assign with bigger count and val", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with bigger count and a val");
	}
	{
		small_test_header("assign with with negative count and a val");
		max_size = 1;
		value = 1;
		assign_size = -1;
		std::vector<int>	og(max_size, value);
		ft::vector<int>		my(max_size, value);
		{
			bool	og_try = false;
			bool	my_try = false;
			try
			{
				og.assign(assign_size, 12);
			}
			catch(const std::exception& e)
			{
				og_try = true;
			}
			try
			{
				my.assign(assign_size, 12);
			}
			catch(const std::exception& e)
			{
				my_try = true;
			}
			if (!check_try_counts(og_try, my_try, "Testing assign with negative count"))
				vars->curr_scope++;
			check_scope_diff(vars, "Throwing exception calling assign with negative count");
		}
	}
}


void	test_assign_with_range(scope_diff *vars)
{
	big_test_header("Testing assign() with range iterators");
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
		small_test_header("assign with with same range");
		std::vector<int>	og(20, 50);
		ft::vector<int>		my(20, 50);

		og.assign(source.begin(), source.end());
		my.assign(source2.begin(), source2.end());
		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after assign with same range", vars);
		}
		check_scope_diff(vars, "Differences after assign with same range");
		check_cap_and_size(&og, &my, "Testing assign with same range", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with same range");
	}
	{
		small_test_header("assign with with smaller range");
		std::vector<int>	og(50, 50);
		ft::vector<int>		my(50, 50);

	
		og.assign(source.begin(), source.end());
		my.assign(source2.begin(), source2.end());
		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after assign with smaller range", vars);
		}
		check_scope_diff(vars, "Differences after assign with smaller range");
		check_cap_and_size(&og, &my, "Testing assign with smaller range", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with smaller range");
	}
	{
		small_test_header("assign with with bigger range");
		max_size = 1;
		std::vector<int>	og(max_size, 12);
		ft::vector<int>		my(max_size, 12);

	
		og.assign(source.begin(), source.end());
		my.assign(source2.begin(), source2.end());
		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after assign with bigger range", vars);
		}
		check_scope_diff(vars, "Differences after assign with bigger range");
		check_cap_and_size(&og, &my, "Testing assign with bigger range", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with bigger range");
	}
	{
		small_test_header("assign with with swapped iterators");
		bool	og_try = false;
		bool	my_try = false;
		max_size = 1;
		std::vector<int>	og(max_size, 12);
		ft::vector<int>		my(max_size, 12);
	
		try
		{
			og.assign(source.end(), source.begin());
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			my.assign(source2.end(), source2.begin());
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "assign() swapped iterators"))
			vars->curr_scope++;
		check_scope_diff(vars, "Throwing exception using assign() with swapped iterators");
		check_cap_and_size(&og, &my, "Testing assign with swapped iterators", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with swapped iterators");
	}
	{
		small_test_header("assign with with identical iterators");
		bool	og_try = false;
		bool	my_try = false;
		max_size = 1;
		std::vector<int>	og(max_size, 12);
		ft::vector<int>		my(max_size, 12);

	
		try
		{
			og.assign(source.begin(), source.begin());
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			my.assign(source2.begin(), source2.begin());
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "assign() with identical iterators"))
			vars->curr_scope++;
		check_scope_diff(vars, "Throwing exception using assign() with identical iterators");
		check_cap_and_size(&og, &my, "Testing assign with identical iterators", vars);
		check_scope_diff(vars, "Differences in size or capacity after assign with identical iterators");
	}
}

void	test_assign(scope_diff *vars)
{
	test_assign_without_range(vars);
	test_assign_with_range(vars);	
}