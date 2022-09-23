/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/23 18:34:43 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_B_TREE
#define R_B_TREE
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
			struct		node;

			// typedef					Key									key_type;
			// typedef					T									mapped_type;
			typedef					T									value_type;
			typedef					allocator							allocator_type;
			typedef typename		allocator_type::reference			reference;
			typedef typename		allocator_type::const_reference		const_reference;
			typedef typename		allocator_type::pointer				pointer;
			typedef typename		allocator_type::const_pointer		const_pointer;
			typedef					ptrdiff_t							difference_type;
			typedef typename		allocator_type::size_type			size_type;
			typedef					node*								node_ptr;
			typedef					T*									pair_ptr;
			// typedef	const			node*								const_iter;
			typedef					Compare								value_compare;



			struct node
			{
				bool					col;
				bool					is_left;
				node_ptr				parent;
				node_ptr				left_child;
				node_ptr				right_child;
				pointer					value;
			};

		private:
			size_type					size;
		public:									//this has to be private (only public for debguging)
			node_ptr					root;	//this has to be private (only public for debguging)
		// protected:
			node_ptr					nil_node;	//this has to be private (only public for debguging)
			size_type					heigth;
			value_compare				compare;
			allocator_type				value_alloc;
			std::allocator<node>		node_alloc;
			// std::allocator<>			value_alloc;



			

			node_ptr	get_node(bool col, const value_type &data)
			{
				node_ptr		out;
				out = node_alloc.allocate(sizeof(struct node));
			
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
				node_ptr		out = node_alloc.allocate(sizeof(struct node));	
				out->parent = NULL;
				out->left_child = NULL;
				out->right_child = NULL;
				out->col = BLCK;
				out->value = NULL;
				return (out);	
			}
			
		public:
			r_b_tree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), value_alloc(alloc_), heigth(0), size(0)
			{
				root = NULL;
				nil_node = init_nil();
			}
			~r_b_tree()
			{
				delete_node(nil_node);
			};


			void	insert( const value_type &val )
			{
				node_ptr	tmp = root;
				node_ptr	tmp_parent = NULL;
				node_ptr	new_node;
				size_t		new_heigth = 1;
				
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
						new_heigth++;
					}
					//setting parent ptr and arents child ptr to new node
					new_node->parent = tmp_parent;
					if (compare(*(new_node->value), *(tmp_parent->value)))			// if new node is bigger
					{
						tmp_parent->left_child = new_node;
						new_node->is_left = false;
					}
					else
						tmp_parent->right_child = new_node;
					// std::cout << RED_COL << "starting a new insert of nr " << DEFAULT_COL << new_node->value->key << std::endl;
					insert_fixup(new_node);
					// std::cout << RED_COL << "finished a new insert of nr " << DEFAULT_COL << new_node->value->key << std::endl << std::endl;
				}
				size++;
				if (new_heigth > heigth)
					heigth = new_heigth;
			}
			void	print_rec(const std::string& prefix, node_ptr node_, bool right, bool key) const
			{
				if (key)
				{
					if (node_ != nil_node)
					{		
						std::cout << prefix;

						std::cout << (right ? "├──" : "└──" );

						// print the value of the node
						if (node_->col == RED)
							std::cout << RED_COL << node_->value->first << DEFAULT_COL << std::endl;
						else
							std::cout << BLUE_COL << node_->value->first << DEFAULT_COL << std::endl;
						print_rec(prefix + (right ? "│   " : "    "), node_->right_child, true, true);
						print_rec(prefix + (right ? "│   " : "    "), node_->left_child, false, true);

						// enter the next tree level - left and right branch
					}
				}
				else
				{
					if (node_ != nil_node)
					{		
						std::cout << prefix;

						std::cout << (right ? "├──" : "└──" );

						// print the value of the node
						if (node_->col == RED)
							std::cout << RED_COL << node_->value->second << DEFAULT_COL << std::endl;
						else
							std::cout << BLUE_COL << node_->value->second << DEFAULT_COL << std::endl;
						print_rec(prefix + (right ? "│   " : "    "), node_->right_child, true, false);
						print_rec(prefix + (right ? "│   " : "    "), node_->left_child, false, false);

						// enter the next tree level - left and right branch
					}
				}
			}
			void	print_rec_complete(const std::string& prefix, node_ptr node_, bool right, bool key) const
			{
				if (node_ != nil_node)
				{		
					std::cout << prefix;

					std::cout << (right ? "├──" : "└──" );

					// print the value of the node
					if (node_->col == RED)
						std::cout << RED_COL << node_->value->first << " = " << node_->value->second << DEFAULT_COL << std::endl;
					else
						std::cout << BLUE_COL << node_->value->first << " = " << node_->value->second << DEFAULT_COL << std::endl;
					print_rec_complete(prefix + (right ? "│   " : "    "), node_->right_child, true, false);
					print_rec_complete(prefix + (right ? "│   " : "    "), node_->left_child, false, false);

					// enter the next tree level - left and right branch
				}
			}
			void print_tree_key() const
			{
				std::cout << "Tree height is " << heigth << " and size is " << size << std::endl;
				print_rec("", root, false, true);
				std::cout << "This tree is finished here!" << size << std::endl;
			}
			void print_tree_val() const
			{
				std::cout << "Tree height is " << heigth << " and size is " << size << std::endl;
				print_rec("", root, false, false);
				std::cout << "This tree is finished here!" << size << std::endl;
			}
			void print_tree_comp() const
			{
				std::cout << "Tree height is " << heigth << " and size is " << size << std::endl;
				print_rec_complete("", root, false, false);
				std::cout << "This tree is finished here!" << size << std::endl;
			}



			void	left_rotation(node_ptr x)			// x = parent of the rotation
			{
				node_ptr	y;
				
				if (!x || x == nil_node)
					return ;
				if (x->right_child == nil_node)
					return ;
				y = x->right_child;
				x->right_child = y->left_child;
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
							// std::cout << "case 1" << std::endl;
							x->parent->col = BLCK;
							u->col = BLCK;
							x->parent->parent->col = RED;
							x = x->parent->parent;
						}
						else												//uncle is black
						{
							if(x == x->parent->right_child)							//difference wether x is right or left child
							{
								// std::cout << "case 2" << std::endl;
								x = x->parent;
								left_rotation(x);
							}
							// std::cout << "case 3" << std::endl;
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
							// std::cout << "case 1" << std::endl;
							x->parent->col = BLCK;
							u->col = BLCK;
							x->parent->parent->col = RED;
							x = x->parent->parent;
						}
						else												//uncle is black
						{
							if(x == x->parent->left_child)							//difference wether x is right or left child
							{
								// std::cout << "case 2" << std::endl;
								x = x->parent;
								right_rotation(x);
							}
							// std::cout << "case 3" << std::endl;
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

			node_ptr	min_subtree(node_ptr x)
			{
				while (x->left_child != nil_node)
					x = x->left_child;
				return (x);
			}
			node_ptr	max_subtree(node_ptr x)
			{
				while (x->right_child != nil_node)
					x = x->right_child;
				return (x);
			}

			node_ptr	successor(node_ptr x)
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

			
			

			node_ptr	end( void )
			{
				return (nil_node);
			}
			node_ptr	begin( void )
			{
				return (min_subtree(root));
			}
			
			void		purge_node(node_ptr x)
			{
				if (x->is_left)
					x->parent->left_child = nil_node;
				else
					x->parent->right_child = nil_node;
				delete_node(x);
			}


			void		delete_node(node_ptr x)
			{
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
			}

			// void		node_transplant(node_ptr one, node_ptr two)
			// {
				
			// }

			void		swap_val_ptr(node_ptr a, node_ptr b)
			{
				pointer		tmp;

				tmp = a->value;
				a->value = b->value;
				b->value = tmp;
			}

			void		erase(const value_type &val)
			{
				// std::cout << "starting erase_orig2 for node before find " << val.key << std::endl;
				node_ptr	x = find(val);
				node_ptr	y;
				// std::cout << "starting erase_orig2 for node after find " << x->value->key << std::endl;
				
				// if (x == NULL)
					// std::cout << "HIEEELLOOO" << std::endl;
				if (x == nil_node || x == NULL)
					return ;

				if (x->left_child == nil_node && x->right_child == nil_node)				//	no children
				{
					if (x == root)
					{
						clear();
						return ;
					}
					y = x;
					if (y->is_left)
						y->parent->left_child = nil_node;
					else
						y->parent->right_child = nil_node;
					erase_fixup(y);				// write fixup
					purge_node(y);
				}
				else if (x->left_child != nil_node && x->right_child != nil_node)			//	two children
				{
					y = successor(x);
					swap_val_ptr(y, x);
					if (y->is_left)
						y->parent->left_child = nil_node;
					else
						y->parent->right_child = nil_node;
					erase_fixup(y);				// write fixup
					purge_node(y);
				}
				else																		//	1 child
				{
					if (x->left_child != nil_node)
						y = x->left_child;
					else
						y = x->right_child;

					if (x == root)
						root = y;		
					else if (x->is_left)
						x->parent->left_child = y;
					else
						x->parent->right_child = y;
					y->parent = x->parent;
					y = x;
					erase_fixup(y);				// write fixup
					delete_node(x);
				}

				size--;
				// erase_fixup();				// write fixup
				// // return (y);
			}


			void	erase_fixup(node_ptr x)
			{
				// std::cout << "starting erase fixup for node " << x->value->key << std::endl;
				while (x != root && x->col == BLCK)
				{
					if (sibling(x)->col == RED)					// case 1
					{
						x->parent->col = RED;
						sibling(x)->col = BLCK;
						rotate(sibling(x));
					}
					else if (nephew(x)->col == RED)				// case 2
					{
						sibling(x)->col = x->parent->col;
						x->parent->col = BLCK;
						nephew(x)->col = BLCK;
						rotate(sibling(x));
						x = root;
						break ;
					}
					else if (niece(x)->col == RED)				// case 3
					{
						niece(x)->col = BLCK;
						sibling(x)->col = RED;
						rotate(niece(x));
					}
					else										// case 4
					{
						sibling(x)->col = RED;
						x = x->parent;
					}
				}
				x->col = BLCK;
			}

































		// void	replace(node_ptr one, node_ptr two)
		// {
		// 	one->value = two->value;
		// }

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
			// if (x->parent->is_left)
			// 	return (x->parent->parent->right_child);
			// return (x->parent->parent->left_child);
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
			// std::cout << "this is da node to be cleared " << x->value->key << std::endl;
			delete_node(x);
			size--;
		}
	



		void	clear()
		{
			clearTreeRec(root);
			// delete_node(nil_node);
			root = NULL;
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






			node_ptr find(const value_type &val)
			{
				node_ptr node = root;

				if (node == NULL)
					return (nil_node);
				while (node != nil_node)
				{
					if (*(node->value) == val)
						break ;
					if (compare(*(node->value), val))
						node = node->left_child;
					else
						node = node->right_child;
				}
				return (node);
			}

			size_type	getSize( void ) const
			{
				return (size);
			}


			// node_ptr find_key(const value_type &val)
			// {
			// 	node_ptr node = root;

			// 	while (node->value != val && node != nil_node)
			// 	{
			// 		if (compare(node->value, val))
			// 			node = node->right_child;
			// 		else
			// 			node = node->left_child;
			// 	}	
			// 	return (node);
			// }			
	};

}
#endif