/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:23:46 by gmary             #+#    #+#             */
/*   Updated: 2022/10/31 11:26:03 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RDT_HPP
# define RDT_HPP

#include "utils.hpp"

/*
	?	https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
	?	https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
	?	https://www.programiz.com/dsa/red-black-tree
	?	https://www.happycoders.eu/algorithms/red-black-tree-java/
	?	https://iq.opengenus.org/red-black-tree-insertion/
*/


#include <iostream>
using namespace std;

struct Node {
int data;
Node *parent;
Node *left;
Node *right;
int color;
};

typedef Node *NodePtr;

class RedBlackTree
{
	private:
		NodePtr root;
		NodePtr TNULL;

		void initializeNULLNode(NodePtr node, NodePtr parent)
		{
			node->data = 0;
			node->parent = parent;
			node->left = nullptr;
			node->right = nullptr;
			node->color = BLACK;
		}

		// Preorder
		void preOrderHelper(NodePtr node)
		{
			if (node != TNULL)
			{
				std::cout << node->data << " ";
				preOrderHelper(node->left);
				preOrderHelper(node->right);
			}
		}

		// Inorder
		void inOrderHelper(NodePtr node)
		{
			if (node != TNULL)
			{
				inOrderHelper(node->left);
				std::cout << node->data << " ";
				inOrderHelper(node->right);
			}
		}

		// Post order
		void postOrderHelper(NodePtr node)
		{
			if (node != TNULL)
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
			if (node == TNULL || key == node->data)
			{
				return node;
			}

			if (key < node->data)
			{
				return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		}

		// For balancing the tree after deletion
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
			if (u->parent == nullptr)
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

		void deleteNodeHelper(NodePtr node, int key) {
			NodePtr z = TNULL;
			NodePtr x, y;
			while (node != TNULL)
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

			if (z == TNULL)
			{
				std::cout << "Key not found in the tree" << std::endl;
				return;
			}

			y = z;
			int y_original_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				rbTransplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				rbTransplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_original_color = y->color;
				x = y->right;
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
			if (y_original_color == 0)
			{
				deleteFix(x);
			}
		}

		// For balancing the tree after insertion
		void insertFix(NodePtr k)
		{
			NodePtr u;
			while (k->parent->color == RED)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							rightRotate(k);
						}
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						leftRotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;

					if (u->color == RED)
					{
						u->color = BLACK;
						k->parent->color = BLACK;
						k->parent->parent->color = RED;
						k = k->parent->parent;
					}
					else
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
				if (k == root)
				{
					break;
				}
			}
			root->color = BLACK;
		}

		void printHelper(NodePtr root, string indent, bool last)
		{
			if (root != TNULL)
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

				string sColor = root->color ? "RED" : "BLACK";
				std::cout << root->data << "(" << sColor << ")" << std::endl;
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		public:
		RedBlackTree()
		{
			TNULL = new Node;
			TNULL->color = BLACK;
			TNULL->left = nullptr;
			TNULL->right = nullptr;
			root = TNULL;
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
			while (node->left != TNULL)
			{
				node = node->left;
			}
			return node;
		}

		NodePtr maximum(NodePtr node)
		{
			while (node->right != TNULL)
			{
				node = node->right;
			}
			return node;
		}

		NodePtr successor(NodePtr x)
		{
			if (x->right != TNULL)
			{
				return minimum(x->right);
			}

			NodePtr y = x->parent;
			while (y != TNULL && x == y->right)
			{
				x = y;
				y = y->parent;
			}
			return y;
		}

		NodePtr predecessor(NodePtr x)
		{
			if (x->left != TNULL)
			{
				return maximum(x->left);
			}

			NodePtr y = x->parent;
			while (y != TNULL && x == y->left)
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
			if (y->left != TNULL)
			{
				y->left->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr)
			{
				this->root = y;
			}
			else if (x == x->parent->left)
			{
				x->parent->left = y;
			}
			else
			{
				x->parent->right = y;
			}
			y->left = x;
			x->parent = y;
		}

		void rightRotate(NodePtr x)
		{
			NodePtr y = x->left;
			x->left = y->right;
			if (y->right != TNULL)
			{
				y->right->parent = x;
			}
			y->parent = x->parent;
			if (x->parent == nullptr)
			{
				this->root = y;
			}
			else if (x == x->parent->right)
			{
				x->parent->right = y;
			}
			else
			{
				x->parent->left = y;
			}
			y->right = x;
			x->parent = y;
		}

		// Inserting a node
		void insert(int key)
		{
			//TODO: on pourait avoir un constructor ici pour node tel que Node(key, color, parent, left, right)
			NodePtr node = new Node;
			node->parent = nullptr;
			node->data = key;
			node->left = TNULL;
			node->right = TNULL;
			node->color = RED;
			//TODO: why this initialization?
			NodePtr y = nullptr;
			NodePtr x = this->root;

			while (x != TNULL)
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
			if (y == nullptr)
			{
				root = node;
			}
			else if (node->data < y->data)
			{
				y->left = node;
			}
			else
			{
				y->right = node;
			}

			//*If the new node is a root node, color it black and return (case 2)
			if (node->parent == nullptr)
			{
				node->color = BLACK;
				return;
			}
			
			//*If the grandparent is null, there is nothing to do (case 3)
			if (node->parent->parent == nullptr)
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

int main() {
	
RedBlackTree bst;
bst.insert(55);
bst.insert(40);
bst.insert(65);
bst.insert(60);
bst.insert(75);
bst.insert(57);

bst.printTree();
std::cout << std::endl
	<< "After deleting" << std::endl;
bst.deleteNode(40);
bst.printTree();
}

#endif