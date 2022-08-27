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
	std::cout << "size before " << a.size() << std::endl;

	a.assign(7, 3);

	std::cout << "size after " << a.size() << std::endl;
	a.test_print();

	// ft::vector<int>::iterator it(x.begin());

	// std::cout << it[0] << std::endl;

	// it[0] = 0;
	// it[1] = 1;
	// it[2] = 2;
	// it[3] = 3;

	// std::vector<int> b(12, 12);

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