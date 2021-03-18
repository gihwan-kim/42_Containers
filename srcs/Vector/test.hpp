/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihwan-kim <kgh06079@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:07:53 by gihwan-kim        #+#    #+#             */
/*   Updated: 2021/03/09 10:17:51 by gihwan-kim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class Vector
	{
	public:
/*
** 		===============================
** 		========  Member types ========
** 		===============================
*/
		typedef T value_type;									  // The first template parameter (T)
		typedef Allocator allocator_type;						  // The second template parameter (Alloc)
																		  // defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference;			  // for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference; // for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;				  // for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;	  // for the default allocator: const value_type*

		// typedef typename iterator	a random access iterator to value_type	convertible to const_iterator
		// typedef typename const_iterator	a random access iterator to const value_type
		// typedef typename reverse_iterator	reverse_iterator<iterator>
		// typedef typename const_reverse_iterator	reverse_iterator<const_iterator>

		// typedef typename difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t

/*
** 		===============================
** 		========= CONSTRUCTOR =========
** 		===============================
*/

		/*
		** [ empty container constructor (default constructor) ]
		**	Constructs an empty container, with no elements.
		*/
		explicit Vector(const allocator_type &alloc = allocator_type())
			: _alloc(nullptr), _data(nullptr)
		{
		}

		/*
		** [ fill constructor ]
		** 	Constructs a container with n elements. Each element is a copy of val.
		*/
		explicit Vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(_alloc.allcate(n))
		{
		}
		/*
		** [ range constructor ]
		** 	Constructs a container with as many elements as the range [first,last),
		** 	with each element constructed from its corresponding element in that range,
		** 	in the same order.
		*/
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type());

		/*
		** [ copy constructor ]
		** 	Constructs a container with a copy of each of the elements in x,
		** 	in the same order.
		*/
		Vector(const Vector &x);

		/* destructor */
		// ~Vector();
		// vector &operator=(const vector &x);

		// /* iterator */
		// iterator begin();
		// const_iterator begin() const;
		// iterator end();
		// const_iterator end() const;
		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;
		// reverse_iterator rend();
		// const_reverse_iterator rend() const;

		// /* Capacity */
		// bool empty() const;
		// size_type size() const;
		// size_type max_size() const;
		// size_type capacity() const;
		// void resize(size_type sz);
		// void resize(size_type n, value_type val = value_type());
		// void reserve(size_type n);

		// /* element access */
		// reference operator[](size_type n);
		// const_reference operator[](size_type n) const;
		// const_reference at(size_type n) const;
		// reference at(size_type n);
		// reference front();
		// const_reference front() const;
		// reference back();
		// const_reference back() const;

		// /* modifiers */
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last); // range(1)
		// void assign(size_type n, const value_type &val);	  // fill(2)
		// void push_back(const value_type &val);
		// void pop_back();
		// iterator insert(iterator position, const value_type &val);			// single element (1)
		// void insert(iterator position, size_type n, const value_type &val); // fill (2)
		// template <class InputIterator>
		// void insert(iterator position, InputIterator first, InputIterator last); // range (3)
		// iterator erase(iterator position);
		// iterator erase(iterator first, iterator last);
		// void swap(vector &x);
		// void clear();

		pointer getData()
		{
			return _data;
		}
	private:
		/* data */
		allocator_type _alloc;
		pointer _data;
	};
} // namespace ft
