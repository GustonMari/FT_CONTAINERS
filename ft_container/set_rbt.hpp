/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rbt.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:23:46 by gmary             #+#    #+#             */
/*   Updated: 2022/11/29 12:51:28 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_RBT_HPP
# define SET_RBT_HPP

# include "utils.hpp"
# include "nullptr.hpp"
# include "iterator_map.hpp"
# include "node.hpp"
# include "less.hpp"
# include <iostream>
# include <string>

/*
	?	https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
	?	https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
	?	https://www.programiz.com/dsa/red-black-tree
	?	https://www.happycoders.eu/algorithms/red-black-tree-java/
	?	https://iq.opengenus.org/red-black-tree-insertion/
*/

namespace ft
{
	template <class value_type, class key_compare, class allocator_type, class _first, class _second>
	class Set_RedBlackTree
	{
		public:
			typedef Node<value_type> *NodePtr;
			typedef typename allocator_type::template rebind<Node<value_type> >::other node_allocator_type;
			//TODO: vraiment pas sur pour les const :/

			typedef typename std::allocator<Node<value_type> >::pointer 							pointer;	
			typedef typename std::size_t										size_type;
			typedef typename std::ptrdiff_t										difference_type;

		private:
			//!Utils variables
			key_compare m_comp;
			node_allocator_type m_alloc;
			NodePtr m_root;

		public:
			//!	Constructors and destructor
			NodePtr root;
			NodePtr LEAF_NULL;

			Set_RedBlackTree()
			{
				m_alloc = allocator_type();
				m_comp = key_compare();
				LEAF_NULL = m_alloc.allocate(sizeof(Node<value_type>));
				m_alloc.construct(LEAF_NULL, Node<value_type>(value_type()));
				LEAF_NULL->parent = ft::_nullptr;
				LEAF_NULL->color = BLACK;
				LEAF_NULL->left = ft::_nullptr;
				LEAF_NULL->right = ft::_nullptr;
				root = LEAF_NULL;
			};

			~Set_RedBlackTree()
			{
				// clear(root);
				// m_alloc.destroy(LEAF_NULL);
				// m_alloc.deallocate(LEAF_NULL, sizeof(Node<value_type>));
			}


			//!Operators
			//!================================Functions================================

			NodePtr begin()
			{
				return ((minimum(root)));
			}

			NodePtr const_begin() const
			{
				return ((const_minimum(root)));
			}

			NodePtr end()
			{
				return (maximum(root));
			}

			NodePtr	const_end() const
			{
				return (const_maximum(root));
			}

			bool empty() const
			{
				return (root == LEAF_NULL);
			}

			// size_type count(const value_type &k) const
			size_type count(const _first &k) const
			{
				return (search_occurence(root, k));
			}

			void	destroy_leaf()
			{
				m_alloc.destroy(LEAF_NULL);
				m_alloc.deallocate(LEAF_NULL, sizeof(Node<value_type>));
			}

			void	delete_tree()
			{
				delete_tree_internal(root);
				m_root = LEAF_NULL;
			}

			void
			clear (void) {
				clear_internal (root);
				root = LEAF_NULL;
			}

			
		private:
			//!Utils functions
			void	delete_tree_internal(NodePtr node)
			{
				if (node == LEAF_NULL)
					return ; 
			
				delete_tree_internal(node->left); 
				delete_tree_internal(node->right); 
			
				m_alloc.destroy(node);
				m_alloc.deallocate(node, sizeof(Node<value_type>));
			}

			void	clear_internal(NodePtr node)
			{
				if (node == LEAF_NULL)
					return ; 
			
				clear_internal(node->left); 
				clear_internal(node->right); 
			
				m_alloc.destroy(node);
				m_alloc.deallocate(node, sizeof(Node<value_type>));
			}

			void initializeNULLNode(NodePtr node, NodePtr parent)
			{
				node->data = 0;
				node->parent = parent;
				node->left = ft::_nullptr;
				node->right = ft::_nullptr;
				node->color = BLACK;
			}

			/*
				!we recusively call the function until we find the good value
				https://www.happycoders.eu/algorithms/binary-search-tree-java/#Binary_Search_Tree_Example
			*/

			// size_type search_occurence(NodePtr node, value_type key)
			size_type search_occurence(NodePtr node, _first key) const
			{
				if (key == node->data)
					return 1;
				if (node == LEAF_NULL)
					return 0;
				if (m_comp(key, node->data))
					return search_occurence(node->left, key);
				return search_occurence(node->right, key);
			}

			NodePtr search_occurence_normal(NodePtr node, const _first key)
			{
				if (key == node->data)
					return node;
				if (node == LEAF_NULL)
					return LEAF_NULL;
				if (m_comp(key, node->data))
					return search_occurence_normal(node->left, key);
				return search_occurence_normal(node->right, key);
			}

			NodePtr const_search_occurence_normal(NodePtr node, const _first key) const
			{
				if (key == node->data)
					return node;
				if (node == LEAF_NULL)
					return LEAF_NULL;
				if (m_comp(key, node->data))
					return const_search_occurence_normal(node->left, key);
				return const_search_occurence_normal(node->right, key);
			}


