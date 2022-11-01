/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:23:46 by gmary             #+#    #+#             */
/*   Updated: 2022/11/01 17:48:10 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

#include "utils.hpp"
#include "nullptr.hpp"

/*
	?	https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
	?	https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
	?	https://www.programiz.com/dsa/red-black-tree
	?	https://www.happycoders.eu/algorithms/red-black-tree-java/
	?	https://iq.opengenus.org/red-black-tree-insertion/
*/


#include <iostream>
#include <string>
// using namespace std;
template <class T>
class RedBlackTree
{
	public:
		struct Node {
			T data;
			// int data;
			Node *parent;
			Node *left;
			Node *right;
			int color;
		};

		typedef Node *NodePtr;
	
	private:
		NodePtr root;
		NodePtr LEAF_NULL;

		void initializeNULLNode(NodePtr node, NodePtr parent)
		{
			node->data = 0;
			node->parent = parent;
			node->left = ft::_nullptr;
			node->right = ft::_nullptr;
			node->color = BLACK;
		}

		// Preorder
		void preOrderHelper(NodePtr node)
		{
			if (node != LEAF_NULL)
			{
				std::cout << node->data << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			}
		}

		// Inorder
		void inOrderHelper(NodePtr node)
		{
			if (node != LEAF_NULL)
			{
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			}
		}

		// Post order
		void postOrderHelper(NodePtr node)
		{
			if (node != LEAF_NULL)
			{
				postOrderHelper(node->left);
				postOrderHelper(node->right);
				std::cout << node->data << " ";
			}
		}

		/*
			!we recusively call the function until we find the good value
			https://www.happycoders.eu/algorithms/binary-search-tree-java/#Binary_Search_Tree_Example
		*/

