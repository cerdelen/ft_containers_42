/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/28 16:53:26 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_B_TREE
#define R_B_TREE

#include <iostream>
#include "../ft_utils/ft_utils.hpp"

#define RED true
#define BLCK false
#define DEFAULT_COL "\33[0m"
#define BLUE_COL "\33[34m"
#define RED_COL "\33[1;31m"

namespace ft
{
	template <class T, class Compare, class allocator >
	class r_b_tree
	{
		public:
			typedef					T									value_type;
			typedef					allocator							allocator_type;
			typedef typename		allocator_type::reference			reference;
			typedef typename		allocator_type::const_reference		const_reference;
			typedef typename		allocator_type::pointer				pointer;
			typedef typename		allocator_type::const_pointer		const_pointer;
			typedef					ptrdiff_t							difference_type;
			typedef typename		allocator_type::size_type			size_type;
			typedef					rbt_node<T>*						node_ptr;
			typedef					T*									pair_ptr;
			// typedef	const			node*								const_iter;
			typedef					Compare								value_compare;


		private:
			value_compare						compare;
			allocator_type						value_alloc;
			size_type							size;
			node_ptr							nil_node;
			node_ptr							root;
			std::allocator<rbt_node<T> >		node_alloc;
		public:									
			
			r_b_tree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), value_alloc(alloc_), size(0), root(NULL)
			{
				#if DEBUG
					std::cout << "[RBT] Default constructor called" << std::endl;
				#endif
				nil_node = init_nil();
			}
			~r_b_tree()
			{
			};


			node_ptr	get_node(bool col, const value_type &data)
			{
				node_ptr		out;
				// out = node_alloc.allocate(sizeof(struct rbt_node<value_type>));
				out = node_alloc.allocate(1);
			
				out->parent = NULL;
				out->left_child = nil_node;
				out->right_child = nil_node;
				out->col = col;
				out->is_left = true;
				out->value = value_alloc.allocate(1);
				value_alloc.construct(out->value, data);
				return (out);
			}

			node_ptr	init_nil( void )
			{
				node_ptr		out = node_alloc.allocate(sizeof(struct rbt_node<value_type>));	
				out->parent = NULL;
				out->left_child = NULL;
				out->right_child = NULL;
				out->col = BLCK;
				out->value = NULL;
				return (out);	
			}

			allocator_type get_allocator(void) const
			{
				return (this->value_alloc);
			}

			value_compare	get_compare() const
			{
				return (compare);
			}
		
			node_ptr		insert_with_hint( node_ptr x, const value_type &val )
			{
				node_ptr	new_node;

				new_node = get_node(RED, val);
				//setting parent ptr and arents child ptr to new node
				new_node->parent = x;
				if (x->right_child != nil_node)
					new_node->right_child = x->right_child;
				x->right_child = new_node;
				x->is_left = false;
				insert_fixup(new_node);
				size++;
				return (new_node);
			}
			void	insert( const value_type &val )
			{
				node_ptr	tmp = root;
				node_ptr	tmp_parent = NULL;
				node_ptr	new_node;
				
				if (!root)
					root = get_node(BLCK, val);
				else
				{
					new_node = get_node(RED, val);
					while (tmp != nil_node)
					{
						tmp_parent = tmp;
						if (compare(*(new_node->value), *(tmp->value)))				// new_node is bigger
							tmp = tmp->left_child;
						else if (compare(*(tmp->value), *(new_node->value)))			// new_node is smaller
							tmp = tmp->right_child;
						else													// both values are same    maybee exception??
						{
							delete_node(new_node);
							return ;
						}
					}
					//setting parent ptr and arents child ptr to new node
					new_node->parent = tmp_parent;
					if (compare(*(new_node->value), *(tmp_parent->value)))			// if new node is bigger
					{
						tmp_parent->left_child = new_node;
						new_node->is_left = true;
					}
					else
					{
						tmp_parent->right_child = new_node;
						new_node->is_left = false;
					}
					// //print_("", get_root_node(), !(get_root_node()->is_left), true, false, true, true);
					insert_fixup(new_node);
				}
				size++;
			}

