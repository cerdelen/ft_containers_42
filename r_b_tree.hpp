/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/17 16:58:47 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_B_TREE
#define R_B_TREE
// #include "namespace.hpp"
#define RED true
#define BLCK false

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
			typedef					size_t								size_type;
			typedef					node*								node_ptr;
			typedef					T*									pair_ptr;
			// typedef	const			node*								const_iter;
			typedef					Compare								value_compare;



			struct node
			{
				bool					col;
				node_ptr				parent;
				node_ptr				left_child;
				node_ptr				right_child;
				value_type				*value;
			};

		public:									//this has to be private (only public for debguging)
			node_ptr					root;	//this has to be private (only public for debguging)
		// protected:
			node_ptr					nil_node;	//this has to be private (only public for debguging)
			size_t						heigth;
			value_compare				compare;
			allocator_type				alloc;
			std::allocator<node>		node_alloc;
			std::allocator<T>			value_alloc;
			size_t						size;



			node_ptr	get_node(bool col, const value_type &data)
			{
				node_ptr		out;
				out = node_alloc.allocate(sizeof(struct node));
				pair_ptr  		pair_out;
				pair_out = value_alloc.allocate(1);
				value_alloc.construct(pair_out, data);
				
			
				out->parent = NULL;
				out->left_child = nil_node;
				out->right_child = nil_node;
				out->col = col;
				out->value = pair_out;
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
			r_b_tree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), alloc(alloc_), heigth(0), size(0)
			{
				root = NULL;
				nil_node = init_nil();
				std::cout << "i got through this :)" << std::endl;
			}
			~r_b_tree() {};


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
						if (compare(new_node->value, tmp->value))				// new_node is bigger
							tmp = tmp->right_child;
						else if (compare(tmp->value, new_node->value))			// new_node is smaller
							tmp = tmp->left_child;
						else													// both values are same    maybee exception??
							return ;
						new_heigth++;
					}
					//setting parent ptr and arents child ptr to new node
					new_node->parent = tmp_parent;
					if (compare(new_node->value, tmp_parent->value))			// if new node is bigger
						tmp_parent->right_child = new_node;
					else
						tmp_parent->left_child = new_node;
					std::cout << RED_COL << "starting a new insert of nr " << DEFAULT_COL << new_node->value->key << std::endl;
					insert_fixup(new_node);
					std::cout << RED_COL << "finished a new insert of nr " << DEFAULT_COL << new_node->value->key << std::endl << std::endl;
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
							std::cout << RED_COL << node_->value->key << DEFAULT_COL << std::endl;
						else
							std::cout << BLUE_COL << node_->value->key << DEFAULT_COL << std::endl;
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
							std::cout << RED_COL << node_->value->val << DEFAULT_COL << std::endl;
						else
							std::cout << BLUE_COL << node_->value->val << DEFAULT_COL << std::endl;
						print_rec(prefix + (right ? "│   " : "    "), node_->right_child, true, false);
						print_rec(prefix + (right ? "│   " : "    "), node_->left_child, false, false);

						// enter the next tree level - left and right branch
					}
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
					x->right_child->parent = x;
				y->parent = x->parent;
				if (x->parent)
				{
					if (x == x->parent->left_child)
						x->parent->left_child = y;
					else
						x->parent->right_child = y;
				}
				if(y->parent == NULL)
					root = y;
				y->left_child = x;
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
					x->left_child->parent = x;
				y->parent = x->parent;
				if (x->parent)
				{
					if (x == x->parent->left_child)
						x->parent->left_child = y;
					else
						x->parent->right_child = y;
				}
				if(y->parent == NULL)
					root = y;
				y->right_child = x;
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
							std::cout << "case 1" << std::endl;
							x->parent->col = BLCK;
							u->col = BLCK;
							x->parent->parent->col = RED;
							x = x->parent->parent;
						}
						else												//uncle is black
						{
							if(x == x->parent->right_child)							//difference wether x is right or left child
							{
								std::cout << "case 2" << std::endl;
								x = x->parent;
								left_rotation(x);
							}
							std::cout << "case 3" << std::endl;
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
							std::cout << "case 1" << std::endl;
							x->parent->col = BLCK;
							u->col = BLCK;
							x->parent->parent->col = RED;
							x = x->parent->parent;
						}
						else												//uncle is black
						{
							if(x == x->parent->left_child)							//difference wether x is right or left child
							{
								std::cout << "case 2" << std::endl;
								x = x->parent;
								right_rotation(x);
							}
							std::cout << "case 3" << std::endl;
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

			node_ptr	erase(node_ptr x)				// returns the node so i can delete it
			{
				node_ptr	y;

				// if (x->left_child == nil_node && x->right_child == nil_node)			// we just remove x and be done with it
				// {
					
				// }
				// else if (x->left_child == nil_node || x->right_child == nil_node)
				
				// // std::cout << "print 1 x = " << x->value->key << std::endl;
				// if (x->left_child == nil_node || x->right_child == nil_node)
				// 	y = x;
				// else
				// 	y = successor(x);

				// std::cout << "print 2 x = " << x->value->key << " and y = " << y->value->key << std::endl;
																					// y wird zum successor, ansonsten 
				if (y->left_child != nil_node)
					x = y->left_child;
				else
					x = y->right_child;

				// if (x != nil_node)
				// 	std::cout << "print 3 x = " << x->value->key << " and y = " << y->value->key << std::endl;
				// else
				// 	std::cout << "print 3 x = nil_node" << " and y = " << y->value->key << std::endl;


				
				if (x != nil_node)
					x->parent = y->parent;

					
				// if (x != nil_node)
				// 	std::cout << "print 4 x = " << x->value->key << " and y = " << y->value->key << std::endl;
				// else
				// 	std::cout << "print 4 x = nil_node" << " and y = " << y->value->key << std::endl;


				
				if (y->parent == NULL)
					root = x;
				else if (y == y->parent->left_child)
					y->parent->left_child = x;
				else
					y->parent->right_child = x;
				if (y != x)
					x->value = y->value;

				// erase_fixup();				// write fixup
				return (y);
			}
			node_ptr	erase_self(node_ptr x)				// returns the node so i can delete it
			{
				node_ptr	temp;

				if (x->left_child == nil_node && x->right_child == nil_node)
			}
			


			void		delete_node(node_ptr x)
			{
				if (x == NULL)
					return ;
				if (x->value != NULL)
				{
					value_alloc.destroy(x->value);
					value_alloc.deallocate(x->value, 1);
				}
				node_alloc.destroy(x);
				node_alloc.deallocate(x, 1);
			}

			node_ptr	erase_orig(node_ptr x)
			{
				node_ptr	y;

				if (x->left_child == nil_node || x->right_child == nil_node)
					y = x;
				else
					y = successor(x);
				if (y->left_child != nil_node)
					x = y->left_child;
				else
					x = y->right_child;
				if (x != nil_node)
					x->parent = y->parent;
				if (y->parent == NULL)
					root = x;
				else if (y == y->parent->left_child)
					y->parent->left_child = x;
				else
					y->parent->right_child = x;
				if (y != x)
					x->value = y->value;
				// erase_fixup();				// write fixup
				delete_node(y);
				return (y);
			}




































		void	replace(node_ptr one, node_ptr two)
		{
			one->value = two->value;
		}

















			




// 			1  if left[x] = NIL or right[x] = NIL

// 2      then y  x

// 3      else y  TREE-SUCCESSOR(x)

// 4  if left[y]  NIL

// 5      then a  left[y]

// 6      else a  right[y]

// 7  if a  NIL

// 8      then p[a]  p[y]

// 9  if p[y] = NIL

// 10      then root[T]  a

// 11      else if y = left[p[y]]

// 12              then left[p[y]]  a

// 13              else right[p[y]]  a

// 14  if y  x

// 15      then key[x]  key[y]

// 16            If y has other fields, copy them, too.

// 17  return y

			node_ptr find_pair(const value_type &val)
			{
				node_ptr node = root;

				while (node->value != val && node != nil_node)
				{
					if (compare(node->value, val))
						node = node->right_child;
					else
						node = node->left_child;
				}	
				return (node);
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
	
			// void	rotation_ll(node_ptr patient)					// grandparent becomes parents right son
			// {
			// 	if (!patient)
			// 		return ;
			// 	node_ptr		patient_father = patient->parent;
				
			// 	if (!patient_father)
			// 		return ;
			// 	node_ptr		grandparent = patient_father->parent;
				
			// 	if (!grandparent )
			// 		return ;				
			// 	if (grandparent->left_child == patient_father)
			// 		grandparent->left_child = nil_node;
			// 	patient_father->parent = grandparent->parent;
			// 	if (patient_father->parent)
			// 	{
			// 		if (compare(patient_father->value, patient_father->parent->value))			// if new node is bigger
			// 			patient_father->parent->right_child = patient_father;
			// 		else
			// 			patient_father->parent->left_child = patient_father;	
			// 	}
			// 	else
			// 		root = patient_father;
			// 	patient_father->right_child = grandparent;
			// 	grandparent->parent = patient_father;
			// }
			
			// void	rotation_lr(node_ptr patient)					// parent becomes childs left child
			// {
			// 	std::cout << "patient = " << patient->value->key << std::endl; 
			// 	if (!patient)
			// 		return ;
			// 	node_ptr		patient_father = patient->parent;

			// 	if (!patient_father)
			// 		return ;
				
			// 	node_ptr		grandparent = patient_father->parent;

			// 	if (grandparent)
			// 	{
			// 		patient->parent = grandparent;
			// 		if (grandparent->left_child == patient_father)
			// 			grandparent->left_child = patient;
			// 		else
			// 			grandparent->right_child = patient;
			// 	}
			// 	else
			// 	{
			// 		root = patient;
			// 		patient->parent = nil_node;
			// 	}
			// 	if (patient->left_child)
			// 	{
			// 		patient_father->left_child = patient->left_child;
			// 		std::cout << " hai " << patient->left_child->value->key << std::endl;
			// 	}
			// 	patient->left_child = patient_father;
			// 	patient_father->parent = patient;
			// 	if (patient_father->right_child == patient)
			// 		patient_father->right_child = nil_node;
			// 	if (patient_father->left_child == patient)
			// 		patient_father->left_child = nil_node;
			// }
			
			// void	rotation_rr(node_ptr patient)									// grandparent becomes parents left son
			// {
			// 	if (!patient)
			// 		return ;
			// 	node_ptr		patient_father = patient->parent;
				
			// 	if (!patient_father)
			// 		return ;
			// 	node_ptr		grandparent = patient_father->parent;
				
			// 	if (!grandparent )
			// 		return ;				
			// 	if (grandparent->right_child == patient_father)
			// 		grandparent->right_child = nil_node;
			// 	patient_father->parent = grandparent->parent;
			// 	if (patient_father->parent)
			// 	{
			// 		if (compare(patient_father->value, patient_father->parent->value))			// if new node is bigger
			// 			patient_father->parent->right_child = patient_father;
			// 		else
			// 			patient_father->parent->left_child = patient_father;	
			// 	}
			// 	else
			// 		root = patient_father;
			// 	patient_father->left_child = grandparent;
			// 	grandparent->parent = patient_father;
			// }
			
			// void	rotation_rl(node_ptr patient)									// parent becomes childs right child
			// {
			// 	if (!patient)
			// 		return ;
			// 	node_ptr		patient_father = patient->parent;

			// 	if (!patient_father)
			// 		return ;
				
			// 	node_ptr		grandparent = patient_father->parent;

			// 	if (grandparent)
			// 	{
			// 		patient->parent = grandparent;
			// 		if (grandparent->left_child == patient_father)
			// 			grandparent->left_child = patient;
			// 		else
			// 			grandparent->right_child = patient;
			// 	}
			// 	else
			// 	{
			// 		root = patient;
			// 		patient->parent = nil_node;
			// 	}
			// 	patient->right_child = patient_father;
			// 	patient_father->parent = patient;
			// 	if (patient_father->right_child == patient)
			// 		patient_father->right_child = nil_node;
			// 	else
			// 		patient_father->left_child = nil_node;
			// }



			
	// template <class T, class Compare, class allocator >
	// class map_tree : public r_b_tree<T, Compare, allocator>
	// {
	// 	private:
	// 		struct node;
	// 		// typedef					node*								node_ptr;

	// 		// typedef					Key									key_type;
	// 		// typedef					T									mapped_type;
	// 		typedef					T									value_type;
	// 		typedef					allocator							allocator_type;
	// 		typedef typename		allocator_type::reference			reference;
	// 		typedef typename		allocator_type::const_reference		const_reference;
	// 		typedef typename		allocator_type::pointer				pointer;
	// 		typedef typename		allocator_type::const_pointer		const_pointer;
	// 		typedef					ptrdiff_t							difference_type;
	// 		typedef					size_t								size_type;
	// 		typedef					node*								node_ptr;
	// 		typedef					T*									pair_ptr;
	// 		// typedef	const			node*								const_iter;
	// 		typedef					Compare								value_compare;
	// 	public:
	// 		map_tree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), alloc(alloc_), heigth(0), size(0)
	// 		{
	// 			root = NULL;
	// 			nil_node = init_nil();
	// 			std::cout << "i got through this :)" << std::endl;
	// 		};
	// 		~map_tree();


	// 		node_ptr find_key(const value_type &val)
	// 		{
	// 			node_ptr node = root;

	// 			while (node->value.key != val && node != nil_node)
	// 			{
	// 				if (compare(node->value, val))
	// 					node = node->right_child;
	// 				else
	// 					node = node->left_child;
	// 			}	
	// 			return (node);
	// 		}	
	// };

}
#endif