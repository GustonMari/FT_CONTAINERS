/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/11/07 14:11:29 by gmary            ###   ########.fr       */
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
	ft::map<int, int> m;

	m.insert(ft::pair<int, int>(1, 1));
	// m.insert(ft::pair<int, int>(8, 8));
	// m.insert(ft::pair<int, int>(10, 10));
	// m.insert(ft::pair<int, int>(12, 12));
	// m.insert(ft::pair<int, int>(14, 14));
	// m.insert(ft::pair<int, int>(6, 6));

	ft::map<int, int>::iterator it = m.begin();
	// std::cout << *it << std::endl;
	// std::cout << it->first << std::endl;
	m.print_tree();
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