			void	left_rotation(node_ptr x)			// x = parent of the rotation
			{
				node_ptr	y;
				
				// //print_("", get_root_node(), !(get_root_node()->is_left), true, false, true, true);
				
				if (!x || x == nil_node)
					return ;
				if (x->right_child == nil_node)
					return ;
				y = x->right_child;
				// std::cout << "Left rot x = " << x->value->first << " y = " << y->value->first << std::endl;
				x->right_child = y->left_child;
				x->right_child->is_left = false;
				if (x->right_child != nil_node)
				{
					x->right_child->parent = x;
					x->right_child->is_left = false;
				}
				y->parent = x->parent;
				if (x->parent)
				{
					if (x == x->parent->left_child)
					{
						x->parent->left_child = y;
						y->is_left = true;
					}
					else
					{
						x->parent->right_child = y;
						y->is_left = false;
					}
				}
				if(y->parent == NULL)
					root = y;
				y->left_child = x;
				x->is_left = true;
				x->parent = y;
			}
			void	right_rotation(node_ptr x)			// x = parent of the rotation
			{
				node_ptr	y;
				
				if (!x || x == nil_node)
					return ;
				if (x->left_child == nil_node)
					return ;
				y = x->left_child;
				x->left_child = y->right_child;
				x->left_child->is_left = true;
				if (x->left_child != nil_node)
				{
					x->left_child->parent = x;
					x->left_child->is_left = true;
				}
				y->parent = x->parent;
				if (x->parent)
				{
					if (x == x->parent->left_child)
					{	
						x->parent->left_child = y;
						y->is_left = true;
					}
					else
					{
						x->parent->right_child = y;
						y->is_left = false;
					}
				}
				if(y->parent == NULL)
					root = y;
				y->right_child = x;
				x->is_left = false;
				x->parent = y;
			}

			void	init_fixup(node_ptr x, node_ptr *p, node_ptr *g, node_ptr *u)
			{
				// std::cout << "heyo" << std::endl;
				if (x->parent)
					*p = x->parent;
				if (x->parent->parent)
				{
					*g = x->parent->parent;
					if ( x->parent->parent->left_child == x->parent->parent)
						*u = x->parent->parent->right_child;
					else
						*u = x->parent->parent->left_child;
				}
				// std::cout << "p = " << *p << std::endl;
			}

			void	insert_fixup(node_ptr x)
			{
				node_ptr		u = NULL;

				// std::cout << "this is tree before fixup" << std::endl;
				// print_tree_key();
				if(!x)
					return ;
				while ((x->parent != NULL && x->parent != root) && (x->parent->col == RED))
				{
					if (x->parent == x->parent->parent->left_child)
					{
						u = x->parent->parent->right_child;
						if(u->col == RED)									//uncle is red
						{
							// std::cout << "Fixup case 1" << std::endl;
							x->parent->col = BLCK;
							u->col = BLCK;
							x->parent->parent->col = RED;
							x = x->parent->parent;
						}
						else												//uncle is black
						{
							if(x == x->parent->right_child)							//difference wether x is right or left child
							{
								// std::cout << "Fixup case 2" << std::endl;
								x = x->parent;
								left_rotation(x);
							}
							// std::cout << "Fixup case 3" << std::endl;
							x->parent->col = BLCK;
							x->parent->parent->col = RED;
							right_rotation(x->parent->parent);
						} 
					}
					else
					{
						u = x->parent->parent->left_child;
						if(u->col == RED)									//uncle is red
						{
							// std::cout << "Fixup case 1" << std::endl;
							x->parent->col = BLCK;
							u->col = BLCK;
							x->parent->parent->col = RED;
							x = x->parent->parent;
						}
						else												//uncle is black
						{
							if(x == x->parent->left_child)							//difference wether x is right or left child
							{
								// std::cout << "Fixup case 2" << std::endl;
								x = x->parent;
								right_rotation(x);
							}
							// std::cout << "Fixup case 3" << std::endl;
							x->parent->col = BLCK;
							x->parent->parent->col = RED;
							left_rotation(x->parent->parent);
						} 
					}
				}
				root->col = BLCK;	
				// std::cout << "this is tree after fixup" << std::endl;
				// print_tree_key();
			}

