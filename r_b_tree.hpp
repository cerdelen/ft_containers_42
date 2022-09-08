/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/08 19:20:22 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R_B_TREE
#define R_B_TREE
// #include "namespace.hpp"
#define RED true
#define BLCK false

namespace ft
{
	

	// typedef ft::pair<class T1, class T2>			compare_type;

	// class pair_compare : public std::binary_function<compare_type, compare_type, bool>
	// {
	// 	public:
	// 		pair_compare();
	// 		~pair_compare();
	// 		bool operator()(const compare_type &first, const compare_type &second) const
	// 		{
	// 			return (first.key > second.val);
	// 		}
	// };
	
	// bool	pair_compare( const pair &pair_1, const pair &pair_2)
	// {
	// 	if (pair_1.first_type > pair_2.first_type)
	// 		return (true);
	// 	return (false);
	// }
	
	template <class T, class Compare, class allocator >
	class r_b_tree
	{
		public:
			struct node;

			// typedef				Key									key_type;
			// typedef				T									mapped_type;
			typedef				T									value_type;
			typedef				allocator							allocator_type;
			typedef typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;
			typedef				ptrdiff_t							difference_type;
			typedef				size_t								size_type;
			typedef				node*								node_ptr;
			typedef				T*									pair_ptr;
			// typedef	const		node*								const_iter;
			typedef				Compare								value_compare;



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
		private:
			size_t						heigth;
			value_compare				compare;
			allocator_type				alloc;
			std::allocator<node>		node_alloc;
			std::allocator<T>			pair_alloc;
			size_t						size;

			
			// node	&get_note( void )
			// {
			// 	// node	*tmp = new node;

			// 	tmp-> = true;

			// 	// node.left = true;
				
					
			// }
			node_ptr	get_node(bool col, const value_type &data)
			{
				node_ptr		out;
				out = node_alloc.allocate(sizeof(struct node));
				// value_type *dates;
				pair_ptr  		pair_out;
				pair_out = pair_alloc.allocate(1);
				pair_alloc.construct(pair_out, data);
				
			
				out->parent = NULL;
				out->left_child = NULL;
				out->right_child = NULL;
				out->col = col;
				// out->value = data;
				out->value = pair_out;
				return (out);	
			}
			
		public:
			r_b_tree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), alloc(alloc_), heigth(0), size(0)
			{
				root = NULL;
			}
			~r_b_tree() {};

			
			// template <class T1>
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
					while (tmp != NULL)
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
					//fix insertion with rules
					
				}
				size++;
				if (new_heigth > heigth)
					heigth = new_heigth;
			}
			void	print_rec(const std::string& prefix, node_ptr node_, bool left, bool key) const
			{
				if (key)
				{
					if (node_ != nullptr)
					{		
						std::cout << prefix;

						std::cout << (left ? "├──" : "└──" );

						// print the value of the node
						std::cout << node_-> value->key << std::endl;
						print_rec(prefix + (left ? "│   " : "    "), node_->left_child, true, true);
						print_rec(prefix + (left ? "│   " : "    "), node_->right_child, false, true);

						// enter the next tree level - left and right branch
					}
				}
				else
				{
					if (node_ != nullptr)
					{		
						std::cout << prefix;

						std::cout << (left ? "├──" : "└──" );

						// print the value of the node
						std::cout << node_-> value->val << std::endl;
						print_rec(prefix + (left ? "│   " : "    "), node_->left_child, true, false);
						print_rec(prefix + (left ? "│   " : "    "), node_->right_child, false, false);

						// enter the next tree level - left and right branch
					}
				}
			}
			void print_tree_key() const
			{
				std::cout << "Tree height is " << heigth << " and size is " << size << std::endl;
				print_rec("", root, false, true);
			}
			void print_tree_val() const
			{
				std::cout << "Tree height is " << heigth << " and size is " << size << std::endl;
				print_rec("", root, false, false);
			}

			void	rotation_ll(node_ptr patient)					// grandparent becomes parents right son
			{
				if (!patient)
					return ;
				node_ptr		patient_father = patient->parent;
				
				if (!patient_father)
					return ;
				node_ptr		grandparent = patient_father->parent;
				
				if (!grandparent )
					return ;				
				if (grandparent->left_child == patient_father)
					grandparent->left_child = NULL;
				patient_father->parent = grandparent->parent;
				if (patient_father->parent)
				{
					if (compare(patient_father->value, patient_father->parent->value))			// if new node is bigger
						patient_father->parent->right_child = patient_father;
					else
						patient_father->parent->left_child = patient_father;	
				}
				else
					root = patient_father;
				patient_father->right_child = grandparent;
				grandparent->parent = patient_father;
			}
			
			void	rotation_lr(node_ptr patient)					// parent becomes childs left child
			{
				if (!patient)
					return ;
				node_ptr		patient_father = patient->parent;

				if (!patient_father)
					return ;
				
				node_ptr		grandparent = patient_father->parent;

				if (grandparent)
				{
					patient->parent = grandparent;
					if (grandparent->left_child == patient_father)
						grandparent->left_child = patient;
					else
						grandparent->right_child = patient;
				}
				else
				{
					root = patient;
					patient->parent = NULL;
				}
				patient->left_child = patient_father;
				patient_father->parent = patient;
				if (patient_father->right_child == patient)
					patient_father->right_child = NULL;
				else
					patient_father->left_child = NULL;
			}
			
			void	rotation_rr(node_ptr patient)									// grandparent becomes parents left son
			{
				
			}
			
			void	rotation_rl(node_ptr patient)									// parent becomes childs right child
			{
				
			}
			
			
			
			// void	print(int depth)
			// {
			// 	while (depth < this->heigth)
			// 	{
					
			// 	}
			// }
	};
}
#endif