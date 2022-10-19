/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:08 by gmary             #+#    #+#             */
/*   Updated: 2022/10/19 18:12:17 by gmary            ###   ########.fr       */
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

namespace ft {

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
			
			// !------------------------------CONSTRUCTOR----------------------------------

			explicit vector (const allocator_type & alloc = allocator_type()): vector_base<Tp, Allocator>(alloc)
			{
				
			};
			
			explicit vector (size_type n, const value_type & val = value_type()): vector_base<Tp, Allocator>(n, val)
			{
				
			};
			// TODO integrer le constructor en dessous 
			// template <class InputIterator>
			// vector (InputIterator first, InputIterator last, const allocator_type & alloc = allocator_type())
			// {
				
			// }
			
			vector (const vector & x): vector_base<Tp, Allocator>(x.size())
			{
				//TODO: ligne 458
			};

			//!------------------------------DESTRUCTOR-----------------------------------
			
			~vector()
			{
				//TODO:DESTROY EVERYTHING ??
				// ft::vector_base<Tp, Allocator>::~vector_base(); //pas sur dutous
			};
			//!------------------------------OPERATOR-------------------------------------
			
			vector & operator= (const vector & x)
			{
				if (this != &x)
				{
					ft::vector_base<Tp, Allocator>::operator=(x);
					
				}
			}

			reference operator[] (size_type n)
			{
				//TODO: QUE FAIR POUR N < 0 ??
				/*
		*This operator allows for easy, array-style, data access.
       *  Note that data access with this operator is unchecked and
       *  out_of_range lookups are not defined. (For checked lookups
       *  see at().)
				*/
			// if (n < 0 || n > this->m_size)
			// 	return (this->m_start[0]);
				//if (n >= this->m_size) //surement faux par consequent
				//	throw std::out_of_range("vector_base::operator[]: out of range");
			return (this->m_start[n]);
			}

			const_reference operator[] (size_type n) const
			{
				//TODO: QUE FAIR POUR N < 0 ??
				/*
		*This operator allows for easy, array-style, data access.
       *  Note that data access with this operator is unchecked and
       *  out_of_range lookups are not defined. (For checked lookups
       *  see at().)
				*/
				
				//if (n >= this->m_size) //surement faux par consequent
				//	throw std::out_of_range("vector_base::operator[]: out of range");
				return (this->m_start[n]);
			}
			

			// !------------------------------FUNCTION-------------------------------------

			void	reserve(size_type n)
			{
				//TODO: QUE FAIR POUR N < 0 ??
				if (n < this->m_capacity)
					return ;
				if (n > this->m_alloc::max_size())
				{
					throw std::length_error("vector_base::reserve: max_size exceeded"); //TODO check message
				}
				ft::vector_base<Tp, Allocator>::reserve(n);
			}
			

			void	resize(size_type n, value_type val = value_type())
			{
				if (n > this->m_size)
				{
					if (n >= this->m_capacity)
						reserve(n);
					for (size_type i = this->m_size; i < n; i++)
						m_alloc.construct(this->m_begin + i, val);
				}
				else if (n < this->m_size)
				{
					for (size_type i = n; i < this->m_size; i++)
						m_alloc.destroy(this->m_begin + i);
				}
				this->m_size = n;
			}
			//TODO: need to do assign function

			Allocator get_allocator() const
			{
				return (this->m_alloc);
			}

			iterator begin()
			{
				return (this->m_start);
			}
			
			iterator end()
			{
				return (this->m_start + this->m_size);
			}

			const_iterator begin() const
			{
				return (this->m_start);
			}

			const_iterator end() const
			{
				return (this->m_start + this->m_size);
			}

			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->m_start + this->m_size));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(this->m_start));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->m_start + this->m_size));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->m_start));
			}
			
			size_type size() const
			{
				return (this->m_size);
			}

			bool empty() const
			{
				return (this->m_size == 0);
			}
			
			size_type capacity() const
			{
				return (this->m_capacity);
			}
			
			size_type	max_size() const
			{
				return (this->m_alloc::max_size());
			}

			reference at(size_type n)
			{
				// if (n < 0)
				// 	throw std::out_of_range("vector_base::at: out of range");
				if (n >= size())
					throw std::out_of_range("vector_base::at: out of range");
				return (this->m_start[n]);
			}

			const_reference at(size_type n) const
			{
				// if (n < 0)
				// 	throw std::out_of_range("vector_base::at: out of range");
				if (n >= size())
					throw std::out_of_range("vector_base::at: out of range");
				return (this->m_start[n]);
			}

			reference front()
			{
				return (this->m_start[0]);
			}
			
			const_reference front() const
			{
				return (this->m_start[0]);
			}
			
			reference back()
			{
				return (this->m_start[this->m_size - 1]);
			}

			const_reference back() const
			{
				return (this->m_start[this->m_size - 1]);
			}

			void	push_back(const value_type & x)
			{
				if (this->m_size >= this->m_capacity)
				{
					if (m_capacity == 0)
						reserve(1);
					else
						this->reserve(this->m_capacity * 2);
				}
				this->m_alloc.construct(this->m_start[this->m_size], x);
				// this->m_start[this->m_size] = x;
				this->m_size++;
			}
			
			void	pop_back()
			{
				this->m_alloc.destroy(this->m_start + this->m_size - 1);
				this->m_size--;
			}

			void	swap(vector<Tp> & x)
			{
				ft::real_swap(this->m_start, x.m_start);
				ft::real_swap(this->m_size, x.m_size);
				ft::real_swap(this->m_capacity, x.m_capacity);
			}

		private:

		template <class T> 
		void swap ( T& a, T& b )
		{
			T	c(a);
			a = b;
			b = c;
		}
	};
}

#endif