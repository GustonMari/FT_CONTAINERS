/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:36:33 by gmary             #+#    #+#             */
/*   Updated: 2022/11/29 13:50:51 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
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
# include "rbt.hpp"
# include "iterator_map.hpp"
#include "node.hpp"
#include "lexicographical_compare.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key,T> > >
	class map
	{
		public:
		
			typedef Key																					key_type;
			typedef T																					mapped_type;
			typedef ft::pair<const Key, mapped_type>													value_type;
			typedef Compare																				key_compare;
			typedef Allocator																			allocator_type;
			typedef RedBlackTree<value_type, key_compare, allocator_type, const Key, mapped_type>		_Rep_type;
			typedef typename Allocator::pointer		 													pointer;
			typedef typename Allocator::const_pointer													const_pointer;
			typedef typename Allocator::reference														reference;
			typedef typename Allocator::const_reference													const_reference;
			typedef typename ft::IteratorMap<value_type, Node<value_type> >								iterator;
			typedef typename ft::IteratorMap<const value_type, Node<value_type> >						const_iterator;
			typedef typename _Rep_type::size_type														size_type;
			typedef typename _Rep_type::difference_type													difference_type;
			typedef typename ft::reverse_iterator<iterator>	 											reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>										const_reverse_iterator;

			/*
				binary_function is a base class for creating function objects with two arguments.
				binary_function does not define operator(); it is expected that derived classes will define this.
				binary_function provides only three types - first_argument_type, second_argument_type and result_type - defined by the template parameters.
			*/

			class value_compare : public std::binary_function<value_type, value_type, bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			_Rep_type		m_root;
			allocator_type	m_alloc;
			key_compare		m_comp;
			size_type		m_size;
		
		public:
			//!=============================== Constructors ======================================================

			//*empty
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):  m_root(), m_alloc(alloc),  m_comp(comp), m_size(0)
			{
			}
		
			//*range
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): m_root(), m_alloc(alloc),  m_comp(comp) , m_size(0)
			{
				insert(first, last);
			}
			
			//*copy
			map (const map& x)/* : m_root(), m_alloc(x.m_alloc), m_comp(x.m_comp), m_size(x.m_size) */
			{
				*this = x;
			}

			//!=============================== Destructor ======================================================
			~map()
			{
				//TODO: double free ???
				if (m_size != 0)
				{
					m_root.delete_tree();
				}
					m_root.destroy_leaf();
			}

			//!=============================== Operators ======================================================
			map& operator= (const map& x)
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

			mapped_type& operator[] (const key_type& k)
			{
				iterator it = find(k);
				if (it == end())
				{
					insert(ft::make_pair(k, mapped_type()));
					it = find(k);
				}
				return (it->second);
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

			//we get the max size of the difference_type and divide by the node to get the max size of node possible
			size_type max_size(void) const
			{
				return (std::numeric_limits<difference_type>::max() / sizeof(Node<value_type>));
			}

			iterator find(const key_type& k)
			{
				if (m_size == 0)
					return (end());
				Node<value_type> *node = m_root.search_in_tree(k);
				if (node == m_root.get_leaf_null())
					return (end());
				return (iterator(node, m_root.get_leaf_null(), m_root.getRoot()));
			}

			const_iterator find(const key_type& k) const
			{
				if (m_size == 0)
					return (end());
				Node<value_type> *node = m_root.const_search_in_tree(k);
				if (node == m_root.const_get_leaf_null())
					return (end());
				return (const_iterator(node, m_root.const_get_leaf_null(), m_root.const_getRoot()));
			}

			//!================================ Insert ======================================================
			
			//*single element
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (m_root.insert(val) == ft::_nullptr)
					return ft::make_pair(iterator(m_root.search_in_tree(val.first), m_root.get_leaf_null(), m_root.getRoot()), false);
				this->m_size++;
				return ft::make_pair(iterator(m_root.search_in_tree(val.first), m_root.get_leaf_null(), m_root.getRoot()), true);
			}
			
			//*with hint
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				insert(val);
				return (iterator(m_root.search_in_tree(val.first), m_root.get_leaf_null(), m_root.getRoot()));
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
					erase(it->first);
				}
			}
			//!================================ Swap ======================================================
			
			void swap (map& x)
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

			//TODO: need to do const version of equal_range
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
			// void	print_tree()
			// {
				// m_root.printTree();
			// }
	};
}

template <class Key, class T, class Compare, class Alloc>
bool	operator==(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename ft::map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator ite = lhs.end();
	typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
	while (it != ite)
	{
		if (*it != *it2)
			return (false);
		it++;
		it2++;
	}
	return (true);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator!=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs == rhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator<=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(rhs < lhs));
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template <class Key, class T, class Compare, class Alloc>
bool	operator>=(const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (!(lhs < rhs));
}

template <class Key, class T, class Compare, class Alloc>
void	swap(ft::map<Key, T, Compare, Alloc>& x, ft::map<Key, T, Compare, Alloc>& y)
{
	if (x == y)
		return ;
	x.swap(y);
}

#endif