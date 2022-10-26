#ifndef RBT_ITERATOR_new_CPE
#define RBT_ITERATOR_new_CPE
// #include "namespace.hpp"
// #include "r_b_tree.hpp"
#include "../ft_utils/iterator_base.hpp"
#include "../ft_utils/ft_utils.hpp"


//			idea is if ptr == nil  means _end
//					if ptr == NULL means _start - 1;
//			
//			always recoverable from nil through its parent you can go to root and then to min/max tree
//			quicker with prev pointer though


namespace ft
{
	template<class node_type>						// it is da node
	class const_rbt_iterator_new;

	template<class node_type>						// it is da node
	class rbt_iterator_new : ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
	{

		public:
			typedef typename	node_type::value_type																	value_type;
			typedef				node_type*																				node_ptr;

			typedef typename	node_type::value_type*																	value_ptr;
			typedef typename	node_type::value_type&																	value_ref;





			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category				iterator_category;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type				difference_type;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer						pointer;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference						reference;

		private:
			node_ptr			_ptr;
			node_ptr			_nil;
			node_ptr			_prev;

		public:

			class	rbt_OutOfBounds : public std::exception{
			public:
				virtual const char *what( void ) const throw()
				{
					return ("Error: Iterator out of bounds!");
				}
			};
			~rbt_iterator_new() {};

			rbt_iterator_new( void ) : _ptr(NULL), _nil(find_nil(NULL)), _prev(NULL)
			{
				#if DEBUG
					std::cout << "default con_const rbt_iterator constructor called" << std::endl;
				#endif
			}

			rbt_iterator_new(node_ptr input) : _ptr(input), _nil(find_nil(input)), _prev(input)
			{
				#if DEBUG
					std::cout << "node_ptr input non_const rbt_iterator constructor called" << std::endl;
				#endif
			}
			
			rbt_iterator_new(const rbt_iterator_new &copy)
			{
				#if DEBUG
					std::cout << "copy non_const rbt_iterator constructor called" << std::endl;
				#endif
				*this = copy;
			}

			rbt_iterator_new	&operator=(const rbt_iterator_new &copy)
			{
				#if DEBUG
					std::cout << "operator= from non_const rbt_iterator to non_const rbt_iterator" << std::endl;
				#endif
				_ptr = copy.base();
				_nil = copy.get_nil();
				_prev = copy.get_prev();
				return (*this);
			}

			node_ptr			base( void ) const
			{
				return (_ptr);
			}

			node_ptr			get_nil( void ) const
			{
				return (_nil);
			}
			
			node_ptr			get_prev( void ) const
			{
				return (_prev);
			}

			value_ref			operator*( void ) const
			{
				// std::cout << "operator* called" << std::endl;
				if (!_ptr || _ptr == _nil)
					throw rbt_iterator_new::rbt_OutOfBounds();
				return (*(_ptr->value));
			}

			value_ptr			operator->( void ) const
			{
				if (!_ptr || _ptr == _nil)
					throw rbt_iterator_new::rbt_OutOfBounds();
				return (_ptr->value);
			}

//					idea is if ptr == nil  means _end
//					if ptr == NULL means _start - 1;
			rbt_iterator_new		&operator--( void )
			{
				node_ptr			_tmp = _ptr;

				_ptr = precessor(_ptr);
				if (_ptr != _tmp)
					_prev = _tmp;
				return (*this);
			}

			rbt_iterator_new		&operator++( void )
			{
				node_ptr			_tmp = _ptr;

				#if DEBUG
					std::cout << "non_const rbt_iterator operator++ before successor ptr = " << _ptr << std::endl;
				#endif
				_ptr = successor(_ptr);
				#if DEBUG
					std::cout << "non_const rbt_iterator operator++ after successor ptr = " << _ptr << std::endl;
				#endif
				if (_ptr != _tmp)
					_prev = _tmp;
				return (*this);
			}

			rbt_iterator_new		operator++( int )
			{
				rbt_iterator_new		tmp(*this);
				++(*this);
				return (tmp);
			}

			rbt_iterator_new		operator--( int )
			{
				rbt_iterator_new		tmp(*this);
				--(*this);
				return (tmp);
			}

			bool				operator==( const rbt_iterator_new<node_type> & other ) const
			{
				return (base() == other.base());
			}

