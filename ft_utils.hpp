/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:19:44 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/23 14:12:41 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_CPE
#define FT_UTILS_CPE

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
			typedef	T1 key_type;
			typedef	T2 mapped_type;

			key_type		key;
			mapped_type		val;	

			pair( void ) : key(), val()
			{
			}
			pair( const key_type &a, const mapped_type &b ) : key(a), val(b)
			{
			}
			template <class X, class Y>
			pair( const pair<X, Y> &other ) : key(other.key), val(other.val)
			{
			}
			~pair(void)
			{
			}


			
			
			// const pair & operator=( const pair & other )
			// {
			// 	key = other.key;
			// 	val = other.val;
				
			// 	new (this) pair(other.first, other.second); // creates new pair 
			// 	return (*this);
			// }
	};

	template< class X, class Y >
	bool operator==(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (first.key == second.key && first.val == second.val);
	}

	template< class X, class Y >
	bool operator!=(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (first.key != second.key || first.val != second.val);
	}	
	
	template< class X, class Y >
	bool operator<(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (first < second);
	}	
	
	template< class X, class Y >
	bool operator<=(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (!(first > second));
	}	

	template< class X, class Y >
	bool operator>(const pair<X, Y>& first, const pair<X, Y>& second)
	{
		return (first > second);
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
			if (*start1 < *start2)
				return (true);
			if (*start1 > *start2)
				return (false);
			start1++;
			start2++;
		}
		// if both conditions 2 it means first range is smaller and second range is not reached end therefore returns true
		return (start1 == end1 && start2 != end2);
	}
}

#endif