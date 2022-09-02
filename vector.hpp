#ifndef C_P_VECTOR
#define C_P_VECTOR
#include <iostream>
#include <memory>
#include <iterator>
#include "namespace.hpp"
#include "stdexcept"

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
			
			
			
			typedef typename ft::random_access_iterator<value_type> 		iterator;
			// typedef	typename ft::const_random_access_iterator<value_type>	const_iterator;
			// typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;


			// difference_type	
			// typedef typename allocator_type::difference_type difference_type;
			
			

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Constructors///////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//		Default Constructor:
//				(empty container with no elements)

			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _capacity(0){
			};

//		Fill Constructor:
//				with n elements >> each a copy of val

			explicit vector(size_t n, const value_type &val,\
				const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _capacity(n)
			{
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
				typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL)
				: _alloc(alloc), _start(NULL), _end(NULL), _capacity(last.base() - first.base())
				{
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

			vector ( const vector& x, const allocator_type &alloc = allocator_type()): _alloc(alloc), _start(NULL), _end(NULL), _capacity(0)
			{
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
			unsigned int		next_pow_2(unsigned int v)
			{
				register unsigned int r; // result of log2(v) will go here
				register unsigned int shift;

				r =		(v > 0xFFFF) << 4; v >>= r;
				shift = (v > 0xFF  ) << 3; v >>= shift; r |= shift;
				shift = (v > 0xF   ) << 2; v >>= shift; r |= shift;
				shift = (v > 0x3   ) << 1; v >>= shift; r |= shift;
														r |= (v >> 1);
				unsigned int	out = 1 << (r + 1);
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
			void assign( InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL)
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
		//////////////////////////////////////////////
		//rbegin//////////////////////////////////////
		//////////////////////////////////////////////
			void				rbegin();			//still have to do
		//////////////////////////////////////////////
		//end/////////////////////////////////////////
		//////////////////////////////////////////////
			iterator			end(void)
			{
				return (iterator(_end));
			}
		//////////////////////////////////////////////
		//rend////////////////////////////////////////
		//////////////////////////////////////////////
			void				rend();			//still have to do

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
			size_type			size( void )
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

					for (size_t i = 0; i < old_size; i++)
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
			
				for (size_t i = 0; i < count; i++)
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
				for (size_t lel = count; lel > 0; lel--)
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
				typename std::enable_if<!std::is_integral<InputIt>::value>::type* = NULL)
			{
				size_type	old_size = size();
				size_type	old_capacity = capacity();
				pointer		tmp;
				size_type	i = 0;
				size_type	count = last.base() - first.base();

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
			}
		//////////////////////////////////////////////
		//erase///////////////////////////////////////
		//////////////////////////////////////////////
			iterator			erase( iterator pos )
			{
				if (!(pos.base() >= _start && pos.base() < _end))
					throw std::out_of_range("Input Iterator for erase() pointing outside vectors range");
				pointer		tmp = _alloc.allocate(_capacity);
				pointer		pos_base = pos.base();
				size_type	i = 0;

				for(; _start + i != pos_base; i++)
				{
					_alloc.construct(tmp + i, *(_start + i));
					_alloc.destroy(_start + i);
				}
				iterator	out(tmp + i);
				_alloc.destroy(_start + i++);
				for(;_start + i != _end; i ++)
				{
					_alloc.construct(tmp + i - 1, *(_start + i));
					_alloc.destroy(_start + i);
				}
				_alloc.deallocate(_start, _capacity);
				_start = tmp;
				_end = _start + i - 1;
				return (out);
			}
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
				for(; _start + i <= last_base; i++)
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
					resize(next_pow_2(old_size), 0);				// probably should be old_size + 1 or just capacity
				_alloc.construct(_end, value);
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
				if ( count > old_size )
				{
					reserve(count);
					for (; old_size < count; old_size++)
					{
						_alloc.construct(_start + old_size, value);
					}
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



		// const iterators
		// rend und rbegin
		// logical comparison operators (either lexicographical compare or equal)

}
#endif



