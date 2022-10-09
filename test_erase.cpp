#include "ft_map.hpp"



// int		main( void )
// {
// 	ft::map<int, int>	mp;
// 	size_t		_ratio = 1000;

//     for (int i = 0, j = 0; i < 10 ; ++i, ++j)
//         mp.insert(ft::make_pair(i, j));




// 	mp.test_print_(true, true, true, false);


// 	std::cout << "test starts here " << std::endl;
//     mp.erase(mp.begin(), --mp.end());
// 	// mp.begin()->first;
// }


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

int		main( void )
{
	ft::map<int, char>	mp = init_tree_fixed(10);
	size_t		_ratio = 1000;

    // for (int i = 0, j = 0; i < 10 ; ++i, ++j)
    //     mp.insert(ft::make_pair(i, j));




	// mp.test_print_(true, true, true, false);
	// mp.test_print_key();

	std::cout << "test starts here " << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	mp.test_print_(true, true, true, false);


	ft::map<int, char>::iterator			it = mp.begin();
    // 	mp.erase(it);
	ft::map<int, char>::iterator			it_e = mp.end();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	// std::cout << "test ends here " << std::endl;
	// mp.test_print_(true, true, true, false);
	while (it != it_e)
	{
    	mp.erase(it);
		it = mp.begin();
		mp.test_print_(true, true, true, false);
	}
    // mp.erase(mp.begin(), --mp.end());
	// mp.begin()->first;
}