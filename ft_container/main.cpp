/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/27 14:16:58 by gmary            ###   ########.fr       */
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
#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

using namespace TESTED_NAMESPACE;

// using namespace NAMESPACE;

int main()
{
	stack<float>								other_stack;
	vector<std::string>							lst;

	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

	stack<std::string, vector<std::string> >	my_stack(lst);
	std::cout << std::boolalpha << other_stack.empty() << std::endl;
	COUT("fjkdhkjfdh")
	other_stack.push(8.5); // 8.5;
	other_stack.push(42.4242); // 8.5; 42.4242;
	std::cout << other_stack.size() << '\n'; // 2
	other_stack.pop(); // 8.5;
	std::cout << other_stack.size() << '\n'; // 1
	other_stack.push(78541.987); // 8.5; 78541.987;
	std::cout << other_stack.size() << '\n'; // 2
	std::cout << other_stack.top() << '\n'; //78541.987
	std::cout << std::boolalpha << other_stack.empty() << std::endl;

	const std::string const_top = my_stack.top();

	std::cout << "const top: " << const_top << '\n';

	while (!my_stack.empty())
	{
		std::cout << my_stack.top() << '\n';
		my_stack.pop();
	}

	return (0);
}
