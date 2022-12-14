/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_fill_constructor.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:59:25 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:42:23 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_fill_constructor(scope_diff *vars)
{
	big_test_header("Testing Fill Constructor");
	{
		small_test_header("Standard Fill Constructor");
		size_t	max_size = 10;
		size_t	value = 10;
		std::vector<size_t>	og(max_size, value);
		ft::vector<size_t>		my(max_size, value);

		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after Fill Constructor", vars);
		}
		check_scope_diff(vars, "Differences after Fill Constructor");
		check_cap_and_size(&og, &my, "Testing Fill Constructor", vars);
		check_scope_diff(vars, "Differences in size or capacity Testing Fill Constructor");
	}
	{
		size_t	max_size = 2000;
		size_t value = -1;
		std::vector<size_t>	og(max_size, value);
		ft::vector<size_t>		my(max_size, value);

		for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after Fill Constructor", vars);
		}
		check_scope_diff(vars, "Differences after Fill Constructor");
		check_cap_and_size(&og, &my, "Testing Fill Constructor", vars);
		check_scope_diff(vars, "Differences in size or capacity Testing Fill Constructor");
	}
	{
		small_test_header("Fill Constructor with negative count");
		int		max_size = -1;
		bool	og_try = false;
		bool	my_try = false;
		try
		{
			std::vector<size_t>	og(max_size, 10);
		}
		catch(const std::exception& e)
		{
			og_try = true;
		}
		try
		{
			ft::vector<size_t>		my(max_size, 10);
		}
		catch(const std::exception& e)
		{
			my_try = true;
		}
		if (!check_try_counts(og_try, my_try, "Calling Fill Constructor with negative size"))
			vars->curr_test++;
		check_scope_diff(vars, "Throwing exception calling Fill Constructor with negative size");
	}
}