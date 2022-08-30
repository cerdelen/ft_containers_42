/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:30:49 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/30 13:09:14 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	compare_ints_with_message(int og, int my, std::string message, scope_diff *vars)
{
	if (og == my)
		return ;
	else
	{
		std::cout << message << RED_COL << " does not return the same value" << std::endl << "og = " << og << std::endl << "my = " << my << DEFAULT_COL << std::endl;
		vars->curr_test++;
	}
}

bool	compare_ints_without_message(int og, int my, scope_diff *vars)
{
	if (og == my)
		return true;
	else
	{
		vars->curr_test++;
		return false;
	}
}

void	end_message(scope_diff *vars)
{
	std::cout << std::endl << std::endl;
	if (vars->global_diff > 0)
		std::cout << RED_COL << vars->global_diff << " TESTS HAVE NOT PASSED!!!" << DEFAULT_COL << std::endl;
	else
		std::cout << GREEN_COL << "ALL TESTS PASSED!!!" << DEFAULT_COL << std::endl;

}

void	small_test_header(std::string description)
{
	std::cout << std::endl << BLUE_COL << "/////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << PURPLE_COL << description << BLUE_COL;
	for (size_t i = 0; i < 105 - description.length(); i++)
	{
		std::cout << "/";
	}
	std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << DEFAULT_COL << std::endl << std::endl;
}

void	big_test_header(std::string description)
{
	std::cout << std::endl << std::endl << YELLOW_COL << "/////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl <<
	"/////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl << PURPLE_COL << description << YELLOW_COL;
	for (size_t i = 0; i < 105 - description.length(); i++)
	{
		std::cout << "/";
	}
	std::cout << std::endl << "/////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl <<
	"/////////////////////////////////////////////////////////////////////////////////////////////////////////" << DEFAULT_COL << std::endl << std::endl << std::endl;
}

bool	check_try_counts(bool og, bool my, std::string test)
{
	std::cout << test << " was tested and ";
	if (og && my)
	{
		std::cout << GREEN_COL << "both threw exception" << DEFAULT_COL << std::endl;
		return true;
	}
	if (!og && my)
	{
		std::cout << RED_COL << "MY threw an exception but OG did not" << DEFAULT_COL << std::endl;
		return false;
	}
	if (og && !my)
	{
		std::cout << RED_COL << "OG threw an exception but MY did not" << DEFAULT_COL << std::endl;
		return false;
	}
	if (!og && !my)
	{
		std::cout << GREEN_COL << "both threw NO exception" << DEFAULT_COL << std::endl;
		return true;
	}
	return true;
}

void	check_scope_diff(scope_diff *vars, std::string message)
{
	// if (vars->curr_scope == vars->prev_scope)
	if (vars->curr_test == 0)
		std::cout << message << GREEN_COL << " was a success!" << DEFAULT_COL << std::endl;
	else
	{
		std::cout << message << RED_COL << " resulted in " << vars->curr_test << " differences" << DEFAULT_COL  << std::endl;		
		vars->curr_scope++;
	}
	vars->curr_test = 0;
}


void	reset_scope_diff(scope_diff *vars)
{
	vars->global_diff += vars->curr_scope;
	vars->curr_scope = 0;
	// vars->prev_scope = 0;
	vars->curr_test = 0;
}
void	init_scope_diff(scope_diff *vars)
{
	vars->global_diff = 0;
	vars->curr_scope = 0;
	// vars->prev_scope = 0;
	vars->curr_test = 0;
}

void	check_cap_and_size(std::vector<int> *og, ft::vector<int> *my, std::string message, scope_diff *vars)
{
	if (og->size() != my->size())
	{	
		std::cout << message << RED_COL << " results in difference in size" << 
		std::endl << "og size = " << og->size() << std::endl << "my size = " << my->size() << DEFAULT_COL << std::endl;
		vars->curr_test++;
	}
	if (og->capacity() != my->capacity())
	{	
		std::cout << message << RED_COL << " results in difference in capacity" << 
		std::endl << "og capacity = " << og->capacity() << std::endl << "my capacity = " << my->capacity() << DEFAULT_COL << std::endl;
		vars->curr_test++;
	}
	if ((og->size() == my->size()) && (og->capacity() == my->capacity()))
	{	
		std::cout << message << GREEN_COL << " results in no differences in capacity or size" << DEFAULT_COL << std::endl;
	}
		
}