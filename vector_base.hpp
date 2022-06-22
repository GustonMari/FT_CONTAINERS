/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_base.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:11:59 by gmary             #+#    #+#             */
/*   Updated: 2022/06/22 14:15:53 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BASE_HPP
# define VECTOR_BASE_HPP

template <typename Tp, typename Allocator = std::allocator<Tp>>
class vector_base
{
	public:
		vector_base();
		vector_base(const vector_base & copy);

		~vector_base();

		vector_base & operator=(const vector_base & copy);
	private:
};

#endif