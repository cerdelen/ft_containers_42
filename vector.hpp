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
				: _alloc(alloc), _start(NULL), _end(NULL), _capacity(last - first)
				{
					_start = _alloc.allocate(last - first);
					_end = _start;
					while(first != last)
					{
						_alloc.construct(_end, first);
						_end++;
						first++;
					}
				};

// 		Copy Constructor:
// 				Constructs a container with a copy of each of the elements in x, in the same order.

			vector (const vector& x);




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
				// void		operator=();			//still have to do
				// void		assign();
				// void		get_allocator();


			// Element accsess 
				// void		at();
				// void		operator[]();			//still have to do
				// void		front();
				// void		back();
				// void		data();
			

			// Iterators
				// iterator	begin();
				// void		rbegin();
				// iterator	end();
				// void		rend();


			// Capacity
				// void		empty();
				// void		size();
				// void		max_size();
				// void		reserve();
				// void		capacity();
			

			// Modifiers
				// void		clear();
				// void		insert();
				// void		erase();
				// void		push_back();
				// void		pop_back();
				// void		resize();
				// void		swap();


			// Non-Member functions
			// void		operator==();				//still have to do
			// void		operator!=();				//still have to do
			// void		operator<();				//still have to do
			// void		operator<=();				//still have to do
			// void		operator>();				//still have to do
			// void		operator>=();				//still have to do



	 //		allocate 


		// struct iterator
		// {
			
		// };
		
		// typedef typename ft::vector<T>::iterator iterator;
		// iterator c;



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

			// void				check_and_adjust_capacity(size_type n)
			// {
			// 	if (n > _capacity)
			// 	{
			// 		size_type	old_size = size();
			// 		pointer		tmp = _alloc.allocate(n);

			// 		for (size_t i = 0; i < old_size; i++)
			// 		{
			// 			_alloc.construct(tmp + i, _start + i);
			// 			_alloc.destroy(_start + i);
			// 		}
			// 		_alloc.deallocate(_start, _capacity);
			// 		_start = tmp;
			// 		_end = _start + old_size;
			// 		_capacity = n;	
			// 	}
			// }


		public:

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Member function////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////
		//operator=///////////////////////////////////
		//////////////////////////////////////////////
				// void		operator=();			//still have to do
			vector& 			operator=( const vector& other );
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
					throw std::length_error("Bigger than max_size");
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
				if (pos > size())
					throw std::out_of_range("trying to acces element with at() outside of vector range");
				return (*(_start + pos));
			}

			const_reference		at( size_type pos ) const
			{
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
				return (*_start);
			}

			const_reference		front( void ) const
			{
				return (*_start);
			}
		//////////////////////////////////////////////
		//back////////////////////////////////////////
		//////////////////////////////////////////////
			reference			back( void )
			{
				return (*(_end - 1));
			}

			const_reference		back( void ) const
			{
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
			void				insert();			//still have to do
			iterator			insert( iterator pos, const T& value )
			{
				size_type	old_size = size();
				size_type	old_capacity = capacity();
				pointer		tmp;

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
				pointer		tmp2 = _start;

				for (size_type i = 0; tmp2 != pos.base(); i++)
				{
					_alloc.construct(tmp + i, *tmp2);
					_alloc.destroy(tmp2);
					tmp2++;
				}
				_alloc.construct(tmp2, value);
				for (size_type i = tmp2 - _start; tmp2 != _end; i++)
				{
					_alloc.construct(tmp + i, *(_start + i));
					_alloc.destroy(_start + i);
				}
				_alloc.deallocate(_start, old_capacity);
				_start = tmp;
				_end = _start + old_size;
				return (iterator(tmp2));
			}
			void				insert( iterator pos, size_type count, const T& value )
			{

			}
			template< class InputIt >
			void				insert( iterator pos, InputIt first, InputIt last )
			{

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
				*_end = value;
				// _alloc.construct(_end, value);
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




		// equal sign opperator
		// copy constructor
		// insert function
		// rend und rbegin
		// logical comparison operators (either lexicographical compare or equal)

}
#endif



