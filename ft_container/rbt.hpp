/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:23:46 by gmary             #+#    #+#             */
/*   Updated: 2022/11/04 14:28:57 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include "utils.hpp"
# include "nullptr.hpp"
# include "node_rbt.hpp"
# include "iterator_map.hpp"
# include <iostream>
# include <string>

/*
	?	https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
	?	https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
	?	https://www.programiz.com/dsa/red-black-tree
	?	https://www.happycoders.eu/algorithms/red-black-tree-java/
	?	https://iq.opengenus.org/red-black-tree-insertion/
*/


// using namespace std;
template <class value_type, class key_compare, class allocator_type>
class RedBlackTree
{
	public:

		//TODO: pas sur du const 

	
		// struct Node
		class Node
		{
			public:
					
				Node(const value_type & new_data): data(new_data), parent(ft::_nullptr), left(ft::_nullptr), right(ft::_nullptr), color(RED)
				{ 
					CCOUT(BGRN, "node constructor 2")
				}
				
				Node(const value_type & new_data, Node * ptr_left, Node * ptr_right): data(new_data), parent(ft::_nullptr), left(ptr_left), right(ptr_right), color(RED)
				{
					CCOUT(BGRN, "node constructor 3 = " << data.first)
					
					// this->data = new_data;
					
					// this->color = color;
					// this->parent = ft::_nullptr;
					// this->left = LEAF_NULL;
					// this->right = LEAF_NULL;
				}
				value_type data;
				Node *parent;
				Node *left;
				Node *right;
				int color;

				typedef value_type 	value_type_data;
		};
	
		typedef Node *NodePtr;
		typedef typename allocator_type::template rebind<Node>::other node_allocator_type; //BUG comment marche reelmend le rebind??
		//TODO: vraiment pas sur pour les const :/

		typedef typename std::allocator<Node>::pointer 							pointer;
		// typedef typename ft::IteratorMap<Node, key_compare> 					iterator;
		// typedef typename ft::IteratorMap<Node, key_compare> 					const_iterator;
		// typedef typename ft::reverse_iterator<iterator> 						reverse_iterator;
		// typedef typename ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		// typedef typename ft::IteratorMap<value_type, key_compare>			*iterator;
		// typedef typename ft::IteratorMap<const value_type, key_compare>		*const_iterator;
		// typedef	typename ft::reverse_iterator<iterator>						*reverse_iterator;
		// typedef	typename ft::reverse_iterator<const_iterator>				*const_reverse_iterator;		
		typedef typename ft::IteratorMap<Node, key_compare>						iterator;
		// typedef typename ft::IteratorMap<Node, key_compare>						const_iterator;
		// typedef	typename ft::reverse_iterator<iterator>							reverse_iterator;
		// typedef	typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename std::size_t										size_type;
		typedef typename std::ptrdiff_t										difference_type;
		

	private:
		//!Utils variables
		key_compare m_comp;
		node_allocator_type m_alloc;
		NodePtr m_root;
		// NodePtr m_nil;

	public:

		
		//!	Constructors and destructor
		NodePtr root;
		NodePtr LEAF_NULL;

		RedBlackTree()
		{
			//TODO: need to instantiate _alloc so need to replace the new
			m_alloc = allocator_type();
			m_comp = key_compare();
			// LEAF_NULL = m_alloc.allocate(sizeof(Node));
			LEAF_NULL = m_alloc.allocate(1);
			m_alloc.construct(LEAF_NULL, Node(value_type()));
			// LEAF_NULL = new Node;
			
			LEAF_NULL->color = BLACK;
			LEAF_NULL->left = ft::_nullptr;
			LEAF_NULL->right = ft::_nullptr;
			root = LEAF_NULL;
		};

		// RedBlackTree(): root(ft::_nullptr), m_comp(key_compare), m_alloc(allocator_type)
		// {
		// 	//TODO: need to instantiate _alloc
		// }

		// RedBlackTree(const RedBlackTree &x)
		// {
		// 	*this = x;
		// }

		~RedBlackTree()
		{
			clear(root);
			m_alloc.destroy(LEAF_NULL);
			m_alloc.deallocate(LEAF_NULL, sizeof(Node));
		}


