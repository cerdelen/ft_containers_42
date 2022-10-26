/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:54:43 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/26 20:22:06 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_IT
#define REV_IT
#include "iterator_base.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		public:
			typedef				Iterator											iterator_type;
			typedef typename	ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename	ft::iterator_traits<Iterator>::reference			reference;
			typedef typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;

		private:
			iterator_type		_base_it;


		public:
			// constructors
			reverse_iterator ( void ) : _base_it() 
			{
			}

			explicit	reverse_iterator ( iterator_type it ) : _base_it(it) 
			{
			}

			template<class Iter>
			reverse_iterator ( const reverse_iterator<Iter> &it ) : _base_it(it.base())
			{
			}
			
			virtual ~reverse_iterator(void) 
			{
			}





			
			reverse_iterator &		operator=(const reverse_iterator &other)
			{
				_base_it = other._base_it;
				return (*this);
			}

			pointer 				base(void) const
			{
				return (_base_it.base());
			}

			reference 				operator*(void) const
			{
				return (*_base_it);
			}
			
			pointer					operator->(void) const
			{
				return (&(operator*()));
			}
			
			reverse_iterator &		operator++(void)
			{
				_base_it--;
				return (*this);
			}
			
			reverse_iterator		operator++(int)
			{
				reverse_iterator	temp(*this);
				_base_it--;
				return (temp);
			}
			
			reverse_iterator &		operator--(void)
			{
				// std::cout << "after" << std::endl;
				_base_it++;
				return (*this);
			}
			
			reverse_iterator		operator--(int)
			{
				// std::cout << "pre" << std::endl;
				reverse_iterator	temp(*this);
				// std::cout << "pre test1" << std::endl;
				_base_it++;
				// std::cout << "pre test2" << std::endl;
				return (temp);
			}

			reverse_iterator		operator+(difference_type n) const
			{
				return (reverse_iterator(this->_base_it - n));
			}
			
			reverse_iterator		operator-(difference_type n) const
			{
				return (reverse_iterator(this->_base_it + n));
			}
			
			reverse_iterator &		operator+=(difference_type n)
			{
				*this = *this + n;
				return (*this);
			}
			
			reverse_iterator &		operator-=(difference_type n)
			{
				*this = *this - n;
				return (*this);
			}
			
			reference				operator[](difference_type n) const
			{
				return (base()[-n - 1]);
			}

			bool		operator==(const reverse_iterator& other) const
			{
				return ( _base_it == other._base_it);
			}
			
			bool		operator!=(const reverse_iterator& other) const
			{
				return (!( _base_it == other._base_it));
			}



	};
}
#endif