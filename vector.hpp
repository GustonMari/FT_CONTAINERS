/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 09:44:08 by gmary             #+#    #+#             */
/*   Updated: 2022/06/16 11:09:19 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#	include <memory>


template <typename T, typename Alloc = std::allocator<T>>
class vector
{
	public:
		typedef T									value_type;
		typedef Alloc								allocator_type;
		typedef allocator_type::reference			reference;
		typedef allocator_type::const_reference		const_reference;
		typedef allocator_type::pointer				pointer;
		typedef allocator_type::const_pointer		const_pointer;
		typedef allocator_type::size_type			size_type; // BUG pas sur que ce soit le même type que size_t
		typedef allocator_type::difference_type		difference_type;
		
		//TODO faire iterator 
		// //!------------------------------CONSTRUCTOR----------------------------------

		// vector<T>::vector()
		// {

		// }

		// vector<T>::vector(const vector& copy)
		// {
		// if (this != &copy)
		// {
		// 	*this = copy;
		// }
		// }

		// //!------------------------------DESTRUCTOR-----------------------------------

		// vector<T>::~vector()
		// {

		// }

		// //!------------------------------OPERATOR-------------------------------------

		// vector<T>	&	vector::operator=(const vector<T> & copy)
		// {
		// if (this != &copy)
		// 	{
		// 	(void)copy;
		// 		return(*this);
		// 	}
		// }

		// //!------------------------------FUNCTION-------------------------------------
	private:
};

#endif