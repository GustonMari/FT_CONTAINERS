/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:36:33 by gmary             #+#    #+#             */
/*   Updated: 2022/11/07 13:15:07 by gmary            ###   ########.fr       */
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

		
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const Key, mapped_type>						value_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef RedBlackTree<value_type, key_compare, allocator_type>	_Rep_type;
			typedef typename Allocator::pointer		 						pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef typename Allocator::reference							reference;
			typedef typename Allocator::const_reference						const_reference;
			typedef typename ft::IteratorMap<value_type, Node<value_type> >		iterator;
			// typedef typename IteratorMap::iterator							iterator;
			// typedef typename IteratorMap::const_iterator						const_iterator;
			//TODO: a quoi serve size_type  et difference_type ? size_t et ptrdiff_t ?
			typedef typename _Rep_type::size_type						size_type;
			typedef typename _Rep_type::difference_type					difference_type;
			// typedef typename IteratorMap::reverse_iterator	 				reverse_iterator;
			// typedef typename IteratorMap::const_reverse_iterator			const_reverse_iterator;

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
					m_root.delete_tree();
					// m_root = NULL;
					m_size = 0;
				// }
			}

			iterator begin(void)
			{
				return (m_root.begin());
			}

			// const_iterator begin(void) const
			// {
			// 	return (m_root.begin());
			// }

			// iterator end(void)
			// {
			// 	return (m_root.end());
			// }

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


			//!================================ Insert ======================================================
			//*single element
			// void insert (const value_type& val)
			// ft::pair<iterator,bool> insert (const value_type& val)
			// {
			// 	ft::pair<iterator, bool> ret;
			// 	m_root.insert(val);
			// 	// ret = ft::make_pair<iterator, bool>(m_root.insert(val)->data.first, true);

			// 	// CCOUT(BYEL, (ret.first));
			// 	// ret.second = ret.first != end();
			// 	// if (ret.second)
			// 	// 	m_size++;
			// 	return (ret);
			// }

			void insert (const value_type& val)
			// ft::pair<iterator,bool> insert (const value_type& val)
			{
				// ft::pair<iterator, bool> ret;
				m_root.insert(val);
				// ret = ft::make_pair<iterator, bool>(m_root.insert(val)->data.first, true);

				// CCOUT(BYEL, (ret.first));
				// ret.second = ret.first != end();
				// if (ret.second)
				// 	m_size++;
				// return (ret);
			}
			
			//*with hint
			// iterator insert (iterator position, const value_type& val);
			
			//*ranges
			// template <class InputIterator>
			// void insert (InputIterator first, InputIterator last);

			//TODO:to delete this function
			void	print_tree()
			{
				m_root.printTree();
			}
	};
}


#endif