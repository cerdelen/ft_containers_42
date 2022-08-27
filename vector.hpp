#ifndef C_P_VECTOR
#define C_P_VECTOR
#include <iostream>
#include <memory>
#include <iterator>
#include "namespace.hpp"

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
			
			

////////////////////////////////////////////////////////////////////////////////
//Constructors//////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//		Default Constructor:
//				(empty container with no elements)

			explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _last(NULL){
				std::cout << "i am default constructor " << std::endl;
			};

//		Fill Constructor:
//				with n elements >> each a copy of val

			explicit vector(size_t n, const value_type &val,\
				const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _last(NULL)
			{
				_start = _alloc.allocate(n);
				_end = _start + n;
				_last = _start;
				while (n--)
				{
					_alloc.construct(_last, val);
					_last++;
				}
				std::cout << "i am the fill constructor " << std::endl;
			};

//		Range Constructor:
//				constructs with as many elementes as range [first > last], filling it same order as in range of elements

			template <class InputIterator>
			vector (InputIterator first, InputIterator last,\
				const allocator_type& alloc = allocator_type(),
				typename std::enable_if<!std::is_integral<InputIterator>::value>::type* = NULL)
				: _alloc(alloc), _start(NULL), _end(NULL), _last(NULL)
				{
				_start = _alloc.allocate(last - first);
				_end = _start + last - first;
				_last = _start;
				while(first != last)
				{
					_alloc.construct(_last, first);
					_last++;
					first++;
				}
				std::cout << "i am range constructor " << std::endl;
			};

// 		Copy Constructor:
// 				Constructs a container with a copy of each of the elements in x, in the same order.

			vector (const vector& x);




////////////////////////////////////////////////////////////////////////////////
//Deconstructor/////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

			~vector(){};



////////////////////////////////////////////////////////////////////////////////
//Member functions//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
			// Member functions
				// void		operator=();			//still have to do
				void		assign();
				void		get_allocator();


			// Element accsess 
				void		at();
				// void		operator[]();			//still have to do
				void		front();
				void		back();
				void		data();
			

			// Iterators
				// iterator	begin();
				void		rbegin();
				// iterator	end();
				void		rend();


			// Capacity
				void		empty();
				void		size();
				void		max_size();
				void		reserve();
				void		capacity();
			

			// Modifiers
				void		clear();
				void		insert();
				void		erase();
				void		push_back();
				void		pop_back();
				void		resize();
				void		swap();


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
			// Pointer to start of allocated space (= first element)
			pointer				_start;
			// Pointer to end of allocated space
			pointer				_end;
			// Pointer to last element
			pointer				_last;
			// allocater type?
			allocator_type		_alloc;











		public:


			void	 test_print()
			{
				pointer temp = _start;
				while (temp != _end)
					std::cout << *temp++ << std::endl; 
			}

			iterator		begin(void)
			{
				return (iterator(_start));
			}

			iterator		end(void)
			{
				return (iterator(_end));
			}

	};


}
#endif