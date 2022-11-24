/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:22:04 by gmary             #+#    #+#             */
/*   Updated: 2022/11/24 17:56:26 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//TODO: maybe delete all std include for evaluation ?
# include <iostream>
# include <vector>
# include <map>
# include <list>
# include <iterator>
# include <string>
# include <set>
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
# include "rbt.hpp"
# include "pair.hpp"
# include "set.hpp"

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

using namespace TESTED_NAMESPACE;


int		main(void)
{
	TESTED_NAMESPACE::vector<int> test_one;
	std::cout << BBLU << "14) RESERVE" << CRESET << std::endl;

		for (int i = 0; i < 100; i++)
		{
			std::cout << "Capacity before = " << test_one.capacity() << std::endl;
			test_one.push_back(i);
			std::cout << "Capacity after = " << test_one.capacity() << std::endl;
		}
		std::cout << "-------" << std::endl;
		test_one.clear();
		TESTED_NAMESPACE::vector<int> test_two;

		test_two.reserve(50);
		for (int i = 0; i < 100; i++)
		{
			std::cout << "Capacity before = " << test_two.capacity() << std::endl;
			test_two.push_back(i);
			std::cout << "Capacity after = " << test_two.capacity() << std::endl;
		}
		test_two.clear();
	return (0);
}