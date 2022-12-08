/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:08 by gmary             #+#    #+#             */
/*   Updated: 2022/12/02 11:51:05 by gmary            ###   ########.fr       */
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
# include <sstream>

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "vector_base.hpp"
# include "utils.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "equal.hpp"
#include <vector>

std::vector<int, malloc> vec;

namespace ft {

	template <typename Tp, typename Allocator = std::allocator<Tp> >
	class vector: protected vector_base<Tp, Allocator>
	{
		public:
			typedef Tp												value_type;
			typedef	Allocator										allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
			typedef Tp*												iterator;
			typedef const Tp* 										const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename Allocator::pointer						pointer;

			// !------------------------------FUNCTION-------------------------------------

			void	reserve(size_type n)
			{
				if (n < this->m_capacity)
					return ;
				if (n > this->m_alloc.max_size())
					throw std::length_error("vector::reserve");
				ft::vector_base<Tp, Allocator>::reserve(n);
			}

			void	resize(size_type n, value_type val = value_type())
			{
				if (n > max_size())
					throw std::length_error("vector::_M_fill_insert");
				if (n > this->m_size)
				{
					if (n >= this->m_size * 2)
						reserve(n);
					else
						reserve(this->m_size * 2);
					for (size_type i = this->m_size; i < n; i++)
						this->m_alloc.construct(this->m_start + i, val);
				}
				else if (n < this->m_size)
				{
					for (size_type i = n; i < this->m_size; i++)
						this->m_alloc.destroy(this->m_start + i);
				}
				this->m_size = n;
			}

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
				return (this->m_alloc.max_size());
			}

			reference at(size_type n)
			{
				std::stringstream str;
				str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->m_size << ")";
				if (n >= size())
					throw std::out_of_range(str.str());
				return (this->m_start[n]);
			}

