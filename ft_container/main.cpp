/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/11/23 15:57:45 by gmary            ###   ########.fr       */
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
	CCOUT(UMAG, "NO ARGS = ALL\n0 - VECTOR\n1 - SET\n2 - MAP\n3 - STACK\n4 - PAIR\n");
	std::string arg;
	if (ac == 2)
		arg = av[1];
	else
		arg = "all";

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
		// myvector3.erase(myvector3.begin(), myvector3.end());
		// for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
		// 	std::cout << *it << std::endl;
		// COUT("erase --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());

		// CCOUT(UMAG, "                                         SWAP\n");
		
		// myvector3.push_back(42);
		// myvector3.push_back(42);
		// myvector3.push_back(42);
		// myvector.push_back(12);
		// myvector.push_back(12);
		
		// myvector.swap(myvector3);
		// for (TESTED_NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
		// 	std::cout << *it << std::endl;
		// COUT("swap --- size: " << myvector.size() << " capacity: " << myvector.capacity());
		
		// for (TESTED_NAMESPACE::vector<int>::iterator it = myvector3.begin(); it != myvector3.end(); it++)
		// 	std::cout << *it << std::endl;
		// COUT("swap --- size: " << myvector3.size() << " capacity: " << myvector3.capacity());

	}
}