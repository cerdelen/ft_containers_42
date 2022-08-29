/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_range_constructor.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:20:09 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/29 18:55:43 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_range_constructor(scope_diff *vars)
{
	test_header("Testing Range Constructor");
	
	int	max_size = 100;
	std::vector<int>	source;
	source.reserve(max_size);
	for (size_t i = 0; i < max_siz e; i++)
	{
		source.push_back(i);
	}
	








	{
		std::vector<int>	og(source.begin(), source.end());
		std::vector<int>	my(source.begin(), source.end());

		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after Range Constructor", vars);
		}
		check_scope_diff(vars, "Differences after Fill Constructor");
	}
	{
		int	max_size = 2000;
		int value = -1;
		std::vector<int>	og(max_size, value);
		ft::vector<int>		my(max_size, value);

		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after Fill Constructor", vars);
		}
		check_scope_diff(vars, "Differences after Fill Constructor");
	}
	{
		int	max_size = -1;
		bool	og_try = false;
		bool	my_try = false;
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
		if (!check_try_counts(og_try, my_try, "Calling Fill Constructor with negative size"))
			vars->curr++;
		check_scope_diff(vars, "Throwing exception calling Fill Constructor with negative size");
	}
}