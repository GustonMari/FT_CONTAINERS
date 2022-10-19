/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/19 16:14:50 by gmary            ###   ########.fr       */
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
	std::vector<std::string> yes;
	yes.reserve(20);
	COUT("|"<< yes.size() << "|")
	CCOUT(BRED, "--------------------")
	ft::vector<int> no;
	no.reserve(20);
	COUT("|"<< no.size() << "|")
	return (0);
}