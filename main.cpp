/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/21 14:53:40 by gmary            ###   ########.fr       */
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
	// CCOUT(UMAG, "-----------erase + pushback ----------")
	// ft::vector<int> yes;
	// yes.push_back(1);
	// yes.push_back(2);
	// yes.push_back(3);
	// ft::vector<int>::iterator it = yes.begin();
	// it++;
	// yes.erase(yes.begin(), it);
	// // yes.insert(it, 9999);
	// for (ft::vector<int>::iterator ito = yes.begin(); ito != yes.end(); ito++)
	// 	CCOUT(BGRN, *ito)

	// std::vector<int> yes2;
	// yes2.push_back(1);
	// yes2.push_back(2);
	// yes2.push_back(3);
	// std::vector<int>::iterator itu = yes2.begin();
	// itu++;
	// yes2.erase(yes2.begin(), itu);
	// // yes.insert(it, 9999);
	// for (std::vector<int>::iterator ita = yes2.begin(); ita != yes2.end(); ita++)
	// 	CCOUT(BRED, *ita)

	// CCOUT(UMAG, "----------- insert(iterator position, const value_type & x) ----------")
	// ft::vector<int> test3;
	// test3.push_back(1);
	// test3.push_back(2);
	// test3.push_back(3);
	// ft::vector<int>::iterator it3 = test3.begin();
	// // it3++;
	// test3.insert(it3, 9999);
	// CCOUT(BHYEL, "insert begin")
	// for (ft::vector<int>::iterator ito = test3.begin(); ito != test3.end(); ito++)
	// 	CCOUT(BGRN, *ito)
	
	// CCOUT(BHYEL, "insert middle")
	// ft::vector<int>::iterator it_middle = test3.begin();
	// it_middle++;
	// test3.insert(it_middle, 22222);
	// for (ft::vector<int>::iterator ita = test3.begin(); ita != test3.end(); ita++)
	// 	CCOUT(BGRN, *ita)
	// test3.insert(it_middle, 22222);
	// for (ft::vector<int>::iterator ita = test3.begin(); ita != test3.end(); ita++)
	// 	CCOUT(BGRN, *ita)
	// test3.insert(it_middle, 22222);
	// for (ft::vector<int>::iterator ita = test3.begin(); ita != test3.end(); ita++)
	// 	CCOUT(BGRN, *ita)

	// CCOUT(BHYEL, "insert end")
	// it3 = test3.end();
	// test3.insert(it3, 77777);
	// for (ft::vector<int>::iterator ito = test3.begin(); ito != test3.end(); ito++)
	// 	CCOUT(BGRN, *ito)
	
	// //!-------------------------------------------------------------------------
	
	// std::vector<int> test33;
	// test33.push_back(1);
	// test33.push_back(2);
	// test33.push_back(3);
	// std::vector<int>::iterator it33 = test33.begin();
	// //it33++;
	// test33.insert(it33, 9999);
	// CCOUT(BHYEL, "insert begin")
	// for (std::vector<int>::iterator ito = test33.begin(); ito != test33.end(); ito++)
		// CCOUT(BRED, *ito)
	
	// CCOUT(BHYEL, "insert middle")
	// std::vector<int>::iterator it33 = test33.begin();

	// it33++;
	// test33.insert(it33, 22222);
	// for (std::vector<int>::iterator ito = test33.begin(); ito != test33.end(); ito++)
	// 	CCOUT(BRED, *ito)
	// // test33.insert(it33, 22222);
	// // for (std::vector<int>::iterator ito = test33.begin(); ito != test33.end(); ito++)
	// // 	CCOUT(BRED, *ito)
	// // test33.insert(it33, 22222);
	// // for (std::vector<int>::iterator ito = test33.begin(); ito != test33.end(); ito++)
	// // 	CCOUT(BRED, *ito)
	
	// CCOUT(BHYEL, "insert end")
	// it33 = test33.end();
	// test33.insert(it33, 77777);
	// for (std::vector<int>::iterator ito = test33.begin(); ito != test33.end(); ito++)
	// 	CCOUT(BRED, *ito)

	// CCOUT(UMAG, "----------- insert (iterator position, size_type n, const value_type& val) ----------")
	// ft::vector<int> n_test;
	// n_test.push_back(1);
	// n_test.push_back(2);
	// n_test.push_back(3);
	// ft::vector<int>::iterator it_n = n_test.begin();
	// // it_n++;
	// n_test.insert(it_n, 3, 9999);
	// CCOUT(BHYEL, "insert begin multiple")
	// for (ft::vector<int>::iterator ito = n_test.begin(); ito != n_test.end(); ito++)
	// 	CCOUT(BGRN, *ito)

	// ft::vector<int>::iterator it_n3 = n_test.begin();
	// it_n3++;
	// n_test.insert(it_n3, 3, 44444);
	// CCOUT(BHYEL, "insert middle multiple")
	// for (ft::vector<int>::iterator ito = n_test.begin(); ito != n_test.end(); ito++)
	// 	CCOUT(BGRN, *ito)


	// ft::vector<int>::iterator it_n2 = n_test.end();
	// //it_n2++;
	// n_test.insert(it_n2, 3, 1111111);
	// CCOUT(BHYEL, "insert end multiple")
	// for (ft::vector<int>::iterator ito = n_test.begin(); ito != n_test.end(); ito++)
	// 	CCOUT(BGRN, *ito)
	
	// //!-------------------------------------------------------------------------

	// std::vector<int> n_test;
	// n_test.push_back(1);
	// n_test.push_back(2);
	// n_test.push_back(3);
	// ft::vector<int>::iterator it_n = n_test.begin();
	// // it_n++;
	// n_test.insert(it_n, 3, 9999);
	// CCOUT(BHYEL, "insert begin multiple")
	// for (ft::vector<int>::iterator ito = n_test.begin(); ito != n_test.end(); ito++)
	// 	CCOUT(BRED, *ito)

	// std::vector<int>::iterator it_n3 = n_test.begin();
	// it_n3++;
	// n_test.insert(it_n3, 3, 44444);
	// CCOUT(BHYEL, "insert middle multiple")
	// for (std::vector<int>::iterator ito = n_test.begin(); ito != n_test.end(); ito++)
	// 	CCOUT(BRED, *ito)


	// ft::vector<int>::iterator it_n2 = n_test.end();
	// //it_n2++;
	// n_test.insert(it_n2, 3, 1111111);
	// CCOUT(BHYEL, "insert end multiple")
	// for (ft::vector<int>::iterator ito = n_test.begin(); ito != n_test.end(); ito++)
	// 	CCOUT(BRED, *ito)


	CCOUT(UMAG, "----------- insert (iterator position, size_type n, const value_type& val) ----------")
	ft::vector<int> range_insert;
	range_insert.push_back(1);
	range_insert.push_back(2);
	range_insert.push_back(3);
	ft::vector<int> to_insert;
	to_insert.push_back(9999);
	to_insert.push_back(8);
	to_insert.push_back(10);
	to_insert.push_back(11);
	ft::vector<int>::iterator	it_range = range_insert.begin();
	ft::vector<int>::iterator	it_first = to_insert.begin();
	ft::vector<int>::iterator	it_last = to_insert.end();
	range_insert.insert(it_range, it_first, it_last);
	P_TABC(BGRN, range_insert)
	
	// for (ft::vector<int>::iterator ito = range_insert.begin(); ito != range_insert.end() ; ito++)
	// 	CCOUT(BGRN, *ito)
	

	return (0);
}