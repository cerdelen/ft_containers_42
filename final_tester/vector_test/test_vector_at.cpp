/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_at.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:30:59 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:51:05 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_at(scope_diff *vars)
{
	{
		big_test_header("Testing at() on empty vector");
		small_test_header("at() with empty vector");
		// size_t	scope_diff = 0;

		
		ft::vector<size_t> my;		
		std::vector<size_t> og;
		
		bool	og_try = false;
		bool	my_try = false;
		try
		{
			og.at(11);
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			my.at(11);
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "Accessing an empty vector with at()"))
			vars->curr_scope++;
		check_scope_diff(vars, "Throwing exception accessing empty vector with at()");
		check_cap_and_size(&og, &my, "Testing assign with empty vector", vars);
		check_scope_diff(vars, "Differences in size or capacity with empty vector");
	}
	{
		big_test_header("Testing at() and [] on filled vector");
		small_test_header("testing at() and [] on filled vector");
		// size_t	scope_diff = 0;

		
		ft::vector<size_t> my(10, 10);		
		std::vector<size_t> og(10, 10);
		for (size_t i = 0; i < 10; i++)
		{
			if (my.at(i) != og.at(i))
			{
				std::cout << RED_COL << "Difference with at() after Fill constructor at ind " << i << std::endl << "og.at(i) = " << og.at(i) << " my.at(i) = " << my.at(i) << DEFAULT_COL << std::endl;
				vars->curr_test++;
			}
			if (my[i] != og[i])
			{
				std::cout << RED_COL << "Difference with [] after Fill constructor at ind " << i << std::endl << "og[i] = " << og[i] << " my[i] = " << my[i] << DEFAULT_COL << std::endl;
				vars->curr_test++;
			}
		}
		check_scope_diff(vars, "Accessing all elements with [] and at() ");
		
		small_test_header("accessing out of bounds with at");
		bool	og_try = false;
		bool	my_try = false;
		try
		{
			og.at(11);
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			my.at(11);
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "Accessing out of bounds (too high) with at()"))
			vars->curr_test++;
		check_scope_diff(vars, "Throwing exception accessing out of bounds (too high) with at() ");
		og_try = false;
		my_try = false;
		try
		{
			og.at(-1);
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			my.at(-1);
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "Accessing out of bounds (negative index) with at()"))
			vars->curr_test++;
		check_scope_diff(vars, "Throwing exception accessing out of bounds (negative index) with at() ");
	}
}
