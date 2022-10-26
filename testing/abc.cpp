#include "../ft_vector/ft_vector.hpp"
#include <vector>

// int main ()
// {
// 	ft::vector<int>  vec;

// 	vec.insert(vec.begin(), 12);
// 	vec.insert(vec.begin(), 13);

// 	ft::vector<int>::reverse_iterator  rit = vec.rbegin();
// 	ft::vector<int>::reverse_iterator  rend = vec.rend();
// 	for (; rit != rend; rit++)
// 	{
// 		std::cout << *rit << std::endl;
// 	}
	
// 	return 0;
// }



int main ()
{
	std::vector<int>  vec;

	vec.insert(vec.begin(), 12);
	vec.insert(vec.begin(), 13);

	std::vector<int>::reverse_iterator  rit = vec.rbegin();
	std::vector<int>::reverse_iterator  rend = vec.rend();
	for (; rit != rend; rit++)
	{
		std::cout << *rit << std::endl;
	}
	
	return 0;
}