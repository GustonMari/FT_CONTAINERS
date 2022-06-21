/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:31:43 by gmary             #+#    #+#             */
/*   Updated: 2022/06/21 10:31:14 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	integral_constant is designed to provide compile-time constants as types.
*/


#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <typename Tp, Tp v>
	struct integral_constant
	{
		static constexpr Tp					value = v;
		typedef Tp							value_type;
		typedef integral_constant<Tp, v>	type;
		constexpr operator value_type() const noexcept { return value; }
	};
	
	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <class T> struct is_integral: public false_type {};
	template <> struct is_integral<bool>: public true_type {};
	template <> struct is_integral<char>: public true_type {};
	template <> struct is_integral<signed char>: public true_type {};
	template <> struct is_integral<unsigned char>: public true_type {};
	template <> struct is_integral<wchar_t>: public true_type {};
	template <> struct is_integral<short>: public true_type {};
	template <> struct is_integral<unsigned short>: public true_type {};
	template <> struct is_integral<int>: public true_type {};
	template <> struct is_integral<unsigned int>: public true_type {};
	template <> struct is_integral<long>: public true_type {};
	template <> struct is_integral<unsigned long>: public true_type {};
	template <> struct is_integral<long long>: public true_type {};
	template <> struct is_integral<unsigned long long>: public true_type {};
	template <> struct is_integral<float>: public true_type {};
	template <> struct is_integral<double>: public true_type {};
	template <> struct is_integral<long double>: public true_type {};
	template <> struct is_integral<void>: public true_type {};
	
	
}

#endif