/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:10:19 by gmary             #+#    #+#             */
/*   Updated: 2022/10/27 14:25:24 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "_colors.hpp"
#include "utils.hpp"
#include "vector.hpp"
#include "enable_if.hpp"
#include <stack>

std::stack<int> st;


namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		protected:
			Container c;
		
		public:
			typedef typename Container::value_type		value_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
			typedef typename Container::size_type		size_type;
			typedef			 Container					container_type;
			
			// stack() : c() {}
			
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

			~stack (void) {}

			bool empty() const { return c.empty(); }
			
			size_type size() const { return c.size(); }
			
			reference top() { return c.back(); }
			
			const_reference top() const { return c.back(); }
			
			void push (const value_type& val) { c.push_back(val); } void pop() { c.pop_back(); }
			
			template <class T_bis, class Container_bis>
			friend bool operator== (const ft::stack<T_bis,Container_bis>& lhs, const ft::stack<T_bis,Container_bis>& rhs);

			template <class T_bis, class Container_bis>
			friend bool operator< (const ft::stack<T_bis,Container_bis>& lhs, const ft::stack<T_bis,Container_bis>& rhs);

	};

template <class T, class Container>
bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs.c == rhs.c);
}

template <class T, class Container>
bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return !(lhs == rhs);
}

template <class T, class Container>
bool operator<  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs.c < rhs.c);
}

template <class T, class Container>
bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return !(rhs < lhs);
}

template <class T, class Container>
bool operator>  (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (rhs < lhs);
}

template <class T, class Container>
bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return !(lhs < rhs);
}


}

#endif