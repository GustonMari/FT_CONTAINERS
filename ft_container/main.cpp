/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/11/23 20:35:22 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: maybe delete all std include for evaluation ?
# include <iostream>
# include <vector>
# include <map>
# include <list>
# include <iterator>
# include <string>
# include "enable_if.hpp"
# include "vector_base.hpp"
# include "vector.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "reverse_iterator.hpp"
# include "iterator.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "pair.hpp"
# include "utils.hpp"
# include "_colors.hpp"
# include "map.hpp"
# include "stack.hpp"
#include "rbt.hpp"
#include "pair.hpp"
#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

using namespace TESTED_NAMESPACE;


int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	CCOUT(YELHB, "                                         GMARY'S TESTS                                         ");
	COUT("\n\n\n")
	CCOUT(UMAG, "NO ARGS = ALL\n0 - VECTOR\n1 - STACK\n2 - MAP\n3 - SET\n4 - PAIR\n");
	std::string arg;
	std::string special_arg;
	if (ac == 3)
	{
		arg = av[1];
		special_arg = av[2];
	}
	else if (ac == 2)
		arg = av[1];
	else
		arg = "all";

	//! NORMAL TESTS FOR VECTOR
	if (arg == "0" || arg == "vector" || arg == "all")
	{

		COUT("\n\n\n")
		CCOUT(YELHB, "                                         VECTOR TESTS                                         ");
		COUT("\n\n\n")
		

		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		

		TESTED_NAMESPACE::vector<int> myvector;
		TESTED_NAMESPACE::vector<int> myvector2(5);
		TESTED_NAMESPACE::vector<int> myvector3(5, 42);
		TESTED_NAMESPACE::vector<int> myvector4(myvector3);
		TESTED_NAMESPACE::vector<int> myvector5(myvector3.begin(), myvector3.end());
		TESTED_NAMESPACE::vector<std::string> myvector6(5, "hello");

		COUT("size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		COUT("size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		COUT("size: " << myvector4.size() << " capacity: " << myvector4.capacity());
		COUT("size: " << myvector5.size() << " capacity: " << myvector5.capacity());

		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;

		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector4.begin(); it != myvector4.end(); it++)
			std::cout << *it << std::endl;

		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector5.begin(); it != myvector5.end(); it++)
			std::cout << *it << std::endl;

		CCOUT(UMAG, "                                         ASSIGNATION\n");

		COUT("before assignation size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector = myvector3;
		COUT("after assignation size: " << myvector.size() << " capacity: " << myvector.capacity());

		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;

		CCOUT(UMAG, "                                         PUSH BACK\n");
		
		myvector.push_back(89);
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.push_back(90);
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.push_back(91);

		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		myvector.push_back(92);
		myvector.push_back(93);
		myvector.push_back(-94);
		myvector.push_back(-95);
		myvector.push_back(-96);
		myvector.push_back(-97);

		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		COUT("size: " << myvector6.size() << " capacity: " << myvector6.capacity());

		myvector6.push_back("wesh");
		myvector6.push_back("hell nooo");
		myvector6.push_back("c mort frr");
		myvector6.push_back("wougada");
		
		COUT("size: " << myvector6.size() << " capacity: " << myvector6.capacity());
		

		CCOUT(UMAG, "                                         ITERATORS\n");

		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.end(); it != myvector.begin(); --it)
			std::cout << *it << std::endl;

		for (TESTED_NAMESPACE::vector<int>::reverse_iterator it = myvector.rbegin(); it != myvector.rend(); ++it)
			std::cout << *it << std::endl;
		
		TESTED_NAMESPACE::vector<std::string>::iterator ito = myvector6.begin();
		ito++;
		ito++;
		ito--;
		--ito;

		CCOUT(UMAG, "                                         INSERT\n");

		myvector.insert(myvector.begin(), 42);
		myvector.insert(myvector.begin(), 42);
		COUT("size: " << myvector6.size() << " capacity: " << myvector6.capacity());
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.insert(myvector.begin(), 2, 42);
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		COUT("size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		COUT("before insert with 3 args --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.insert(myvector.begin(), myvector3.begin(), myvector3.end());
		COUT("after insert with 3 args --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		COUT("size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		
		CCOUT(UMAG, "                                         ERASE\n");

		COUT("before erase --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector.erase(myvector.begin());
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		COUT("after erase --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		myvector3.erase(myvector3.begin(), myvector3.end());
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		COUT("erase --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());

		CCOUT(UMAG, "                                         SWAP\n");
		
		myvector3.push_back(42);
		myvector3.push_back(42);
		myvector3.push_back(42);
		myvector.push_back(12);
		myvector.push_back(12);
		
		myvector.swap(myvector3);
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
			std::cout << *it << std::endl;
		COUT("swap --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		COUT("swap --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());

		CCOUT(UMAG, "                                         CLEAR\n");

		myvector6.clear();
		COUT("swap --- size: " << myvector6.size() << " capacity: " << myvector6.capacity());
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
			
		CCOUT(UMAG, "                                         AT\n");
		myvector3.at(0) = 42;
		COUT("at --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		COUT(myvector3.at(0));
		COUT("at --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());
		COUT("back: " << myvector3.back());
		COUT("front: " << myvector3.front());
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
			std::cout << *it << std::endl;
		
		CCOUT(UMAG, "                                         POP BACK\n");
		
		COUT("pop back --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2.pop_back();
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("pop back --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		CCOUT(UMAG, "                                         ASSIGN\n");
		
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2.assign(5, 42);
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		TESTED_NAMESPACE::vector<int>::const_iterator it_const_int = myvector2.begin();
		TESTED_NAMESPACE::vector<int>::const_iterator it_const_end = myvector2.end();

		myvector2.assign(it_const_int, it_const_end);
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
			
		it_const_int++;
		it_const_end--;
		myvector2.assign(it_const_int, it_const_end);
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("assign --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		CCOUT(UMAG, "                                         RESIZE\n");

		COUT("resize --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2.resize(10);
		for (TESTED_NAMESPACE::vector<int>::iterator it = myvector2.begin(); it != myvector2.end(); it++)
			std::cout << *it << std::endl;
		COUT("resize --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());

		CCOUT(UMAG, "                                         OPERATOR []\n");

		COUT("operator [] --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
		myvector2[0] = 42;
		myvector2[1] = 42;
		COUT("operator [] --- size: " << myvector2.size() << " capacity: " << myvector2.capacity());
	}
	if (special_arg == "0" )
	{
		try
		{
			TESTED_NAMESPACE::vector<int> myvector(10);
			myvector.push_back(42);
			myvector.at(42);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	if (arg == "1" || arg == "stack" || arg == "all")
	{

		COUT("\n\n\n")
		CCOUT(YELHB, "                                         STACK TESTS                                         ");
		COUT("\n\n\n")
		

		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		TESTED_NAMESPACE::map<int, int> map;
		TESTED_NAMESPACE::stack<int, TESTED_NAMESPACE::map<int, int> > mystack_test(map);
		COUT("empty: " << mystack_test.empty());
		COUT("size: " << mystack_test.size());
	
		CCOUT(UMAG, "                                         TEST\n");

		TESTED_NAMESPACE::stack<int> mystack;
		mystack.push(42);
		mystack.push(478);
		mystack.push(389);
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		mystack.pop();
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		TESTED_NAMESPACE::stack<int> mystack2(mystack);
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		mystack2.pop();
		COUT("size: " << mystack.size());
		COUT("top: " << mystack.top());
		COUT("empty: " << mystack.empty());
		
	}
	if (arg == "2" || arg == "map" || arg == "all" )
	{
		COUT("\n\n\n")
		CCOUT(YELHB, "                                         MAP TESTS                                         ");
		COUT("\n\n\n")
		
		CCOUT(UMAG, "                                         CONSTRUCTORS\n");
		TESTED_NAMESPACE::map<int, int> map;
		map.insert(TESTED_NAMESPACE::pair<int, int>(42, 42));
		map.insert(TESTED_NAMESPACE::pair<int, int>(478, 478));
		map.insert(TESTED_NAMESPACE::pair<int, int>(389, 389));
		map.insert(TESTED_NAMESPACE::pair<int, int>(443, 443));
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map.begin(); it != map.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		TESTED_NAMESPACE::map<int, int> map2(map);
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		TESTED_NAMESPACE::map<int, int> map3(map2.begin(), map2.end());
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map3.begin(); it != map3.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		TESTED_NAMESPACE::map<int, int> map4(map3.begin(), map3.end(), map3.key_comp());
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map4.begin(); it != map4.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		TESTED_NAMESPACE::map<int, int> map5(map4.begin(), map4.end(), map4.key_comp(), map4.get_allocator());
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map5.begin(); it != map5.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		TESTED_NAMESPACE::map<int, int> map6(map5.begin(), map5.end(), map5.key_comp(), map5.get_allocator());
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map6.begin(); it != map6.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;

		CCOUT(UMAG, "                                         CLEAR\n");

		COUT("size: " << map6.size());
		map6.clear();
		COUT("size: " << map6.size());
		COUT("empty: " << map.empty());
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map6.begin(); it != map6.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		
		CCOUT(UMAG, "                                         OPERATOR\n");

		map6 = map;
		COUT("size: " << map6.size());
		COUT("size: " << map6.size());
		COUT("empty: " << map.empty());
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map6.begin(); it != map6.end(); it++)
			std::cout << it->first << " " << it->second << std::endl;
		COUT(map6[42]);
		COUT(map6[-30]);
		COUT(map6[478]);
		map6[478] = 42;
		
		CCOUT(UMAG, "                                         ITERATORS\n");
		
		for (TESTED_NAMESPACE::map<int, int>::iterator it = map6.begin(); it != map6.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT("reverse iterator");
		for (TESTED_NAMESPACE::map<int, int>::reverse_iterator it = map6.rbegin(); it != map6.rend(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
		COUT("const it + decrement"); //!becareful this test can take things in memory so its normal that output is not the same
		// for (TESTED_NAMESPACE::map<int, int>::const_iterator it = map6.end(); it != map6.begin(); --it)
		// 	std::cout << it->first << " " << it->second << std::endl;
		
		TESTED_NAMESPACE::map<int, int>::const_iterator it_decrement = map6.end();
		--it_decrement;
		for (; it_decrement != map6.begin(); --it_decrement)
			std::cout << it_decrement->first << " " << it_decrement->second << std::endl;
		
	}
}

