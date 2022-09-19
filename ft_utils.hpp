/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:19:44 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/19 14:32:00 by cerdelen         ###   ########.fr       */
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
}

#endif