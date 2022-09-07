/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:57:27 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/07 17:18:33 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_CPE
#define FT_MAP_CPE
// #include "namespace.hpp"

namespace ft
{
	


	
	template <	class T1, class T2, class Compare = std::less<T1>,
				class Allocator = std::allocator<std::pair<const T1, T2> > >
	class map
	{

						
		typedef T1												key_type;
		typedef T2												mapped_type;
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef Compare											key_compare;
		typedef Allocator										allocator_type;

		
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename allocator_type::size_type				size_type;
		typedef typename allocator_type::difference_type		difference_type;
		
		allocator_type		alloc_;
		
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			// value_compare() {};
			// ~value_compare() {};

			
			public:
				key_compare		comp;
				value_compare(key_compare c) : comp(c) {}
			public:
				bool	operator()(const value_type *first, const value_type *second) const
				{
					return (first->key > second->key);
				}		
		};

		public:
			// map( void );  do i need a standard constructor?
			explicit map( const key_compare & comp = key_compare(), const allocator_type &alloc = allocator_type()) : alloc_(alloc), tree(comp, alloc)     //why explicit?
			{};
			~map() {};


		private:
			typedef ft::r_b_tree< value_type, value_compare, allocator_type >		tree_type;		
		public:
			tree_type			tree;							// will be private
		public:
			// void	insert(const key_type key, const mapped_type val)
			// {
			// 	// allocater = malloc
			// 	// construct = constructor
			// 	// pointer		tmp(key, val);
			// 	// pointer		in = alloc_.allocate(1);			// probably have to allcoate it
				
			// 	// in = alloc_.allocate(1);
			// 	// alloc_.construct(in, tmp);
			// 	tree.insert(in);
			// };
			void	erase();

			void	test_print( void )
			{
				tree.print_tree();
			}
			
	};	
}

#endif