			void delete_balance(NodePtr x) {
				NodePtr s;
				while (x != root && x->color == BLACK)
				{
					if (x == x->parent->left)
					{
						s = x->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							left_rotation(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								right_rotation(s);
								s = x->parent->right;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							left_rotation(x->parent);
							x = root;
						}
					}
					//*same as above but the rotation is contrar
					else
					{
						s = x->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x->parent->color = RED;
							right_rotation(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x = x->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								left_rotation(s);
								s = x->parent->left;
							}

							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							right_rotation(x->parent);
							x = root;
						}
					}
				}
				x->color = BLACK;
			}


			void transplant(NodePtr u, NodePtr v)
			{
				if (u->parent == ft::_nullptr)
					root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			}


			//? https://www.youtube.com/watch?v=lU99loSvD8s&ab_channel=MichaelSambol
			//TODO: replace int with value_type juste en dessous ??
			bool delete_node(NodePtr node, value_type key)
			{
				NodePtr z = LEAF_NULL;
				NodePtr x, y;
				//*find the node to delete
				while (node != LEAF_NULL)
				{
					if (node->data == key)
						z = node;
					if (m_comp(node->data, key))
						node = node->right;
					else
						node = node->left;
				}

				if (z == LEAF_NULL)
					return (false);

				y = z;
				//* we save the original color of futur deleted node
				int y_original_color = y->color;
				//* if the left child is null (leaf)
				if (z->left == LEAF_NULL)
				{
					//*we assign the right child to x (it became a null_leaf)
					x = z->right;
					//* we transplant (replace) the deleted node with x
					transplant(z, z->right);
				}
				else if (z->right == LEAF_NULL) //*same thing but symetrics
				{
					x = z->left;
					transplant(z, z->left);
				}
				else //* neither child is null (leaf)
				{
					//* we assign the minimum of the right subtree (of the node to be deleted) to y
					y = minimum(z->right);
					//* we save the original color of y
					y_original_color = y->color;
					//* we assign the right child of y to x
					x = y->right;
					//* if y is one of the child of the node to be deleted, then we assign x parent to y
					if (y->parent == z)
					{
						x->parent = y;
					}
					else
					{
						transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				m_alloc.destroy(z);
				m_alloc.deallocate(z, sizeof(Node<value_type>));
				//* if the original color of y was black, then we need to fix the tree
				if (y_original_color == BLACK)
					delete_balance(x);
				return (true);
			}

			// *For balancing the tree after insertion
			//* the case 1 is when the node is the root is already check if insert
			//* the case 2 is when the parent is black it cannot append because we insert red node
			//* sowe need to resolve the case 3 where we violate the property of to red node side by side
			void insert_balance(NodePtr k)
			{
				NodePtr u;
				while (k->parent->color == RED)
				{
					if (k->parent == k->parent->parent->right)
					{
						u = k->parent->parent->left;
						//* the new node (child ) is red and the parent is red so we color black the parent and the uncle in black and the grandparent in red
						if (u->color == RED) //* case 3.1
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else //* case 3.2 we need double or single rotation depending if k is right or left child of parent
						{
							if (k == k->parent->left) //* case 3.2.2
							{
								k = k->parent;
								right_rotation(k);
							}
							//*case 3.2.1
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							//* we need to rotate the grandparent to the left,so the grand parent is now the sibling of k
							left_rotation(k->parent->parent);
						}
					}
					else //* symetric case
					{
						u = k->parent->parent->right;

						if (u->color == RED)
						{
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else //* case 3.2.3 and 3.2.4 is the symetric of 3.2.1 and 3.2.2
						{
							if (k == k->parent->right)
							{
								k = k->parent;
								left_rotation(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							right_rotation(k->parent->parent);
						}
					}
					if (k == root) //* finish the loop because everything is balanced
						break;
				}
				//* root node is always black
				root->color = BLACK;
			}

			void print_tree(NodePtr root, std::string indent, bool last)
			{
				if (root != LEAF_NULL)
				{
					std::cout << indent;
					if (last)
					{
						std::cout << "R----";
						indent += "   ";
					}
					else
					{
						std::cout << "L----";
						indent += "|  ";
					}
					if (root->color == RED)
						std::cout << BRED << root->data << "(" << "RED" << ")" << "--->" << root->data << CRESET<< std::endl;
					else
						std::cout << BBLU << root->data << "(" << "BLACK" << ")" << "--->" << root->data << CRESET << std::endl;
					print_tree(root->left, indent, false);
					print_tree(root->right, indent, true);
				}
			}

			public:

			NodePtr search_in_tree(const _first k)
			{
				return search_occurence_normal(this->root, k);
			}

			NodePtr const_search_in_tree(const _first k) const
			{
				return const_search_occurence_normal(this->root, k);
			}

			NodePtr minimum(NodePtr node)
			{
				if (node == LEAF_NULL)
					return node;
				while (node->left != LEAF_NULL)
					node = node->left;
				return node;
			}

			NodePtr const_minimum(NodePtr node) const
			{
				if (node == LEAF_NULL)
					return node;
				while (node->left != LEAF_NULL)
					node = node->left;
				return node;
			}

			NodePtr maximum(NodePtr node)
			{
				if (node == LEAF_NULL)
					return node;
				while (node->right != LEAF_NULL)
					node = node->right;
				return node;
			}

			NodePtr const_maximum(NodePtr node) const
			{
				if (node == LEAF_NULL)
					return node;
				while (node->right != LEAF_NULL)
					node = node->right;
				return node;
			}

			void left_rotation(NodePtr x)
			{
				NodePtr y = x->right;
				x->right = y->left;
				//* if y's left child is not null (y has a left subtree), assign x as the parent of the left subtree of y
				if (y->left != LEAF_NULL)
					y->left->parent = x;
				y->parent = x->parent;
				//* if x's parent is null, assign y as the root of the tree
				if (x->parent == ft::_nullptr)
					this->root = y;
				//* else if x is the left child of parent, assign y as the left child of x's parent
				else if (x == x->parent->left)
					x->parent->left = y;
				//* else assign y as the right child of x's parent
				else
					x->parent->right = y;
				//* y is now the parent of x
				y->left = x;
				x->parent = y;
			}

			void right_rotation(NodePtr x)
			{
				NodePtr y = x->left;
				x->left = y->right;
				//* if x's right child is not null (x has a right subtree), assign y as the parent of the right subtree of x
				if (y->right != LEAF_NULL)
					y->right->parent = x;
				y->parent = x->parent;
				//* if x's parent is null, assign y as the root of the tree
				if (x->parent == ft::_nullptr)
					this->root = y;
				//* else if x is the right child of parent, assign y as the right child of x's parent
				else if (x == x->parent->right)
					x->parent->right = y;
				//* else assign y as the left child of x's parent
				else
					x->parent->left = y;
				//* y is now the parent of x
				y->right = x;
				x->parent = y;
			}

			//!========================================= Inserting a node =======================================================================
			//* we always insert a node as a red node, and then we fix the tree, because red nodes does not violate the red-black tree properties
			//* If you attach a red node to a red node, then the rule is violated but it is easier to fix this problem than the problem introduced by violating the depth property.
			
			pointer insert(value_type key)
			{
				NodePtr node = m_alloc.allocate(sizeof(Node<value_type>));
				m_alloc.construct(node, Node<value_type>(key, LEAF_NULL, LEAF_NULL));
				NodePtr y = ft::_nullptr;
				NodePtr x = this->root;

				while (x != LEAF_NULL)
				{
					y = x;
					//*Move depending on the value of the data
					if (m_comp(node->data, x->data))
					{
						//*If the data is smaller than the current node, go left
						x = x->left;
					}
					// else if (node->data > x->data)
					else if (m_comp(x->data, node->data))
					{
						//*If the data is bigger than the current node, go right
						x = x->right;
					}
					else
					{
						m_alloc.destroy(node);
						m_alloc.deallocate(node, sizeof(Node<value_type>));
						return ft::_nullptr;
					}
				}
				//*inserting the new node
				node->parent = y;
				//*If the tree is empty, the new node is the root (case 1)
				if (y == ft::_nullptr)
					root = node;
				//* place node to left of right of y depending on the value of the data
				else if (m_comp(node->data, y->data))
					y->left = node;
				else
					y->right = node;
				//*If the new node is a root node, color it black and return (case 2)
				if (node->parent == ft::_nullptr)
				{
					node->color = BLACK;
					return (node);
				}
				//*If the grandparent is null, there is nothing to do (case 3)
				if (node->parent->parent == ft::_nullptr)
					return (node);
				//*Recalibrate the tree after insertion
				insert_balance(node);
				return (node);
			}

			NodePtr	lower_bound_rbt(NodePtr node, _first k) const
			{
				NodePtr tmp = LEAF_NULL;
				
				if (node == LEAF_NULL)
					return (node);
				while (node != LEAF_NULL)
				{
					if (m_comp(node->data, k) == false)
					{
						tmp = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				return (tmp);
			}

			NodePtr	upper_bound_rbt(NodePtr node, _first k) const
			{
				NodePtr tmp = LEAF_NULL;
				
				if (node == LEAF_NULL)
					return (node);
				while (node != LEAF_NULL)
				{
					if (m_comp(k, node->data) == true)
					{
						tmp = node;
						node = node->left;
					}
					else
						node = node->right;
				}
				return (tmp);
			}


			NodePtr	get_leaf_null()
			{
				return (LEAF_NULL);
			}

			NodePtr	const_get_leaf_null() const
			{
				return (LEAF_NULL);
			}

			NodePtr getRoot()
			{
				return this->root;
			}

			NodePtr const_getRoot() const
			{
				return this->root;
			}

			bool deleteNode(value_type data)
			{
				return (delete_node(this->root, data));
			}

			void printTree()
			{
				if (root)
					print_tree(this->root, "", true);
			}
	};
}


#endif