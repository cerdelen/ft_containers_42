/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:10:56 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/29 15:25:31 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"




void	check_scope_diff(scope_diff *vars, std::string message)
{
	if (vars->curr == vars->prev)
		std::cout << message << GREEN_COL << " was a success!" << DEFAULT_COL << std::endl;
	else
		std::cout << message << RED_COL << " resulted in " << vars->curr - vars->prev << "differences" << DEFAULT_COL  << std::endl;
		



}


void	reset_scope_diff(scope_diff *vars)
{
	vars->global_diff += vars->curr;
	vars->curr = 0;
	vars->prev = 0;
}
void	init_scope_diff(scope_diff *vars)
{
	vars->global_diff = 0;
	vars->curr = 0;
	vars->prev = 0;
}

int main()
{
	scope_diff	diff_scope;
	init_scope_diff(&diff_scope);
	test_at(&diff_scope);	
	reset_scope_diff(&diff_scope);
	test_fill_constructor(&diff_scope);



















	end_message(&diff_scope);



	
	
}
