/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 11:33:21 by gmary             #+#    #+#             */
/*   Updated: 2022/11/02 17:25:11 by gmary            ###   ########.fr       */
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
#ifndef TESTED_NAMESPACE
# define TESTED_NAMESPACE ft
#endif

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

using namespace TESTED_NAMESPACE;

// using namespace NAMESPACE;
int main() {
	RedBlackTree<int, int, std::allocator<std::pair<int, int> > > bst;
	(void)bst;
	bst.insert(10);
	bst.insert(6);
	bst.insert(14);
	bst.insert(4);
	// // bst.insert(8);
	bst.insert(12);
	bst.insert(16);
	bst.insert(3);
	bst.insert(5);
	bst.insert(7);
	bst.insert(9);
	bst.insert(11);
	bst.insert(13);
	bst.insert(15);
	bst.insert(17);
	bst.insert(18);
	bst.insert(19);
	bst.insert(20);
	bst.insert(8);
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(75);
	bst.insert(57);

	// bst.printTree();
	bst.deleteNode(8);
	bst.deleteNode(7);
	bst.deleteNode(16);
	bst.printTree();
	// std::cout << std::endl
	// 	<< "After deleting" << std::endl;
	// bst.deleteNode(40);
	// bst.printTree();
}