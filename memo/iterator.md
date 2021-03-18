3/9

# Random access iterator
- [참고 사이트](http://www.cplusplus.com/reference/iterator/RandomAccessIterator/)
- 포인터처럼 가리키고 있는 임의의 원소에 접근하는데 사용된다.

- 각 컨테이너마다 자신만의 iterator type 을 가지고 있다.
    > iterator 를 통해서 요소에 접근하고 반복한다.


### 모든 random acess iterator 들은 아래 작업을 지원해야함
1. Is default-constructible, copy-constructible, copy-assignable and destructible
    > 기본, 복사 생성자, 복사 대입, 파괴자
        X a;
        X b(a);
        b = a;
2. Can be compared for equivalence using the equality/inequality operators
    (meaningful when both iterator values iterate over the same underlying sequence).	
        a == b
        a != b
3. Can be dereferenced as an rvalue (if in a dereferenceable state).	
        *a
        a->m
4. For mutable iterators (non-constant iterators):
    Can be dereferenced as an lvalue (if in a dereferenceable state).
        *a = t
5. Can be incremented (if in a dereferenceable state).
    The result is either also dereferenceable or a past-the-end iterator.
    Two iterators that compare equal, keep comparing equal after being both increased.
        ++a
        a++
        *a++
6. Can be decremented (if a dereferenceable iterator value precedes it).
        --a
        a--
        *a--
7. Supports the arithmetic operators + and - between an iterator and an integer value, or subtracting an iterator from another.	
        a + n
        n + a
        a - n
        a - b
8. Can be compared with inequality relational operators (<, >, <= and >=).	
        a < b
        a > b
        a <= b
        a >= b
9. Supports compound assignment operations += and -=	
        += n
        a -= n
10. Supports the offset dereference operator ([])
        	a[n]