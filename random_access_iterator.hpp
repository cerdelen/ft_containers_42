/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:12:16 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/13 19:31:15 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAI_ITERATOR
#define RAI_ITERATOR

#include "iterator_base.hpp"
# include <iostream>

namespace ft
{
	template<typename T>
	class random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:
			typedef typename ft::iterator<random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference				reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;

		protected:
			pointer		_ptr;

		public:
			
		//	Constructor
			// random_access_iterator(/* args */);
														random_access_iterator() : _ptr(nullptr) {};
														random_access_iterator(pointer init_ptr) : _ptr(init_ptr) {};
    		template <class U> 							random_access_iterator(const random_access_iterator<U>& u);		
    												// random_access_iterator(Iterator x);									//idk what this is
    		template <class U> random_access_iterator&	operator=(const random_access_iterator<U>& u);

			
		//	Deconstructor
			~random_access_iterator(){};

		//	Iterator-Functions/Overloads
    		// pointer							base() const;
			// reference						operator*() const;
			// pointer							operator->() const;
			// random_access_iterator&			operator++();
			// random_access_iterator			operator++(int);
			// random_access_iterator&			operator--();
			// random_access_iterator			operator--(int);
			// random_access_iterator			operator+ (difference_type n) const;
			// random_access_iterator&			operator+=(difference_type n);
			// random_access_iterator			operator-(difference_type n) const;
			// random_access_iterator&			operator-=(difference_type n);
			// reference						operator[](difference_type n) const;






			
			// advance					Advance iterator (function template) 
			// distance				Return distance between iterators (function template)
			// begin					Iterator to beginning (function template)
			// end	Iterator to			end (function template)
			// prev					Get iterator to previous element (function template)
			// next					Get iterator to next element (function template)





    		pointer						base() const
			{
				return (_ptr);
			}

    		random_access_iterator&	operator=(const random_access_iterator& u)
			{
				_ptr = u._ptr;
				return (*this);
			}
			
			reference						operator*( void ) const
			{
				return (*_ptr);
			}
			
			random_access_iterator&			operator++( void )
			{
				_ptr++;
				return (*this);
			}
			
			random_access_iterator			operator++(int)
			{
				random_access_iterator	temp(*this);
				_ptr++;
				return (temp);
			}

			random_access_iterator&			operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}
			
			random_access_iterator			operator+(difference_type n) const
			{
				return (random_access_iterator(_ptr + n));
			}

			reference						operator[](difference_type n) const
			{
				return (*(_ptr + n));
			}

			pointer							operator->() const
			{
				return (&(operator*()));
			}

			random_access_iterator			operator-(difference_type n) const
			{
				return (random_access_iterator(_ptr - n));
			}

			random_access_iterator&			operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}

			random_access_iterator&			operator--( void )
			{
				_ptr++;
				return (*this);
			}
			
			random_access_iterator			operator--(int)
			{
				random_access_iterator	temp(*this);
				_ptr++;
				return (temp);
			}
	};


	

	template<typename T1, typename T2>
	bool		operator!=(const random_access_iterator<T1>& first, const random_access_iterator<T2>& second)
	{
		return (first.base() != second.base());
	}
	template<typename T1, typename T2>
	bool		operator==(const random_access_iterator<T1>& first, const random_access_iterator<T2>& second)
	{
		return (first.base() == second.base());
	}
	template<typename T1, typename T2>
	bool		operator<(const random_access_iterator<T1>& first, const random_access_iterator<T2>& second)
	{
		return (first.base() < second.base());
	}
	template<typename T1, typename T2>
	bool		operator>(const random_access_iterator<T1>& first, const random_access_iterator<T2>& second)
	{
		return (first.base() > second.base());
	}
	template<typename T1, typename T2>
	bool		operator>=(const random_access_iterator<T1>& first, const random_access_iterator<T2>& second)
	{
		return (first.base() >= second.base());
	}
	template<typename T1, typename T2>
	bool		operator<=(const random_access_iterator<T1>& first, const random_access_iterator<T2>& second)
	{
		return (first.base() <= second.base());
	}
	



	









}





#endif