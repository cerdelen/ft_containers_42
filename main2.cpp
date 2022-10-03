#include "namespace.hpp"


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

void	try_catch_derefference_it_increased(ft::map<int, char> &mappy, ft::map<int, char>::reverse_iterator &it, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		try
		{
			// std::cout << it.base() << std::endl;
			std::cout << (*it).first << " = " << (*it).second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		// std::cout << "before" << std::endl;
		it++;
		// std::cout << "after" << std::endl;
	}
}
void	try_catch_derefference_it_decreased(ft::map<int, char> &mappy, ft::map<int, char>::reverse_iterator &it, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		try
		{
			// std::cout << it.base() << std::endl;
			std::cout << it->first << " = " << (*it).second << std::endl;
			// std::cout << (*it).first << " = " << (*it).second << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		// std::cout << "before" << std::endl;
		it--;
		// std::cout << "after" << std::endl;
	}
}
// int main()
// {
// 	std::map<int ,char>   mappy;

// 	char				val = 'a';

// 	for (size_t i = 0; i < 15; i++)
// 	{
// 		mappy.insert(std::make_pair(i + 1, val + i));
// 	}

// 	std::map<int, char>::iterator		it = mappy.begin();
// 	std::cout << it->first << std::endl;
// }

// int main()
// {
// 	#if DEBUG
// 		std::cout << "this is debug Mode" << std::endl;
// 	#endif
// 	ft::map<int ,char>   mappy = init_tree_fixed(15);

// 	// ft::map<int, char>::iterator			it = mappy.end();
// 	ft::map<int, char>::const_iterator		consty = mappy.end();
// 	// std::cout << "this is _nil " << mappy.tree.nil_node << std::endl;
// 	// mappy.test_print_comp_with_ptr();
// 	// try_catch_derefference_it_increased(mappy, it, 20);
// 	// std::cout << "Zwischenstopp" << std::endl;
// 	// try_catch_derefference_it_decreased(mappy, it, 20);
// 	// std::cout << "Zwischenstopp 2" << std::endl;
// 	// try_catch_derefference_it_increased(mappy, it, 20);
// 	// std::cout << "Zwischenstopp 3" << std::endl;
// 	// try_catch_derefference_it_decreased(mappy, it, 20);
// 	// std::cout << "Zwischenstopp 4" << std::endl;
// }

int main()
{
	ft::map<int ,char>   mappy = init_tree_fixed(15);

	ft::map<int, char>::reverse_iterator		it = mappy.rbegin();
	// std::cout << "this is _nil " << mappy.tree.nil_node << std::endl;
	// mappy.test_print_comp_with_ptr();
	try_catch_derefference_it_increased(mappy, it, 20);
	std::cout << "Zwischenstopp" << std::endl;
	try_catch_derefference_it_decreased(mappy, it, 20);
	std::cout << "Zwischenstopp 2" << std::endl;
	try_catch_derefference_it_increased(mappy, it, 20);
	std::cout << "Zwischenstopp 3" << std::endl;
	try_catch_derefference_it_decreased(mappy, it, 20);
	std::cout << "Zwischenstopp 4" << std::endl;
}