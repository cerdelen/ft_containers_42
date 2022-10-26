/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:57:27 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/26 13:00:00 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_CPE
#define FT_MAP_CPE
#include "../ft_utils/ft_utils.hpp"
#include "../ft_r_b_tree/r_b_tree.hpp"
#include "../ft_r_b_tree/rbt_iterator.hpp"
#include "../ft_utils/reverse_iterator.hpp"

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
				bool	operator()(const key_type &first, const key_type &second) const
				{
					return (comp(first, second));
				}
		};

		public:
			// map( void );  do i need a standard constructor?
			explicit map( const key_compare & comp = key_compare(), const allocator_type &alloc = allocator_type()) : alloc_(alloc), tree(comp, alloc)     //why explicit?
			{
				#if DEBUG
					std::cout << "[MAP] Default constructor called" << std::endl;
				#endif
			};

			~map()
			{
				#if DEBUG
					std::cout << "[MAP] Deconstructor called" << std::endl;
				#endif
			};

			map( const map& other ) : tree(key_compare(), allocator_type())
			{
				#if DEBUG
					std::cout << "[MAP] Copy constructor called" << std::endl;
				#endif
				*this = other;
			};
			
			template< class InputIt >
			map( InputIt first, InputIt last,  const key_compare & comp = key_compare(), const Allocator& alloc = Allocator() ) : alloc_(alloc), tree(comp, alloc)
			{
				#if DEBUG
					std::cout << "[MAP] Range constructor called" << std::endl;
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
			typedef				ft::reverse_iterator<iterator>								reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		public:
			tree_type																tree;
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

			map&				operator=( const map& other )
			{
				clear();
				const_iterator	first = other.begin();
				const_iterator	last = other.end();
				insert(first, last);
				return (*this);	
			}

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
				return ((*((insert(ft::make_pair(key_, mapped_type()))).first)).second);
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
				iterator		out(tree.last_node());
				
				#if DEBUG
					std::cout << "middle of non_const map.end() with out == " << out.base() << " nil == " << tree.get_nil_node() << std::endl;
				#endif
				out++;
				#if DEBUG
					std::cout << "end of non_const map.end()" << std::endl;
				#endif
				return (out);			
			}
			
			const_iterator		begin( void ) const
			{
				#if DEBUG
					std::cout << "const map.begin() called" << std::endl;
				#endif
				return (const_iterator(tree.begin()));
			}

			const_iterator		end() const
			{
				#if DEBUG
					std::cout << "const map.end() called" << std::endl;
				#endif
				const_iterator		out(tree.last_node());
				out++;
				return (out);	
			}

			//	REVERSE ITERATORS

			reverse_iterator				rbegin( void )
			{
				#if DEBUG
					std::cout << "non_const_reverse map.rbegin() called" << std::endl;
				#endif
				return (reverse_iterator(end()));
			}
			
			reverse_iterator				rend( void )
			{
				#if DEBUG
					std::cout << "non_const_reverse map.rend() called" << std::endl;
				#endif
				return (reverse_iterator(begin()));			
			}
			
			const_reverse_iterator					rbegin( void ) const
			{
				#if DEBUG
					std::cout << "const_reverse map.rbegin() called" << std::endl;
				#endif
				return (reverse_iterator(end()));
			}

			const_reverse_iterator					rend() const
			{
				#if DEBUG
					std::cout << "const_reverse map.rend() called" << std::endl;
				#endif
				return (reverse_iterator(begin()));	
			}

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
			ft::pair<iterator, bool> insert( const value_type& value )
			{
				// std::cout << "Inserting node with value " << value.first << std::endl; 
				// test_print_(true, true, true, false);
				// std::cout << std::endl;
				iterator	it = find(value.first);
				// std::cout << "Inserting node AFTER finding value" << std::endl; 
				if (it == end())
				{
					
					// std::cout << "trying to insert" << std::endl; 
					tree.insert(value);
					it = find(value.first);
					// test_print_(true, true, true, false);
					// std::cout << "Finished inserting node with value " << value.first << std::endl;
					// std::cout << std::endl;
					return (ft::make_pair(it ,true));
				}
				// std::cout << "not trying to insert and exiting insert" << std::endl; 
				return(ft::make_pair(it, false));
			}

			iterator insert( iterator hint, const value_type& value )
			{
				#if DEBUG
					std::cout << "map.insert() with hint called" << std::endl;
				#endif
				if (!(hint.base() == NULL || hint.base() == tree.get_nil_node()))
				{
					value_compare	com(key_comp());
					iterator		tmp = hint;	
					if (((++tmp)--).base() == tree.get_nil_node())									//if hint is last node
					{
						if (com((*tmp), value))													//check if new value is bigger than hint
						{
							#if DEBUG	
								std::cout << "map.insert() case 1" << std::endl;
							#endif
							return (iterator(tree.insert_with_hint(hint.base(), value)));
						}
					}
					else																			//check if new value is bigger than hint and smaller than hint + 1
					{
						if (com((*tmp++), value) && com(value, *tmp))
						{
							#if DEBUG
								std::cout << "map.insert() case 2" << std::endl;
							#endif
							return (iterator(tree.insert_with_hint(hint.base(), value)));
						}
					}
				}
				#if DEBUG
					std::cout << "map.insert() case 3" << std::endl;
				#endif
				ft::pair<iterator, bool> out = insert(value);
				return (out.first);
			}
			
			template< class InputIt >
			void insert( InputIt first, InputIt last )
			{
				while(first != last)
					insert(*(first++));
			}
			
			void				erase( iterator pos )
			{
				tree.erase(pos.base());
			}
			
			void				erase( iterator first, iterator last )
			{
				iterator		tmp;
				for (; first != last;)
				{
					tmp = first;
					// std::cout << "Trying to del " << first->first << std::endl;
					first++;
					erase(tmp);
					// test_print_(true, true, true, false);
					
				}
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
			
			void			swap( map& other )
			{
				tree_type	tmp = other.tree;
				other.tree = tree;
				tree = tmp;
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lookup/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			size_type count( const key_type& key_ ) const
			{				
				return (find(key_) != end());
			}

			iterator find( const key_type& key_ )
			{
				#if DEBUG
					std::cout << "start of map.find() with key = " << key_ << std::endl;
				#endif
				return (iterator(tree.find_key(ft::make_pair<key_type, mapped_type>(key_, mapped_type()))));
			}

			const_iterator find( const key_type& key_ ) const
			{
				return (const_iterator(tree.find_key(ft::make_pair<key_type, mapped_type>(key_, mapped_type()))));
			}

			ft::pair<iterator,iterator>					equal_range( const key_type& key_ )				//still have to do
			{
				return (ft::make_pair(lower_bound(key_), upper_bound(key_)));
			}

			ft::pair<const_iterator,const_iterator>		equal_range( const key_type& key_ ) const		//still have to do
			{
				return (ft::make_pair(lower_bound(key_), upper_bound(key_)));
			}
			
			iterator			lower_bound( const key_type& key_ )
			{
				iterator		it = begin();
				iterator		it_e = end();

				while(it != it_e && (tree.get_compare())(it->first, key_))
					it++;
				return (it);
			}

			const_iterator		lower_bound( const key_type& key_ ) const
			{
				const_iterator		it = begin();
				const_iterator		it_e = end();

				while(it != it_e && (tree.get_compare())(it->first, key_))
					it++;
				return (it);
			}

	// 		iterator upper_bound (const key_type& key)
	// {
	// 	iterator it = tree.begin();
	// 	iterator end = tree.end();
	// 	while(it != end && !key_comp()(key, it->first))
	// 		it++;
	// 	return (it);
	// }

			iterator				upper_bound( const key_type& key_ )
			{
				iterator		it = begin();
				iterator		it_e = end();
				value_compare	com = value_compare(key_comp());

				// while(it != it_e && !((tree.get_compare())(key_, it->first)))
				while(it != it_e && !(com(key_, it->first)))
					it++;
				return (it);
			}
			const_iterator				upper_bound( const key_type& key_ ) const
			{
				const_iterator		it = begin();
				const_iterator		it_e = end();
				value_compare	com = value_compare(key_comp());

				// while(it != it_e && !((tree.get_compare())(key_, it->first)))
				while(it != it_e && !(com(key_, it->first)))
					it++;
				return (it);
			}

			// const_iterator			upper_bound( const key_type& key_ ) const
			// {
			// 	const_iterator		it = begin();
			// 	const_iterator		it_e = end();

			// 	while(it != it_e && !((tree.get_compare())(key_, it->first)))
			// 		it++;
			// 	return (it);
			// }


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Observers//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			key_compare			key_comp() const
			{
				return (key_compare());
			}

			value_compare		value_comp() const
			{
				return (value_compare(key_comp()));
			}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Testing functions//////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			void	test_print_( bool key_, bool col_, bool direction, bool mapped_, bool ptr ) const
			{
				if (ptr)
					std::cout << "nil == " << tree.get_nil_node() << std::cout;
				tree.print_("", tree.get_root_node(), false, key_, mapped_, direction, col_, ptr);
			}
	};	

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Non-member functions///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class Key, class T, class Compare, class Allocator>
	bool operator ==(	const map<Key, T, Compare, Allocator>& first,
						const map<Key, T, Compare, Allocator>& second)
	{
		return ((first.size() == second.size()) && ft::equal(first.begin(), first.end(), second.begin(), second.end()));
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