#include "namespace.hpp"
#include <vector>
#include <iterator>
// #include "vector.hpp"
#include "r_b_tree.hpp"

int main()
{
	try
	{
		// std::cout << std::endl;
		// std::cout << std::endl;
		// std::cout << std::endl;
		// std::cout << "Start of Main" << std::endl;
		// std::cout << std::endl;
		// std::cout << std::endl;

		// int size = 13;
		// std::vector<int> og(size, 12);
		// // std::vector<int> og2;
		// ft::vector<int> my(size, 12);
		// // ft::vector<int> my2;

		// for (size_t i = 0; i < size; i++)
		// {
		// 	og[i] = i;
		// 	my[i] = i;
		// }
		// // for (size_t i = 0; i < 20; i++)
		// // {
		// // 	og2[i] = i;
		// // 	my2[i] = i;
		// // }

		// std::vector<int> og2(og);
		// ft::vector<int> my2(my);

		// og2 = og;
		// my2 = my;

	// for (size_t i = 0; i < 13; i++)
	// {
	// 	std::cout << "og = " << *(og.insert(og.begin() + 6, 900 + i));
	// 	std::cout << " my = " << *(my.insert(my.begin() + 6, 900 + i)) << std::endl;
	// }

	// og.insert(og.begin() + 6, og2.begin(), og2.end());
	// my.insert(my.begin() + 6, my2.begin(), my2.end());
	
	// std::cout << "og    my" << std::endl;
	// for (size_t i = 0; i < og.size(); i++)
	// {
	// 	std::cout << og2[i] << "    " << my2[i] << std::endl;
	// }
	// for (size_t i = 0; i < my.size(); i++)
	// {
	// }

	// std::cout << "og size = " << og.size() << " capacity " << og.capacity() << std::endl;
	// std::cout << "my size = " << my.size() << " capacity " << my.capacity() << std::endl;

		// a[0] = 0;
		// a[1] = 1;
		// a[2] = 2;
		// a[3] = 3;
		// a[4] = 4;
		// // std::vector<int> a(10, 5);
		// // ft::vector<int> b(10, 5);
		// // ft::vector<int> x;
		// // a.test_print();
		// // std::cout << "size before " << a.size() << std::endl;

		// // a.assign(7, 3);

		// // std::cout << "size after " << a.size() << std::endl;


		// // a.test_print();
		// // std::vector<int>::iterator it;
		// ft::vector<int>::iterator it(a.begin());
		// ft::vector<int>::iterator it2(a.begin() + 2);

		// // a.erase(it);

		// // std::cout << "it " << *it << std::endl;
		// std::cout << "it " << *it << " it2 " << *it2 << std::endl;


		// a.test_print();
		// // a.erase(it);
		// std::cout << *(a.erase(it, it2))<< std::endl;
		// std::cout << std::endl;
		// a.test_print();

		// a.erase(a.end());
		// a.erase(a.end());
		// a.erase(a.end());
		// a.erase(a.end());
		// a.erase(a.end());
		// a.erase(a.begin());

		
		// std::cout << a[0] << std::endl;
		// std::cout << a[1] << std::endl;
		// std::cout << a[2] << std::endl;
		// std::cout << a[3] << std::endl;
		// std::cout << a[4] << std::endl;


		// a.reserve(15);
		// std::cout << a.capacity() << std::endl;

		// std::cout << *(a.insert(a.end(), 12)) << std::endl;

		// std::cout << a.capacity() << std::endl;

		// b.reserve(15);
		// std::cout << b.capacity() << std::endl;

		// std::cout << *(b.insert(b.end(), 12)) << std::endl;

		// std::cout << b.capacity() << std::endl;


		// a.push_back(12);



		// std::cout << std::endl;
		
		// a.pop_back();
		// a.pop_back();
		// a.pop_back();
		// a.pop_back();
		// a.pop_back();
		// a.pop_back();
		// a.push_back(12);
		
		// a.test_print();


		// std::cout << std::endl << a.max_size() << std::endl;

		// std::cout << a.size() << std::endl;
		// a.clear();
		// std::cout << a.size() << std::endl;

		// x.test_print();
		// std::cout << "i call assing with it here " << std::endl;
		// x.assign(a.begin(), a.end());

		// x.test_print();

		// a.front() = 3;

		// std::cout << std::endl << a.front() << std::endl;




		// std::cout << std::endl << a.back() << std::endl;





		// ft::vector<int>::iterator it(x.begin());

		// std::cout << it[0] << std::endl;

		// it[0] = 0;
		// it[1] = 1;
		// it[2] = 2;
		// it[3] = 3;

		// std::vector<int> b;

		// for (size_t i = 0; i < 33; i++)
		// {
		// 	b.push_back(12);
		// 	std::cout << "size == " << b.size() << " and capacity = " << b.capacity() << std::endl;
		// 	/* code */
		// }
		// std::cout << "da" << b[60] << std::endl;
		// int x = 1;
		// x = x << 0;
		// std::cout << "start " << x << std::endl; 

		// x = x << 4;
		// std::cout << "after shift " << x << std::endl; 

		// 000000001
		// 000000100
		
		// std::cout << "size == " << b.size() << " and capacity = " << b.capacity() << std::endl;


		// std::vector<int>::iterator k(b.begin());

		// ft::vector<int>::iterator s;

		// s = a.begin();

		// std::cout << "this is dereferenced iterator: " << *s << std::endl;

		// while (it != x.end())
		// {
		// 	std::cout << *it << std::endl;
		// 	it++;
		// }


		// ft::r_b_tree<ft::pair<int, int>, ft::pair_compare > tree;
		// ft::r_b_tree	tree(compare_function, std::allocator<ft::pair>);
		// tree.insert
		ft::map<int, int>  map;

		ft::pair<int, int> test(1, 1);
		map.tree.insert(test);
		// map.insert(1, 1);
		// map.insert(2, 2);
		// map.insert(3, 3);
		// map.insert(4, 4);
		map.test_print();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}