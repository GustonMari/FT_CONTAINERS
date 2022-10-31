/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:59:56 by gmary             #+#    #+#             */
/*   Updated: 2022/10/31 13:13:51 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NULLPTR_HPP
# define NULLPTR_HPP

//*this is a const object

namespace ft
{
	const class nullptr_t
	{
		public:
		
			//* convertible to any type of null non-member pointer
			template<class T>
			operator T*() const { return 0; }
			
			//* or any type of null member pointer
			template<class C, class T>
			operator T C::*() const { return 0; }

			friend bool operator==(nullptr_t, nullptr_t) { return true; }
			
			friend bool operator!=(nullptr_t, nullptr_t) { return false; }
			
		private:
			void operator&() const;
	} _nullptr = {};
}
#endif