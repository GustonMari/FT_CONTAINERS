/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:08 by gmary             #+#    #+#             */
/*   Updated: 2022/06/23 14:23:01 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
typedef typename : You are not actually creating a new data type,
 but rather defining a new name for an existing type.

  L'allocateur par défaut est sans état, c'est-à-dire que toutes les instances de l'allocateur donné sont interchangeables,
   comparables et peuvent libérer de la mémoire allouée par toute autre instance du même type d'allocateur.
	explicit: Vous ne pouvez affecter que des valeurs qui correspondent aux valeurs du type de classe. docn pas de conv dans dautres types
	
	description de l'imbrication de base dans vector
	https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_vector.h.html#std::vector::_Base
	https://stackoverflow.com/questions/31358804/whats-the-advantage-of-using-stdallocator-instead-of-new-in-c
*/

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <vector>
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "vector_base.hpp"

template <typename Tp, typename Allocator = std::allocator<Tp> >
class vector: protected vector_base<Tp, Allocator>
{
	public:
		typedef Tp												value_type;
		typedef	Allocator										allocator_type;
		typedef value_type&										reference;
		//typedef std::__1::allocator_traits<Allocator>			alloc_traits; //BUG que faire ??
		typedef const value_type&								const_reference;
		typedef size_t											size_type;
		typedef ptrdiff_t										difference_type;
		typedef Tp*												iterator;
		typedef const Tp* 										const_iterator; // pas sur dutous
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename Allocator::pointer						pointer; //aka Tp*
		
		//!------------------------------CONSTRUCTOR----------------------------------

		explicit vector (const allocator_type & alloc = allocator_type()): vector_base<Tp, Allocator>(alloc)
		{
			
		};
		
		explicit vector (size_type n, const value_type & val = value_type()): vector_base<Tp, Allocator>(n, val)
		{
			
		};
		
		//template <class InputIterator>
		//vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type());
		vector (const vector & x): vector_base<Tp, Allocator>(x.size())
		{
			//TODO: ligne 458
		};

		//!------------------------------DESTRUCTOR-----------------------------------
		//!------------------------------OPERATOR-------------------------------------
		//!------------------------------FUNCTION-------------------------------------
	private:
};

#endif