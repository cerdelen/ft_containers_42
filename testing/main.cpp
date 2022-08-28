/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:10:56 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/28 23:44:46 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../namespace.hpp"
#include <vector>
#include <iterator>
#include "../vector.hpp"
#include "colours.h"

bool	check_try_counts(bool og, bool my, std::string test)
{
	std::cout << test << " was tested and ";
	if (og && my)
	{
		std::cout << GREEN_COL << "both threw exception" <<std::endl;
		return true;
	}
	if (!og && my)
	{
		std::cout << RED_COL << "MY threw an exception but OG did not" <<std::endl;
		return false;
	}
	if (og && !my)
	{
		std::cout << RED_COL << "OG threw an exception but MY did not" <<std::endl;
		return false;
	}
	if (!og && !my)
	{
		std::cout << GREEN_COL << "both threw NO exception" <<std::endl;
		return true;
	}
	return true;
}


int main()
{
	int	differences = 0;
	{
		ft::vector<int> my(10, 10);		
		std::vector<int> og(10, 10);
		
		for (size_t i = 0; i < 10; i++)
		{
			if (my.at(i) != og.at(i))
			{
				std::cout << RED_COL << "Difference with at() after Fill constructor at ind " << i << DEFAULT_COL << std::endl;
				differences++;
			}
			if (my[i] != og[i])
			{
				std::cout << RED_COL << "Difference with [] after Fill constructor at ind " << i << DEFAULT_COL << std::endl;
				differences++;
			}
		}
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
		if (!check_try_counts(og_try, my_try, "Accessing out of bounds with at()"))
			differences++;





		
	}

	if (differences > 0)
		std::cout << RED_COL << differences << " TESTS HAVE NOT PASSED!!!" << std::endl;
	else
		std::cout << GREEN_COL << "ALL TESTS PASSED!!!" << std::endl;




	
	// try
	// {
	// 	ft::vector<int> a;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}




//