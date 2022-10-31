/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerdelen <cerdelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:54:14 by cerdelen          #+#    #+#             */
/*   Updated: 2022/10/31 16:25:39 by cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../namespace.hpp"
#include <map>
#include "colours.h"
#include <utility>

#define _mymap ft::map<size_t, size_t>
#define _ogmap std::map<size_t, size_t>
#define _myit _mymap::iterator
#define _ogit _ogmap::iterator
#define _my_mpair ft::make_pair<size_t, size_t>
#define _og_mpair std::make_pair<size_t, size_t>

bool equal_for_test(_myit start1, _myit end1, _ogit start2)
{
	try
	{
		while(start1 != end1)
		{
			if ((*start1).first != (*start2).first || (*start1).second != (*start2).second)
				return (false);
			start1++;
			start2++;
		}
		return (true);
	}
	catch(const std::exception& e)
	{
	}
	return (false);
}

void	check_if_equal(std::string test_case, _mymap my, _ogmap og)
{
	if (equal_for_test(my.begin(), my.end(), og.begin()))
		std::cout << test_case << GREEN_COL << " is equal!" << std::endl;
	else
		std::cout << test_case << RED_COL << " is not equal!" << std::endl;
	std::cout << DEFAULT_COL << std::endl;
}

template <class T>
void	check_if_equal(std::string test_case, T my_value, T og_value)
{
	if (my_value == og_value)
		std::cout << test_case << GREEN_COL << " returns same value!" << std::endl;
	else
		std::cout << test_case << RED_COL << " returns different value!" << std::endl;
	std::cout << DEFAULT_COL << std::endl;
}

int main()
{
	_mymap		my_source;
	_ogmap		og_source;
	_mymap		my_source2;
	_ogmap		og_source2;

	check_if_equal("Empty after default constructor", my_source, og_source);
	for (size_t i = 0; i < 10; i++)
	{
		my_source.insert(_my_mpair(i, i));
		og_source.insert(_og_mpair(i, i));
		my_source2.insert(_my_mpair(i + 10, i + 10));
		og_source2.insert(_og_mpair(i + 10, i + 10));
	}

	if (my_source.size() == 10)
		std::cout << GREEN_COL << "size() returns correct value" << std::endl;
	else
		std::cout << RED_COL << "size() returns false value" << std::endl;

	std::cout << DEFAULT_COL << std::endl;

	check_if_equal("Filled with insert", my_source, og_source);
	{
		_mymap		tmp_my(my_source);
		_ogmap		tmp_og(og_source);
		
		check_if_equal("Maps after copy constructor", my_source, og_source);
	}

	{
		_mymap		tmp_my(my_source.begin(), my_source.end());
		_ogmap		tmp_og(og_source.begin(), og_source.end());
		
		check_if_equal("Maps after range constructor", my_source, og_source);
		for (size_t i = 5; i < 10; i++)
		{
			tmp_my.erase(i);
			tmp_og.erase(i);
		}
		check_if_equal("Erased with Key", tmp_my, tmp_og);
		{
			_myit	it = tmp_my.begin();
			_ogit	it2 = tmp_og.begin();
			for (size_t i = 0; i < 3; i++)
			{
				tmp_my.erase(it++);
				tmp_og.erase(it2++);
			}
		}
		check_if_equal("Erased with iterator", tmp_my, tmp_og);

		tmp_my = my_source;
		tmp_og = og_source;
		check_if_equal("Equal sign operator", tmp_my, tmp_og);
	}


	{
		_mymap		tmp_my(my_source.begin(), my_source.end());
		_mymap		tmp_my2(my_source2.rbegin(), my_source2.rend());
		
		_myit		it1 = tmp_my.begin();
		_myit		it2 = tmp_my2.begin();

		std::cout << "[MY] Before swap it 1 ->" << it1->first << " and it2 -> " << it2->first << std::endl;
		tmp_my.swap(tmp_my2);
		std::cout << "[MY] After swap it 1 ->" << it1->first << " and it2 -> " << it2->first << std::endl;
		std::cout << std::endl;

		_ogmap		tmp_og(og_source.begin(), og_source.end());
		_ogmap		tmp_og2(og_source2.rbegin(), og_source2.rend());
		
		_ogit		ogit1 = tmp_og.begin();
		_ogit		ogit2 = tmp_og2.begin();

		std::cout << "[OG] Before swap it 1 ->" << ogit1->first << " and it2 -> " << ogit2->first << std::endl;
		tmp_og.swap(tmp_og2);
		std::cout << "[OG] After swap it 1 ->" << ogit1->first << " and it2 -> " << ogit2->first << std::endl;
		std::cout << std::endl;
	}

	{
		check_if_equal("Valid [] operator", my_source[9], og_source[9]);
		check_if_equal("Invalid [] operator", my_source[12], og_source[12]);
		
		check_if_equal("Valid at()", my_source.at(9),  og_source.at(9));
		bool	try_res = false;
		try
		{
			my_source.at(1000);
		}
		catch(const std::exception& e)
		{
			try_res = true;
		}
		std::cout << "Invalid at()";
		if (try_res)
			std::cout << GREEN_COL << " did throw an exeption!";
		else
			std::cout << RED_COL << " did not throw an exeption!";
		std::cout << DEFAULT_COL << std::endl << std::endl;
	}

	{
		check_if_equal("Checking begin()", (my_source.begin())->first,  (og_source.begin())->first);
		check_if_equal("Checking --end()", (--(my_source.end()))->first,  (--(og_source.end()))->first);
		check_if_equal("Checking empty()", my_source.empty(),  og_source.empty());
		check_if_equal("Checking size()", my_source.size(),  og_source.size());

		check_if_equal("Checking find()", my_source.find(5)->first,  og_source.find(5)->first);
		check_if_equal("Checking equal_range()", my_source.equal_range(5).first->first,  og_source.equal_range(5).first->first);
		check_if_equal("Checking lower_bound()", my_source.lower_bound(5)->first,  og_source.lower_bound(5)->first);
		check_if_equal("Checking upper_bound()", my_source.upper_bound(5)->first,  og_source.upper_bound(5)->first);

	}


}
