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
				std::cout << "i am default constructor " << std::endl;
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
				std::cout << "i am the fill constructor " << std::endl;
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
					std::cout << "i am range constructor " << std::endl;
				};

// 		Copy Constructor:
// 				Constructs a container with a copy of each of the elements in x, in the same order.

			vector (const vector& x);




/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
//Deconstructor//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

			~vector(){};

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
			// Pointer to start of allocated space (= first element)
			pointer				_start;
			// Pointer to end of allocated space
			pointer				_end;
			// Pointer to last element
			// pointer				_last;
			// allocater type?
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

			void				check_and_adjust_capacity(size_type n)
			{
				if (n > _capacity)
				{
					size_type	old_size = size();
					pointer		tmp = _alloc.allocate(n);

					for (size_t i = 0; i < old_size; i++)
					{
						_alloc.construct(tmp + i, _start + i);
						_alloc.destroy(_start + i);
					}
					_alloc.deallocate(_start, _capacity);
					_start = tmp;
					_capacity = n;	
				}
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
				// void		operator=();			//still have to do
		//////////////////////////////////////////////
		//assign//////////////////////////////////////
		//////////////////////////////////////////////
			void				assign( size_type count, const T& val )
			{
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

			// template< class InputIterator >
			// void assign( InputIterator first, InputIterator last, typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL)
			// {
			// 	std::cout << "retarded c++ " << std::endl;
			// }
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
					throw std::out_of_range("vector");
				return (*(_start + pos));
			}

			const_reference		at( size_type pos ) const
			{
				if (pos > size())
					throw std::out_of_range("vector");
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
			void				max_size();			//still have to do
			size_type			max_size() const;
		//////////////////////////////////////////////
		//reserve/////////////////////////////////////
		//////////////////////////////////////////////
			void				reserve();			//still have to do
			void				reserve( size_type new_cap );
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
			iterator			insert( iterator pos, const T& value );
			void				insert( iterator pos, size_type count, const T& value );
			template< class InputIt >
			void				insert( iterator pos, InputIt first, InputIt last );
		//////////////////////////////////////////////
		//erase///////////////////////////////////////
		//////////////////////////////////////////////
			void				erase();			//still have to do
			iterator			erase( iterator pos );
			iterator			erase( iterator first, iterator last );
		//////////////////////////////////////////////
		//push_back///////////////////////////////////
		//////////////////////////////////////////////

			void				push_back();			//still have to do
			void				push_back( const T& value )
			{
				size_type	old_size = size();
				if (old_size + 1 > _capacity)
					resize(next_pow_2(old_size), 0);
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
			void				resize();			//still have to do
			void				resize( size_type count, T value = T() )
			{
				size_type	old_size = size();
				if ( count > old_size )
				{
					check_and_adjust_capacity(count);
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
			void				swap();			//still have to do
			void				swap( vector& other );
		







				
			void	 test_print()
			{
				pointer temp = _start;
				while (temp != _end)
					std::cout << *temp++ << std::endl; 
			}
	};


}
#endif



