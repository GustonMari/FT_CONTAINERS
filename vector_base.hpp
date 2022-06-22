/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_base.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:11:59 by gmary             #+#    #+#             */
/*   Updated: 2022/06/22 17:32:52 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
	https://www.systutorials.com/docs/linux/man/3-std%3A%3A_Vector_base/
	1)allocate
		Le stockage est aligné de manière appropriée pour les objets de type value_type ,
		 mais ils ne sont pas construits. Dans l' allocateur
		par défaut standard ,
		 le bloc de stockage est alloué à l'aide de ::operator new une ou plusieurs fois,
		  et lève bad_alloc s'il ne peut pas allouer la quantité totale de stockage demandée.
	2)construct:
		Constructs an object of type T in allocated uninitialized storage pointed to by p, using placement-new
		a) Calls new((void *)p) T(val)
		b) Calls ::new((void *)p) U(std::forward<Args>(args)...)
	3)destruct
	4)deallocates
*/

#ifndef VECTOR_BASE_HPP
# define VECTOR_BASE_HPP

template <typename Tp, typename Allocator>
class vector_base
{
	std::vector<int> salut;
	public:
		typedef Tp*			iterator;
		typedef Tp*			pointer;
		typedef Allocator	alloc_type;
		typedef size_t		size_type;

	private:
		alloc_type			m_alloc; //object allocate
		size_type			m_capacity; //the capacity of object in th e vector
		pointer				m_start; //pointer on the first element of the vector
		size_type			m_size; //number of object
		
		//!----------------------------CONSTRUCTOR-------------------------------------
		
		vector_base(const alloc_type & alloc = alloc_type()): m_alloc(alloc), m_capacity(0), m_start(nullptr), m_size(0)
		{
			//? ici on initialise le vecteur et par deffaut on utilise Allocator appartenant au template
		}
		
		vector_base(size_t n, const value_type & val, const alloc_type & alloc = alloc_type()):
		 m_alloc(alloc), m_capacity(n), m_start(m_alloc.allocate(n)), m_size(n)
		{
			//TODO: need to continue this constructor to add the value to the vector
			//? ici on initialise le vecteur et par deffaut on utilise Allocator appartenant au template
		}

		//!----------------------------DESTRUCTOR-------------------------------------
		//!----------------------------FUNCTION-------------------------------------
};

		//!----------------------------OPERATOR-------------------------------------
//TODO FAIRE == ET !=

#endif