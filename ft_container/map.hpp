/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:36:33 by gmary             #+#    #+#             */
/*   Updated: 2022/11/01 19:17:39 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
# include <memory>
# include <vector>
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "vector_base.hpp"
# include "utils.hpp"
# include "pair.hpp"
# include "less.hpp"
# include "rbt.hpp"

namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key,T> > >
	class map
	{
		public:

		
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const Key, mapped_type>					value_type;
			typedef Compare												key_compare;
			typedef Allocator											allocator_type;
			typedef RedBlackTree<value_type, key_compare, allocator_type>	_Rep_type;
			typedef typename Allocator::pointer		 					pointer;
			typedef typename Allocator::const_pointer					const_pointer;
			typedef typename Allocator::reference						reference;
			typedef typename Allocator::const_reference					const_reference;
			// typedef typename _Rep_type::iterator						iterator;
			// typedef typename _Rep_type::const_iterator					const_iterator;
			// typedef typename _Rep_type::size_type						size_type;
			// typedef typename _Rep_type::difference_type					difference_type;
			// typedef typename _Rep_type::reverse_iterator	 			reverse_iterator;
			// typedef typename _Rep_type::const_reverse_iterator			const_reverse_iterator;

			map(void) {}
		private:
			
	};
}

#endif