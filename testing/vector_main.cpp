/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:10:56 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/17 18:46:40 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"






int main()
{
	scope_diff	diff_scope;
	init_scope_diff(&diff_scope);
	test_at(&diff_scope);	
	reset_scope_diff(&diff_scope);
	test_fill_constructor(&diff_scope);
	reset_scope_diff(&diff_scope);
	test_range_constructor(&diff_scope);
	reset_scope_diff(&diff_scope);
	test_copy_constructor(&diff_scope);
	reset_scope_diff(&diff_scope);
	// test_operator_equal(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_get_allocator(&diff_scope);
	// reset_scope_diff(&diff_scope);
	test_assign(&diff_scope);
	reset_scope_diff(&diff_scope);


	test_accessing_functions(&diff_scope);
	reset_scope_diff(&diff_scope);
	
	



	
	// test_begin(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_rbegin(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_end(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_rend(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_empty(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_size(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_max_size(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_reserve(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_capacity(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_clear(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_insert(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_erase(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_push_bash(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_pop_back(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_resize(&diff_scope);
	// reset_scope_diff(&diff_scope);
	// test_swap(&diff_scope);
	// reset_scope_diff(&diff_scope);






	//missing the logical operators
	// test_(&diff_scope);
	// test_(&diff_scope);
	// test_(&diff_scope);

	










	end_message(&diff_scope);	
}