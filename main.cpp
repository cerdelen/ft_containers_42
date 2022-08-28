#include "namespace.hpp"
#include <vector>
#include <iterator>
#include "vector.hpp"


int main()
{
	// ft::vector<int> a(12, 12);
	ft::vector<int> a(5, 5);
	// ft::vector<int> x(5, 5);
	// a.test_print();
	// std::cout << "size before " << a.size() << std::endl;

	// a.assign(7, 3);

	// std::cout << "size after " << a.size() << std::endl;


	a.test_print();

	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	// a.push_back(12);

	a.test_print();


	std::cout << std::endl;
	
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	// a.push_back(12);
	
	a.test_print();

	// std::cout << std::endl << a.front() << std::endl;

	// a.front() = 3;

	// std::cout << std::endl << a.front() << std::endl;




	// std::cout << std::endl << a.back() << std::endl;





	// ft::vector<int>::iterator it(x.begin());

	// std::cout << it[0] << std::endl;

	// it[0] = 0;
	// it[1] = 1;
	// it[2] = 2;
	// it[3] = 3;

	std::vector<int> b;

	for (size_t i = 0; i < 33; i++)
	{
	b.push_back(12);
	std::cout << "size == " << b.size() << " and capacity = " << b.capacity() << std::endl;
		/* code */
	}
	std::cout << "da" << b[60] << std::endl;
	// int x = 1;
	// 	x = x << 0;
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
	


}