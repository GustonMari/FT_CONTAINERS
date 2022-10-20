/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_base.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:11:59 by gmary             #+#    #+#             */
/*   Updated: 2022/10/20 10:20:24 by gmary            ###   ########.fr       */
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

namespace ft {

	template <typename Tp, typename Allocator>
	class vector_base
	{
		public:
			typedef Tp*			iterator;
			typedef Tp*			pointer;
			typedef Allocator	alloc_type;
			typedef size_t		size_type;
			typedef Tp			value_type;
		protected:
			alloc_type			m_alloc; //object allocate
			size_type			m_capacity; //the capacity of object in th e vector
			pointer				m_start; //pointer on the first element of the vector
			size_type			m_size; //number of object
			
			//!----------------------------CONSTRUCTOR-------------------------------------
			
			//TODO: il y a bcp de constructor faut-il tous les faire ??
		public:
			
			//vector_base(const alloc_type & alloc = alloc_type()): m_alloc(alloc), m_capacity(0), m_start(std::nullptr_t), m_size(0)
			//BUG pq std::nullptr_t ne marche pas ??
			vector_base(const alloc_type & alloc = alloc_type()): m_alloc(alloc), m_capacity(0), m_start(NULL), m_size(0)
			{
				//? ici on initialise le vecteur et par deffaut on utilise Allocator appartenant au template
			}
			
			vector_base(size_t n, const value_type & val, const alloc_type & alloc = alloc_type()):
			m_alloc(alloc), m_capacity(n), m_start(m_alloc.allocate(n)), m_size(n)
			{
				for (size_type i = 0; i < n; i++)
					m_alloc.construct(m_start + i, val);
				//TODO: need to continue this constructor to add the value to the vector
				//? ici on initialise le vecteur et par deffaut on utilise Allocator appartenant au template
			}
			
			vector_base(size_t n): m_alloc(alloc_type()), m_capacity(n), m_start(m_alloc.allocate(n)), m_size(n)
			{
				//?????????? dois je  continuer
			}

			
			//!----------------------------DESTRUCTOR-------------------------------------

			~vector_base()
			{
				destroy_vector();
			}

			//!----------------------------FUNCTION-------------------------------------
			size_type	size() const { return m_size; }

			void	reserve(size_type n)
			{
				pointer tmp = m_alloc.allocate(n);
				for (size_type i = 0; i < m_size; i++)
					m_alloc.construct(tmp + i, m_start[i]);
				m_alloc.deallocate(m_start, m_capacity);
				m_start = tmp;
				m_capacity = n;
			}
			


			void	resize(size_type count)
			{
				(void)count;
				//if (count > m_size)
				//	//TODO: neeD TO CONTINUE
			}

			void	realloc(size_type count) //TODO not sure for realloc
			{
				destroy_vector();
				pointer tmp = m_alloc.allocate(count);
				for (size_type i = 0; i < m_size; i++)
					m_alloc.construct(tmp + i, m_start[i]);
				m_start = tmp;
				m_capacity = count;
				m_size = count;
			}

			void	realloc_arg(size_type count, const value_type & val)
			{
				destroy_vector();
				pointer tmp = m_alloc.allocate(count);
				for (size_type i = 0; i < m_size; i++)
					m_alloc.construct(tmp + i, val);
				m_start = tmp;
				m_capacity = count;
				m_size = count;
			}

			//void	add_back
		//!----------------------------OPERATOR-------------------------------------
	
		vector_base & operator=(const vector_base & rhs)
		{
			if (this != rhs)
			{
				destroy_vector();
				m_capacity = rhs.m_capacity;
				m_start = m_alloc.allocate(m_capacity);
				m_size = rhs.m_size;
				for (size_type i = 0; i < m_size; i++)
					m_alloc.construct(m_start + i, rhs.m_start[i]);
			}
		}
		
		private:
		
			void	destroy_vector()
			{
				if (m_capacity)
				{
					for (size_type i = 0; i < m_size; i++)
						m_alloc.destroy(m_start + i);
					m_alloc.deallocate(m_start, m_capacity);
				}
			}
	};
	
	template<typename Tp, typename Allocator>
	bool operator==(const vector_base<Tp, Allocator> & lhs, const vector_base<Tp, Allocator> & rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template<typename Tp, typename Allocator>
	bool operator!=(const vector_base<Tp, Allocator> & lhs, const vector_base<Tp, Allocator> & rhs)
	{
		return !(lhs == rhs);
	}

}



#endif