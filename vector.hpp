/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:08 by gmary             #+#    #+#             */
/*   Updated: 2022/06/22 13:08:25 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef typename : You are not actually creating a new data type,
 but rather defining a new name for an existing type.

  L'allocateur par défaut est sans état, c'est-à-dire que toutes les instances de l'allocateur donné sont interchangeables,
   comparables et peuvent libérer de la mémoire allouée par toute autre instance du même type d'allocateur.
*/

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <vector>
# include "iterator_traits.hpp"
# include "reverse_itertor.hpp"

template <typename Tp, typename Allocator = std::allocator<Tp>>
class vector
{
	public:
		typedef Tp												value_type;
		typedef	Allocator										allocator_type;
		typedef value_type&										reference;
		typedef std::__1::allocator_traits<Allocator>			alloc_traits;
		typedef const value_type&								const_reference;
		typedef size_t											size_type;
		typedef ptrdiff_t										difference_type;
		typedef Tp*												iterator;
		typedef const Tp* 										const_iterator; // pas sur dutous
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename Allocator::pointer						pointer; //aka Tp*
		
		//!------------------------------CONSTRUCTOR----------------------------------
		//!------------------------------DESTRUCTOR-----------------------------------
		//!------------------------------OPERATOR-------------------------------------
		//!------------------------------FUNCTION-------------------------------------
	private:
};

#endif