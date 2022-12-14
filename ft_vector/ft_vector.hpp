/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:54:57 by cerdelen          #+#    #+#             */
/*   Updated: 2022/11/01 10:46:41 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_P_VECTOR
#define C_P_VECTOR
#include <memory>

#include "../ft_utils/reverse_iterator.hpp"				// includes random_access_iterators and reverse iterators
#include "../ft_utils/ft_utils.hpp"

namespace ft
{
	template <typename T , typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef typename	allocator_type::reference				reference;
			typedef typename	allocator_type::const_reference			const_reference;
			typedef typename	allocator_type::pointer					pointer;
			typedef typename	allocator_type::const_pointer			const_pointer;
			typedef typename	allocator_type::size_type				size_type;



			// es fehlen noch die typedef typenames für die iterators
			
			
			
			typedef typename ft::random_access_iterator<T> 					iterator;
			typedef	typename ft::const_random_access_iterator<const T>		const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;


			// difference_type	
			// typedef typename allocator_type::difference_type difference_type;
			
			

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructors///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//		Default Constructor:
//				(empty container with no elements)

			explicit vector(const allocator_type &alloc = allocator_type()) : _start(NULL), _end(NULL), _alloc(alloc), _capacity(0){
				#if DEBUG
					std::cout << "[VECTOR] Default constructor called" << std::endl;
				#endif
			};

//		Fill Constructor:
//				with n elements >> each a copy of val

			explicit vector(size_t n, const value_type &val,\
				const allocator_type &alloc = allocator_type()) :  _start(NULL), _end(NULL), _alloc(alloc), _capacity(n)
			{
				#if DEBUG
					std::cout << "[VECTOR] Fill constructor called" << std::endl;
				#endif
				_start = _alloc.allocate(n);
				_end = _start;
				while (n--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			};

//		Range Constructor:
//				constructs with as many elementes as range [first > last], filling it same order as in range of elements

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,\
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL)
				: _start(NULL), _end(NULL), _alloc(alloc), _capacity(last.base() - first.base())
				{
					#if DEBUG
						std::cout << "[VECTOR] Range constructor called" << std::endl;
					#endif
					_start = _alloc.allocate(last.base() - first.base());
					_end = _start;
					while(first != last)
					{
						_alloc.construct(_end, *first);
						_end++;
						first++;
					}
				};

// 		Copy Constructor:
// 				Constructs a container with a copy of each of the elements in x, in the same order.

			vector ( const vector& x, const allocator_type &alloc = allocator_type()): _start(NULL), _end(NULL),_alloc(alloc),  _capacity(0)
			{
				#if DEBUG
					std::cout << "[VECTOR] Copy constructor called" << std::endl;
				#endif
				assign(x.begin(), x.end());
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Deconstructor//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			~vector()
			{
				for (size_type i = 0; _start + i != _end; i++)
				{
					_alloc.destroy(_start + i);
				}
				_alloc.deallocate(_start, _capacity);	
			};

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member functions(declaration only)/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			// Member functions
				// bool				operator=();
				// void				assign();
				// allocator_type	get_allocator();


			// Element accsess 
				// reference		at();
				// reference		operator[]();
				// reference		front();
				// reference		back();
				// T*				data();
			

			// Iterators
				// iterator			begin();
				// iterator			rbegin();
				// iterator			end();
				// iterator			rend();


			// Capacity
				// bool				empty();
				// size_type		size();
				// size_type		max_size();
				// void				reserve();
				// size_type		capacity();
			

			// Modifiers
				// void				clear();
				// iterator			insert();
				// iterator			erase();
				// void				push_back();
				// void				pop_back();
				// void				resize();
				// void				swap();


			// Non-Member functions
				// void		operator==();				//still have to do
				// void		operator!=();				//still have to do
				// void		operator<();				//still have to do
				// void		operator<=();				//still have to do
				// void		operator>();				//still have to do
				// void		operator>=();				//still have to do


		private:
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Private Member Attributes//////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			pointer				_start;
			pointer				_end;
			allocator_type		_alloc;
			size_type			_capacity;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Private Helper functions///////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
			size_type		next_pow_2(unsigned int v)
			{
				register unsigned int r; // result of log2(v) will go here
				register unsigned int shift;

				r =		(v > 0xFFFF) << 4; v >>= r;
				shift = (v > 0xFF  ) << 3; v >>= shift; r |= shift;
				shift = (v > 0xF   ) << 2; v >>= shift; r |= shift;
				shift = (v > 0x3   ) << 1; v >>= shift; r |= shift;
														r |= (v >> 1);

				size_type	out = 1 << (r + 1);
				return (out);
			}
			void				make_it_empty( void )
			{
				clear();
				if (_start)
					_alloc.deallocate(_start, size());
				_start = NULL;
				_end = NULL;
				_capacity = 0;
			}
		public:
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member function////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////
		//operator=///////////////////////////////////
		//////////////////////////////////////////////
			vector& 			operator=( const vector& other )
			{
				make_it_empty();
				assign(other.begin(), other.end());
				return (*this);
			}
		//////////////////////////////////////////////
		//assign//////////////////////////////////////
		//////////////////////////////////////////////
			void				assign( size_type count, const T& val )
			{
				if (count > max_size())
					throw std::length_error("Bigger than max_size");
				clear();
				if (count > _capacity)
				{
					_alloc.deallocate(_start, _capacity);
					_start = _alloc.allocate(count);
					_capacity = count;
					_end = _start;
				}
				while (count--)
				{
					_alloc.construct(_end, val);
					_end++;
				}
			}
			template< class InputIterator >
			void assign( InputIterator first, InputIterator last, typename ft::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL)
			{
				if ((first.base() > _start && first.base() < _end) || (last.base() > _start && last.base() < _end))			//undefined behaviour if range iterators are inside of vector
					return ;
				size_type	new_size = last.base() - first.base();
				if (new_size > max_size())
				{
					make_it_empty();
					throw std::length_error("Bigger than max_size");
				}
				clear();
				reserve(new_size);
				for (size_type i = 0; first.base() + i != last.base(); i++)
				{
					_alloc.construct(_end, *(first.base() + i));
					_end++;
				}
			}
		//////////////////////////////////////////////
		//get_allocator///////////////////////////////
		//////////////////////////////////////////////
			allocator_type		get_allocator() const
			{
				return (_alloc);
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Element access/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////
		//at//////////////////////////////////////////
		//////////////////////////////////////////////
			reference			at( size_type pos )
			{
				if (_start == NULL)
					throw std::out_of_range("trying to access element with at() of an empty vector");
				if (pos > size())
					throw std::out_of_range("trying to acces element with at() outside of vector range");
				return (*(_start + pos));
			}

			const_reference		at( size_type pos ) const
			{
				if (_start == NULL)
					throw std::out_of_range("trying to access element with at() of an empty vector");
				if (pos > size())
					throw std::out_of_range("trying to acces element with at() outside of vector range");
				return (*(_start + pos));
			}
		//////////////////////////////////////////////
		//operator[]//////////////////////////////////
		//////////////////////////////////////////////
			reference			operator[](size_type n)
			{
				return (*(_start + n));
			}
			const_reference		operator[](size_type n) const
			{
				return (*(_start + n));
			}
		//////////////////////////////////////////////
		//front///////////////////////////////////////
		//////////////////////////////////////////////
			reference			front( void )
			{
				if (!_start)
					throw std::out_of_range("Calling front() of an empty vector");
				if (size() == 0)
					throw std::out_of_range("Calling front() of vector with size 0");
				return (*_start);
			}

			const_reference		front( void ) const
			{
				if (!_start)
					throw std::out_of_range("Calling front() of an empty vector");
				if (size() == 0)
					throw std::out_of_range("Calling front() of vector with size 0");
				return (*_start);
			}
		//////////////////////////////////////////////
		//back////////////////////////////////////////
		//////////////////////////////////////////////
			reference			back( void )
			{
				if (!_end)
					throw std::out_of_range("Calling back() of an empty vector");
				if (size() == 0)
					throw std::out_of_range("Calling back() of vector with size 0");
				return (*(_end - 1));
			}

			const_reference		back( void ) const
			{
				if (!_end)
					throw std::out_of_range("Calling back() of an empty vector");
				if (size() == 0)
					throw std::out_of_range("Calling back() of vector with size 0");
				return (*(_end - 1));
			}
		//////////////////////////////////////////////
		//data////////////////////////////////////////
		//////////////////////////////////////////////
			T*					data()
			{
				return (_start);
			}
			const T*			data() const
			{
				return (_start);
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Iterators//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////
		//begin///////////////////////////////////////
		//////////////////////////////////////////////
			iterator			begin(void)
			{
				return (iterator(_start));
			}
			const_iterator			begin(void) const
			{
				return (const_iterator(_start));
			}
		//////////////////////////////////////////////
		//rbegin//////////////////////////////////////
		//////////////////////////////////////////////
			reverse_iterator		rbegin()
			{
				return (reverse_iterator(_end - 1));
			}
			const_reverse_iterator		rbegin() const
			{
				return (const_reverse_iterator(_end - 1));
			}
		//////////////////////////////////////////////
		//end/////////////////////////////////////////
		//////////////////////////////////////////////
			iterator			end(void)
			{
				return (iterator(_end));
			}
			const_iterator			end(void) const
			{
				return (const_iterator(_end));
			}
		//////////////////////////////////////////////
		//rend////////////////////////////////////////
		//////////////////////////////////////////////
			reverse_iterator				rend()
			{
				return (reverse_iterator(_start));
			}
			const_reverse_iterator				rend() const
			{
				return (const_reverse_iterator(_start));
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Capacity///////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////
		//empty///////////////////////////////////////
		//////////////////////////////////////////////
			bool				empty() const
			{
				return (_start == _end);
			}
		//////////////////////////////////////////////
		//size////////////////////////////////////////
		//////////////////////////////////////////////
			size_type			size( void ) const
			{
				return (_end - _start);
			}
		//////////////////////////////////////////////
		//max_size////////////////////////////////////
		//////////////////////////////////////////////
			size_type			max_size() const
			{
				return (_alloc.max_size());
			}
		//////////////////////////////////////////////
		//reserve/////////////////////////////////////
		//////////////////////////////////////////////
			void				reserve( size_type n )
			{
				if (n > _capacity)
				{
					size_type	old_size = size();
					pointer		tmp = _alloc.allocate(n);

					for (size_type i = 0; i < old_size; i++)
					{
						_alloc.construct(tmp + i, *(_start + i));
						_alloc.destroy(_start + i);
					}
					_alloc.deallocate(_start, _capacity);
					_start = tmp;
					_end = _start + old_size;
					_capacity = n;	
				}
			}
		//////////////////////////////////////////////
		//capacity////////////////////////////////////
		//////////////////////////////////////////////
			size_type			capacity() const
			{
				return (_capacity);
			}
			
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Modifiers//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////
		//clear///////////////////////////////////////
		//////////////////////////////////////////////
			void				clear( void )
			{
				size_type	count = size();
			
				for (size_type i = 0; i < count; i++)
				{
					_alloc.destroy(_end);
					_end--;
				}
			}
		//////////////////////////////////////////////
		//insert//////////////////////////////////////
		//////////////////////////////////////////////
			iterator			insert( iterator pos, const T& value )
			{
				size_type	old_size = size();
				size_type	old_capacity = capacity();
				pointer		tmp;
				pointer		tmp2 = _start;
				size_type	i = 0;

				if ( old_size + 1 > _capacity )
				{
					if ( _capacity * 2 > max_size())
						throw std::length_error("Bigger than max_size");
					tmp = _alloc.allocate(_capacity * 2);
					_capacity = _capacity * 2;	
				}
				else 
				{
					tmp = _alloc.allocate(_capacity);
				}
				while(_start + i != pos.base())
				{
					_alloc.construct(tmp + i, *(_start + i));
					_alloc.destroy(_start + i);
					i++;
				}
				_alloc.construct(tmp + i, value);
				tmp2 = tmp + i;
				i++;
				while (_start + i - 1 != _end)
				{
					_alloc.construct(tmp + i, *(_start + i - 1));
					_alloc.destroy(_start + i - 1);
					i++;
				}
				_alloc.deallocate(_start, old_capacity);
				_start = tmp;
				_end = _start + old_size + 1;
				return (iterator(tmp2));
			}
			void				insert( iterator pos, size_type count, const T& value )
			{
				size_type	old_size = size();
				size_type	old_capacity = capacity();
				pointer		tmp;
				size_type	i = 0;

				if ( old_size + count > _capacity )
				{
					if ( _capacity + count > max_size())
						throw std::length_error("Bigger than max_size");
					tmp = _alloc.allocate(_capacity + count);
					_capacity = _capacity + count;	
				}
				else 
				{
					tmp = _alloc.allocate(_capacity);
				}
				while(_start + i != pos.base())
				{
					_alloc.construct(tmp + i, *(_start + i));
					_alloc.destroy(_start + i);
					i++;
				}
				for (size_type lel = count; lel > 0; lel--)
				{
					_alloc.construct(tmp + i, value);
					i++;

				}
				while (_start + i - count != _end)
				{
					_alloc.construct(tmp + i, *(_start + i - count));
					_alloc.destroy(_start + i - count);
					i++;
				}
				_alloc.deallocate(_start, old_capacity);
				_start = tmp;
				_end = _start + old_size + count;
			}
			template< class InputIt >
			void				insert( iterator pos, InputIt first, InputIt last, 
				typename ft::enable_if<!std::is_integral<InputIt>::value>::type* = NULL)
			{
				pointer		tmp;
				size_type	weirdo;
				try
				{
					size_type	old_size = size();
					size_type	old_capacity = capacity();
					size_type	new_capacity;
					size_type	i = 0;
					size_type	count = last.base() - first.base();

					if ( old_size + count > _capacity )
					{
						if (_capacity * 2 >= old_size + count)
							new_capacity = _capacity * 2;
						else
							new_capacity = old_size + count;
						if ( new_capacity > max_size())
							throw std::length_error("Bigger than max_size");
						tmp = _alloc.allocate(new_capacity);
						weirdo = new_capacity;
					}
					else 
					{
						tmp = _alloc.allocate(_capacity);
						weirdo = _capacity;
					}
					while(_start + i != pos.base())
					{
						_alloc.construct(tmp + i, *(_start + i));
						_alloc.destroy(_start + i);
						i++;
					}
					while (first != last)
					{
						_alloc.construct(tmp + i, *first);
						i++;
						first++;
					}
					while (_start + i - count != _end)
					{
						_alloc.construct(tmp + i, *(_start + i - count));
						_alloc.destroy(_start + i - count);
						i++;
					}
					_alloc.deallocate(_start, old_capacity);
					_start = tmp;
					_end = _start + old_size + count;
					_capacity = new_capacity;
				}
				catch(...)
				{
					for (size_type i = 0; i < weirdo; i++)
					{
						_alloc.destroy(tmp + i);
					}
					_alloc.deallocate(tmp, weirdo);
					throw ;
				}
				
			}
		//////////////////////////////////////////////
		//erase///////////////////////////////////////
		//////////////////////////////////////////////
			iterator			erase( iterator pos )
			{
				if (!(pos.base() >= _start && pos.base() < _end))
					throw std::out_of_range("Input Iterator for erase() pointing outside vectors range");

				pointer		ptr = pos.base();
				_alloc.destroy(ptr);
				iterator		out(ptr);

				for (;ptr + 1 != _end; ptr++)
				{
					_alloc.construct(ptr, *(ptr + 1));
					_alloc.destroy(ptr + 1);
				}
				_end = ptr;
				return (out);
			}
			// iterator			erase( iterator pos )					//working slower backup :)
			// {
			// 	if (!(pos.base() >= _start && pos.base() < _end))
			// 		throw std::out_of_range("Input Iterator for erase() pointing outside vectors range");
			// 	pointer		tmp = _alloc.allocate(_capacity);
			// 	pointer		pos_base = pos.base();
			// 	size_type	i = 0;

			// 	for(; _start + i != pos_base; i++)
			// 	{
			// 		_alloc.construct(tmp + i, *(_start + i));
			// 		_alloc.destroy(_start + i);
			// 	}
			// 	iterator	out(tmp + i);
			// 	_alloc.destroy(_start + i++);
			// 	for(;_start + i != _end; i ++)
			// 	{
			// 		_alloc.construct(tmp + i - 1, *(_start + i));
			// 		_alloc.destroy(_start + i);
			// 	}
			// 	_alloc.deallocate(_start, _capacity);
			// 	_start = tmp;
			// 	_end = _start + i - 1;
			// 	return (out);
			// }
			iterator			erase( iterator first, iterator last )
			{
				if (first.base() > last.base())
					throw std::logic_error("Range iterator last is smaller than first");
				if (!(first.base() >= _start && first.base() < _end) || !(last.base() >= _start && last.base() < _end))
					throw std::out_of_range("Input Iterator for erase() pointing outside vectors range");
				pointer		tmp = _alloc.allocate(_capacity);
				pointer		first_base = first.base();
				pointer		last_base = last.base();
				size_type	i = 0;
				size_type	j;

				for(; _start + i != first_base; i++)
				{
					_alloc.construct(tmp + i, *(_start + i));
					_alloc.destroy(_start + i);
				}
				j = i;
				iterator	out(tmp + i);
				for(; _start + i < last_base; i++)
				{
					_alloc.destroy(_start + i);
				}
				for(;_start + i != _end; i ++)
				{
					_alloc.construct(tmp + j, *(_start + i));
					_alloc.destroy(_start + i);
					j++;
				}
				_alloc.deallocate(_start, _capacity);
				_start = tmp;
				_end = tmp + j;
				return (out);
			}
		//////////////////////////////////////////////
		//push_back///////////////////////////////////
		//////////////////////////////////////////////
			void				push_back( const T& value )
			{
				size_type	old_size = size();
				if (old_size + 1 > _capacity)
				{
					reserve(next_pow_2(old_size));				// probably should be old_size + 1 or just capacity
				}
				_alloc.construct(_end, value);
				// std::cout << "hiello from after construct" << std::endl;
				_end++;
			}
		//////////////////////////////////////////////
		//pop_back////////////////////////////////////
		//////////////////////////////////////////////
			void				pop_back()
			{
				if (_end <= _start)
					return ;
				_alloc.destroy(&back());
				_end--;
			}
		//////////////////////////////////////////////
		//resize//////////////////////////////////////
		//////////////////////////////////////////////
			void				resize( size_type count, T value = T() )
			{
				size_type	old_size = size();


				// std::cout << "old size = " << old_size << " count = " << count << std::endl;
				if ( count > old_size )
				{
					if (capacity() < count)
					{
						if (capacity() * 2 >= count)
							reserve(capacity() * 2);
						else 
							reserve(count);
					}
					for (; old_size < count; old_size++)
					{
						_alloc.construct(_start + old_size, value);
					}
					_end = _start + count;
					return ;
				}
				if ( count < old_size )
				{
					for (size_t i = count; i < old_size; i++)
					{
						_alloc.destroy(_start + i);
					}
					_end = _start + count;
				}
			}
		//////////////////////////////////////////////
		//swap////////////////////////////////////////
		//////////////////////////////////////////////
			void				swap( vector& other )
			{
				pointer				temp_start;
				pointer				temp_end;
				allocator_type		temp_alloc;
				size_type			temp_capacity;

				temp_start = _start;
				temp_end = _end;
				temp_alloc = _alloc;
				temp_capacity = _capacity;

				_start = other._start;
				_end = other._end;
				_alloc = other._alloc;
				_capacity = other._capacity;

				other._start = temp_start;
				other._end = temp_end;
				other._alloc = temp_alloc;
				other._capacity = temp_capacity;
			}
		

				
			void	 test_print()
			{
				std::cout << "this is test print" << std::endl;
				pointer temp = _start;
				while (temp != _end)
					std::cout << *temp++ << std::endl; 
			}
	};


	template<class T, class Alloc>
	bool		operator==(const vector<T, Alloc> &first, const vector<T, Alloc> &second)
	{
		if (first.size() != second.size())
			return (false);
		
		typename ft::vector<T, Alloc>::const_iterator it_one = first.begin();
		typename ft::vector<T, Alloc>::const_iterator it_two = second.begin();
		typename ft::vector<T, Alloc>::const_iterator end_first = first.end();
		typename ft::vector<T, Alloc>::const_iterator end_second = second.end();

		while (it_one != end_first)
		{
			if (*it_one != *it_two || it_two == end_second)
				return (false);

			it_one++;
			it_two++;
		}
		if (it_two == end_second)
			return (true);
		return (false);
	}


	template<class T, class Alloc>
	bool		operator!=(const vector<T, Alloc> &first, const vector<T, Alloc> &second)
	{
		return (!(first == second));
	}


	template<class T, class Alloc>
	bool		operator<(const vector<T, Alloc> &first, const vector<T, Alloc> &second)
	{
		return (ft::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end()));
	}


	template<class T, class Alloc>
	bool		operator<=(const vector<T, Alloc> &first, const vector<T, Alloc> &second)
	{
		return (!(first > second));
	}


	template<class T, class Alloc>
	bool		operator>(const vector<T, Alloc> &first, const vector<T, Alloc> &second)
	{
		return (second < first);
	}
	

	template<class T, class Alloc>
	bool		operator>=(const vector<T, Alloc> &first, const vector<T, Alloc> &second)
	{
		return (!(first < second));
	}
}


// this overload so the normal swap calls my swap which otherwise it wont :)
namespace std
{
	template<class T, class Alloc>
	void swap(ft::vector<T, Alloc> &x, ft::vector<T, Alloc> &y)
	{
		x.swap(y);
	}
}
#endif
