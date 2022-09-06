/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:19:44 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/06 22:26:30 by cerdelen         ###   ########.fr       */
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
			typedef	T1 first_type;
			typedef	T2 second_type;

			first_type		key;
			second_type		val;	

			pair( void ) : key(), val()
			{
			}
			pair( const first_type &a, const second_type &b ) : key(a), val(b)
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
			// 	new (this) pair(other.first, other.second); // creates new pair 
			// 	return (*this);
			// }
	};
}

#endif