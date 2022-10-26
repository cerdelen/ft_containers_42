/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:19:44 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/26 14:45:02 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_CPE
#define FT_UTILS_CPE

namespace ft
{
	template<class T>
	struct rbt_node
	{
		typedef T				value_type;
		bool					col;
		bool					is_left;
		rbt_node*				parent;
		rbt_node*				left_child;
		rbt_node*				right_child;
		T*						value;
	};
	
	template <class T1, class T2>
	class pair
	{
		public:
			typedef	T1 key_type;
			typedef	T2 mapped_type;

			key_type		first;
			mapped_type		second;

			pair( void ) : first(), second()
			{
			}
			pair( const key_type &a, const mapped_type &b ) : first(a), second(b)
			{
			}
			template <class X, class Y>
			pair( const pair<X, Y> &other ) : first(other.first), second(other.second)
			{
			}
			~pair(void)
			{
			}

			pair & operator=( const pair & other )
			{
				first = other.first;
				second = other.second;

				return (*this);
			}
	};

	template< class X, class Y >
	bool operator==(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (first.first == second.first && first.second == second.second);
	}

	template< class X, class Y >
	bool operator!=(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (!(first == second));
	}	
	
	template< class X, class Y >
	bool operator<(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		if (first.first == second.first)
			return (first.second < second.second);
		return (first.first < second.first);
	}	
	
	template< class X, class Y >
	bool operator<=(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (!(first > second));
	}	

	template< class X, class Y >
	bool operator>(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (second < first);
	}	
	
	template< class X, class Y >
	bool operator>=(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (!(first < second));
	}

	template< class X, class Y >
	ft::pair<X,Y>		make_pair( X key_, Y val_ )
	{
		return (pair<X, Y>(key_, val_));
	};


	//Checks if the first range (first1, last1) is lexicographically less than the second range (first2, last2).
	template<class T1, class T2>
	bool		lexicographical_compare(T1 start1, T1 end1, T2 start2, T2 end2)
	{
		while(start1 != end1 && start2 != end2)
		{
			// std::cout << "hiello " << *start1 << " " << *start2 << std::endl;
			// std::cout << "hiello " << std::endl;
			if (*start1 < *start2)
			{
				// std::cout << "xcusssseeee meeee " << std::endl;
				return (true);
			}
			if (*start1 > *start2)
			{
				// std::cout << "xcusssseeee meeee 2 " << std::endl;
				return (false);
			}
			// std::cout << "byeeeooooo" << std::endl;
			start1++;
			start2++;
		}
		// if both conditions 2 it means first range is smaller and second range is not reached end therefore returns true
		// if (start1 == end1)
		// 	return true;
		// if( start2 == end2)
		// 	return false;
		return (start1 == end1 && start2 != end2);
	}
	template<class T1, class T2>
	bool		equal(T1 start1, T1 end1, T2 start2, T2 end2)
	{
		while(start1 != end1 && start2 != end2)
		{
			if (*start1 != *start2)
				return (false);
			start1++;
			start2++;
		}
		return (start1 == end1 && start2 == end2);
	}
}

#endif