		NodePtr searchTreeHelper(NodePtr node, int key)
		{
			if (node == LEAF_NULL || key == node->data)
			{
				return node;
			}

			if (key < node->data)
			{
				return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		}


		void deleteFix(NodePtr x) {
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
						leftRotate(x->parent);
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
							rightRotate(s);
							s = x->parent->right;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->right->color = BLACK;
						leftRotate(x->parent);
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
						rightRotate(x->parent);
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
							leftRotate(s);
							s = x->parent->left;
						}

						s->color = x->parent->color;
						x->parent->color = BLACK;
						s->left->color = BLACK;
						rightRotate(x->parent);
						x = root;
					}
				}
			}
			x->color = BLACK;
		}


		void rbTransplant(NodePtr u, NodePtr v)
		{
			if (u->parent == ft::_nullptr)
			{
				root = v;
			}
			else if (u == u->parent->left)
			{
				u->parent->left = v;
			}
			else
			{
				u->parent->right = v;
			}
			v->parent = u->parent;
		}


		//? https://www.youtube.com/watch?v=lU99loSvD8s&ab_channel=MichaelSambol
		void deleteNodeHelper(NodePtr node, int key)
		{
			NodePtr z = LEAF_NULL;
			NodePtr x, y;
			//*find the node to delete
			while (node != LEAF_NULL)
			{
				if (node->data == key)
				{
					z = node;
				}

				if (node->data <= key)
				{
					node = node->right;
				}
				else
				{
					node = node->left;
				}
			}

			if (z == LEAF_NULL)
			{
				std::cout << "Key not found in the tree" << std::endl;
				return;
			}

			y = z;
			//* we save the original color of futur deleted node
			int y_original_color = y->color;
			//* if the left child is null (leaf)
			if (z->left == LEAF_NULL)
			{
				//*we assign the right child to x (it became a null_leaf)
				x = z->right;
				//* we transplant (replace) the deleted node with x
				rbTransplant(z, z->right);
			}
			else if (z->right == LEAF_NULL) //*same thing but symetrics
			{
				x = z->left;
				rbTransplant(z, z->left);
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
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			//* if the original color of y was black, then we need to fix the tree
			if (y_original_color == BLACK)
			{
				deleteFix(x);
			}
		}

		// *For balancing the tree after insertion
		//* the case 1 is when the node is the root is already check if insert
		//* the case 2 is when the parent is black it cannot append because we insert red node
		//* sowe need to resolve the case 3 where we violate the property of to red node side by side
		void insertFix(NodePtr k)
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
							rightRotate(k);
						}
						//*case 3.2.1
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						//* we need to rotate the grandparent to the left,so the grand parent is now the sibling of k
						leftRotate(k->parent->parent);
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
							leftRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						rightRotate(k->parent->parent);
					}
				}
				if (k == root) //* finish the loop because everything is balanced
				{
					break;
				}
			}
			//* root node is always black
			root->color = BLACK;
		}

		void printHelper(NodePtr root, std::string indent, bool last)
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

				// std::string sColor = root->color ? "RED" : "BLACK";
				// std::cout << root->data << "(" << sColor << ")" << std::endl;
				if (root->color == RED)
				std::cout << BRED << root->data << "(" << "RED" << ")" << CRESET<< std::endl;
				else
				{
					std::cout << BBLU << root->data << "(" << "BLACK" << ")" << CRESET << std::endl;
				}
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		public:
		RedBlackTree()
		{
			LEAF_NULL = new Node;
			LEAF_NULL->color = BLACK;
			LEAF_NULL->left = ft::_nullptr;
			LEAF_NULL->right = ft::_nullptr;
			root = LEAF_NULL;
		}

		void preorder()
		{
			preOrderHelper(this->root);
		}

		void inorder()
		{
			inOrderHelper(this->root);
		}

		void postorder()
		{
			postOrderHelper(this->root);
		}

		NodePtr searchTree(int k)
		{
			return searchTreeHelper(this->root, k);
		}

		NodePtr minimum(NodePtr node)
		{
			while (node->left != LEAF_NULL)
			{
				node = node->left;
			}
			return node;
		}

		NodePtr maximum(NodePtr node)
		{
			while (node->right != LEAF_NULL)
			{
				node = node->right;
			}
			return node;
		}

		NodePtr successor(NodePtr x)
		{
			if (x->right != LEAF_NULL)
			{
				return minimum(x->right);
			}

			NodePtr y = x->parent;
			while (y != LEAF_NULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		NodePtr predecessor(NodePtr x)
		{
			if (x->left != LEAF_NULL)
			{
				return maximum(x->left);
			}

			NodePtr y = x->parent;
			while (y != LEAF_NULL && x == y->left)
			{
				x = y;
				y = y->parent;
			}

			return y;
		}

		void leftRotate(NodePtr x)
		{
			NodePtr y = x->right;
			x->right = y->left;
			//* if y's left child is not null (y has a left subtree), assign x as the parent of the left subtree of y
			if (y->left != LEAF_NULL)
			{
				y->left->parent = x;
			}
			y->parent = x->parent;
			//* if x's parent is null, assign y as the root of the tree
			if (x->parent == ft::_nullptr)
			{
				this->root = y;
			}
			//* else if x is the left child of parent, assign y as the left child of x's parent
			else if (x == x->parent->left)
			{
				x->parent->left = y;
			}
			//* else assign y as the right child of x's parent
			else
			{
				x->parent->right = y;
			}
			//* y is now the parent of x
			y->left = x;
			x->parent = y;
		}

		void rightRotate(NodePtr x)
		{
			NodePtr y = x->left;
			x->left = y->right;
			//* if x's right child is not null (x has a right subtree), assign y as the parent of the right subtree of x
			if (y->right != LEAF_NULL)
			{
				y->right->parent = x;
			}
			y->parent = x->parent;
			//* if x's parent is null, assign y as the root of the tree
			if (x->parent == ft::_nullptr)
			{
				this->root = y;
			}
			//* else if x is the right child of parent, assign y as the right child of x's parent
			else if (x == x->parent->right)
			{
				x->parent->right = y;
			}
			//* else assign y as the left child of x's parent
			else
			{
				x->parent->left = y;
			}
			//* y is now the parent of x
			y->right = x;
			x->parent = y;
		}

		//! Inserting a node
		//* we always insert a node as a red node, and then we fix the tree, because red nodes does not violate the red-black tree properties
		//* If you attach a red node to a red node, then the rule is violated but it is easier to fix this problem than the problem introduced by violating the depth property.
		void insert(int key)
		{
			//TODO: on pourait avoir un constructor ici pour node tel que Node(key, color, parent, left, right)
			NodePtr node = new Node;
			node->parent = ft::_nullptr;
			node->data = key;
			node->left = LEAF_NULL;
			node->right = LEAF_NULL;
			node->color = RED;
			NodePtr y = ft::_nullptr;
			NodePtr x = this->root;

			while (x != LEAF_NULL)
			{
				y = x;
				//*Move depending on the value of the data
				if (node->data < x->data)
				{
					//*If the data is smaller than the current node, go left
					x = x->left;
				}
				else
				{
					//*If the data is bigger than the current node, go right
					x = x->right;
				}
			}

			//*inserting the new node
			node->parent = y;
			//*If the tree is empty, the new node is the root (case 1)
			if (y == ft::_nullptr)
			{
				root = node;
			}
			//* place node to left of right of y depending on the value of the data
			else if (node->data < y->data)
			{
				y->left = node;
			}
			else
			{
				y->right = node;
			}

			//*If the new node is a root node, color it black and return (case 2)
			if (node->parent == ft::_nullptr)
			{
				node->color = BLACK;
				return;
			}
			
			//*If the grandparent is null, there is nothing to do (case 3)
			if (node->parent->parent == ft::_nullptr)
			{
				return;
			}

			//*Recalibrate the tree after insertion
			insertFix(node);
		}

		NodePtr getRoot()
		{
			return this->root;
		}

		void deleteNode(int data)
		{
			deleteNodeHelper(this->root, data);
		}

		void printTree()
		{
			if (root)
			{
				printHelper(this->root, "", true);
			}
		}
};



#endif