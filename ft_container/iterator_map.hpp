/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmary <gmary@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:53:55 by gmary             #+#    #+#             */
/*   Updated: 2022/11/02 10:20:35 by gmary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP


//?https://cdmana.com/2021/12/202112300642463009.html

template <class T, class k>
class IteratorMap
{
	public:
		typedef T									value_type;
		typedef k									key_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef const T*							const_pointer;
		typedef const T&							const_reference;
		typedef std::ptrdiff_t						difference_type;
		typedef std::bidirectional_iterator_tag		iterator_category;
		typedef k*									key_pointer;
		key_pointer									node;


		//! ============================ Constructor ============================
		IteratorMap(): node(NULL) {};
		IteratorMap(key_pointer x): node(x) {};
		IteratorMap(const IteratorMap &x): node(x.node) {};
		~IteratorMap() {};
		
		//! ============================ Operators ============================
		
		IteratorMap &operator=(const IteratorMap &x)
		{
			this->node = x.node;
			return (*this);
		}
		
		bool operator==(const IteratorMap &x) const
		{
			return (this->node == x.node);
		}
		
		bool operator!=(const IteratorMap &x) const
		{
			return (this->node != x.node);
		}
		
		reference operator*() const
		{
			return (this->node->data);
		}
		
		pointer operator->() const
		{
			return (&(this->node->data));
		}
		
		//TODO: l'incrementation et l decrementationne sont pas bonnes

		IteratorMap &operator++()
		{
			increment();
			return (*this);
		}
		
		IteratorMap operator++(int)
		{
			IteratorMap tmp(*this);
			increment();
			return (tmp);
		}
		
		IteratorMap &operator--()
		{
			decrement();
			return (*this);
		}
		
		IteratorMap operator--(int)
		{
			IteratorMap tmp(*this);
			decrement();
			return (tmp);
		}
		
		// IteratorMap(T *ptr);
		// IteratorMap(T *ptr, bool is_end);
		// T *getPtr() const;
		// bool getIsEnd() const;
		// void setIsEnd(bool is_end);
	private:
		// T *_ptr;
		// bool _is_end;
		void	increment()
		{
			if (this->node->right != NULL)
			{
				this->node = this->node->right;
				while (this->node->left != NULL)
					this->node = this->node->left;
			}
			else
			{
				Node *tmp = this->node->parent;
				while (tmp != NULL && this->node == tmp->right)
				{
					this->node = tmp;
					tmp = tmp->parent;
				}
				this->node = tmp;
			}
		}

		void	decrement()
		{
			if (this->node->left != NULL)
			{
				this->node = this->node->left;
				while (this->node->right != NULL)
					this->node = this->node->right;
			}
			else
			{
				Node *tmp = this->node->parent;
				while (tmp != NULL && this->node == tmp->left)
				{
					this->node = tmp;
					tmp = tmp->parent;
				}
				this->node = tmp;
			}
		}
};

#endif