/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:10:30 by gmary             #+#    #+#             */
/*   Updated: 2022/10/24 17:19:22 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_TPP
# define ITERATOR_TRAITS_TPP
# include <cstddef>

/*
**	IteratorTraitshttps://code.woboq.org/gcc/include/c++/7.2.1/bits/stl_iterator_base_types.h.html#std::output_iterator_tag
	-> iterator_tag sont des types vide permetant de stocker des types différents d'itérateurs
	-> struct input_iterator_tag {}; et les tag correspondent a des balises qui permettent 
	de selectionner l'algorithme le plus adequate pour un itérateur
	-> La technique courante de sélection d'algorithme basée sur les balises de catégorie d'itérateur
	consiste à utiliser une fonction de répartiteur (l'alternative est std::enable_if )
	-> les tag correspondent enfaite a des legacy iterator:
		-> legacy_input_iterator : permet de lire depuis l'element pointer
		-> legacy_output_iterator : permet d'ecrire dans l'element pointer (par exemple ostream_iterator)
		-> legacy_forward_iterator : it can be used in multipass algorithm
					it's value_type is the same as the container's,
					so dereferencing (*it) obtains the container's value_type
		-> legacy_bidirectional_iterator : peut etre utiliser dans les deux directions
		-> legacy_random_access_iterator : peut etre utiliser dans les deux directions et
					it's value_type is the same as the container's,
					so dereferencing (*it) obtains the container's value_type
		prtdiff_t : permet de calculer la différence entre deux itérateurs
*/

namespace ft {

	//TODO pas trop compris comment inclure vraiment les legacy iterator
	// struct input_iterator_tag {};
	// struct output_iterator_tag {};
	// struct forward_iterator_tag : public input_iterator_tag {};
	// struct bidirectional_iterator_tag : public forward_iterator_tag {};
	// struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// on passe par des struct car on ne peut pas faire de typedef sur un template direct tel que : typedef std::vector Tableau; // erreur de compilation
	//la classe permet de definir les typedef utiliser plustard lors des specialistation
	template <typename Category, typename Tp, typename Distance = std::ptrdiff_t, typename Pointer = Tp*, typename Reference = Tp&>
	struct iterator
	{
		typedef Category	iterator_category; // lien avec l'iterateur tag
		typedef Tp			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer; //pointeur sur la value type
		typedef Reference	reference; //ref sur la value type
	};
	
	//TODO pas trop compris l'utilite de cette classe 
	template<typename Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};
	
	template<typename Tp>
	struct iterator_traits<Tp*> //permet la specialisation de l'iterateur
	{
		typedef std::random_access_iterator_tag			iterator_category;
		typedef Tp										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef Tp*										pointer;
		typedef Tp&										reference;
	};	

	template<typename Tp>
	struct iterator_traits<const Tp*> //pareille mais en constt
	{
		typedef std::random_access_iterator_tag			iterator_category;
		typedef Tp										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef const Tp*								pointer;
		typedef const Tp&								reference;
	};

	
}

#endif