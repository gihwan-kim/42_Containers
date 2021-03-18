/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihwan-kim <kgh06079@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:22:55 by gihwan-kim        #+#    #+#             */
/*   Updated: 2021/03/18 22:00:36 by gihwan-kim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

namespace ft
{

	/*
**  ===============================
**  ========  ft::iterator ========
**  ===============================
**  base class template
**      요청하는 타입에 대한 iterator 에 제공되는 base class
**      iterator class 가 아님, 기능적으로 iterator 가 가져야할 어떤것도 제공하지 않음
*/
	template <class Category,			  // iterator::iterator_category
			  class T,					  // iterator::value_type
			  class Distance = ptrdiff_t, // iterator::difference_type	ptrdiff_t : 부호가 있는 Interger type 에 대한 allias(별칭)
			  class Pointer = T *,		  // iterator::pointer
			  class Reference = T &		  // iterator::reference
			  >
	class iterator
	{
	private:
		/* data */
	public:
		typedef Distance difference_type; // iterator 를 다른 iterator 에 뺀 결과를 표현할 타입
		typedef T value_type;			  // iterator 가 가리킬 수 있는 타입
		typedef T *pointer;				  // iterator 가 가리킬 수 있는 타입의 포인터
		typedef T &reference;			  // iterator 가 가리킬 수 있는 타입의 레퍼런스
		typedef Category iterator_category;
	};

	// iterator category
	struct input_iterator_tag
	{
	};
	struct output_iterator_tag
	{
	};
	struct forward_iterator_tag
	{
	};
	struct bidirectional_iterator_tag
	{
	};
	struct random_access_iterator_tag
	{
	};

	template <class Iterator>
	struct iterator_traits
	{
	public:
		typedef typename Iterator::difference_type difference_type;		// iterator 를 다른 iterator 에 뺀 결과를 표현할 타입
		typedef typename Iterator::value_type value_type;				// iterator 가 가리킬 수 있는 타입
		typedef typename Iterator::pointer pointer;						// iterator 가 가리킬 수 있는 타입의 포인터
		typedef typename Iterator::reference reference;					// iterator 가 가리킬 수 있는 타입의 레퍼런스
		typedef typename Iterator::iterator_category iterator_category; // iterator 종류
	};

	template <class T>
	struct iterator_traits<T *>
	{
	public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
	public:
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef ft::random_access_iterator_tag iterator_category;
	};

/*
** Iterator operations:
** 	advance 	Advance iterator (function template )			[ 구현 끝 ]
** 	distance	Return distance between iterators (function template )
** 	begin 		Iterator to beginning (function template )
** 	end 		Iterator to end (function template )
** 	prev		Get iterator to previous element (function template )
** 	next		Get iterator to next element (function template )
** 
*/
	// iterator 간의 길이 구하는 함수(차이)
	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type
	distance(InputIterator first, InputIterator last)
	{
		typename ft::iterator_traits<InputIterator>::difference_type ret_distance = 0;
		for (first != last)
		{
			ret_distance++
			first++;;
		}
		return (ret_distance);
	}



	// original iterator 의 복사본이 내부적으로 유지됨
	// 정방향 iterator 와 반대로 동작한다.
	// iterator.
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer pointer;
		typedef typename ft::iterator_traits<Iterator>::reference reference;

	protected:
		/* data */

		// 바탕이 되는 iterator 의 base() 멤버함수 리턴 값
		// Iterator.base()
		iterator_type data;

	public:
		/*            [reverse_iterator]
** 		===============================
** 		========= CONSTRUCTOR =========
** 		===============================
*/
		// [ Default constructor ]
		reverse_iterator() {}

		// explicit : 암시적 형변환 허용 x
		// iter 로 부터 reverse iterator 를 생성한다.
		explicit reverse_iterator(iterator_type iter)
			: data(iter)
		{
		}

		// [ copy constructor ]
		reverse_iterator(const reverse_iterator<Iterator> &rev_it)
			: data(rev_it.base())
		{
		}

		~reverse_iterator();

		/*            [reverse_iterator]
** 		===============================
** 		========== OPERATOR ===========
** 		===============================
*/

		reverse_iterator &operator=(const reverse_iterator &other)
		{
			this->data = other.data;
			return (*this);
		}

		// base iterator 를 리턴
		iterator_type base() const { return (this->data); }

		// data 이전의 element 에 대한 reference 를 return
		reference operator*() const
		{
			iterator_type tmp = this->data;
			return (*(--tmp));
		}

		pointer operator->() const { return &(operator*()); }

		reverse_iterator operator+(difference_type n) const
		{
			this->data -= n;
			return (reverse_iterator(base()));
		}

		reverse_iterator operator-(difference_type n) const
		{
			this->data += n;
			return (reverse_iterator(base()));
		}

		// 전위 : void (연산한 자신을 리턴)
		// 후위 : int (연산하기 전의 복사본을 리턴)
		reverse_iterator &operator++()
		{
			this->data--;
			return (*this);
		}

		reverse_iterator &operator--()
		{
			this->data++;
			return (*this);
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator tmp = *this;
			this->data--;
			return (tmp);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator tmp = *this;
			this->data++;
			return (tmp);
		}

		reverse_iterator &operator+=(difference_type n)
		{
			this->data -= n;
			return (*this);
		}

		reverse_iterator &operator-=(difference_type n)
		{
			this->data += n;
			return (*this);
		}

		reference operator[](difference_type n) const
		{
			return (base()[n - 1]);
		}
	};

	/*            [reverse_iterator]
** 		===============================
** 		========= Non-member ==========
** 		===============================
*/

	// underlying iterator (this.data) 를 비교한다.
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return (lhs.base() == rhs.base()); }
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return (lhs.base() != rhs.base()); }
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) { return (lhs.base() < rhs.base()); }
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return (lhs.base() <= rhs.base()); }
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator> &lhs,
				   const reverse_iterator<Iterator> &rhs) { return (lhs.base() > rhs.base()); }
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator> &lhs,
					const reverse_iterator<Iterator> &rhs) { return (lhs.base() >= rhs.base()); }

	// rev_it 에서 n 위치를 가리키는 reverse iterator 를 리턴한다.
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
										 const reverse_iterator<Iterator> &rev_it) { return (rev_it + n); }

	// reverse_iterator 간의 거리
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &lhs,
		const reverse_iterator<Iterator> &rhs) { return (rhs.base() - lhs.base()); }
} // namespace ft