/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_at.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:30:59 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/29 14:58:26 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_at(scope_diff *vars)
{
	{
		test_header("Testing at() on empty vector");
		int	scope_diff = 0;

		
		ft::vector<int> my;		
		std::vector<int> og;
		
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
			vars->curr++;
		check_scope_diff(vars, "Throwing exception accessing empty vector with at()");
	}
	{
		test_header("Testing at() and [] on filled vector");
		int	scope_diff = 0;

		
		ft::vector<int> my(10, 10);		
		std::vector<int> og(10, 10);
		for (size_t i = 0; i < 10; i++)
		{
			if (my.at(i) != og.at(i))
			{
				std::cout << RED_COL << "Difference with at() after Fill constructor at ind " << i << std::endl << "og.at(i) = " << og.at(i) << " my.at(i) = " << my.at(i) << DEFAULT_COL << std::endl;
				vars->curr++;
			}
			if (my[i] != og[i])
			{
				std::cout << RED_COL << "Difference with [] after Fill constructor at ind " << i << std::endl << "og[i] = " << og[i] << " my[i] = " << my[i] << DEFAULT_COL << std::endl;
				vars->curr++;
			}
		}
		check_scope_diff(vars, "Accessing all elements with [] and at() resulted in ");
		
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
			vars->curr++;
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
			vars->curr++;
		check_scope_diff(vars, "Throwing exception accessing out of bounds (negative index) with at() ");
	}
}
