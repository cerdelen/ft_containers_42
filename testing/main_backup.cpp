#include "namespace.hpp"
#include <vector>
#include <iterator>
// #include "vector.hpp"
// #include "r_b_tree.hpp"


#define _testnode map.tree.root->right_child->right_child


void	print_rel_error(std::string rel, int key)
{
	std::cout << "testing " << rel << " of " << key << " is " << "NULL ptr" << std::endl;
}

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

		 ft::pair<int, int> test1 = ft::make_pair(1, 1);
		 ft::pair<int, int> test2 = ft::make_pair(2, 2);
		 ft::pair<int, int> test3 = ft::make_pair(3, 3);
		 ft::pair<int, int> test4 = ft::make_pair(4, 4);
		 ft::pair<int, int> test5 = ft::make_pair(5, 5);
		 ft::pair<int, int> test6 = ft::make_pair(6, 6);
		 ft::pair<int, int> test7 = ft::make_pair(7, 7);
		 ft::pair<int, int> test8 = ft::make_pair(8, 8);
		 ft::pair<int, int> test9 = ft::make_pair(9, 9);
		 ft::pair<int, int> test10 = ft::make_pair(10, 10);
		 ft::pair<int, int> test11 = ft::make_pair(11, 11);
		 ft::pair<int, int> test12 = ft::make_pair(12, 12);
		 ft::pair<int, int> test13 = ft::make_pair(13, 13);
		 ft::pair<int, int> test18 = ft::make_pair(18, 18);
		 ft::pair<int, int> test14 = ft::make_pair(14, 14);
		 ft::pair<int, int> test17 = ft::make_pair(17, 17);
		 ft::pair<int, int> test19 = ft::make_pair(19, 19);
		 ft::pair<int, int> test22 = ft::make_pair(22, 22);
		 ft::pair<int, int> test20 = ft::make_pair(20, 20);



		map.tree.insert(test5);
		map.tree.insert(test13);
		map.tree.insert(test6);
		map.tree.insert(test4);
		map.tree.insert(test12);
		map.tree.insert(test2);
		map.tree.insert(test9);
		map.tree.insert(test7);
		map.tree.insert(test7);
		map.tree.insert(test3);
		map.tree.insert(test20);
		map.tree.insert(test22);
		map.tree.insert(test19);
		map.tree.insert(test17);
		map.tree.insert(test11);

		
		


		// std::cout << "this " << (map.tree.successor(map.tree.root->left_child->left_child))->value->key << " is the successor of " << map.tree.root->left_child->left_child->value->key << std::endl << std::endl;
		// std::cout << "this " << (map.tree.successor(map.tree.root->left_child))->value->key << " is the successor of " << map.tree.root->left_child->value->key << std::endl << std::endl;
		// std::cout << "this " << (map.tree.successor(map.tree.root))->value->key << " is the successor of " << map.tree.root->value->key << std::endl << std::endl;
		// std::cout << "this " << (map.tree.successor(map.tree.root->right_child))->value->key << " is the successor of " << map.tree.root->right_child->value->key << std::endl << std::endl;



		// map.tree.insert(test4);
		// map.tree.insert(test3);
		// map.tree.insert(test2);
		// map.tree.insert(test5);



		// map.tree.insert(test5);
		// map.tree.insert(test1);
		// map.tree.insert(test10);





	
		// std::cout << "insert 1" << std::endl;
		// map.tree.insert(test7);
		// std::cout << "insert 2" << std::endl;
		// map.tree.insert(test4);
		// std::cout << "insert 3" << std::endl;
		// map.tree.insert(test6);
		// map.tree.insert(test3);
		// map.tree.insert(test2);
		// map.tree.insert(test11);
		// std::cout << RED_COL << "insert 18" << DEFAULT_COL << std::endl;
		// map.tree.insert(test18);
		// std::cout << RED_COL << "insert 9" << DEFAULT_COL << std::endl;
		// map.tree.insert(test9);
		// map.tree.insert(test14);
		// map.tree.insert(test12);
		// map.tree.insert(test17);
		// map.tree.insert(test19);
		// map.tree.insert(test22);
		// map.tree.insert(test20);





		// std::cout << "roots father == " << map.tree.root->parent << std::endl;


		// std::cout << map.tree.root << std::endl;
		// std::cout <<map.tree.root->right_child<< std::endl;
		// std::cout << "testing " <<  map.tree.root->left_child->left_child->left_child->left_child << std::endl;
		// std::cout << map.tree.root->left_child->left_child << std::endl;



		// map.test_print_val();
		// map.tree.left_rotation(map.tree.root->right_child);
		// map.test_print_val();
		// map.tree.right_rotation(map.tree.root->right_child);
		// map.test_print_val();
		// map.tree.insert_fixup(map.tree.root->right_child->left_child);

		// map.tree.rotation_ll(map.tree.root->left_child->left_child);
		// std::cout << "testing " <<  map.tree.root->left_child->left_child->left_child->left_child << std::endl;
		// map.tree.rotation_lr(map.tree.root->left_child->left_child);




		// map.test_print_val();
		// // std::cout << "testing " <<  map.tree.root->left_child->left_child->left_child->left_child << std::endl;
		// map.tree.rotation_rl(map.tree.root->left_child->left_child);
		// map.test_print_val();
		// // std::cout << "testing " <<  map.tree.root->left_child->left_child->left_child->left_child << std::endl;
		// map.tree.rotation_rr(map.tree.root->left_child->left_child);
		// map.test_print_val();





		// std::cout << "test " <<  map.tree.root->right_child->right_child->value->key << std::endl;


		// map.test_print_val();


		// std::cout << "test " <<  map.tree.root->left_child->value->key << std::endl << "return = " << map.tree.erase(map.tree.root->left_child)->value->key << std::endl;
		// map.tree.erase(map.tree.root->left_child);
		// std::cout << "test " <<  map.tree.nil_node->value->key << std::endl;
		// map.tree.replace(map.tree.root, map.tree.root->left_child);

		// map.test_print_val();

		// // std::cout << "hiello " << _testnode->value->key << "also " << map.tree.nil_node <<  std::endl;

		// void *tmp;
		// // void *test_node = _testnode;

		// tmp = map.tree.niece(_testnode);
		// // std::cout << "hiello " << tmp << std::endl;
		// if (!tmp)
		// 	print_rel_error("niece", _testnode->value->key);
		// else
		// 	std::cout << "testing niece of " << _testnode->value->key << " is " << map.tree.niece(_testnode)->value->key << std::endl;


		// tmp = map.tree.nephew(_testnode);
		// if (!tmp)
		// 	print_rel_error("nephew", _testnode->value->key);
		// else
		// 	std::cout << "testing nephew of " << _testnode->value->key << " is " << map.tree.nephew(_testnode)->value->key << std::endl;



		// tmp = map.tree.aunt(_testnode);
		// if (!tmp)
		// 	print_rel_error("aunt", _testnode->value->key);
		// else
		// 	std::cout << "testing aunt of " << _testnode->value->key << " is " << map.tree.aunt(_testnode)->value->key << std::endl;





		// std::cout << "testing nephew of " << _testnode->value->key << " is " << map.tree.nephew(_testnode)->value->key << std::endl;
		// std::cout << "testing aunt of " << _testnode->value->key << " is " << map.tree.aunt(_testnode)->value->key << std::endl;

		// std::cout << "nil_node value ptr " << map.tree.nil_node->value << std::endl;


		map.test_print_val();

		// std::cout << "this is da node " << _testnode->value->key << std::endl;

		map.tree.erase_orig2(test5);
		map.tree.erase_orig2(test13);
		map.tree.erase_orig2(test6);
		map.tree.erase_orig2(test12);
		map.tree.erase_orig2(test7);
		// std::cout << "nil_node value ptr " << map.tree.nil_node->value << std::endl;

		// std::cout << "this is after erase" << std::endl;
		map.test_print_val();
		map.tree.clear();

		// std::cout << map.tree.root->left_child->right_child->is_left << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}