			size_type		max_size( void ) const
			{
				return  (value_alloc.max_size());	
			}

			bool		empty() const
			{
				return (size == 0);
			}

			node_ptr	min_subtree(node_ptr x) const
			{
				if (x)
				{
					while (x->left_child != nil_node)
						x = x->left_child;
				}
				return (x);
			}
			node_ptr	max_subtree(node_ptr x) const
			{
				if (x)
				{
					while (x->right_child != nil_node)
						x = x->right_child;
				}
				return (x);
			}



			node_ptr	successor(node_ptr x) const
			{
				if (x->right_child != nil_node)
					return (min_subtree(x->right_child));
				node_ptr	y = x->parent;
				
				while (y->parent != NULL && x == y->right_child)		// WHY IS IT A WHILE?????
				{
					x = y;
					y = y->parent;
				}
				return (y);
			}

			node_ptr	end( void ) const
			{
				return (nil_node);
			}

			node_ptr	begin( void ) const
			{
				if (root == NULL)
					return (end());
				return (min_subtree(root));
			}
			
			void		purge_node(node_ptr x)
			{
				// std::cout << "purge node with value " << x->value->first << std::endl;
				if (x->is_left)
					x->parent->left_child = nil_node;
				else
					x->parent->right_child = nil_node;
				delete_node(x);
			}

			void		delete_node(node_ptr x)
			{
				// if (x->value)
				// 	std::cout << "delete node with value " << x->value->first << std::endl;
				// else
				// 	std::cout << "delete node without value " << std::endl;
					
				// std::cout << "delete node with value " << x->value->first << std::endl;
				if (x == NULL)
					return ;
				if (x->value != NULL)
				{
					// std::cout << "problem in value deletion " << std::endl;
					value_alloc.destroy(x->value);
					value_alloc.deallocate(x->value, 1);
				}
				// std::cout << "problem in node deletion " << std::endl;
				node_alloc.destroy(x);
				node_alloc.deallocate(x, 1);
				// std::cout << "end of delete_node() " << std::endl;
			}

			void		swap_val_ptr(node_ptr a, node_ptr b)
			{
				pointer		tmp;

				tmp = a->value;
				a->value = b->value;
				b->value = tmp;
			}

			void		erase(node_ptr x)
			{
				node_ptr	y;

				if (x == nil_node || x == NULL)
					return ;

				// std::cout << "Input node ptr in tree.erase() = " << x->value->first << std::endl;
				
				//print_("", get_root_node(), !(get_root_node()->is_left), true, false, true, true);
				if (x->left_child == nil_node && x->right_child == nil_node)				//	no children
				{
					// std::cout << "tree.erase() case 1" << std::endl;
					if (x == root)
					{
						// std::cout << "tree.erase() case 1.5" << std::endl;
						clear();
						return ;
					}
					y = x;
					// std::cout << "here y should be te same as what we try to delete " <<  x->value->first << std::endl;
					if (y->is_left == true)
					{
						// std::cout << "this one first" << std::endl;
						y->parent->left_child = nil_node;
					}
					else
					{
						// std::cout << "this one seconddd" << std::endl;
						y->parent->right_child = nil_node;
					}
					// std::cout << "hieeeelllooo " << std::endl;
					//print_("", get_root_node(), !(get_root_node()->is_left), true, false, true, true);
					// std::cout << "trying to delet node ptr in tree.erase() = " << y->value->first << std::endl;
					erase_fixup(y);
					purge_node(y);
				}
				else if (x->left_child != nil_node && x->right_child != nil_node)			//	two children
				{
					// std::cout << "tree.erase() case 2" << std::endl;
					y = successor(x);
					// std::cout << "successor of " << x->value->first << " is " << y->value->first << std::endl;
					// y = max_subtree(x);
					swap_val_ptr(y, x);
					while(y->right_child != nil_node)
					{
						node_ptr	tmp;

						tmp = successor(y);
						swap_val_ptr(tmp, y);
						y = tmp;
					}
					if (y->is_left)
						y->parent->left_child = nil_node;
					else
						y->parent->right_child = nil_node;
					// std::cout << "trying to delet node ptr in tree.erase() = " << y->value->first << std::endl;
					erase_fixup(y);				// write fixup
					purge_node(y);
				}
				else																		//	1 child
				{
					// std::cout << "tree.erase() case 3" << std::endl;
					if (x->left_child != nil_node)
						y = x->left_child;
					else
						y = x->right_child;
					if (x == root)
					{
						root = y;		
						size--;
						y->parent = NULL;
						delete_node(x);
						return ;
					}
					else if (x->is_left)
						x->parent->left_child = y;
					else
						x->parent->right_child = y;
					y->parent = x->parent;
					y->is_left = x->is_left;
					y = x;
					// std::cout << "trying to delet node ptr in tree.erase() = " << x->value->first << std::endl;
					erase_fixup(y);				// write fixup
					delete_node(x);
				}
				size--;
				// erase_fixup();				// write fixup
				// // return (y);
			}

