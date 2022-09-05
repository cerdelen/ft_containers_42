/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/03 17:55:47 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_B_TREE
#define R_B_TREE
#include "namespace.hpp"

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			typedef	T1 first_type;
			typedef	T2 second_type;
			
			pair( void ) : _first(), _second()
			{
			}
			pair( const first_type &a, const second_type &b ) : _first(a), _second(b)
			{
			}
			template <class X, class Y>
			pair( const pair<X, Y> &other ) : _first(other._first), _second(other._second)
			{
			}
			~pair(void)
			{
			}


			const pair & operator=( const pair & other )
			{
				_first = other._first;
				_second = other._second;
				return (*this);
			}

			first_type		_first;
			second_type		_second;	
	};

	template <typename Key, typename T,
				class Alloc = std::allocator<pair<const Key, T> >, class Compare = std::less<Key> >
	class r_b_tree
	{
			struct node;

			typedef				Key									key_type;
			typedef				T									mapped_type;
			typedef				ft::pair<const Key, T>				value_type;
			typedef				Alloc								allocator_type;
			typedef typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;
			typedef				ptrdiff_t							difference_type;
			typedef				size_t								size_type;
			typedef				node*								iter;
			typedef	const		node*								const_iter;
			typedef				Compare								key_compare;


		struct r_b_node
		{
			T			value;
			bool		red;
			r_b_node	*left_child;
			r_b_node	*right_child;
			r_b_node	*parent;
		};
		
		private:
			r_b_node	*_root;
			r_b_node	&get_note( void )
			{
				r_b_node	*tmp = new r_b_node;

				tmp->red = true;

				// r_b_node.left = true;
				
					
			}
			
		public:
			r_b_tree();
			~r_b_tree();

			
			template <class T1>
			insert( pair val )
			{
				if (!_root)
				{
					//create node ... root = node ... make node black
					// (some kind of root constructor ... left and right child = null ... colour = red value = pair)
				}
			}
	};
}
#endif