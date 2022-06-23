/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:47:38 by gmary             #+#    #+#             */
/*   Updated: 2022/06/23 13:46:33 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

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
			
			explicit reverse_iterator(iterator_type other) : current(other) {} //why need a explicit constructor?
			
			reverse_iterator(const reverse_iterator<Iterator>& other) : current(other.current) {}
			
			//!----------------------------OPERATORS---------------------------------------------------------
			
			
			
			//return c current, accesss the underlying container
			Iterator & base() const { return current; }

			reverse_iterator& operator=(const reverse_iterator<Iterator>& other)
			{
				if (this != &other)
				{
					current = other.current;
				}
				return *this;
			}
			
			//retourne une reference sur le contenu de l'itérateur
			reference operator*() const //TODO: vraiment a tester
			{
				Iterator tmp = current; 
				return *(tmp);
			}
			
			//retourne un pointeur sur le contenu de l'itérateur (a --current)
			pointer operator->() const { return &(operator*()); } //TODO vraiment a tester

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
			
			reverse_iterator & operator+=(difference_type n) // BUG peut etre cest pas ce quil faut faire
			{
				current -= n;
				return *this;
			}

			reverse_iterator & operator-=(difference_type n) //BUG cets peut etre pas exactement ca
			{
				current += n;
				return *this;
			}
			
			reference operator[](difference_type n) const
			{
				return *(*this + n);
			}
	};
	
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
		return lhs.base() < rhs.base();
	}

	template <typename Iterator>
	inline bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename Iterator>
	inline bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename Iterator>
	inline bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return lhs.base() >= rhs.base();
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
		return lhs.base() < rhs.base();
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator>(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() > rhs.base();
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator<=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() <= rhs.base();
	}

	template <typename IteratorL, typename IteratorR>
	inline bool operator>=(const reverse_iterator<IteratorL> &lhs, const reverse_iterator<IteratorR> &rhs)
	{
		return lhs.base() >= rhs.base();
	}
	
}

#endif