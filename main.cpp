#include "namespace.hpp"
#include <vector>
#include <iterator>
#include "reverse_iterator.hpp"

#define tree_max_size 10


#define _testnode map.tree.root->right_child->right_child


void	print_rel_error(std::string rel, int key)
{
	std::cout << "testing " << rel << " of " << key << " is " << "NULL ptr" << std::endl;
}

ft::map<int, int>	init_tree_rand(size_t n)
{
	srand(time(NULL));
	ft::map<int, int>  map;

	int	value;
	for (size_t i = 0; i < n; i++)
	{
		value = rand()%100;
		map.tree.insert(ft::make_pair(value , value));
	}
	return (map);
}
ft::map<int, char>	init_tree_fixed(size_t n)
{
	ft::map<int, char>  map;
	char				val = 'a';

	for (size_t i = 0; i < n; i++)
	{
		map.tree.insert(ft::make_pair(i + 1, val + i));
	}
	return (map);
}

void	erase_map_func(ft::map<int, char> *map, int del)
{
	std::cout << "before erase " << del << "!" << std::endl;
	map->test_print_comp();
	map->tree.erase(ft::make_pair(del, del));
	std::cout << "after erase " << del << "!" << std::endl;
	map->test_print_comp();
}

int main()
{
	try
	{
		ft::map<int, char>  map = init_tree_fixed(tree_max_size);

		// map.test_print_val();


		erase_map_func(&map, 1);

		std::cout << "size = " << map.size() << std::endl;

		// map.test_print_val();
		// map.tree.clear();
		std::cout << "size = " << map.size() << std::endl;
		// rbt_iterator<ft::pair<int, int> > it;




		ft::map<int, char>::iterator it = map.begin();
		it--;
		it++;
		for (size_t i = 0; i < tree_max_size; i++)
		{
			std::cout << i << " content of it = " << (*it).first << std::endl;
			it++;
		}
		it++;
		// std::cout << "content of it = " << (*it).first << std::endl;
		it--;
		// std::cout <<  "nil node = " << map.tree.nil_node << std::endl;

		for (size_t i = 0; i < tree_max_size; i++)
		{

			// std::cout << i << " ptr inside it = " << it._ptr << std::endl;
			std::cout << i << " content of it = " << (*it).first << std::endl;
			it--;
		}
		// it--;
		// std::cout << " content of it = " << (*it).first << std::endl;

		ft::map<int, char>::iterator it2 = map.find(7);

		std::cout << " return of find = " << (*it2).first << std::endl;

		std::cout << " return of at = " << map.at(5) << std::endl;

		ft::pair<ft::map<int, char>::iterator, bool> weirdo = map.insert(ft::make_pair(8, 'z'));
		
		if(weirdo.second == true)
			std::cout << "bool return of insert true" << std::endl;
		else
			std::cout << "bool return of insert tfalse" << std::endl;



		map.clear();
		if(map.empty() == true)
			std::cout << "empty = true " << std::endl;
		else
			std::cout << "empty = false " << std::endl;
		std::cout << "max size = " << map.max_size() << std::endl;
		// std::cout << "size = " << map.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << std::endl << e.what() << std::endl;
	}
}