			// void		erase(const value_type &val)
			// {
			// 	// std::cout << "starting erase_orig2 for node before find " << val.key << std::endl;
			// 	node_ptr	x = find(val);
			// 	node_ptr	y;
			// 	// std::cout << "starting erase_orig2 for node after find " << x->value->key << std::endl;
				
			// 	// if (x == NULL)
			// 		// std::cout << "HIEEELLOOO" << std::endl;
			// 	if (x == nil_node || x == NULL)
			// 		return ;

			// 	if (x->left_child == nil_node && x->right_child == nil_node)				//	no children
			// 	{
			// 		if (x == root)
			// 		{
			// 			clear();
			// 			return ;
			// 		}
			// 		y = x;
			// 		if (y->is_left)
			// 			y->parent->left_child = nil_node;
			// 		else
			// 			y->parent->right_child = nil_node;
			// 		erase_fixup(y);				// write fixup
			// 		purge_node(y);
			// 	}
			// 	else if (x->left_child != nil_node && x->right_child != nil_node)			//	two children
			// 	{
			// 		y = successor(x);
			// 		swap_val_ptr(y, x);
			// 		if (y->is_left)
			// 			y->parent->left_child = nil_node;
			// 		else
			// 			y->parent->right_child = nil_node;
			// 		erase_fixup(y);				// write fixup
			// 		purge_node(y);
			// 	}
			// 	else																		//	1 child
			// 	{
			// 		if (x->left_child != nil_node)
			// 			y = x->left_child;
			// 		else
			// 			y = x->right_child;

			// 		if (x == root)
			// 			root = y;		
			// 		else if (x->is_left)
			// 			x->parent->left_child = y;
			// 		else
			// 			x->parent->right_child = y;
			// 		y->parent = x->parent;
			// 		y = x;
			// 		erase_fixup(y);				// write fixup
			// 		delete_node(x);
			// 	}

			// 	size--;
			// 	// erase_fixup();				// write fixup
			// 	// // return (y);
			// }

			void	erase_fixup(node_ptr x)
			{
				// std::cout << "starting erase fixup for node " << x->value->key << std::endl;
				while (x != root && x->col == BLCK)
				{
					if (sibling(x)->col == RED)					// case 1
					{
						// std::cout << "erase_fixup case 1" << std::endl;
						x->parent->col = RED;
						sibling(x)->col = BLCK;
						rotate(sibling(x));
					}
					else if (nephew(x)->col == RED)				// case 2
					{
						// std::cout << "erase_fixup case 2" << std::endl;
						sibling(x)->col = x->parent->col;
						x->parent->col = BLCK;
						nephew(x)->col = BLCK;
						rotate(sibling(x));
						x = root;
						break ;
					}
					else if (niece(x)->col == RED)				// case 3
					{
						// std::cout << "erase_fixup case 3" << std::endl;
						niece(x)->col = BLCK;
						sibling(x)->col = RED;
						rotate(niece(x));
					}
					else										// case 4
					{
						// std::cout << "erase_fixup case 4" << std::endl;
						sibling(x)->col = RED;
						x = x->parent;
					}
				}
				x->col = BLCK;
			}

