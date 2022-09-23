#ifndef RBT_ITERATOR_CPE
#define RBT_ITERATOR_CPE
// #include "namespace.hpp"
// #include "r_b_tree.hpp"
#include "iterator_base.hpp"

namespace ft
{
	template <class T, class Tree>
	class rbt_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T																							value_type;
			typedef T*																							value_ptr;

			typedef typename	Tree::node*																		node_ptr;
			typedef				Tree*																			tree_ptr;

			// typedef typename T::value																			value_type; 
	
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category		iterator_category;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference				reference;

		// private:
		public:
			node_ptr			_ptr;
			// node_ptr			_nil;
			tree_ptr			_tree;
			// value_ptr			_data;
			class	TooHighBounds : public std::exception{
			public:
				virtual const char *what( void ) const throw()
				{
					return ("Error: Map iterator out of bounds(too high)!");
				}
			};
			class	TooLowBounds : public std::exception{
			public:
				virtual const char *what( void ) const throw()
				{
					return ("Error: Map iterator out of bounds(too low)!");
				}
			};


		public:
			rbt_iterator( void ) : _ptr(NULL)
			{
			}

			rbt_iterator(node_ptr input, tree_ptr tree) : _ptr(input), _tree(tree)
			{
			}

			node_ptr			base( void ) const
			{
				return (_ptr);
			}

			value_type			&operator*( void ) const
			{
				if (_ptr == _tree->nil_node)
					throw rbt_iterator::TooHighBounds();
				if (_ptr == NULL)
					throw rbt_iterator::TooLowBounds();
				return (*(_ptr->value));
			}

			value_type			*operator->( void ) const
			{
				if (_ptr == _tree->nil_node)
					throw rbt_iterator::TooHighBounds();
				if (_ptr == NULL)
					throw rbt_iterator::TooLowBounds();
				return (_ptr->value);
			}

			rbt_iterator		&operator++( void )
			{
				if (_ptr != _tree->nil_node)
					_ptr = successor(_ptr);
				return (*this);
			}
			rbt_iterator		&operator++( int )
			{
				if (_ptr != _tree->nil_node)
					_ptr = successor(_ptr);
				return (*this);
			}


			
			rbt_iterator		&operator--( void )				// nil == _end
			{
				if (_ptr != NULL)
					_ptr = precessor(_ptr);
				return (*this);
			}
			
			rbt_iterator		&operator--( int )				//working on dis
			{
				if (_ptr != NULL)
					_ptr = precessor(_ptr);
				return (*this);
			}
			
			bool				operator==( const rbt_iterator<T, Tree> & other ) const
			{
				return (base() == other.base());
			}

			bool				operator!=( const rbt_iterator<T, Tree> & other ) const
			{
				return (base() != other.base());
			}
		
			node_ptr	min_subtree(node_ptr x)
			{
				while (x->left_child != _tree->nil_node)
					x = x->left_child;
				return (x);
			}

			node_ptr	max_subtree(node_ptr x)
			{
				while (x->right_child != _tree->nil_node)
					x = x->right_child;
				return (x);
			}


			// node_ptr	successor(node_ptr x)
			// {
			// 	if (x->right_child != _tree->nil_node)
			// 		return (min_subtree(x->right_child));
			// 	node_ptr	y = x->parent;
			// 	node_ptr	z = x;
			// 	while (y->parent != NULL && x == y->right_child)		// WHY IS IT A WHILE?????
			// 	{
			// 		x = y;
			// 		y = y->parent;
			// 	}
			// 	// if (compare(z->value, y->value))
			// 	if (compare(z->value, y->value))
			// 		return (y);
			// 	return (_tree->nil_node);
			// }



