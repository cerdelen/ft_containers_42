#ifndef C_P_VECTOR
#define C_P_VECTOR
#include <iostream>
#include <memory>
// #include "namespace.hpp"

namespace ft
{
	template <typename T , typename Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			
			
			
			
			


			// difference_type	
			// typedef typename allocator_type::difference_type difference_type;
			
			
			// typedef typename     iterator	 
			// const_iterator	
			// reverse_iterato
			// const_reverse_iterator



			vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(nullptr), _end(nullptr), _last(nullptr){
			};
			vector(size_t n,const value_type &val,\
				const allocator_type &alloc = allocator_type()) : _alloc(alloc), _start(nullptr), _end(nullptr), _last(nullptr){
					_start = _alloc.allocate(n);
					_end = _start + n;
					_last = _start;
					while (n--)
					{
						_alloc.construct(_last, val);
						_last++;
					}
			};

			~vector(){

			};

			// Member functions
			// void		operator=();
			void		assign();
			void		get_allocator();


			// Element accsess 
			void		at();
			// void		operator[]();
			void		front();
			void		back();
			void		data();
			

			// Iterators
			void		begin();
			void		rbegin();
			void		end();
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
			// void		operator==();
			// void		operator!=();
			// void		operator<();
			// void		operator<=();
			// void		operator>();
			// void		operator>=();






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
	};


}
#endif