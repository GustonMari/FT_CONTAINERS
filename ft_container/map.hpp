/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:36:33 by gmary             #+#    #+#             */
/*   Updated: 2022/11/14 13:38:13 by gmary            ###   ########.fr       */
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
# include "iterator_map.hpp"
#include "node.hpp"

// #include <map>
// std::map<int, int> m;


namespace ft
{
	template <class Key, class T, class Compare = less<Key>, class Allocator = std::allocator<pair<const Key,T> > >
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
			// typedef typename IteratorMap::iterator							iterator;
			// typedef typename IteratorMap::const_iterator						const_iterator;
			//TODO: a quoi serve size_type  et difference_type ? size_t et ptrdiff_t ?
			typedef typename _Rep_type::size_type														size_type;
			typedef typename _Rep_type::difference_type													difference_type;
			typedef typename ft::reverse_iterator<iterator>	 											reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>										const_reverse_iterator;

		private:
			_Rep_type		m_root;
			allocator_type	m_alloc;
			key_compare		m_comp;
			size_type		m_size;
		
		public:
			//!=============================== Constructors ======================================================

			//*empty
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):  m_root(), m_alloc(alloc),  m_comp(comp),  m_size(0)
			{
			}
		
			// //*range
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): m_root(), m_size(std::distance(first, last)), m_comp(comp), m_alloc(alloc)
			{
				insert(first, last);
			}
			
			// //*copy
			map (const map& x): m_root(), m_size(x.m_size), m_comp(x.m_comp), m_alloc(x.m_alloc)
			{
				insert(x.begin(), x.end());
			}

			//!=============================== Destructor ======================================================
			~map()
			{
				//TODO: double free ???
				if (m_size != 0)
					clear();
			}

			//!=============================== Operators ======================================================
			map& operator= (const map& x)
			{
				if (this != &x)
				{
					clear();
					insert(x.begin(), x.end());
				}
				return (*this);
			}

			//!=============================== Functions ======================================================
		
			void	clear()
			{
				// if (m_root)
				// {
					if (m_size != 0)
					{
						m_root.delete_tree();
						m_size = 0;
					}
					// m_root.delete_tree();
					// m_root = NULL;
					// m_size = 0;
				// }
			}

			iterator begin(void)
			{
				return (iterator(m_root.begin(), m_root.get_leaf_null()));
			}

			// const_iterator begin(void) const
			// {
			// 	return (const_iterator(m_root.begin()));
			// }

			iterator end(void)
			{
				//BUG: ilfaut surement fait it++ pour avoir le past end iterator
				iterator it(m_root.end(), m_root.get_leaf_null());
				++it;
				return (it);
			}

			// const_iterator end(void) const
			// {
			// 	return (m_root.end());
			// }
			
			// reverse_iterator rbegin(void)
			// {
			// 	return (m_root.rbegin());
			// }
			
			bool empty(void) const
			{
				//ou utiliser la fonction empty dans rbt
				return (m_size == 0);
			}
			
			size_type count (const key_type& k) const
			{
				if (m_size == 0)
					return (0);
				return (m_root.count(k));
			}

			size_type size(void) const
			{
				return (m_size);
			}

			size_type max_size(void) const
			{
				return (m_alloc.max_size());
			}

			iterator find(const key_type& k)
			{
				if (m_size == 0)
					return (end());
				Node<value_type> *node = m_root.searchTree(k);
				if (node == m_root.get_leaf_null())
					return (end());
				return (iterator(node, m_root.get_leaf_null()));
			}
			//TODO:neeed to do const_iterator version of find

			//!================================ Insert ======================================================
			//*single element
			// void insert (const value_type& val)
			ft::pair<iterator,bool> insert (const value_type& val)
			{
				if (m_root.insert(val) == NULL)
					return ft::make_pair(iterator(m_root.searchTree(val.first), m_root.get_leaf_null()), false);
				this->m_size++;
				return ft::make_pair(iterator(m_root.searchTree(val.first), m_root.get_leaf_null()), true);
			}
			
			//TODO: check if it works
			//*with hint
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				insert(val);
				return (iterator(m_root.searchTree(val.first), m_root.get_leaf_null()));
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
				m_root.deleteNode(*position);
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
				m_size--;
				return (1);
			}

			//*range
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					erase(first);
					first++;
				}
			}
			//!================================ Swap ======================================================
			
			//TODO: make non-memeber function and member functions
			// void swap (map& x)
			// {
			// 	ft::swap(m_root, x.m_root);
			// 	ft::swap(m_size, x.m_size);
			// }

			//!================================ Key Compare ======================================================
			
			key_compare key_comp(void) const
			{
				return (m_comp);
			}

			//!================================ Value Compare ======================================================

			//TODO: need to create a value compare class
			// value_compare value_comp(void) const
			// {
			// 	return (value_compare(m_comp));
			// }
			
			//!================================ Lower Bound ======================================================
			
			//TODO: this maybe is not working because "The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false."
			
			iterator	lower_bound(const key_type& k)
			{
				iterator it = find(k);
				if (it == end())
					return (end());
				return (it);
			}

			//TODO: need to do const version of lower_bound
			// const_iterator	lower_bound(const key_type& k) const
			// {
			// 	const_iterator it = find(k);
			// 	if (it == end())
			// 		return (end());
			// 	return (it);
			// }

			//!================================ Upper Bound ======================================================
			
			iterator	upper_bound(const key_type& k)
			{
				iterator it = find(k);
				if (it == end())
					return (end());
				it++;
				return (it);
			}

			//TODO: need to do const version of upper_bound
			// const_iterator	upper_bound(const key_type& k) const
			// {
			// 	const_iterator it = find(k);
			// 	if (it == end())
			// 		return (end());
			// 	it++;
			// 	return (it);
			// }
			
			//!================================ Equal Range ======================================================
			
			pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			//TODO: need to do const version of equal_range
			// pair<const_iterator, const_iterator>	equal_range(const key_type& k) const
			// {
			// 	return (ft::make_pair(lower_bound(k), upper_bound(k)));
			// }

			//!================================ Get allocator ======================================================
			
			allocator_type get_allocator() const
			{
				return (m_alloc);
			}
			
			//!================================ Utils ======================================================
			//TODO:to delete this function
			void	print_tree()
			{
				m_root.printTree();
			}
	};
}


#endif