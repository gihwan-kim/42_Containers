
```
template<
    class T,
    class Allocator = std::allocator<T>
> class vector;
```

- Allocator 매개변수
    > 메모리 할당 방식을 정하고 싶을 경우



### 고정크기 Vector
- 생성자에서 vector 의 크기를 지정

- operator[] 에서 vector 의 범위를 벗어난 원소에 접근할 경우 undefined behavior


### 생성자

```
default (1)	explicit vector (const allocator_type& alloc = allocator_type());
fill (2)	explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type());
range (3)	template <class InputIterator>
                        vector (InputIterator first, InputIterator last,
                        const allocator_type& alloc = allocator_type());
copy (4)	vector (const vector& x);
```
- 디폴트 생성자 : 원수 개수가 0 인 vector
- fill          : 개수만큼 해당 값을 채울 수 있음



### vector 의 복사, 대입
- vector 는 객체의 복사본을 저장한다. => 깊은 복사
- vector 의 소멸자는 원소 객체의 소멸자를 호출한다.



### Member types
> Memeber types ?

- typedef 또는 using 을 사용해서 사용자 정의 타입을 만듬
- 중첩된 타입일 경우
- 해당 class 의 범위 안에 속하기 때문에 '::' 를 사용해서 scope 범위 순서에 맞게 접근해줘야함
