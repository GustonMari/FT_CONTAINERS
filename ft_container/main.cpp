/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/11/14 13:56:03 by gmary            ###   ########.fr       */
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

// using namespace NAMESPACE;
int main() {
	TESTED_NAMESPACE::map<int, int> m;

	m.insert(TESTED_NAMESPACE::pair<int, int>(18, 1));
	m.insert(TESTED_NAMESPACE::pair<int, int>(8, 8));
	m.insert(TESTED_NAMESPACE::pair<int, int>(10, 10));
	m.insert(TESTED_NAMESPACE::pair<int, int>(12, 12));
	m.insert(TESTED_NAMESPACE::pair<int, int>(14, 14));
	m.insert(TESTED_NAMESPACE::pair<int, int>(6, 6));

	// m.erase(m.begin());
	CCOUT(BRED, m[1587])
	// if (ito == m.end())
	// 	std::cout << "not found" << std::endl;
	// else
	// 	std::cout << "found" << std::endl;

	// for (ft::map<int, int>::iterator it = m.begin(); it != ito; it++)
	// 	std::cout << it->first << " " << it->second << std::endl;
	// ft::map<int, int>::iterator it = m.find(8);

	// std::cout << it->first << " -- " << it->second << std::endl;
	// CCOUT(BGRN, "find =" << m.find(8))

	// m.print_tree();
	// ft::IteratorMap<int, int> it;
	// ft::IteratorMap<int, int> it2;
	
	// it = it2;
	// CCOUT(BYEL, *it << " it2 =  " << *it2);
	// RedBlackTree<ft::pair<int, bool>, less<ft::pair<int, bool> >, std::allocator<std::pair<int, int> > > bst;
	// bst.insert(ft::pair<int, bool>(101, true));
	// bst.insert(ft::pair<int, bool>(102, true));
	// bst.insert(ft::pair<int, bool>(103, true));
	// bst.insert(ft::pair<int, bool>(104, true));
	// bst.insert(ft::pair<int, bool>(105, true));
	// bst.insert(ft::pair<int, bool>(106, true));
	// bst.insert(ft::pair<int, bool>(107, true));
	// bst.insert(ft::pair<int, bool>(108, true));
	// bst.insert(ft::pair<int, bool>(109, true));
	// bst.printTree();
	// // std::cout << std::endl
	// // 	<< "After deleting" << std::endl;
	// // bst.deleteNode(40);
	// // bst.printTree();
}