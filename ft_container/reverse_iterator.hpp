/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:47:38 by gmary             #+#    #+#             */
/*   Updated: 2022/11/28 15:28:02 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"
# include "_colors.hpp"
# include "utils.hpp"

/*
	Les inline spécificateurs et __inline les spécificateurs indiquent au compilateur 
	d’insérer une copie du corps de la fonction dans chaque endroit où la fonction est appelée.
	le compilateur peut annuler une demande d'inline si on a des boucle, on a des var static, recursivite,
	retourn different de void (peut etre aussi bool ), si il contient un switch ou goto, etc.
	iniline permet l'acceleration de reduire la surchage des appelles de fonction
*/

namespace ft
{
	template <typename Iterator>
	class reverse_iterator
	{
		protected:
			Iterator current;
			typedef reverse_iterator<Iterator>	traits_type;
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
			
			//!----------------------------CONSTRUCTORS------------------------------------------------------
			
			reverse_iterator() : current() {}
			
			explicit reverse_iterator(iterator_type other) : current(other) {}
			
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& other) : current(other.base()) {}
			
			//!----------------------------OPERATORS---------------------------------------------------------
			
			Iterator base() const { return current; }


			reverse_iterator& operator=(const reverse_iterator<Iterator>& other)
			{
				if (this != &other)
				{
					current = other.current;
				}
				return *this;
			}
			
			//retourne une reference sur le contenu de l'itérateur,par exmple on en a besoin pour it[0] = size;
			reference operator*() const
			{
				Iterator tmp = current;
				return *--tmp;
			}

			//retourne un pointeur sur le contenu de l'itérateur (a --current)
			pointer operator->() const { return &(operator*()); }

			reverse_iterator & operator++()
			{
				--current;
				return *this;
			}
			
			reverse_iterator operator++(int)
			{
				reverse_iterator tmp = *this;
				--current;
				return (tmp);
			}

			reverse_iterator & operator--()
			{
				++current;
				return *this;
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator tmp = *this;
				++current;
				return (tmp);
			}
			
			// ici on utilise difference_type car on a sait que (ptrdiff_t) appartient forcement au container associee
			reverse_iterator operator+(difference_type n) const
			{
				return (reverse_iterator(current - n));
			}
			
			reverse_iterator operator-(difference_type n) const
			{
				return (reverse_iterator(current + n));
			}
			
			reverse_iterator & operator+=(difference_type n)
			{
				current -= n;
				return *this;
			}

			reverse_iterator & operator-=(difference_type n)
			{
				current += n;
				return *this;
			}
			
			reference operator[](difference_type n) const
			{
				return (*(*this + n));
			}
	};

	//! END CLASS ---------------------------------------------------------------------------------------

	template<typename Iterator>
	typename ft::reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> & x)
	{
		return (reverse_iterator<Iterator>(x.base() + n));
	}
	
	template<typename Iterator>
	typename ft::reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> & x)
	{
		return (reverse_iterator<Iterator>(x.base() - n));
	}
	
	template <typename IteratorL, typename IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <typename IteratorL, typename IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator+(const reverse_iterator<IteratorL>& lhs, const reverse_iterator<IteratorR>& rhs)
	{
		return (rhs.base() + lhs.base());
	}

	//! template with one argument: const/const or non const/non const
	
	template <typename Iterator>
	inline bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() == rhs.base();
	}
	
	template <typename Iterator>
	inline bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template <typename Iterator>
	inline bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename Iterator>
	inline bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename Iterator>
	inline bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename Iterator>
	inline bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	//! template with two arguments: const/non const or non const/ const

	template <typename IteratorL, typename IteratorR>
	inline bool operator==(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() == rhs.base();
	}
	
	template <typename IteratorL, typename IteratorR>
	inline bool operator!=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() != rhs.base();
	}
	
	template <typename IteratorL, typename IteratorR>
	inline bool operator<(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator>(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() < rhs.base();
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator<=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() >= rhs.base();
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator>=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() <= rhs.base();
	}
}

#endif