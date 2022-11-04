/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:20:53 by gmary             #+#    #+#             */
/*   Updated: 2022/11/03 15:13:54 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_pair.h.html#std::pair
	https://docs.w3cub.com/cpp/utility/pair TOP pour connaitre membre

	tres smart pour l'operator!= plustot que deux tout redefinir on peut utiliser l'operator== tel que:
	return !(x == y);
	tes smart aussi d'utiliser l'operator< pour faire l'operator> qui est juste l'inverse apres tout
	tres smart d'utiliser !(x < y) (l'operator<)pour faire l'operator>= qui est juste l'inverse apres tout
*/

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template <typename T1, typename T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		T1 first;
		T2 second;
		
		// basic constructor
		pair() : first(), second() {}
		// two object can be passed to be copy constructed
		pair(const T1 & a, const T2 & b) : first(a), second(b) {}
		// copy constructor for the c pair class iself
		template <class U1, class U2> pair(const pair<U1, U2> & p) : first(p.first), second(p.second) {}

		~pair() {}

		pair & operator=(const pair & p)
		{
			if (this != &p)
			{
				first = p.first;
				second = p.second;
			}
			return *this;
		}

		//TODO: swap nest pas a inclure puisqu'il est code seuement a partir de c11 ??
	};

	template <class T1, class T2>
	inline pair<T1, T2> make_pair(const T1 & a, const T2 & b)
	{
		return pair<T1, T2>(a, b);
	}

	template <class T1, class T2>
	inline bool operator==(const pair<T1, T2> & a, const pair<T1, T2> & b)
	{
		return (a.first == b.first && a.second == b.second);
	}

	template <class T1, class T2>
	inline bool operator!=(const pair<T1, T2> & a, const pair<T1, T2> & b)
	{
		return !(a == b);
	}
	
	template <class T1, class T2>
	inline bool operator<(const pair<T1, T2> & a, const pair<T1, T2> & b)
	{
		return (a.first < b.first || (!(b.first < a.first) && a.second < b.second));
	}

	template <class T1, class T2>
	inline bool operator>(const pair<T1, T2> & a, const pair<T1, T2> & b)
	{
		return (b < a);
	}

	template <class T1, class T2>
	inline bool operator<=(const pair<T1, T2> & a, const pair<T1, T2> & b)
	{
		return !(b < a);
	}

	template <class T1, class T2>
	inline bool operator>=(const pair<T1, T2> & a, const pair<T1, T2> & b)
	{
		return !(a < b);
	}
}

#endif