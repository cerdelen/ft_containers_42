/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:57:27 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/03 17:30:20 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_CPE
#define FT_MAP_CPE
#include "ft_utils.hpp"
// #include "rbt_iterator.hpp"
#include "r_b_tree.hpp"
#include "rbt_iterator_new.hpp"

namespace ft
{	
	template <	class T1, class T2, class Compare = std::less<T1>,
				class Allocator = std::allocator<ft::pair<const T1, T2> > >
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
				bool	operator()(const value_type &first, const value_type &second) const
				{
					return (comp(first.first, second.first));
				}		
		};

		public:
			// map( void );  do i need a standard constructor?
			explicit map( const key_compare & comp = key_compare(), const allocator_type &alloc = allocator_type()) : alloc_(alloc), tree(comp, alloc)     //why explicit?
			{
				#if DEBUG
					std::cout << "default map constructor called" << std::endl;
				#endif
			};

			~map()
			{
				#if DEBUG
					std::cout << "default map Deconstructor called" << std::endl;
				#endif
			};

			map( const map& other ) : tree(key_compare(), allocator_type())
			{
				#if DEBUG
					std::cout << "copy map constructor called" << std::endl;
				#endif
				*this = other;
			};
			
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			{
				#if DEBUG
					std::cout << "map range input constructor called" << std::endl;
				#endif
				while (first != last)
				{
					insert(*first);
					first++;
				}
			};






		private:
			typedef ft::r_b_tree< value_type, value_compare, allocator_type >				tree_type;		
		public:
			typedef				rbt_iterator_new<ft::rbt_node<value_type> >					iterator;
			typedef				const_rbt_iterator_new<ft::rbt_node<value_type> >			const_iterator;
			// typedef				rbt_iterator<value_type, tree_type>					iterator;
			// typedef				const_rbt_iterator<value_type, tree_type>			const_iterator;
		public:
			tree_type																tree;							// will be private		//still have to do (set private)
		public:
		


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member functions(declaration only)/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			// Member functions
			// 	operator=
			// 	get_allocator

			// Element access
			// 	at
			// 	operator[]
			
			// Iterators
			// 	begin
			// 	end
			// 	rbegin
			// 	rend

			// Capacity
			// 	empty
			// 	size
			// 	max_size

			// Modifiers
			// 	clear
			// 	insert
			// 	erase
			// 	swap

			// Lookup
			// 	count
			// 	find
			// 	equal_range
			// 	lower_bound
			// 	upper_bound

			// Observers
			// 	key_comp
			// 	value_comp

			// Non-member functions
			// 	operator==
			// 	operator!=
			// 	operator<
			// 	operator<=
			// 	operator>
			// 	operator>=



/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member functions///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			// map&				operator=( const map& other )
			// {
			// 	this->clear();
			// 	const_iterator	first = other.begin();
			// 	const_iterator	last = other.end();
			// 	while(first != last)
			// 	{
			// 		this->tree.insert(*first);
			// 		first++;
			// 	}
			// 	return (*this);	
			// }

			allocator_type		get_allocator( void ) const
			{
				return (this->tree.get_allocator());
			}
			


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Element access/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			mapped_type&			at( const key_type& key_ )
			{
				iterator	it = find(key_);
				return ((*it).second);
			}
			
			const mapped_type&		at( const key_type& key_ ) const
			{
				iterator	it = find(key_);
				return ((*it).second);
			}

			mapped_type&			operator[]( const key_type& key_ )
			{
				iterator	it = find(key_);
				if (it != end())
					return ((*it).second);
				return ((*(insert(ft::make_pair(key_, mapped_type())))).second);
				
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Iterators//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			iterator				begin( void )
			{
				#if DEBUG
					std::cout << "non_const map.begin() called" << std::endl;
				#endif
				return (iterator(tree.begin()));
			}
			
			iterator				end( void )
			{
				#if DEBUG
					std::cout << "non_const map.end() called" << std::endl;
				#endif
				iterator		out = tree.last_node();
				out++;
				return (out);			
			}
			
			const_iterator		begin( void ) const						//still have to do
			{
				#if DEBUG
					std::cout << "const map.begin() called" << std::endl;
				#endif
				return (const_iterator(tree.begin()));
			}

			const_iterator		end() const							//still have to do
			{
				#if DEBUG
					std::cout << "const map.end() called" << std::endl;
				#endif
				const_iterator		out = tree.last_node();
				out++;
				return (out);	
			}




			// 	rbegin														//still have to do
			// 	rend														//still have to do

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Capacity///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			bool		empty() const
			{
				return (tree.empty());
			}
			size_type	size() const
			{
				return (tree.getSize());
			}
			size_type		max_size( void )
			{
				return (tree.max_size());
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Modifiers//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			void	clear( void )
			{
				tree.clear();
			}
			ft::pair<iterator, bool> insert( const value_type& value )								//still have to do
			{
				iterator	it = find(value.first);
				if (it == end())
				{
					tree.insert(value);
					it = find(value.first);
					return (ft::make_pair(it ,true));
				}
				return(ft::make_pair(it, false));
			}
			iterator insert( iterator hint, const value_type& value )							//still have to do
			{

			}
			
			template< class InputIt >
			void insert( InputIt first, InputIt last )											//still have to do
			{

			}
			
			void				erase( iterator pos )
			{
				tree.erase(pos.base());
			}
			
			void				erase( iterator first, iterator last )
			{
				for (; first != last; first++)
					erase(first);
			}
			
			size_type			erase( const key_type & key_ )			//returns the number of elements lost (0 or 1)
			{
				iterator	it = find(key_);
				if (it != end())
				{
					erase(it);
					return (1);	
				}
				return (0);
			}
			
			void			swap( map& other )							//still have to do
			{
				
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lookup/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			// 	count										//still have to do
			// 	find										//still have to do
			iterator find( const key_type& key_ )
			{
				iterator	it = iterator(tree.begin(), &tree);
				iterator	it_end = iterator(tree.end(), &tree);
				for (; it.base() != it_end.base(); it++)
				{
					if ((*it).first == key_)
						break ;
				}
				return (it);
			}
			// const_iterator find( const key_type& key ) const;

			ft::pair<iterator,iterator>					equal_range( const key_type& key_ )				//still have to do
			{
				
			}

			// ft::pair<const_iterator,const_iterator>		equal_range( const key_type& key ) const		//still have to do
			// {
				
			// }

			// 	lower_bound			//still have to do
			
			// 	upper_bound			//still have to do

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Observers//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			// key_compare key_comp() const			//still have to do
			// {
			// 	return (key_compare());
			// }

				// value_comp						//still have to do

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Non-member functions///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			// 	operator==					//still have to do
			// 	operator!=					//still have to do
			// 	operator<					//still have to do
			// 	operator<=					//still have to do
			// 	operator>					//still have to do
			// 	operator>=					//still have to do


			void	test_print_key( void )
			{
				tree.print_tree_key();
			}
			void	test_print_val( void )
			{
				tree.print_tree_val();
			}
			void	test_print_comp( void )
			{
				tree.print_tree_comp();
			}
			void	test_print_comp_with_ptr( void )
			{
				tree.print_tree_comp_with_ptr();
			}
			
	};	


template <class Key, class T, class Compare, class Allocator>
	bool operator ==(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return ((first.size() != second.size()) && ft::equal(first.begin(), first.end(), second.begin(), second.end()));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator !=(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return (!(first == second));
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator <(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return (ft::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end()));
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator >(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return (second < first);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator >=(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return (!(first < second));
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator <=(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return (!(first > second));
	}
}

#endif