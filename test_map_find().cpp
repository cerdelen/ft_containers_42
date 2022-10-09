#include "ft_map.hpp"
#include <iostream>


ft::map<int, char>	init_tree_fixed(size_t n)
{
	ft::map<int, char>  map;
	char				val = 'a';

	for (size_t i = 0; i < n; i++)
	{
		map.insert(ft::make_pair(i + 1, val + i));
	}
	return (map);
}

int main( void )
{
	ft::map<int, char>	mappy = init_tree_fixed(15);

	#define DEBUG
	mappy.test_print_comp();
	mappy.clear();
	mappy.clear();
	mappy.clear();
	mappy.clear();
	mappy.test_print_comp();
	// std::cout << "From here starts the testing" << std::endl << std::endl;
	// std::cout << (mappy.find(12))->first << std::endl;
}