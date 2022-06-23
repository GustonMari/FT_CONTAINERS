/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:31:43 by gmary             #+#    #+#             */
/*   Updated: 2022/06/23 16:19:34 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	integral_constant is designed to provide compile-time constants as types.

	noexcept dit si une exception est générée par une fonction elle peut prendre un bolleen tel que:
		noexcept(true) ou encore noexcept(std::fonction<T>)
	Marquez une fonction comme noexcept uniquement si toutes les fonctions qu’elle appelle,
	 directement ou indirectement, sont également noexcept ou const
	
	la difference entre constexpr et const est que constexpr est défini dans le contexte de compilation
	cest a dire que :
	const     double PI1 = 3.141592653589793;
	constexpr double PI2 = 3.141592653589793;
	constexpr double PI3 = PI1;  // error
	constexpr double PI3 = PI2;  // ok
	static_assert(PI1 == 3.141592653589793, "");  // error
	static_assert(PI2 == 3.141592653589793, "");  // ok

	int sz;
	constexpr auto arraySize1 = sz;    // error! sz's value unknown at compilation
	std::array<int, sz> data1;         // error! same problem
	constexpr auto arraySize2 = 10;    // fine, 10 is a compile-time constant
	std::array<int, arraySize2> data2; // fine, arraySize2 is constexpr

	compiler will execute that function by itself at compile time & substitute the result with function.
	Mostly this matters when initialization at runtime would be time-consuming
	and you want to push that work off onto the compiler, 
	where it's also time-consuming, but doesn't slow down execution time of the compiled program
	https://stackoverflow.com/questions/29469225/how-to-use-c11-integral-constantvalue-type
*/


#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{
	template <typename Tp, Tp v>
	struct integral_constant
	{
		static const Tp					value = v;
		typedef Tp							value_type;
		typedef integral_constant<Tp, v>	type;
		value_type operator() (void) const { return value; } //BUG : compile error why ??
		operator value_type() const { return value; } //BUG pas compris ca
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