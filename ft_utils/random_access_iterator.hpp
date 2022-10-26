/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:12:16 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/26 11:29:28 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAI_ITERATOR
#define RAI_ITERATOR

#include "iterator_base.hpp"
# include <iostream>

namespace ft
{
	template<typename T>
	class const_random_access_iterator;
	
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
			//default constructor
			random_access_iterator() : _ptr(nullptr) {};
			//copy constructo
			random_access_iterator(const random_access_iterator& copy) : _ptr(copy.base()) {};	
			//ptr contructor
			random_access_iterator(pointer init_ptr) : _ptr(init_ptr) {};
			//constant copy constructor				
			template <class U> 		
				random_access_iterator(const const_random_access_iterator<T> &copy) : _ptr(copy._ptr) {};
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



			template<typename U>
    		random_access_iterator&	operator=(const const_random_access_iterator<U>& u)
			{
				_ptr = u._ptr;
				return (*this);
			}

    		random_access_iterator&	operator=(const random_access_iterator& u)
			{
				_ptr = u._ptr;
				return (*this);
			}
			
    		pointer						base() const
			{
				return (_ptr);
			}

			reference						operator*( void ) const
			{
				return (*_ptr);
			}
			
			pointer							operator->() const
			{
				return (&(operator*()));
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

			random_access_iterator&			operator--( void )
			{
				_ptr--;
				return (*this);
			}
			
			random_access_iterator			operator--(int)
			{
				random_access_iterator	temp(*this);
				_ptr--;
				return (temp);
			}
			
			random_access_iterator			operator+(difference_type n) const
			{
				return (random_access_iterator(_ptr + n));
			}

			random_access_iterator			operator-(difference_type n) const
			{
				return (random_access_iterator(_ptr - n));
			}
			
			random_access_iterator&			operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}

			random_access_iterator&			operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			
			reference						operator[](difference_type n) const
			{
				return (*(_ptr + n));
			}

			//	logical operators
			bool		operator==(const random_access_iterator<T>& other) const
			{
				return (base() == other.base());
			}

			bool		operator!=(const random_access_iterator<T>& other) const
			{
				return (base() != other.base());
			}

			bool		operator<(const random_access_iterator<T>& other) const
			{
				return (base() < other.base());
			}

			bool		operator>(const random_access_iterator<T>& other) const
			{
				return (base() > other.base());
			}

			bool		operator>=(const random_access_iterator<T>& other) const
			{
				return (base() >= other.base());
			}

			bool		operator<=(const random_access_iterator<T>& other) const
			{
				return (base() <= other.base());
			}

			//logical operators with const iterators
			
			bool		operator==(const const_random_access_iterator<T>& other) const
			{
				return (base() == other.base());
			}

			bool		operator!=(const const_random_access_iterator<T>& other) const
			{
				return (base() != other.base());
			}

			bool		operator<(const const_random_access_iterator<T>& other) const
			{
				return (base() < other.base());
			}

			bool		operator>(const const_random_access_iterator<T>& other) const
			{
				return (base() > other.base());
			}

			bool		operator>=(const const_random_access_iterator<T>& other) const
			{
				return (base() >= other.base());
			}

			bool		operator<=(const const_random_access_iterator<T>& other) const
			{
				return (base() <= other.base());
			}

	};
	
	template<typename T>
	class const_random_access_iterator : public ft::iterator<random_access_iterator_tag, T>
	{
		public:
			typedef const typename ft::iterator<random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<random_access_iterator_tag, T>::reference				reference;
			typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category		iterator_category;

		protected:
			pointer		_ptr;

		public:
			
		//	Constructor
			//default constructor
			const_random_access_iterator() : _ptr(nullptr) {};
			//copy constructo
			const_random_access_iterator(const const_random_access_iterator &copy) : _ptr(copy._ptr) {};
			//ptr contructor
			const_random_access_iterator(pointer init_ptr) : _ptr(init_ptr) {};
			//non_constant copy constructor				
			template <class U> 		
				const_random_access_iterator(const random_access_iterator<U>& copy) : _ptr(copy.base()) {};	
		//	Deconstructor
			~const_random_access_iterator(){};
				

			

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




			const_random_access_iterator&	operator=(const const_random_access_iterator& u)
			{
				_ptr = u._ptr;
				return (*this);
			}

			template<typename U>
    		const_random_access_iterator&	operator=(const random_access_iterator<U>& u)
			{
				_ptr = u._ptr;
				return (*this);
			}
			
    		pointer						base() const
			{
				return (_ptr);
			}

			reference						operator*( void ) const
			{
				return (*_ptr);
			}
			
			pointer							operator->() const
			{
				return (&(operator*()));
			}

			const_random_access_iterator&			operator++( void )
			{
				_ptr++;
				return (*this);
			}
			
			const_random_access_iterator			operator++(int)
			{
				const_random_access_iterator	temp(*this);
				_ptr++;
				return (temp);
			}

			const_random_access_iterator&			operator--( void )
			{
				_ptr++;
				return (*this);
			}
			
			const_random_access_iterator			operator--(int)
			{
				const_random_access_iterator	temp(*this);
				_ptr++;
				return (temp);
			}
			
			const_random_access_iterator			operator+(difference_type n) const
			{
				return (const_random_access_iterator(_ptr + n));
			}

			const_random_access_iterator			operator-(difference_type n) const
			{
				return (const_random_access_iterator(_ptr - n));
			}
			
			const_random_access_iterator&			operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}

			const_random_access_iterator&			operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
			
			reference						operator[](difference_type n) const
			{
				return (*(_ptr + n));
			}

			//	logical operators
			bool		operator==(const const_random_access_iterator<T>& other) const
			{
				return (base() == other.base());
			}

			bool		operator!=(const const_random_access_iterator<T>& other) const
			{
				return (base() != other.base());
			}

			bool		operator<(const const_random_access_iterator<T>& other) const
			{
				return (base() < other.base());
			}

			bool		operator>(const const_random_access_iterator<T>& other) const
			{
				return (base() > other.base());
			}

			bool		operator>=(const const_random_access_iterator<T>& other) const
			{
				return (base() >= other.base());
			}

			bool		operator<=(const const_random_access_iterator<T>& other) const
			{
				return (base() <= other.base());
			}

			//logical operators with non_const iterators
			
			bool		operator==(const random_access_iterator<T>& other) const
			{
				return (base() == other.base());
			}

			bool		operator!=(const random_access_iterator<T>& other) const
			{
				return (base() != other.base());
			}

			bool		operator<(const random_access_iterator<T>& other) const
			{
				return (base() < other.base());
			}

			bool		operator>(const random_access_iterator<T>& other) const
			{
				return (base() > other.base());
			}

			bool		operator>=(const random_access_iterator<T>& other) const
			{
				return (base() >= other.base());
			}

			bool		operator<=(const random_access_iterator<T>& other) const
			{
				return (base() <= other.base());
			}

	};


	
}





#endif