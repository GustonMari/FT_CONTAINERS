/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:24:54 by gmary             #+#    #+#             */
/*   Updated: 2022/11/28 14:17:59 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
	the function is used in stl stack !!!!!
	shift ] => deplacement directement fin debut de la function
	Compare) which returns ​true if the first argument is less than the second:
	bool cmp(const Type1 &a, const Type2 &b);
	
*/

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	//* is needed for < operators
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first1 < *first2)
				return true;
			else if (*first2 < *first1)
				return false;
			++first1;
			++first2;
		}
		return ((first1 == last1) && first2!=last2);
	}
}

#endif