		node_ptr	get_nil_node( void ) const
		{
			return(nil_node);
		}
		
		node_ptr	get_root_node( void ) const
		{
			return(root);
		}
		
		node_ptr	last_node( void ) const
		{
			if (root)
				return(max_subtree(root));
			return (nil_node);
		}
		
		node_ptr	sibling(node_ptr x) const
		{
			if (x->parent == NULL)
				return (NULL);
			if (x->is_left)
				return (x->parent->right_child);
			return (x->parent->left_child);
		}
		
		node_ptr	aunt(node_ptr x) const
		{
			if (x->parent == NULL)
				return (NULL);
			return (sibling(x->parent));
		}
		
		node_ptr	niece(node_ptr x) const
		{
			node_ptr	sib = sibling(x);

			if (sib)
			{
				if (x->is_left)
					return (sib->left_child);
				return (sib->right_child);
			}
			return (NULL);
		}
		
		node_ptr	nephew(node_ptr x) const
		{
			node_ptr	sib = sibling(x);

			if (sib)
			{
				if (!(x->is_left))
					return (sib->left_child);
				return (sib->right_child);
			}
			return (NULL);
		}

		void	clearTreeRec(node_ptr x)
		{
			if (!x || x == nil_node)
				return ;
			if (x->left_child != nil_node)
				clearTreeRec(x->left_child);
			if (x->right_child != nil_node)
				clearTreeRec(x->right_child);
			delete_node(x);
			size--;
		}

		void	clear()
		{
			clearTreeRec(root);
			root = NULL;
			size = 0;
		}


		void	rotate(node_ptr child)
		{
			if (child->is_left)
			{
				right_rotation(child->parent);
				return ;
			}
			left_rotation(child->parent);
		}

		node_ptr find_pair(const value_type &val) const
		{
			#if DEBUG
				std::cout << "rbt.find_pair() called" << std::endl;
			#endif
			node_ptr node = root;

			if (node == NULL)
				return (nil_node);
			while (node != nil_node)
			{
				if (*(node->value) == val)
					break ;
				if (compare(*(node->value), val))
					node = node->right_child;
				else
					node = node->left_child;
			}
			return (node);
		}

		node_ptr find_key(const value_type &val) const
		{
			#if DEBUG
				std::cout << "rbt.find_key() called" << std::endl;
			#endif
			node_ptr node = root;

			if (node == NULL)
				return (nil_node);
			while (node != nil_node)
			{
				if (compare(*(node->value), val))
					node = node->right_child;
				else if (compare(val, *(node->value)))
					node = node->left_child;
				else
					break ;
			}
			if(node == nil_node)
				std::cout << " what the fuck actually "<< std::endl;
			return (node);
		}

		size_type	getSize( void ) const
		{
			return (size);
		}

		const r_b_tree &operator=(const r_b_tree& copy)
		{
			compare = copy.compare;
			value_alloc = copy.value_alloc;
			size = copy.size;
			nil_node = copy.nil_node;
			root = copy.root;
			node_alloc = copy.node_alloc;

			return (*this);
		}

		void	print_(const std::string& prefix, node_ptr node_, bool right, bool key_, bool mapped_, bool direction, bool col_, bool ptr) const
		{
			if (node_ != nil_node && node_ != NULL)
			{		
				std::cout << prefix;

				std::cout << (right ? "├──" : "└──" );

				// print the value of the node
				if (col_)
				{
					if (node_->col == RED)
						std::cout << RED_COL;
					else
						std::cout << BLUE_COL;	
				}
				if (key_)
					std::cout << node_->value->first << " ";	
				if (mapped_)
					std::cout << node_->value->second << " ";
				if (direction)
				{
					if (node_->is_left)
						std::cout << "is left";
					else
						std::cout << "is right";
				}
					std::cout << node_ << " ";
				if(ptr)
				std::cout << DEFAULT_COL << std::endl;	

				print_(prefix + (right ? "│   " : "    "), node_->right_child, true, key_, mapped_, direction, col_, ptr);
				print_(prefix + (right ? "│   " : "    "), node_->left_child, false, key_, mapped_, direction, col_, ptr);
			}
		}


		
	};
}
#endif