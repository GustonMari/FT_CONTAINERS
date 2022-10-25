/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:01:01 by gmary             #+#    #+#             */
/*   Updated: 2022/10/25 16:46:50 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Compares the elements in the range [first1,last1) with those in the range beginning at first2,
	and returns true if all of the elements in both ranges match.
	
	maniere astucieuse d'ecrire la boucle for: 
	for (; __first1 != __last1; ++__first1, (void)++__first2)
		if (!bool(__binary_pred(*__first1, *__first2)))
			return false;

	pred: It is a binary function that accepts two elements as arguments
	and performs the task designed by the function.
*/


#ifndef EQUAL_HPP
# define EQUAL_HPP

#include <algorithm>

namespace ft
{
	//TODO : implement equal other eqaul ? ask mathias
	//TODO : neeed to implement other func
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	// template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	// bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	// {
	// 	while (first1 != last1)
	// 	{
	// 		if (!pred(*first1, *first2))
	// 			return false;
	// 		++first1;
	// 		++first2;
	// 	}
	// 	return true;
	// }

	//template 
}


#endif