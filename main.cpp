/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/19 13:48:22 by gmary            ###   ########.fr       */
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
	std::vector<int> yes;
	yes.push_back(1);
	COUT(yes[0])
	
	
	CCOUT(BRED, "========== data test =================")
	std::vector<int> tab;
	ft::vector<int> test;
	std::vector<int> tab2;
	ft::vector<int> test2;

	COUT("empty data test")
	CCOUT(BRED, tab.data())
	CCOUT(BGRN, test.data())
	COUT("empty data test")
	CCOUT(BRED, tab2.data())
	CCOUT(BGRN, test2.data())
	return (0);
}