			bool				operator!=( const rbt_iterator_new<node_type> & other ) const
			{
				return (base() != other.base());
			}

			bool				operator==( const const_rbt_iterator_new<node_type> & other ) const
			{
				return (base() == other.base());
			}

			bool				operator!=( const const_rbt_iterator_new<node_type> & other ) const
			{
				return (base() != other.base());
			}
		
			node_ptr	find_nil(node_ptr x) const
			{
				if(x)
				{
					while (x->left_child != NULL)
						x = x->left_child;
				}
				return (x);
			}

			node_ptr	min_subtree(node_ptr x) const
			{
				if(x)
				{
					while (x->left_child != _nil)
						x = x->left_child;
				}			
				return (x);
			}

			node_ptr	max_subtree(node_ptr x) const
			{
				if(x)
				{
					while (x->right_child != _nil)
						x = x->right_child;
				}			
				return (x);
			}


			node_ptr		find_root(node_ptr x) const
			{
				if(x)
				{
					while(x->parent != NULL)
						x = x->parent;
				}				
				return (x);
			}

			node_ptr		find_begin(node_ptr x) const
			{
				x = find_root(x);
				return (min_subtree(x));
			}

			node_ptr	precessor(node_ptr x) const
			{
				// if (x == NULL)
				// 	return (NULL);
				if (x == _nil)												//x == nil means _end
					return (_prev);
				if (x == NULL)												//x == NULL means _start - 1;
					return (x);
				if(x->parent == NULL && x->left_child == _nil)
					return (NULL);
				if (x->left_child != _nil)
					return (max_subtree(x->left_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x == y->left_child)
				{
					x = y;
					y = y->parent;
				}
				if (y->parent == NULL && x == y->left_child)
					return (NULL);
				return (y);
			}

			node_ptr	successor(node_ptr x) const
			{
				// if (x == NULL)
				// 	return (NULL);
				if (x == _nil)												//x == nil means _end
					return (x);
				if (x == NULL)												//x == NULL means _start - 1;
					return (_prev);
				if(x->parent == NULL && x->right_child == _nil)
					return (_nil);
				if (x->right_child != _nil)
					return (min_subtree(x->right_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x->is_left == false)
				{
					x = y;
					y = y->parent;
				}
				if (y->parent == NULL && x == y->right_child)
				{
					
					return (_nil);
				}
				return (y);
			}
	};



	template<class node_type>						// it is da node
	class const_rbt_iterator_new : ft::iterator<ft::bidirectional_iterator_tag, typename node_type::value_type>
	{

		public:
			typedef const typename	node_type::value_type																	value_type;
			typedef					node_type*																				node_ptr;

			typedef typename		node_type::value_type*																	value_ptr;
			typedef typename		node_type::value_type&																	value_ref;





			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category					iterator_category;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type					difference_type;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer							pointer;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference							reference;

		private:
			node_ptr			_ptr;
			node_ptr			_nil;
			node_ptr			_prev;

		public:

			class	rbt_OutOfBounds : public std::exception{
			public:
				virtual const char *what( void ) const throw()
				{
					return ("Error: Iterator out of bounds!");
				}
			};
			~const_rbt_iterator_new() {};

			const_rbt_iterator_new( void ) : _ptr(NULL), _nil(find_nil(NULL)), _prev(NULL)
			{
				#if DEBUG
					std::cout << "default const rbt_iterator constructor called" << std::endl;
				#endif
			}

			const_rbt_iterator_new(node_ptr input) : _ptr(input), _nil(find_nil(input)),_prev(input)
			{
				#if DEBUG
					std::cout << "node_ptr input const rbt_iterator constructor called" << std::endl;
				#endif
			}

			const_rbt_iterator_new(const const_rbt_iterator_new &copy)
			{
				#if DEBUG
					std::cout << "copy const rbt_iterator constructor called (const iterator input)" << std::endl;
				#endif
				*this = copy;
			}

			const_rbt_iterator_new(const rbt_iterator_new<node_type>&copy)
			{
				#if DEBUG
					std::cout << "copy const rbt_iterator constructor called (non_const iterator input)" << std::endl;
				#endif
				*this = copy;
			}

			const_rbt_iterator_new	&operator=(const rbt_iterator_new<node_type> &copy)
			{
				#if DEBUG
					std::cout << "operator= from non_const rbt_iterator to const rbt_iterator" << std::endl;
				#endif
				_ptr = copy.base();
				_nil = copy.get_nil();
				_prev = copy.get_prev();
				return (*this);
			}

			const_rbt_iterator_new	&operator=(const const_rbt_iterator_new &copy)
			{
				#if DEBUG
					std::cout << "operator= from const rbt_iterator to const rbt_iterator" << std::endl;
				#endif
				_ptr = copy.base();
				_nil = copy.get_nil();
				_prev = copy.get_prev();
				return (*this);
			}

			node_ptr			base( void ) const
			{
				return (_ptr);
			}

			node_ptr			get_nil( void ) const
			{
				return (_nil);
			}
			
			node_ptr			get_prev( void ) const
			{
				return (_prev);
			}

			value_ref			operator*( void ) const
			{
				// std::cout << "operator* called" << std::endl;
				if (!_ptr || _ptr == _nil)
					throw const_rbt_iterator_new::rbt_OutOfBounds();
				return (*(_ptr->value));
			}

			value_ptr			operator->( void ) const
			{
				if (!_ptr || _ptr == _nil)
					throw const_rbt_iterator_new::rbt_OutOfBounds();
				return (_ptr->value);
			}

//					idea is if ptr == nil  means _end
//					if ptr == NULL means _start - 1;
			const_rbt_iterator_new		&operator--( void )
			{
				node_ptr			_tmp = _ptr;
				_ptr = precessor(_ptr);
				if (_ptr != _tmp)
					_prev = _tmp;
				return (*this);
			}

			const_rbt_iterator_new		&operator++( void )
			{
				node_ptr			_tmp = _ptr;
				_ptr = successor(_ptr);
				if (_ptr != _tmp)
					_prev = _tmp;
				return (*this);
			}

			const_rbt_iterator_new		operator++( int )
			{
				const_rbt_iterator_new		tmp(*this);
				++(*this);
				return (tmp);
			}

			const_rbt_iterator_new		operator--( int )
			{
				const_rbt_iterator_new		tmp(*this);
				--(*this);
				return (tmp);
			}

			bool				operator==( const const_rbt_iterator_new<node_type> & other ) const
			{
				return (base() == other.base());
			}

			bool				operator!=( const const_rbt_iterator_new<node_type> & other ) const
			{
				return (base() != other.base());
			}

			bool				operator==( const rbt_iterator_new<node_type> & other ) const
			{
				return (base() == other.base());
			}

			bool				operator!=( const rbt_iterator_new<node_type> & other ) const
			{
				return (base() != other.base());
			}
		
			node_ptr	find_nil(node_ptr x) const
			{
				while (x->left_child != NULL)
					x = x->left_child;
				return (x);
			}

			node_ptr	min_subtree(node_ptr x) const
			{
				while (x->left_child != _nil)
					x = x->left_child;
				return (x);
			}

			node_ptr	max_subtree(node_ptr x) const
			{
				while (x->right_child != _nil)
					x = x->right_child;
				return (x);
			}


			node_ptr		find_root(node_ptr x) const
			{
				while(x->parent != NULL)
					x = x->parent;
				return (x);
			}

			node_ptr		find_begin(node_ptr x) const
			{
				x = find_root(x);
				return (min_subtree(x));
			}

			node_ptr	precessor(node_ptr x) const
			{
				if(x->parent == NULL && x->left_child == _nil)
					return (NULL);
				if (x == _nil)												//x == nil means _end
					return (_prev);
				if (x == NULL)												//x == NULL means _start - 1;
					return (x);
				if (x->left_child != _nil)
					return (max_subtree(x->left_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x == y->left_child)
				{
					x = y;
					y = y->parent;
				}
				if (y->parent == NULL && x == y->left_child)
					return (NULL);
				return (y);
			}

			node_ptr	successor(node_ptr x) const
			{
				if(x->parent == NULL && x->right_child == _nil)
					return (_nil);
				if (x == _nil)												//x == nil means _end
					return (x);
				if (x == NULL)												//x == NULL means _start - 1;
					return (_prev);
				if (x->right_child != _nil)
					return (min_subtree(x->right_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x->is_left == false)
				{
					x = y;
					y = y->parent;
				}
				if (y->parent == NULL && x == y->right_child)
				{
					
					return (_nil);
				}
				return (y);
			}
	};	
}

#endif