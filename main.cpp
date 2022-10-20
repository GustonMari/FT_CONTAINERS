/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/20 14:47:00 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "enable_if.hpp"
#include "vector_base.hpp"
#include "vector.hpp"
#include "equal.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "pair.hpp"
#include "utils.hpp"
#include "_colors.hpp"

int main()
{
	CCOUT(UMAG, "-----------erase + pushback ----------")
	ft::vector<int> yes;
	yes.push_back(1);
	yes.push_back(2);
	yes.push_back(3);
	ft::vector<int>::iterator it = yes.begin();
	it++;
	yes.erase(yes.begin(), it);
	// yes.insert(it, 9999);
	for (ft::vector<int>::iterator ito = yes.begin(); ito != yes.end(); ito++)
		CCOUT(BGRN, *ito)

	std::vector<int> yes2;
	yes2.push_back(1);
	yes2.push_back(2);
	yes2.push_back(3);
	std::vector<int>::iterator itu = yes2.begin();
	itu++;
	yes2.erase(yes2.begin(), itu);
	// yes.insert(it, 9999);
	for (std::vector<int>::iterator ita = yes2.begin(); ita != yes2.end(); ita++)
		CCOUT(BRED, *ita)

	CCOUT(UMAG, "----------- insert(iterator position, const value_type & x) ----------")
	ft::vector<int> test3;
	test3.push_back(1);
	test3.push_back(2);
	test3.push_back(3);
	ft::vector<int>::iterator it3 = test3.begin();
	//it3++;
	test3.insert(it3, 9999);
	CCOUT(BHYEL, "insert begin")
	for (ft::vector<int>::iterator ito = test3.begin(); ito != test3.end(); ito++)
		CCOUT(BGRN, *ito)
	
	// CCOUT(BHYEL, "insert middle")
	// ft::vector<int>::iterator it3 = test3.begin();
	// it3++;
	// test3.insert(it3, 22222);
	// for (ft::vector<int>::iterator ito = test3.begin(); ito != test3.end(); ito++)
	// 	CCOUT(BGRN, *ito)
	
	CCOUT(BHYEL, "insert end")
	it3 = test3.end();
	test3.insert(it3, 77777);
	for (ft::vector<int>::iterator ito = test3.begin(); ito != test3.end(); ito++)
		CCOUT(BGRN, *ito)
	return (0);
}