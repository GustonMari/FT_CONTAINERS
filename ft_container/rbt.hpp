/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:23:46 by gmary             #+#    #+#             */
/*   Updated: 2022/11/29 12:55:27 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

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
	class RedBlackTree
	{
		public:
			typedef Node<value_type> 														*NodePtr;
			//?		https://alp.developpez.com/tutoriels/templaterebinding/
			//?		rebind is used to get a template typedef from a template class and permit to compile this line
			typedef typename allocator_type::template rebind<Node<value_type> >::other 		node_allocator_type;
			typedef typename std::allocator<Node<value_type> >::pointer 					pointer;
			typedef typename std::size_t													size_type;
			typedef typename std::ptrdiff_t													difference_type;

		private:
			//!Utils variables
			key_compare				m_comp;
			node_allocator_type		m_alloc;
			NodePtr					m_root;

		public:

			
			//!	Constructors and destructor
			NodePtr	root;
			NodePtr	LEAF_NULL;

			RedBlackTree()
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

			~RedBlackTree()
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

			/*
				!we recusively call the function until we find the good value
				https://www.happycoders.eu/algorithms/binary-search-tree-java/#Binary_Search_Tree_Example
			*/

			size_type search_occurence(NodePtr node, _first key) const
			{
				if (key == node->data.first)
					return 1;
				if (node == LEAF_NULL)
					return 0;
				if (m_comp(key, node->data.first))
					return search_occurence(node->left, key);
				return search_occurence(node->right, key);
			}

			NodePtr search_occurence_normal(NodePtr node, const _first key)
			{
				if (key == node->data.first)
					return node;
				if (node == LEAF_NULL)
					return LEAF_NULL;
				if (m_comp(key, node->data.first))
					return search_occurence_normal(node->left, key);
				return search_occurence_normal(node->right, key);
			}

			NodePtr const_search_occurence_normal(NodePtr node, const _first key) const
			{
				if (key == node->data.first)
					return node;
				if (node == LEAF_NULL)
					return LEAF_NULL;
				if (m_comp(key, node->data.first))
					return const_search_occurence_normal(node->left, key);
				return const_search_occurence_normal(node->right, key);
			}


			void delete_balance(NodePtr x_node) {
				NodePtr s;
				while (x_node != root && x_node->color == BLACK)
				{
					if (x_node == x_node->parent->left)
					{
						s = x_node->parent->right;
						if (s->color == RED)
						{
							s->color = BLACK;
							x_node->parent->color = RED;
							left_rotation(x_node->parent);
							s = x_node->parent->right;
						}

						if (s->left->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x_node = x_node->parent;
						}
						else
						{
							if (s->right->color == BLACK)
							{
								s->left->color = BLACK;
								s->color = RED;
								right_rotation(s);
								s = x_node->parent->right;
							}

							s->color = x_node->parent->color;
							x_node->parent->color = BLACK;
							s->right->color = BLACK;
							left_rotation(x_node->parent);
							x_node = root;
						}
					}
					//*same as above but the rotation is contrar
					else
					{
						s = x_node->parent->left;
						if (s->color == RED)
						{
							s->color = BLACK;
							x_node->parent->color = RED;
							right_rotation(x_node->parent);
							s = x_node->parent->left;
						}

						if (s->right->color == BLACK && s->right->color == BLACK)
						{
							s->color = RED;
							x_node = x_node->parent;
						}
						else
						{
							if (s->left->color == BLACK)
							{
								s->right->color = BLACK;
								s->color = RED;
								left_rotation(s);
								s = x_node->parent->left;
							}

							s->color = x_node->parent->color;
							x_node->parent->color = BLACK;
							s->left->color = BLACK;
							right_rotation(x_node->parent);
							x_node = root;
						}
					}
				}
				x_node->color = BLACK;
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
				NodePtr x_node, y_node;
				//*find the node to delete
				while (node != LEAF_NULL)
				{
					if (node->data == key)
						z = node;
					if (m_comp(node->data.first, key.first))
						node = node->right;
					else
						node = node->left;
				}

				if (z == LEAF_NULL)
					return (false);

				y_node = z;
				//* we save the original color of futur deleted node
				int y_original_color = y_node->color;
				//* if the left child is null (leaf)
				if (z->left == LEAF_NULL)
				{
					//*we assign the right child to x_node (it became a null_leaf)
					x_node = z->right;
					//* we transplant (replace) the deleted node with x_node
					transplant(z, z->right);
				}
				else if (z->right == LEAF_NULL) //*same thing but symetrics
				{
					x_node = z->left;
					transplant(z, z->left);
				}
				else //* neither child is null (leaf)
				{
					//* we assign the minimum of the right subtree (of the node to be deleted) to y_node
					y_node = minimum(z->right);
					//* we save the original color of y_node
					y_original_color = y_node->color;
					//* we assign the right child of y_node to x_node
					x_node = y_node->right;
					//* if y_node is one of the child of the node to be deleted, then we assign x_node parent to y_node
					if (y_node->parent == z)
						x_node->parent = y_node;
					else
					{
						transplant(y_node, y_node->right);
						y_node->right = z->right;
						y_node->right->parent = y_node;
					}

					transplant(z, y_node);
					y_node->left = z->left;
					y_node->left->parent = y_node;
					y_node->color = z->color;
				}
				m_alloc.destroy(z);
				m_alloc.deallocate(z, sizeof(Node<value_type>));
				// delete z;
				//* if the original color of y_node was black, then we need to fix the tree
				if (y_original_color == BLACK)
					delete_balance(x_node);
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
				// if (root == ft::_nullptr)
				// 	return ;
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
					{
						std::cout << BRED << root->data.first << "(" << "RED" << ")" << "--->" << root->data.second << CRESET<< std::endl;
					}
					else
					{
						std::cout << BBLU << root->data.first << "(" << "BLACK" << ")" << "--->" << root->data.second << CRESET << std::endl;
					}
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


			// NodePtr successor(NodePtr x_node)
			// {
			// 	if (x_node->right != LEAF_NULL)
			// 	{
			// 		return minimum(x_node->right);
			// 	}

			// 	NodePtr y_node = x_node->parent;
			// 	while (y_node != LEAF_NULL && x_node == y_node->right)
			// 	{
			// 		x_node = y_node;
			// 		y_node = y_node->parent;
			// 	}
			// 	return y_node;
			// }

			// NodePtr predecessor(NodePtr x_node)
			// {
			// 	if (x_node->left != LEAF_NULL)
			// 	{
			// 		return maximum(x_node->left);
			// 	}

			// 	NodePtr y_node = x_node->parent;
			// 	while (y_node != LEAF_NULL && x_node == y_node->left)
			// 	{
			// 		x_node = y_node;
			// 		y_node = y_node->parent;
			// 	}

			// 	return y_node;
			// }

			void left_rotation(NodePtr x_node)
			{
				NodePtr y_node = x_node->right;
				x_node->right = y_node->left;
				//* if y_node's left child is not null (y_node has a left subtree), assign x_node as the parent of the left subtree of y_node
				if (y_node->left != LEAF_NULL)
					y_node->left->parent = x_node;
				y_node->parent = x_node->parent;
				//* if x_node's parent is null, assign y_node as the root of the tree
				if (x_node->parent == ft::_nullptr)
					this->root = y_node;
				//* else if x_node is the left child of parent, assign y_node as the left child of x_node's parent
				else if (x_node == x_node->parent->left)
					x_node->parent->left = y_node;
				//* else assign y_node as the right child of x_node's parent
				else
					x_node->parent->right = y_node;
				//* y_node is now the parent of x_node
				y_node->left = x_node;
				x_node->parent = y_node;
			}

			void right_rotation(NodePtr x_node)
			{
				NodePtr y_node = x_node->left;
				x_node->left = y_node->right;
				//* if x_node's right child is not null (x_node has a right subtree), assign y_node as the parent of the right subtree of x_node
				if (y_node->right != LEAF_NULL)
					y_node->right->parent = x_node;
				y_node->parent = x_node->parent;
				//* if x_node's parent is null, assign y_node as the root of the tree
				if (x_node->parent == ft::_nullptr)
					this->root = y_node;
				//* else if x_node is the right child of parent, assign y_node as the right child of x_node's parent
				else if (x_node == x_node->parent->right)
					x_node->parent->right = y_node;
				//* else assign y_node as the left child of x_node's parent
				else
					x_node->parent->left = y_node;
				//* y_node is now the parent of x_node
				y_node->right = x_node;
				x_node->parent = y_node;
			}

			//!========================================= Inserting a node =======================================================================
			//* we always insert a node as a red node, and then we fix the tree, because red nodes does not violate the red-black tree properties
			//* If you attach a red node to a red node, then the rule is violated but it is easier to fix this problem than the problem introduced by violating the depth property.
			
			pointer insert(value_type key)
			{
				NodePtr node = m_alloc.allocate(sizeof(Node<value_type>));
				m_alloc.construct(node, Node<value_type>(key, LEAF_NULL, LEAF_NULL));
				NodePtr y_node = ft::_nullptr;
				NodePtr x_node = this->root;

				while (x_node != LEAF_NULL)
				{
					y_node = x_node;
					//*Move depending on the value of the data
					if (m_comp(node->data.first, x_node->data.first)) 
					{
						//*If the data is smaller than the current node, go left
						x_node = x_node->left;
					}
					else if (m_comp(x_node->data.first, node->data.first))
					{
						//*If the data is bigger than the current node, go right
						x_node = x_node->right;
					}
					else
					{
						m_alloc.destroy(node);
						m_alloc.deallocate(node, sizeof(Node<value_type>));
						return ft::_nullptr;
					}
				}

				//*inserting the new node
				node->parent = y_node;
				//*If the tree is empty, the new node is the root (case 1)
				if (y_node == ft::_nullptr)
					root = node;
				//* place node to left of right of y_node depending on the value of the data
				else if (m_comp(node->data.first, y_node->data.first))
					y_node->left = node;
				else
					y_node->right = node;
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
					if (m_comp(node->data.first, k) == false)
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
					if (m_comp(k, node->data.first) == true)
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
				{
					print_tree(this->root, "", true);
				}
			}
	};
}


#endif