/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:10:22 by gmary             #+#    #+#             */
/*   Updated: 2022/11/28 15:39:59 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include <vector>
# include <functional>
# include <limits>
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "vector_base.hpp"
# include "utils.hpp"
# include "pair.hpp"
# include "less.hpp"
# include "set_rbt.hpp"
# include "iterator_map.hpp"
#include "node.hpp"
#include "lexicographical_compare.hpp"
// # include <set>

// std::set<int, int> myp;

namespace ft
{
	template <class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set
	{
		public:

			typedef T																					key_type;
			typedef T																					value_type;
			typedef Compare																				key_compare;
			typedef Compare																				value_compare;
			typedef Allocator																			allocator_type;
			typedef Set_RedBlackTree<value_type, key_compare, allocator_type, const T, T>				_Rep_type;
			typedef typename Allocator::pointer		 													pointer;
			typedef typename Allocator::const_pointer													const_pointer;
			typedef typename Allocator::reference														reference;
			typedef typename Allocator::const_reference													const_reference;
			typedef typename ft::IteratorMap<const value_type, Node<value_type> >						iterator;
			typedef typename ft::IteratorMap<const value_type, Node<value_type> >						const_iterator;
			typedef typename _Rep_type::size_type														size_type;
			typedef typename _Rep_type::difference_type													difference_type;
			typedef typename ft::reverse_iterator<const_iterator>	 									reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>										const_reverse_iterator;

		private:
			_Rep_type		m_root;
			allocator_type	m_alloc;
			key_compare		m_comp;
			size_type		m_size;
		
		public:
			//!=============================== Constructors ======================================================

			//*empty
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):  m_root(), m_alloc(alloc),  m_comp(comp), m_size(0)
			{
			}
		
			//*range
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): m_root(), m_alloc(alloc),  m_comp(comp) , m_size(0)
			{
				insert(first, last);
			}
			
			//*copy
			set (const set& x)/* : m_root(), m_alloc(x.m_alloc), m_comp(x.m_comp), m_size(x.m_size) */
			{
				*this = x;
			}

			//!=============================== Destructor ======================================================
			~set()
			{
				if (m_size != 0)
				{
					m_root.delete_tree();
				}
					m_root.destroy_leaf();
				
			}

			//!=============================== Operators ======================================================
			set& operator= (const set& x)
			{
				if (this != &x)
				{
					clear();
					m_alloc = x.m_alloc;
					m_comp = x.m_comp;
					insert(x.begin(), x.end());
					m_size = x.m_size;
				}
				return (*this);
			}

			//!=============================== Functions ======================================================
		
			void	clear()
			{
					if (m_size != 0)
					{
						m_root.clear();
						m_size = 0;
					}
			}

			iterator begin(void) 
			{
				return (iterator(m_root.begin(), m_root.get_leaf_null(), m_root.getRoot()));
			}

			const_iterator begin(void) const
			{
				return (const_iterator(m_root.const_begin(), m_root.const_get_leaf_null(), m_root.const_getRoot()));
			}

			iterator end(void)
			{
				iterator it(m_root.end(), m_root.get_leaf_null(), m_root.getRoot());
				it++;
				return (it);
			}
			
			const_iterator end(void) const
			{
				const_iterator it(m_root.const_end(), m_root.const_get_leaf_null(), m_root.const_getRoot());
				it++;
				return (it);
			}

			reverse_iterator rbegin(void)
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin(void) const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator rend(void)
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend(void) const
			{
				return (const_reverse_iterator(begin()));
			}

			bool empty(void) const
			{
				return (m_root.empty());
			}
			
			size_type count (const key_type& k) const
			{
				if (m_size == 0 || find(k) == end())
					return (0);
				return (m_root.count(k));
			}

			size_type size(void) const
			{
				return (m_size);
			}

			size_type max_size(void) const
			{
				return (std::numeric_limits<difference_type>::max() / sizeof(Node<value_type>));
			}

			iterator find(const key_type& k)
			{
				if (m_size == 0)
					return (end());
				Node<value_type> *node = m_root.searchTree(k);
				if (node == m_root.get_leaf_null())
					return (end());
				return (iterator(node, m_root.get_leaf_null(), m_root.getRoot()));
			}

			const_iterator find(const key_type& k) const
			{
				if (m_size == 0)
					return (end());
				Node<value_type> *node = m_root.const_searchTree(k);
				if (node == m_root.const_get_leaf_null())
					return (end());
				return (const_iterator(node, m_root.const_get_leaf_null(), m_root.const_getRoot()));
			}
			//TODO:neeed to do const_iterator version of find

			//!================================ Insert ======================================================
			//*single element
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (m_root.insert(val) == ft::_nullptr)
					return ft::make_pair(iterator(m_root.searchTree(val), m_root.get_leaf_null(), m_root.getRoot()), false);
				this->m_size++;
				return ft::make_pair(iterator(m_root.searchTree(val), m_root.get_leaf_null(), m_root.getRoot()), true);
			}
			
			//*with hint
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				insert(val);
				return (iterator(m_root.searchTree(val), m_root.get_leaf_null(), m_root.getRoot()));
			}
			
			//*ranges
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			}

			//!================================ Erase ======================================================
			//*single element
			void erase (iterator position)
			{
				if (m_size == 0)
					return ;
				if (m_root.deleteNode(*position))
					m_size--;
			}

			//*key value
			size_type erase (const key_type& k)
			{
				if (m_size == 0)
					return (0);
				iterator it = find(k);
				if (it == end())
					return (0);
				erase(it);
				return (1);
			}

			//*range
			void erase (iterator first, iterator last)
			{
				iterator it = first;
				while (first != last)
				{
					it = first;
					first++;
					erase(*it);
				}
			}
			//!================================ Swap ======================================================
			
			void swap (set& x)
			{
				real_swap(m_root, x.m_root);
				real_swap(m_size, x.m_size);
			}

			//!================================ Key Compare ======================================================
			
			key_compare key_comp(void) const
			{
				return (m_comp);
			}

			//!================================ Value Compare ======================================================

			value_compare value_comp(void) const
			{
				return (value_compare(m_comp));
			}
			
			//!================================ Lower Bound ======================================================
			
			iterator	lower_bound(const key_type& k)
			{
				return (iterator(m_root.lower_bound_rbt(m_root.getRoot(), k), m_root.get_leaf_null(), m_root.getRoot()));
			}

			const_iterator	lower_bound(const key_type& k) const
			{
				return (const_iterator(m_root.lower_bound_rbt(m_root.const_getRoot(), k), m_root.const_get_leaf_null(), m_root.const_getRoot()));
			}

			//!================================ Upper Bound ======================================================
			
			iterator	upper_bound(const key_type& k)
			{
				return (iterator(m_root.upper_bound_rbt(m_root.getRoot(), k), m_root.get_leaf_null(), m_root.getRoot()));
			}

			const_iterator	upper_bound(const key_type& k) const
			{
				return (const_iterator(m_root.upper_bound_rbt(m_root.const_getRoot(), k), m_root.const_get_leaf_null(), m_root.const_getRoot()));
			}
			
			//!================================ Equal Range ======================================================
			
			pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			//!================================ Get allocator ======================================================
			
			allocator_type get_allocator() const
			{
				return (m_alloc);
			}
			
			
		private:

			template <class L> 
			void real_swap ( L& a, L& b )
			{
				L	c(a);
				a = b;
				b = c;
			}

			// !================================ Utils ======================================================
	};

template <class Key, class Compare, class Allocator>
bool	operator==(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename ft::set<Key, Compare, Allocator>::const_iterator it = lhs.begin();
	typename ft::set<Key, Compare, Allocator>::const_iterator ite = lhs.end();
	typename ft::set<Key, Compare, Allocator>::const_iterator it2 = rhs.begin();
	while (it != ite)
	{
		if (*it != *it2)
			return (false);
		it++;
		it2++;
	}
	return (true);
}

template <class Key, class Compare, class Allocator>
bool	operator!=(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class Compare, class Allocator>
bool	operator<(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class Compare, class Allocator>
bool	operator<=(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class Compare, class Allocator>
bool	operator>(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class Compare, class Allocator>
bool	operator>=(const ft::set<Key, Compare, Allocator>& lhs, const ft::set<Key, Compare, Allocator>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class Compare, class Allocator>
void	swap(ft::set<Key, Compare, Allocator>& x, ft::set<Key, Compare, Allocator>& y)
{
	if (x == y)
		return ;
	x.swap(y);
}
}

#endif