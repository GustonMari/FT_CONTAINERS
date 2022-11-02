/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rbt.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:16:43 by gmary             #+#    #+#             */
/*   Updated: 2022/11/02 09:38:18 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_RBT_HPP
# define NODE_RBT_HPP

template <class value_type>
struct Node
{
	value_type data;
	Node *parent;
	Node *left;
	Node *right;
	int color;
};

#endif