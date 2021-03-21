/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihwan-kim <kgh06079@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:07:53 by gihwan-kim        #+#    #+#             */
/*   Updated: 2021/03/19 00:15:12 by gihwan-kim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/iterator.hpp"
#include <memory>

namespace ft
{
	template <class T>
	class random_iterator_vector
	{
	public:
/*
** 		===============================
** 		========  Member types ========
** 		===============================
*/
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;


		/* Is default-constructible, copy-constructible, copy-assignable and destructible */
		random_iterator_vector();
		random_iterator_vector(random_iterator_vector &_object);
		random_iterator_vector &operator=(random_iterator_vector &_object);
		~random_iterator_vector();

		/* Can be compared for equivalence using the equality/inequality operators */
		bool	operator==(random_iterator_vector &_object);
		bool	operator!=(random_iterator_vector &_object);

		const reference		operator*() { return (*m_iter); }
		reference			operator*() { return (*m_iter); }
		reference			operator->() { return (m_iter); }
		const reference		operator->() { return (m_iter); }

		random_iterator_vector	operator++(int) { m_iter++; return (*this); } 	// ++i
		random_iterator_vector	&operator++()									// i++
		{
			random_iterator_vector oldVecIter(*this);
			m_iter++;
			return (*this);
		}
		random_iterator_vector	operator--(int) { m_iter--; return (*this); }
		random_iterator_vector	&operator--()
		{
			random_iterator_vector	tmp = *this;
			m_iter--;
			return (*this);
		}

	private:
		/* data */
		pointer	m_iter;
	};

	template <class T, class Allocator = std::allocator<T>>
	class Vector
	{
	public:

/*
** 		===============================
** 		========  Member types ========
** 		===============================
*/
		typedef T	value_type;											  // The first template parameter (T)
		typedef Allocator allocator_type;								  // The second template parameter (Alloc)
																		  // defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference;			  // for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference; // for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;				  // for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;	  // for the default allocator: const value_type*

		typedef random_iterator_vector<value_type> iterator;
		typedef random_iterator_vector<value_type> const_iterator;
		// typedef typename const_iterator	a random access iterator to const value_type
		// typedef typename reverse_iterator	reverse_iterator<iterator>
		// typedef typename const_reverse_iterator	reverse_iterator<const_iterator>

		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;	// a signed integral type, identical to: 	usually the same as ptrdiff_t
		typedef size_t size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t


	private:
		/* data */
		allocator_type m_alloc;
		pointer m_data;
		pointer m_start;
		pointer m_end;
		pointer m_end_of_storage;

	protected:
		// allocate : throw bad_alloc 처리 해줘야함
		template <class Size, class T1>
		void fill_initialize(Size n, const T1 &x)
		{
			// allocate memory
			m_data = m_alloc.allocate(n);
			for (n--)
			{
				// construct object
				m_alloc.construct(ptr, x);
			}
		}

		template <class Size, class InputIterator>
		void range_initialize(Size n, InputIterator first)
		{
			// allocate memory
			m_data = m_alloc.allocate(n);
			for (n--)
			{
				// construct object
				m_alloc.construct(ptr, *first);
				first++;
			}
		}

		void copy_initialize(const Vector &x)
		{
			insert(this->begin(), x.begin(), x.end());
		}


	public:
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
			: m_alloc(alloc), m_data(nullptr)
		{}

		/*
		** [ fill constructor ]
		** 	Constructs a container with n elements. Each element is a copy of val.
		**  n : 
		*/
		explicit Vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: m_alloc(alloc), m_data(this->m_alloc.allcate(n))
		{
			fill_initialize(n, val);
		}

		/*
		** [ range constructor ]
		** 	Constructs a container with as many elements as the range [first,last),
		** 	with each element constructed from its corresponding element in that range,
		** 	in the same order.
		*/
		template <class InputIterator>
		Vector(InputIterator first, InputIterator last,
			   const allocator_type &alloc = allocator_type())
		{
			difference_type n = ft::distance(first, last);
			range_initialize(n, first);
		}

		/*
		** [ copy constructor ]
		** 	Constructs a container with a copy of each of the elements in x,
		** 	in the same order.
		*/
		Vector(const Vector &x)
		{
			copy_initialize(x);
		}

		/* destructor */
		~Vector();
		// vector &operator=(const vector &x);
/*
** 		===============================
** 		========= ITERATOR =========
** 		===============================
*/
		iterator begin() { return (iteratr(this->m_start)); }
		const_iterator begin() const { return (const_iterator(this->m_start)); }

		iterator end() { return (iterator(this->m_end)); }
		const_iterator end() const { return (const_iterator(this->m_end)); }

		reverse_iterator rbegin() { return (reverse_iterator(this->m_end)); }
		const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->m_end)); }
		
		reverse_iterator rend() { return (reverse_iterator(this->m_start)); }
		const_reverse_iterator rend() const {  return (reverse_iterator(this->m_start)); }


/*
** 		===============================
** 		========= CAPACITY =========
** 		===============================
*/

		bool empty() const
		{

		}
		
		size_type size() const
		{

		}
		
		size_type max_size() const
		{

		}
		
		size_type capacity() const
		{

		}
		
		void resize(size_type sz)
		{

		}
		
		void resize(size_type n, value_type val = value_type())
		{

		}
		
		void reserve(size_type n)
		{

		}
		

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

		// pointer getData()
		// {
		// 	return m_data;
		// }

	};
} // namespace ft
