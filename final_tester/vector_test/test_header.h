/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:22:39 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:53:56 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_TEST_HEADER
#define CONTAINERS_TEST_HEADER

#include "../../namespace.hpp"
#include "../colours.h"
#include <vector>
#include <iterator>

struct scope_diff
{
	// size_t	prev_scope;
	size_t	curr_scope;
	size_t	curr_test;
	size_t	global_diff;
};

void	big_test_header(std::string description);
void	small_test_header(std::string description);
bool	check_try_counts(bool og, bool my, std::string test);
void	check_scope_diff(scope_diff *vars, std::string message);
void	end_message(scope_diff *vars);
void	reset_scope_diff(scope_diff *vars);
void	init_scope_diff(scope_diff *vars);
void	test_at(scope_diff *vars);
void	compare_ints_with_message(int og, int my, std::string message, scope_diff *vars);
bool	compare_ints_without_message(int og, int my, scope_diff *vars);
void	test_fill_constructor(scope_diff *vars);
void	test_range_constructor(scope_diff *vars);
void	test_copy_constructor(scope_diff *vars);
void	test_assign(scope_diff *diff_scope);

void	check_cap_and_size(std::vector<size_t> *og, ft::vector<size_t> *my, std::string message, scope_diff *vars);

void	test_get_allocator(scope_diff *vars);
void	test_accessing_functions(scope_diff *vars);




#endif