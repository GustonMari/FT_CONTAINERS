/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/20 13:09:03 by gmary            ###   ########.fr       */
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
	yes.push_back(2);
	yes.push_back(3);
	std::vector<int>::iterator it = yes.begin();
	it++;
	yes.insert(it, 9999);
	for (std::vector<int>::iterator ito = yes.begin(); ito != yes.end(); ito++)
		std::cout << *ito << std::endl;
	return (0);
}