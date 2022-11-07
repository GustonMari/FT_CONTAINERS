/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:46:38 by gmary             #+#    #+#             */
/*   Updated: 2022/11/07 10:48:07 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// struct Node
namespace ft
{
	template <typename value_type>
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
}