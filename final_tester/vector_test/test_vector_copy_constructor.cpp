/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector_copy_constructor.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:18:34 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:45:15 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	test_copy_constructor(scope_diff *vars)
{
	big_test_header("Testing Copy Constructor");

	size_t	max_size = 20;
	std::vector<size_t>	source;
	source.reserve(max_size);
	for (size_t i = 0; i < max_size; i++)
	{
		source.push_back(i);
	}
	ft::vector<size_t>	source2;
	source2.reserve(max_size);
	for (size_t i = 0; i < max_size; i++)
	{
		source2.push_back(i);
	}
	
	{
		small_test_header("Standard Copy Constructor");
		std::vector<size_t>	og(source);
		ft::vector<size_t>		my(source2);
		
				for (size_t i = 0; i < max_size; i++)
		{
			compare_ints_with_message(og[i], my[i], "Differences after Range Constructor", vars);
		}
		check_scope_diff(vars, "Differences after Range Constructor");
		check_cap_and_size(&og, &my, "Testing Range Constructor", vars);
		check_scope_diff(vars, "Differences in size or capacity Testing Range Constructor");
	}

	{
		std::vector<size_t>		og_empty;
		ft::vector<size_t>			my_empty;
		small_test_header("Empty Copy Constructor");
		std::vector<size_t>		og(og_empty);
		ft::vector<size_t>			my(my_empty);

		check_cap_and_size(&og, &my, "Testing empty copy Constructor", vars);
		check_scope_diff(vars, "Differences in size or capacity Testing Range Constructor");
	}	
}
