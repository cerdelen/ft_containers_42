/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_b_tree.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:29:46 by cerdelen          #+#    #+#             */
/*   Updated: 2022/09/06 19:49:07 by cerdelen         ###   ########.fr       */
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
			// typedef	const		node*								const_iter;
			typedef				Compare								value_compare;



		struct node
		{
			T			value;
			bool		col;
			node_ptr	left_child;
			node_ptr	right_child;
			node_ptr	parent;
		};
		
		private:
			node_ptr			root;
			size_t				heigth;
			value_compare		compare;
			allocator_type		alloc;
			
			// node	&get_note( void )
			// {
			// 	// node	*tmp = new node;

			// 	tmp-> = true;

			// 	// node.left = true;
				
					
			// }
			node_ptr	get_node(bool col, value_type &data)
			{
				node_ptr	out = alloc.allocate(sizeof(struct node));
			
				out->parent = NULL;
				out->left_child = NULL;
				out->rigth_child = NULL;
				out->col = col;
				out->value = data;
				return (out);	
			}
			
		public:
			r_b_tree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), alloc(alloc_), heigth(0)
			{
				root = NULL;
			}
			~r_b_tree();

			
			template <class T1>
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
							tmp = tmp->left_child;
						else if (compare(tmp->value, new_node->value))			// new_node is smaller
							tmp = tmp->right_child;
						else													// both values are same
							return ;
						new_heigth++;
					}

					//setting parent ptr and arents child ptr to new node
					new_node->parent = tmp_parent;
					if (compare(new_node->value, tmp_parent->value))
						tmp_parent->left_child = new_node;
					else
						tmp_parent->right_child = new_node;

					//fix insertion with rules
					
				}
				if (new_heigth > heigth)
					heigth = new_heigth;
			}
			void	print_rec(const std::string& prefix, node_ptr node_, bool left) const
			{
				if (node_ != nullptr)
				{		
					std::cout << prefix;

					std::cout << (left ? "├──" : "└──" );

					// print the value of the node
					std::cout << node_->value.key << std::endl;

					// enter the next tree level - left and right branch
					print_rec(prefix + (left ? "│   " : "    "), node_->left_child, true);
					print_rec(prefix + (left ? "│   " : "    "), node_->right_child, false);
				}
			}
			void print_tree(void) const
			{
				print_rec("", root, false);
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