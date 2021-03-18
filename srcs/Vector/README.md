
# 구현순서
- [참고 사이트](http://www.cplusplus.com/reference/stl/)
1. 생성자 소멸자
2. 각 컨테이너 타입에 맞는 메소드 구성
3. 기본 메소드 구성
4. member type 만들기
    > C++ 표준 라이브러리 컨테이너가 필수로 가져야하는 것들 : public
        value_type          : 원소 타입
        reference           : 원소에 대한 참조
        const_reference
        iterator
        const_iterator
        size_type
        difference_type
5. iterator 클래스 만들기


# iterator 클래스


# 생성자
1. allocator_type::allocate() : 메모리 할당
2. 초기화
    > 컨테이너의 종류마다 초기화 종류가 같다.
    > 초기화 부분을 템플릿으로 구현?
        => 리스트 벡터마다 모양이 다르기 때문에 다시또 오버로딩해야한다.

### 생성자 종류
1. empty
2. fill
3. range
4. copy

### 생성자 구현 계획
1. empty
2. fill
    _M_fill_initialize
        std::uninitialized_fill_n 구현
    void
    _M_fill_initialize(size_type __n, const value_type& __value)
    {
        this->_M_impl._M_finish =
        std::__uninitialized_fill_n_a(this->_M_impl._M_start, __n, __value,
                                        _M_get_Tp_allocator());
    }
    - __uninitialized_fill_n_a 함수
    

3. range

4. copy
