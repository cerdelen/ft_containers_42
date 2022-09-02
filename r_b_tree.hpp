/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/08/31 21:37:59 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "namespace.hpp"
#include ""


template <typename T , typename Alloc = std::allocator<T> >
class r_b_tree
{
	struct r_b_node
	{
		T			value;
		bool		r_b_id;
		r_b_node	*left_child;
		r_b_node	*right_child;
		r_b_node	*parent;
	};
	
	private:
		r_b_node	*root;
	public:
		r_b_tree();
		~r_b_tree();
};

