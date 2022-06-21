/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:35:37 by gmary             #+#    #+#             */
/*   Updated: 2022/06/21 11:04:51 by gmary            ###   ########.fr       */
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
*/


namespace ft
{
	/*
		TODO: faut il faire deux declaration de enable if tel que (https://cplusplus.com/reference/type_traits/enable_if/) ou une seul??
	*/
	
	template <bool B, class T = void> struct enable_if {};
	
	template <class T> struct enable_if<true, T> { typedef T type; };
	
	
}
#endif