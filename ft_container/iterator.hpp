// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   iterator.hpp                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/06/17 11:17:13 by gmary             #+#    #+#             */
// /*   Updated: 2022/06/20 10:58:38 by gmary            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// /*
// 	Depuis c++11 tout constructeur sans explicit est un constructeur de conversion
// */

// #include "iterator_traits.hpp"


// namespace ft {

// 	template <typename Iterator>
// 	class random_access_iterator : public iterator_traits<Iterator>
// 	{
// 		protected:
// 			Iterator								current;
// 			typedef	ft::iterator_traits<Iterator>	traits_type;
// 		public:
// 			//TODO need to add some shit here
// 			//!--------------------------------CONSTRUCTOR------------------------------------------------------
// 			random_access_iterator() : current() {}
// 			explicit random_access_iterator(Iterator it) : current(it) {} // [ ] pq avoir proteger le constructeur de tte conversion
// 			random_access_iterator(const random_access_iterator<Iterator>& it) : current(it.current) {}
// 			//!--------------------------------OPERATOR------------------------------------------------------

// 			random_access_iterator& operator=(const random_access_iterator<Iterator>& it)
// 			{
// 				// TODO: need to protect this
// 				current = it.current;
// 				return (*this);
// 			}

// 			random_access_iterator& operator++()
// 			{
// 				++current;
// 				return (*this);
// 			}

// 			random_access_iterator& operator--()
// 			{
// 				--current;
// 				return (*this);
// 			}

// 			/*
// 			difference type is equivalent of ptdrdiff_t, we now know that it is signed
// 			and that it belongs to the same container
// 			*/
		
// 			random_access_iterator& operator+=(difference_type n)
// 			{
// 				current += n;
// 				return (*this);
// 			}

// 			random_access_iterator& operator-=(difference_type n)
// 			{
// 				current -= n;
// 				return (*this);
// 			}

// 			random_access_iterator operator+(difference_type n) const
// 			{
// 				return (random_access_iterator(current + n));
// 			}

// 			random_access_iterator operator-(difference_type n) const
// 			{
// 				return (random_access_iterator(current - n));
// 			}
			

// 			/*
// 				BUG to check 
// 			*/
// 			random_access_iterator operator+(const random_access_iterator<Iterator>& it) const
// 			{
// 				return (random_access_iterator(current + it.current));
// 			}

// 			random_access_iterator operator-(const random_access_iterator<Iterator>& it) const
// 			{
// 				return (random_access_iterator(current - it.current));
// 			}

// 			random_access_iterator operator==(const random_access_iterator<Iterator>& it) const
// 			{
// 				return (current == it.current);
// 			}
// 			//!--------------------------------FUNCTION------------------------------------------------------
// 			//faire fucntion pour retourner l'iterator type ??
// 			//operator
// 	};
	
// };