			node_ptr	precessor(node_ptr x)
			{
				if (x == _tree->nil_node)									//x == nil means _end
					return (max_subtree(_tree->root));
				if (x == NULL)												//x == NULL means _start - 1;
					return (x);
				if (x->left_child != _tree->nil_node)
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

			node_ptr	successor(node_ptr x)
			{
				if (x == _tree->nil_node)									//x == nil means _end
					return (x);
				if (x == NULL)												//x == NULL means _start - 1;
					return (_tree->begin());
				if (x->right_child != _tree->nil_node)
					return (min_subtree(x->right_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x == y->right_child)
				{
					x = y;
					y = y->parent;
				}
				if (y->parent == NULL && x == y->right_child)
					return (_tree->nil_node);
				return (y);
			}
	};

	template <class T, class Tree>
	class const_rbt_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef const T																							value_type;
			typedef T*																							value_ptr;

			typedef typename	Tree::node*																		node_ptr;
			typedef				Tree*																			tree_ptr;

			// typedef typename T::value																			value_type; 
	
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category		iterator_category;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
			typedef typename	ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference				reference;

		// private:
		public:
			node_ptr			_ptr;
			// node_ptr			_nil;
			tree_ptr			_tree;
			// value_ptr			_data;
			class	TooHighBounds : public std::exception{
			public:
				virtual const char *what( void ) const throw()
				{
					return ("Error: Map iterator out of bounds(too high)!");
				}
			};
			class	TooLowBounds : public std::exception{
			public:
				virtual const char *what( void ) const throw()
				{
					return ("Error: Map iterator out of bounds(too low)!");
				}
			};


		public:
			const_rbt_iterator( void ) : _ptr(NULL)
			{
			}

			const_rbt_iterator(node_ptr input, tree_ptr tree) : _ptr(input), _tree(tree)
			{
			}

			node_ptr			base( void ) const
			{
				return (_ptr);
			}

			value_type			&operator*( void ) const
			{
				if (_ptr == _tree->nil_node)
					throw const_rbt_iterator::TooHighBounds();
				if (_ptr == NULL)
					throw const_rbt_iterator::TooLowBounds();
				return (*(_ptr->value));
			}

			value_type			*operator->( void ) const
			{
				if (_ptr == _tree->nil_node)
					throw const_rbt_iterator::TooHighBounds();
				if (_ptr == NULL)
					throw const_rbt_iterator::TooLowBounds();
				return (_ptr->value);
			}


			const_rbt_iterator		&operator++( void )
			{
				if (_ptr != _tree->nil_node)
					_ptr = successor(_ptr);
				return (*this);
			}
			const_rbt_iterator		&operator++( int )
			{
				if (_ptr != _tree->nil_node)
					_ptr = successor(_ptr);
				return (*this);
			}


			
			const_rbt_iterator		&operator--( void )				// nil == _end
			{
				if (_ptr != NULL)
					_ptr = precessor(_ptr);
				return (*this);
			}
			
			const_rbt_iterator		&operator--( int )				//working on dis
			{
				if (_ptr != NULL)
					_ptr = precessor(_ptr);
				return (*this);
			}
			
			bool				operator==( const const_rbt_iterator<T, Tree> & other ) const
			{
				return (base() == other.base());
			}

			bool				operator!=( const const_rbt_iterator<T, Tree> & other ) const
			{
				return (base() != other.base());
			}
		
			node_ptr	min_subtree(node_ptr x)
			{
				while (x->left_child != _tree->nil_node)
					x = x->left_child;
				return (x);
			}

			node_ptr	max_subtree(node_ptr x)
			{
				while (x->right_child != _tree->nil_node)
					x = x->right_child;
				return (x);
			}


			// node_ptr	successor(node_ptr x)
			// {
			// 	if (x->right_child != _tree->nil_node)
			// 		return (min_subtree(x->right_child));
			// 	node_ptr	y = x->parent;
			// 	node_ptr	z = x;
			// 	while (y->parent != NULL && x == y->right_child)		// WHY IS IT A WHILE?????
			// 	{
			// 		x = y;
			// 		y = y->parent;
			// 	}
			// 	// if (compare(z->value, y->value))
			// 	if (compare(z->value, y->value))
			// 		return (y);
			// 	return (_tree->nil_node);
			// }



			node_ptr	precessor(node_ptr x)
			{
				if (x == _tree->nil_node)									//x == nil means _end
					return (max_subtree(_tree->root));
				if (x == NULL)												//x == NULL means _start - 1;
					return (x);
				if (x->left_child != _tree->nil_node)
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

			node_ptr	successor(node_ptr x)
			{
				if (x == _tree->nil_node)									//x == nil means _end
					return (x);
				if (x == NULL)												//x == NULL means _start - 1;
					return (_tree->begin());
				if (x->right_child != _tree->nil_node)
					return (min_subtree(x->right_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x == y->right_child)
				{
					x = y;
					y = y->parent;
				}
				if (y->parent == NULL && x == y->right_child)
					return (_tree->nil_node);
				return (y);
			}
	};
}

#endif

// y = min_subtree(x->right_child);
// 					if (compare(y->value, x->value)

// 						return (_tree->nil_node);
// 					}
// 					x = y;
// 					return (min_subtree(x->right_child));