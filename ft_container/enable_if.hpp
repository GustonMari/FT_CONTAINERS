/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:35:37 by gmary             #+#    #+#             */
/*   Updated: 2022/11/28 14:06:15 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

/*
	If B is true, std::enable_if has a public member typedef type, equal to T;
	otherwise, there is no member typedef. it it used for SFINAE ("Substitution Failure Is Not An Error")
	la fonction permet de pour retirer conditionnellement des fonctions de l'ensemble des candidats 
	en fonction des traits de type, permettant des surcharges de fonctions distinctes 
	ou des spécialisations basées sur ces différents traits de type.
	TODO: FINIR DE LIRE LE LINK EN DESSOUS
	TOP:
		https://riptutorial.com/cplusplus/example/3777/enable-if
		https://h-deb.clg.qc.ca/Sujets/TrucsScouts/Comprendre_enable_if.html
*/


namespace ft
{
	
	template <bool B, class T = void>
	struct enable_if {};
	
	template <class T>
	struct enable_if<true, T> 
	{
		typedef T type;
	};
	
}
#endif