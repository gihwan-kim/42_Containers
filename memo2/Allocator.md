- [참고사이트](https://en.cppreference.com/w/cpp/memory/allocator)
- [참고 사이트](http://www.cplusplus.com/reference/memory/allocator/?kw=allocator)

# Allocator 
> 메모리 할당을 관리하는 객체
> 동적 메모리 할당을 통합 관리하는 기능 제공

- 표준 라이브러리에서 사용되는 클래스
- 컨테이너에 메모리를 할당하는 방식을 변경할 수 있다.

- 컨테이너가 메모리를 할당할때마다 Allocator 객체의 allcate () 메서드를 호출

- 메모리를 해제할 때 : deallocate() 메서드 호출


- allocate 와 deallocate 를  operator 'new' 와 operator 'delete' 에 대한 래퍼로 구현해놓은 것

- 컨테이너의 메모리 할당, 해제 방식을 직접 정의하고 싶으면 Allocator 클래스를 작성해주면됨


### std::allocator::allocate

> public member function

```
pointer allocate (size_type n, allocator<void>::const_pointer hint=0);

n : 요소 개수
    sizeof(value_type) 만큼 할당된다.
hint : 0 or value
    0 이 아닐 경우 새로운 블럭을 할당하면서 성능을 향상시키기위해 사용된다.
```

- 초기화 되지 않은 저장 블록 할당
- 템플릿 파라미터 value_type 인 n 개의 멤버 요소를 충분히 포함할 수 있는 size 메모리 만큼 할당한다.

- return
    > 첫번째 요소의 포인터 리턴
    > pointer and const_pointer are member types (defined as aliases of T* and const T* respectively in std::allocator<T>).

- operator new 를 한번이상 사용해서 할당된다.
- throw 'bad_alloc'
    > 요청한 총 용량만큼 할당이 안될경우

### std::allocator<T>::construct

> public member function
```
void construct ( pointer p, const_reference val );

p : 충분한 공간이 할당된 포인터

val : 생성된 요소를 초기화할 값

```
> 객체를 생성한다. (consturct!)



- 요소에대한 공간을 할당하지는 않는다!!!
- 포인터 p 에 이미 할당되어 있어야한다.
    > void construct ( pointer p, const_reference val ); 를 내부적으로 사용해서초기화 한다.
    > 고급 연산자 오버로딩.md 참고
