/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/10/25 11:42:50 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: maybe delete all std include for evaluation ?
# include <iostream>
# include <vector>
# include <map>
# include <list>
# include <iterator>
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

#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#define TESTED_TYPE int




int main()
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);


	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	// printSize(vct);
	return (0);
}