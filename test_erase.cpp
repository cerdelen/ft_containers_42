#include "ft_map.hpp"



// int		main( void )
// {
// 	ft::map<int, int>	mp;
// 	size_t		_ratio = 1000;

//     for (int i = 0, j = 0; i < 10 ; ++i, ++j)
//         mp.insert(ft::make_pair(i, j));




// 	mp.test_print_(true, true, true, false);
// 	mp.test_print_key();


// 	std::cout << "test starts here " << std::endl;
//     mp.erase(mp.begin(), --mp.end());
// 	// mp.begin()->first;
// }




int		main( void )
{
	ft::map<int, int>	mp;
	size_t		_ratio = 1000;

    for (int i = 0, j = 0; i < 10 ; ++i, ++j)
        mp.insert(ft::make_pair(i, j));




	// mp.test_print_(true, true, true, false);
	// mp.test_print_key();

	// std::cout << "test starts here " << std::endl;


	// ft::map<int, int>::iterator			it = mp.begin();
	// ft::map<int, int>::iterator			it_e = mp.end();

	// while (it != it_e)
	// {
    // 	mp.erase(it);
	// 	it = mp.begin();
	// 	mp.test_print_(true, true, true, false);
	// }
    // mp.erase(mp.begin(), --mp.end());
	// mp.begin()->first;
}