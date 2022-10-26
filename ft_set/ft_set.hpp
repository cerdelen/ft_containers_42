/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:49:51 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/26 20:21:47 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_utils/ft_utils.hpp"
#include "../ft_r_b_tree/r_b_tree.hpp"
#include "../ft_r_b_tree/rbt_iterator.hpp"
#include "../ft_utils/reverse_iterator.hpp"

namespace ft
{
	template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
			typedef				Key										key_type;
			typedef				Key										value_type;
			typedef				std::size_t								size_type;
			typedef				std::ptrdiff_t							difference_type;
			typedef				Compare									key_compare;
			typedef				Compare									value_compare;
			typedef				Allocator								allocator_type;
			typedef				value_type &							reference;
			typedef				const value_type &						const_reference;
			typedef typename	Allocator::pointer						pointer;
			typedef typename	Allocator::const_pointer				const_pointer;


		private:
			typedef ft::r_b_tree< value_type, value_compare, allocator_type >				tree_type;
		public:
			typedef				rbt_iterator_new<ft::rbt_node<value_type> >					iterator;
			typedef				const_rbt_iterator_new<ft::rbt_node<value_type> >			const_iterator;
			typedef				ft::reverse_iterator<iterator>								reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		private:
			tree_type		tree;

		public:

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member functions(declaration only)/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
			//	Member functions
			//		Constructor
			//		Deconstructor
			//		operator=
			//		get_allocator


			//	Iterators
			//		begin
			//		end
			//		rbegin
			//		rend

			//	Capacity
			//		empty
			//		size
			//		max_size

			//	Modifiers
			//		clear
			//		insert
			//		erase
			//		swap

			//	Lookup
			//		count
			//		find
			//		equal_range
			//		lower_bound
			//		upper_bound

			//	Observers
			//		key_comp
			//		value_comp

			//	Non-member functions
			//		operator==
			//		operator!=
			//		operator<=
			//		operator>=
			//		operator>
			//		operator<


			
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member functions///////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			set( void ) : tree(value_compare(), allocator_type())
			{
				
			}
			explicit	set( const Compare& comp, const Allocator& alloc = Allocator()) : tree(comp, alloc)
			{
				
			}

