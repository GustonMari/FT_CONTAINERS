/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_trees.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:16:42 by gmary             #+#    #+#             */
/*   Updated: 2022/10/24 16:39:40 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREES_HPP
# define RED_BLACK_TREES_HPP

namespace ft
{
	struct t_red_black_node {
	int color;
	// enum { red, black } colour;
	void *item;
	struct t_red_black_node *left,
					*right,
					*parent;
	};
}

#endif