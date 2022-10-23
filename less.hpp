/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 22:38:38 by gmary             #+#    #+#             */
/*   Updated: 2022/10/23 22:48:59 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LESS_HPP
# define LESS_HPP

/*
It is defined as a function object class for less than inequality comparison which returns a boolean value depending upon the condition.
This can be used to change the functionality of the given function
*/

//TODO: WTFFFFF is this shit ??

namespace ft
{
	template <class T> struct less {

	// Declaration of the less operation
		bool operator() (const T& x, const T& y) const
		{
			return x  < y;
		}
	
		// Type of first parameter
		typedef T first_argument_type;
	
		// Type of second parameter
		typedef T second_argument_type;
	
		// The result is returned
		// as bool type
		typedef bool result_type;
	};
}

#endif