			const_reference at(size_type n) const
			{
				std::stringstream str;
				str << "vector::_M_range_check: __n (which is " << n << ") >= this->size() (which is " << this->m_size << ")";
				if (n >= size())
					throw std::out_of_range(str.str());
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
					if (this->m_capacity == 0)
						reserve(1);
					else
						this->reserve(this->m_capacity * 2);
				}
				this->m_alloc.construct(&(this->m_start[this->m_size]), x);
				this->m_size++;
			}

			void	pop_back()
			{
				this->m_alloc.destroy(this->m_start + this->m_size - 1);
				this->m_size--;
			}

			void	swap(vector<Tp> & x)
			{
				real_swap(this->m_start, x.m_start);
				real_swap(this->m_size, x.m_size);
				real_swap(this->m_capacity, x.m_capacity);
			}

			//! A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function.
			void	clear()
			{
				for (size_type i = 0; i < this->m_size; i++)
					this->m_alloc.destroy(this->m_start + i);
				this->m_size = 0;
			}

			iterator	erase(iterator pos)
			{
				if (pos == this->end() - 1)
				{
					this->pop_back();
					return (pos);
				}
				this->m_alloc.destroy(pos);
				for (iterator tmp = pos; !(tmp == this->m_start + this->m_size - 1); tmp++)
				{
					//on deference pour avoir la valeur n+1 et on la met dans la case n
					this->m_alloc.construct(tmp, *(tmp + 1));
					this->m_alloc.destroy(tmp + 1);
				}
				this->m_size--;
				// An iterator pointing to the new location of the element that followed the last element erased by the function call.
				return (pos);
			}


			iterator	erase(iterator first, iterator last)
			{
				iterator tmp = first;
				while (tmp != last)
				{
					tmp = this->erase(tmp);
					last--;
				}
				return (first);
			}

			iterator	insert(iterator position, const value_type & x)
			{
				
				ptrdiff_t pos = position - begin();
				//https://c.developpez.com/cours/bernard-cassagne/node44.php
				if (this->m_size >= this->m_capacity)
				{
					if (this->m_capacity == 0)
						reserve(1);
					else
						this->reserve(this->m_capacity * 2);
				}
				iterator it = end();
				for(; it != this->m_start + pos; it--)
				{
					this->m_alloc.construct(it, *(it - 1));
					this->m_alloc.destroy((it - 1));
				}
				this->m_alloc.construct(&(*it), x);
				this->m_size++;
				return (begin() + pos);
			}

			void insert (iterator position, size_type n, const value_type& val)
			{
				if (n == 0)
					return ;
				// ptrdiff_t pos = std::distance(begin(), position);
				ptrdiff_t pos = position - begin();
				if (this->m_size + n >= this->m_capacity)
				{
					if (this->m_capacity * 2 > this->m_size + n)
						this->reserve(this->m_size * 2);
					else
						this->reserve(this->m_size + n);
				}
				for (size_type i = 0; i < n; i++)
				{
					this->insert(begin() + pos + i, val);
				}
			}
			

			template <class InputIterator>
			void insert (iterator position, InputIterator first, ENABLE_IF(InputIterator) last)
			{
				//calculate the position of the iterator
				ptrdiff_t pos = position - begin();
				if (this->m_size + (std::distance(first, last)) >= this->m_capacity)
				{
					if (this->m_capacity * 2 > this->m_size + (std::distance(first, last)))
					{
						// this->reserve(this->m_capacity * 2);
						this->reserve(this->m_size * 2);
					}
					else
					{
						this->reserve(this->m_size + (std::distance(first, last)));
					}
				}
				
				for (int i = 0; last != first; first++)
				{
					this->insert(begin() + pos + i, *first);
					i++;
				}
				// this->insert_specialised(position, first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
			}
			
			template <class InputIterator>
			void	assign(InputIterator first, ENABLE_IF(InputIterator) last)
			{

				difference_type	nb = std::distance(first, last);
				this->clear();
				reserve(nb);
				// this->clear();
				this->m_size = nb;
				for (difference_type i = 0; i < nb; i++)
				{
					this->m_alloc.construct(this->m_start + i, *first);
					first++;
				}
				this->m_size = nb;

				
				// this->clear();
				// this->insert_specialised(this->begin(), first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
			}

			void	assign(size_type n, const value_type & val)
			{
				this->clear();
				for (size_type i = 0; i < n; i++)
					this->push_back(val);
			}

		public:
			// !------------------------------CONSTRUCTOR----------------------------------

			explicit vector (const allocator_type & alloc = allocator_type()): vector_base<Tp, Allocator>(alloc)
			{
				
			};
			
			explicit vector (size_type n, const value_type & val = value_type()): vector_base<Tp, Allocator>(n, val)
			{
				
			};
			
			template <class InputIterator>
			vector (InputIterator first, ENABLE_IF(InputIterator) last, const allocator_type & alloc = allocator_type()): vector_base<Tp, Allocator>(first, last, alloc)
			{
				// this->insert_specialised(this->begin(), first, last, typename ft::iterator_traits<InputIterator>::iterator_category());
				for (; first != last; first++)
					push_back(*first);
				this->m_capacity = this->m_size;
			};
			
			vector (const vector & x): vector_base<Tp, Allocator>(x) {};

			//!------------------------------DESTRUCTOR-----------------------------------
			
			virtual ~vector() {};

			//!------------------------------OPERATOR-------------------------------------
			
			vector & operator= (const vector & x)
			{
				if (this != &x)
				{
					this->clear();
					this->assign(x.begin(), x.end());
				}
				return (*this);
			}

			reference operator[] (size_type n)
			{
				/*
				*This operator allows for easy, array-style, data access.
				*  Note that data access with this operator is unchecked and
				*  out_of_range lookups are not defined. (For checked lookups
				*  see at().)
				*/
			return (this->m_start[n]);
			}

			const_reference operator[] (size_type n) const
			{
				/*
				*This operator allows for easy, array-style, data access.
				*  Note that data access with this operator is unchecked and
				*  out_of_range lookups are not defined. (For checked lookups
				*  see at().)
				*/
				return (this->m_start[n]);
			}

		private:

		template <class T> 
		void real_swap ( T& a, T& b )
		{
			T	c(a);
			a = b;
			b = c;
		}

		// template <class InputIterator>
		// void	insert_specialised(iterator position, InputIterator first, InputIterator last, std::forward_iterator_tag)
		// {
		// 		//calculate the position of the iterator
		// 		ptrdiff_t pos = position - begin();
		// 		if (this->m_size + (std::distance(first, last)) >= this->m_capacity)
		// 		{
		// 			if (this->m_capacity * 2 > this->m_size + (std::distance(first, last)))
		// 				this->reserve(this->m_size * 2);
		// 			else
		// 				this->reserve(this->m_size + (std::distance(first, last)));
		// 		}
				
		// 		for (int i = 0; last != first; first++)
		// 		{
		// 			this->insert(begin() + pos + i, *first);
		// 			i++;
		// 		}
		// }

		// template <class InputIterator>
		// void	insert_specialised(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag)
		// {
		// 	ft::vector<value_type> tmp;
		// 	tmp.insert(tmp.begin(), this->begin(), position);
		// 	for (;first != last; first++)
		// 		tmp.push_back(*first);
		// 	tmp.insert(tmp.end(), position, this->end());
		// 	this->swap(tmp);
		// }
	};

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		if (!ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (false);
		return (true);
	}



	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		if (lhs == rhs || lhs < rhs)
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		if (lhs <= rhs)
			return (false);
		return (true);
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
	{
		if (lhs < rhs)
			return (false);
		return (true);
	}

}

#endif