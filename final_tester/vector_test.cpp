/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:10:56 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:32:05 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_test/test_header.h"






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
	test_assign(&diff_scope);
	reset_scope_diff(&diff_scope);
	test_accessing_functions(&diff_scope);
	reset_scope_diff(&diff_scope);
	end_message(&diff_scope);	
}