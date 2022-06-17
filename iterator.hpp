/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:17:13 by gmary             #+#    #+#             */
/*   Updated: 2022/06/17 14:01:45 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Depuis c++11 tout constructeur sans explicit est un constructeur de conversion
*/

#include "iterator_traits.hpp"

namespace ft {

	template <typename Iterator>
	class random_access_iterator : public iterator_traits<Iterator>
	{
		protected:
			Iterator						current;
			typedef	ft::iterator_traits		traits_type;
		public:
			//TODO need to add some shit here
			//!--------------------------------CONSTRUCTOR------------------------------------------------------
			random_access_iterator() : current() {}
			explicit random_access_iterator(Iterator it) : current(it) {} // [ ] pq avoir proteger le constructeur de tte conversion
			random_access_iterator(const random_access_iterator<Iterator>& it) : current(it.current) {}
			//operator
	};
	
};