		// //!Operators
		RedBlackTree &operator=(const RedBlackTree &x)
		{
			if (this != &x)
			{
				m_root = x.m_root;
				m_comp = x.m_comp;
				m_alloc = x.m_alloc;
			}
			return (*this);
		}

		// void operator*(void)
		// {
		// 	std::cout << "operator*" << std::endl;
		// }

		//!================================Functions================================
		
		iterator begin()
		{
			return (iterator(minimum(root)));
		}

		// const_iterator begin() const
		// {
		// 	return (const_iterator(minimum(root)));
		// }
	
		iterator end()
		{
			//BUG: vraiment pas sur du ++
			iterator it = iterator(maximum(root));
			it++;
			return (it);
			// return (iterator(LEAF_NULL));
		}

		// const_iterator end() const
		// {
		// 	//BUG: vraiment pas sur du ++
		// 	const_iterator it = const_iterator(maximum(root));
		// 	it++;
		// 	return (it);
		// 	// return (const_iterator(LEAF_NULL));
		// }

		// reverse_iterator rbegin()
		// {
		// 	return (reverse_iterator(maximum(root)));
		// }

		// const_reverse_iterator rbegin() const
		// {
		// 	return (const_reverse_iterator(maximum(root)));
		// }

		// reverse_iterator rend()
		// {
		// 	//BUG: vraiment pas sur du ++
		// 	reverse_iterator it = reverse_iterator(minimum(root));
		// 	//BUG: doit on faire -- ducoup ??
		// 	it++;
		// 	return (it);
		// 	// return (reverse_iterator(LEAF_NULL));
		// }

		// const_reverse_iterator rend() const
		// {
		// 	//BUG: vraiment pas sur du ++
		// 	const_reverse_iterator it = const_reverse_iterator(minimum(root));
		// 	//BUG: doit on faire -- ducoup ??
		// 	it++;
		// 	return (it);
		// 	// return (const_reverse_iterator(LEAF_NULL));
		// }

		bool empty() const
		{
			return (root == LEAF_NULL);
		}

		// size_type size() const
		// {
		// 	return (size(root));
		// }

		size_type count(const value_type &k) const
		{
			//voir si ca boucle pas inf
			return (searchCase(root, k));
		}

		void	delete_tree()
		{
			clear(root);
			m_alloc.destroy(LEAF_NULL);
			m_alloc.deallocate(LEAF_NULL, sizeof(Node));
		}

	private:
		//!Utils functions
		// NodePtr root;
		// NodePtr LEAF_NULL;


		void	clear(NodePtr node)
		{
			if (node == LEAF_NULL)
				return ; 
		
			clear(node->left); 
			clear(node->right); 
		
			m_alloc.destroy(node);
			m_alloc.deallocate(node, 1);
		}

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

		size_type searchCase(NodePtr node, value_type key)
		{
			if (key == node->data)
			{
				return 1;
			}
			if (node == LEAF_NULL)
				return 0;

			if (key < node->data)
			{
				return searchTreeHelper(node->left, key);
			}
			return searchTreeHelper(node->right, key);
		}

		NodePtr searchTreeHelper(NodePtr node, value_type key)
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
		//TODO: replace int with value_type juste en dessous ??
		void deleteNodeHelper(NodePtr node, value_type key)
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
			m_alloc.destroy(z);
			m_alloc.deallocate(z, sizeof(Node));
			// delete z;
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

