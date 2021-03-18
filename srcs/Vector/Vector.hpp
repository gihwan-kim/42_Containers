/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihwan-kim <kgh06079@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:07:53 by gihwan-kim        #+#    #+#             */
/*   Updated: 2021/03/18 21:52:58 by gihwan-kim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <memory>

namespace ft
{
	template <class T>
	class RandomVectorIterator
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
		RandomVectorIterator();
		RandomVectorIterator(RandomVectorIterator &_object);
		RandomVectorIterator &operator=(RandomVectorIterator &_object);
		~RandomVectorIterator();

		/* Can be compared for equivalence using the equality/inequality operators */
		bool	operator==(RandomVectorIterator &_object);
		bool	operator!=(RandomVectorIterator &_object);

		const reference		operator*() { return (*iter); }
		reference			operator*() { return (*iter); }
		reference			operator->() { return (iter); }
		const reference		operator->() { return (iter); }

		RandomVectorIterator	operator++(int) { iter++; return (*this); } // ++i
		RandomVectorIterator	&operator++()
		{
			RandomVectorIterator oldVecIter(*this);
			iter++; return (*this);
		}	// i++
		RandomVectorIterator	operator--(int)
		{
			
		}
		RandomVectorIterator	&operator--();

		/* incremented */

	private:
		/* data */
		pointer	iter;
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
		typedef T value_type;											  // The first template parameter (T)
		typedef Allocator allocator_type;								  // The second template parameter (Alloc)
																		  // defaults to: allocator<value_type>
		typedef typename allocator_type::reference reference;			  // for the default allocator: value_type&
		typedef typename allocator_type::const_reference const_reference; // for the default allocator: const value_type&
		typedef typename allocator_type::pointer pointer;				  // for the default allocator: value_type*
		typedef typename allocator_type::const_pointer const_pointer;	  // for the default allocator: const value_type*

		// typedef typename iterator	a random access iterator to value_type	convertible to const_iterator
		typedef RandomVectorIterator<value_type> iterator;
		// typedef typename const_iterator	a random access iterator to const value_type
		// typedef typename reverse_iterator	reverse_iterator<iterator>
		// typedef typename const_reverse_iterator	reverse_iterator<const_iterator>

		// typedef typename difference_type	a signed integral type, identical to: iterator_traits<iterator>::difference_type	usually the same as ptrdiff_t
		typedef size_t size_type; //	an unsigned integral type that can represent any non-negative value of difference_type	usually the same as size_t


	private:
		/* data */
		allocator_type _alloc;
		pointer _data;

	protected:
		// allocate : throw bad_alloc 처리 해줘야함
		template <class Size, class T1>
		void fill_initialize(Size n, const T1 &x)
		{
			for ()
			{
				// allocate memory
				_data = std::allocator::allocate(n);
				// construct object
				std::allocator::construct(ptr, x);

			}
		}
    // new (static_cast<void*>(&*first))
    //   typename iterator_traits<ForwardIterator>::value_type(x);
    // new (static_cast<void*>(&*result))
    //   typename iterator_traits<ForwardIterator>::value_type(*first);
		template <class InputIterator, class Size, class T1>
		void range_initialize(InputIterator first, InputIterator last)
		{
			// allocate memory
			const size_type	n = ft::distance(first, last);
			pointer	tmp = _data;
			while (first != last)
			{
				// construct object
				_data = std::allocator::allocate(n);
				std::allocator::construct(tmp, *first);
				tmp++;
			}
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
			: _alloc(alloc), _data(nullptr)
		{}

		/*
		** [ fill constructor ]
		** 	Constructs a container with n elements. Each element is a copy of val.
		**  n : 
		*/
		explicit Vector(size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _data(_alloc.allcate(n))
		{
			initialize(n, val);
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
			initialize(first, last, alloc);
		}

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

		// pointer getData()
		// {
		// 	return _data;
		// }

	};
} // namespace ft
