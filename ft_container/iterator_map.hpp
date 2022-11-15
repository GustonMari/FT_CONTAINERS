/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:53:55 by gmary             #+#    #+#             */
/*   Updated: 2022/11/15 14:01:36 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP
# include "iterator_traits.hpp"
# include "rbt.hpp"
# include "node.hpp"

//?https://cdmana.com/2021/12/202112300642463009.html
//?https://www.cs.fsu.edu/~lacher/courses/COP4530/lectures/binary_search_trees3/index.html?$$$slide08t.html$$$

namespace ft
{
	template <class T, class Node>
	class IteratorMap
	{
		public:
			typedef T										value_type; // pair type
			typedef Node									node_type;
			// typedef T*										pointer;
			// typedef T&										reference;
			
			typedef typename ft::iterator< std::bidirectional_iterator_tag, value_type >::iterator_category	iterator_category;
			typedef typename ft::iterator< std::bidirectional_iterator_tag, value_type >::pointer			pointer;
			typedef typename ft::iterator< std::bidirectional_iterator_tag, value_type >::reference			reference;
			typedef typename ft::iterator< std::bidirectional_iterator_tag, value_type >::difference_type		difference_type;
		
		private:
			node_type	*_node;
			// node_type	*_ptr;
			node_type	*_end;
			node_type	*_begin;
			node_type	*_root;
			typedef node_type* node_type_ptr;
			// typedef value_type	*_value_type_ptr;
			
		public:


			//! ============================ Constructor ============================
			// IteratorMap(): _node(NULL) {
			// 	// CCOUT(BCYN, "1")
			// };

			// IteratorMap(node_type_ptr & x): _node(x) {
			// 	// CCOUT(BCYN, "2")
			// };
			// IteratorMap(const node_type_ptr &x): _node(x) {
			// 	// CCOUT(BCYN, "3")
			// };
			// IteratorMap(const node_type_ptr &x, const node_type_ptr &y): _node(x), _end(y) {
			// 	// CCOUT(BCYN, "4")
			// };

			IteratorMap(const node_type_ptr &x, const node_type_ptr &y, const node_type_ptr &z): _node(x), _end(y), _root(z) {
				// CCOUT(BCYN, "5")
			};
			~IteratorMap() {
				// CCOUT(BCYN, "ouchhhh")
			};
			
			//! ============================ Operators ============================
			
			IteratorMap &operator=(const IteratorMap &x)
			{
				this->_node = x._node;
				return (*this);
			}
			
			bool operator==(const IteratorMap &x) const
			{
				return (this->_node == x._node);
			}
			
			bool operator!=(const IteratorMap &x) const
			{
				return (this->_node != x._node);
			}
			
			reference operator*() const
			{
				return (this->_node->data);
			}
			
			pointer operator->() const
			{
				return (&(this->_node->data));
			}
			
			//TODO: l'incrementation et l decrementationne sont pas bonnes

			IteratorMap &operator++()
			{
				increment();
				return (*this);
			}
			
			IteratorMap operator++(int)
			{
				IteratorMap tmp(*this);
				increment();
				return (tmp);
			}
			
			IteratorMap &operator--()
			{
				decrement();
				return (*this);
			}
			
			IteratorMap operator--(int)
			{
				IteratorMap tmp(*this);
				decrement();
				return (tmp);
			}
			
		private:

			
			
			void	increment()
			{

				//* do nothing on a null iterator
				//TODO: pas sur de cette condition en dessous
				if (this->_node == _end)
					return ;
				//* if _node is right threaded
				if (this->_node->right != _end)
				{
					this->_node = this->_node->right;
					//* if _node is left threaded, go to the leftmost _node
					while (this->_node->left != _end)
						this->_node = this->_node->left;
				}
				//* if _node is left threaded
				else
				{
					//* if _node is right threaded, go to the rightmost _node
					// pointer *tmp = this->_node->parent;
					
					node_type_ptr tmp = this->_node->parent;
					while (tmp != ft::_nullptr && tmp != _end && this->_node == tmp->right)
					{
						this->_node = tmp;
						tmp = tmp->parent;
					}
					//TODO: c'est peut etre plus == _end
					if (tmp == ft::_nullptr)
						this->_node = _end;
					else
						this->_node = tmp;
					// this->_node = tmp;
				}

			}

			// void	decrement()
			// {
			// 	//TODO: pas sur de cette condition en dessous
				
			// 	if (this->_node && this->_node != _end)
			// 	{
			// 		if (this->_node->left && this->_node->left != _end)
			// 		{
			// 			//*find max
			// 			this->_node = this->_node->left;
			// 			while (this->_node->right != _end)
			// 				this->_node = this->_node->right;
			// 		}
			// 		else
			// 		{
			// 			node_type_ptr	tmp = this->_node->parent;
			// 			while (tmp && tmp != _end && this->_node == tmp->left)
			// 			{
			// 				this->_node = tmp;
			// 				tmp = tmp->parent;
			// 			}
			// 			CCOUT(BMAG, "IN")
			// 			if (tmp == _end)
			// 				this->_node = _end;
			// 			else if (tmp != ft::_nullptr)
			// 				this->_node = maximum(_root);
			// 				// this->_node = tmp;
			// 			CCOUT(BMAG, "OUT")
			// 			// if (tmp != _end)
			// 			// 	this->_node = tmp;
			// 			// this->_node = tmp;
			// 		}
			// 	}
			// 	else
			// 		this->_node = maximum(_root);
			// 		// this->_node = _end;
			// }
			
			void	decrement()
			{
				//TODO: pas sur de cette condition en dessous
				if (this->_node == _end)
				{
					this->_node = maximum(_root);
					return ;
				}
				if (this->_node->left != _end)
				{
					this->_node = this->_node->left;
					while (this->_node->right != _end)
						this->_node = this->_node->right;
				}
				else
				{
					node_type_ptr	tmp = this->_node->parent;
					while (tmp && tmp != _end && this->_node == tmp->left)
					{
						this->_node = tmp;
						tmp = tmp->parent;
					}
					this->_node = tmp;
				}
			}
			
			public:

				void	setEnd()
				{
					// this->_node = _end;
					// increment();
				}

			private:
			
			node_type_ptr	maximum(node_type_ptr x)
			{
				while (x->right != _end)
					x = x->right;
				return (x);
			}

			node_type_ptr	minimum(node_type_ptr x)
			{
				while (x->left != _end)
					x = x->left;
				return (x);
			}

	};

}

#endif