			template< class InputIt >
			set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ) : tree(comp, alloc)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}
						
			set(const set &copy) : tree(copy.value_comp(), copy.get_allocator())
			{
				*this = copy;
			}

			set	&operator=(const set& other)
			{
				clear();
				const_iterator		begin = other.begin();
				const_iterator		end = other.end();
				while (begin != end)
				{
					tree.insert(*begin);
					begin++;
				}
				return (*this);
			}
			
			~set()
			{
				tree.clear();
				tree.delete_node(tree.get_nil_node());
			}

			allocator_type		get_allocator() const
			{
				return (tree.get_allocator());
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Iterators//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			iterator			begin( void )
			{
				return (tree.begin());
			}
			const_iterator		begin( void ) const
			{
				return (tree.begin());
			}
			iterator			end( void )
			{
				iterator		out(tree.last_node());
				out++;
				return (out);
			}
			const_iterator		end( void ) const
			{
				const_iterator		out(tree.last_node());
				out++;
				return (out);
			}
			
			
			// reverse_iterator			rbegin( void )
			// {
			// 	return (reverse_iterator(tree.end()));
			// }
			// const_reverse_iterator		rbegin( void ) const
			// {
			// 	return (const_reverse_iterator(tree.end()));
			// }
			// reverse_iterator			rend( void )
			// {
			// 	return (reverse_iterator(tree.begin()));
			// }
			// const_reverse_iterator		rend( void ) const
			// {
			// 	return (const_reverse_iterator(tree.begin()));
			// }
			reverse_iterator						rbegin( void )
			{
				iterator					tmp(end());
				tmp--;
				reverse_iterator			out(tmp);
				return (out);
			}
			
			const_reverse_iterator					rbegin( void ) const
			{
				const_iterator					tmp(end());
				tmp--;
				const_reverse_iterator			out(tmp);
				return (out);
			}

			reverse_iterator						rend( void )
			{
				iterator					tmp(begin());
				tmp--;
				reverse_iterator			out(tmp);
				return (out);
			}
			
			const_reverse_iterator					rend() const
			{
				const_iterator					tmp(begin());
				tmp--;
				const_reverse_iterator			out(tmp);
				return (out);
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Capacity///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			bool		empty( void ) const
			{
				return (tree.empty());
			}

			size_type	size( void ) const
			{
				return (tree.getSize());
			}
			
			size_type	max_size( void ) const
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
				erase(tree.begin(), tree.end());
			}

			pair<iterator, bool>		insert( const value_type& value )
			{
				// pair<key_type, bool>		blob = make_pair<key_type, bool>(value, true);
				iterator	it = find(value);
				if (it == end())
				{
					tree.insert(value);
					it = find(value);
					return (ft::make_pair(it ,true));
				}
				return(ft::make_pair(it, false));
			}

			iterator					insert( iterator hint, const value_type& value )
			{
				if (!(hint.base() == NULL || hint.base() == tree.get_nil_node()))
				{
					value_compare	com(key_comp());
					iterator		tmp = hint;	
					if (((++tmp)--).base() == tree.get_nil_node())									//if hint is last node
					{
						if (com((*tmp), value))													//check if new value is bigger than hint
							return (iterator(tree.insert_with_hint(hint.base(), value)));
					}
					else																			//check if new value is bigger than hint and smaller than hint + 1
					{
						if (com((*tmp++), value) && com(value, *tmp))
							return (iterator(tree.insert_with_hint(hint.base(), value)));
					}
				}
				ft::pair<iterator, bool> out = insert(value);
				return (out.first);
			}

			template< class InputIt >
			void						insert( InputIt first, InputIt last )
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

		
			void					erase( iterator pos )
			{
				tree.erase(pos.base());
			}

			void					erase( iterator first, iterator last )
			{
				iterator		tmp;
				for (; first != last;)
				{
					tmp = first;
					first++;
					erase(tmp);
				}
			}

			size_type					erase( const Key& key_ )
			{
				iterator	it = find(key_);
				if (it != end())
				{
					erase(it);
					return (1);	
				}
				return (0);
			}

			void						swap( set& other )
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

			size_type		count( const Key& key ) const
			{
				return (find(key) != end());
			}

			iterator		find( const key_type& key_ )
			{
				#if DEBUG
					std::cout << "start of map.find() with key = " << key_ << std::endl;
				#endif
				return (iterator(tree.find_key(key_)));
			}

			const_iterator	find( const key_type& key_ ) const
			{
				return (const_iterator(tree.find_key(key_)));
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

				while(it != it_e && (tree.get_compare())(*it, key_))
					it++;
				return (it);
			}

			const_iterator		lower_bound( const key_type& key_ ) const
			{
				const_iterator		it = begin();
				const_iterator		it_e = end();

				while(it != it_e && (tree.get_compare())(*it, key_))
					it++;
				return (it);
			}

			iterator				upper_bound( const key_type& key_ )
			{
				iterator		it = begin();
				iterator		it_e = end();
				value_compare	com = value_compare(key_comp());

				// while(it != it_e && !((tree.get_compare())(key_, it->first)))
				while(it != it_e && !(com(key_, *it)))
					it++;
				return (it);
			}
			const_iterator				upper_bound( const key_type& key_ ) const
			{
				const_iterator		it = begin();
				const_iterator		it_e = end();
				value_compare	com = value_compare(key_comp());

				// while(it != it_e && !((tree.get_compare())(key_, it->first)))
				while(it != it_e && !(com(key_, *it)))
					it++;
				return (it);
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Observers//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			key_compare		key_comp( void ) const
			{
				return (tree.get_compare());
			}

			value_compare	value_comp( void ) const
			{
				return (tree.get_compare());
			}


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Non-member functions///////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//utils//////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

	}; // class stack	
	
	template<class Key, class Compare, class Allocator >
	bool		operator==( const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs)
	{
		return (rhs.size() == lhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	
	template<class Key, class Compare, class Allocator >
	bool		operator!=( const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class Key, class Compare, class Allocator >
	bool		operator<( const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class Compare, class Allocator >
	bool		operator>( const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class Compare, class Allocator >
	bool		operator<=( const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class Key, class Compare, class Allocator >
	bool		operator>=( const set<Key, Compare, Allocator> &lhs, const set<Key, Compare, Allocator> &rhs)
	{
		return (!(lhs < rhs));
	}




	


} // namespace ft