				// std::string sColor = root->color ? "RED" : "BLACK";
				// std::cout << root->data << "(" << sColor << ")" << std::endl;
				if (root->color == RED)
				{
					std::cout << BRED << root->data << "(" << "RED" << ")" << CRESET<< std::endl;
				}
				else
				{
					std::cout << BBLU << root->data << "(" << "BLACK" << ")" << CRESET << std::endl;
				}
				printHelper(root->left, indent, false);
				printHelper(root->right, indent, true);
			}
		}

		public:
		// RedBlackTree()
		// {
		// 	LEAF_NULL = new Node;
		// 	LEAF_NULL->color = BLACK;
		// 	LEAF_NULL->left = ft::_nullptr;
		// 	LEAF_NULL->right = ft::_nullptr;
		// 	root = LEAF_NULL;
		// }

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

		//!========================================= Inserting a node =======================================================================
		//* we always insert a node as a red node, and then we fix the tree, because red nodes does not violate the red-black tree properties
		//* If you attach a red node to a red node, then the rule is violated but it is easier to fix this problem than the problem introduced by violating the depth property.
		
		//TODO: need to change int for the key to value_type??
		// value_type insert(value_type key)
		pointer insert(value_type key)
		{
			//TODO: on pourait avoir un constructor ici pour node tel que Node(key, color, parent, left, right)
			// NodePtr node = new Node;
			NodePtr node = m_alloc.allocate(1);
			m_alloc.construct(node, Node(key, LEAF_NULL, LEAF_NULL));
			// node->parent = ft::_nullptr;
			// node->data = key;
			// node->left = LEAF_NULL;
			// node->right = LEAF_NULL;
			// node->color = RED;
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
			
			
			// iterator(node);
			// ft::pair<iterator, bool> ret = ft::make_pair(iterator, true);
			// ft::pair<iterator, bool> ret = ft::make_pair(iterator(node), true);
			// iterator ret = iterator(node);
			// CCOUT(BYEL, ret)
			// ft::pair<iterator::value_type, bool> ret = ft::make_pair(iterator(node), true);
			// CCOUT(BYEL,"a = " << ret.first << " b = " << ret.second);
			// CCOUT(BMAG, *(ret.first) );
			// return ft::make_pair<iterator, bool>(iterator(node), true);
				// return (ft::make_pair(iterator(node), true));
				// return (node->data);
				return (node);
				// return;
			}
			
			//*If the grandparent is null, there is nothing to do (case 3)
			if (node->parent->parent == ft::_nullptr)
			{
				return (node);
				// return (ft::make_pair(iterator(node), true));
				// return (ft::make_pair(iterator(node), true));
				// return (node->data);
				// return;
			}

			//*Recalibrate the tree after insertion
			insertFix(node);
				// return (ft::make_pair(iterator(node), true));
			return (node);
		}

		// void insert(int key)
		// {
		// 	//TODO: on pourait avoir un constructor ici pour node tel que Node(key, color, parent, left, right)
		// 	NodePtr node = new Node;
		// 	node->parent = ft::_nullptr;
		// 	node->data = key;
		// 	node->left = LEAF_NULL;
		// 	node->right = LEAF_NULL;
		// 	node->color = RED;
		// 	NodePtr y = ft::_nullptr;
		// 	NodePtr x = this->root;

		// 	while (x != LEAF_NULL)
		// 	{
		// 		y = x;
		// 		//*Move depending on the value of the data
		// 		if (node->data < x->data)
		// 		{
		// 			//*If the data is smaller than the current node, go left
		// 			x = x->left;
		// 		}
		// 		else
		// 		{
		// 			//*If the data is bigger than the current node, go right
		// 			x = x->right;
		// 		}
		// 	}

		// 	//*inserting the new node
		// 	node->parent = y;
		// 	//*If the tree is empty, the new node is the root (case 1)
		// 	if (y == ft::_nullptr)
		// 	{
		// 		root = node;
		// 	}
		// 	//* place node to left of right of y depending on the value of the data
		// 	else if (node->data < y->data)
		// 	{
		// 		y->left = node;
		// 	}
		// 	else
		// 	{
		// 		y->right = node;
		// 	}

		// 	//*If the new node is a root node, color it black and return (case 2)
		// 	if (node->parent == ft::_nullptr)
		// 	{
		// 		node->color = BLACK;
		// 		return;
		// 	}
			
		// 	//*If the grandparent is null, there is nothing to do (case 3)
		// 	if (node->parent->parent == ft::_nullptr)
		// 	{
		// 		return;
		// 	}

		// 	//*Recalibrate the tree after insertion
		// 	insertFix(node);
		// }

		NodePtr getRoot()
		{
			return this->root;
		}

		void deleteNode(value_type data)
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