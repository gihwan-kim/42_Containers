# General rules

템플릿을 제외하고 함수가 헤더에 구현되어있을 경우 : 0 점

malloc, calloc, printf, free 사용 x

표준 라이브러리 사용할 것

STL 라이브러리는 사용 x

"using namespace" 사용 x

c++11, Boost, 사용 x


#  Objectives

- C++ 표준 템플릿 라이브러리의 다양한 컨테이너 타입을 구현해볼 것임
- 각 컨테이너마다 적절한 이름의 클래스 파일을 제출할 것
- namespace 는 ft, 컨테이너는 ft::<container> 로 테스트됨
- You need to respect the structure of the reference container. If it’s missing a part of the
Coplien form, do not implement it.
    > Coplien form 이 없을 경우 구현하지않아도됨

- c++98 로 코딩
- c++98 기준의 표준 라이브러리 컨테이너만 구현하기


# Mandatory part

- 필수파일을 <container>.hpp 로 제출
- main.cpp 파일로 테스트 할것

- The member function get_allocator is not expected here, the remaining member
functions are. Non-member overloads are expected aswell.
   > 멤버 함수 get_allocator 는 구현하지말고 나머지 멤버함수들은 구현해라.
   > Non-member overload  함수들도 구현할것

- 컨테이너가 iterator 를 가질 경우 구현할 것
- https://www.cplusplus.com/ 참고 해서 구현

- You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function/-
variable must be justified
   > 표준 컨테이너가 제공하는 것보다 많이 public 함수를 구현할 수 없다.
   > 모든 것은 private 또는 protected
   > 모든 public 함수/변수 들은 정당화되야한다.

- • For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.
   > 멤버가 아닌 overload 의 경우 "friend" 키워드가 허락된다. "friend" 를 사용할 때마다 정당화 시켜야하고 평가때 확인받아야함
   > 레퍼런스 보면 Non-member function overloads 항목을 말하는 것 같다.
- 구현해야할 컨테이너, 그 컨테이너의 함수들도 구현
    • List
    • Vector
    • Map
    • Stack
    • Queue
- STL 금지, STD 라이브러리 사용은 됨


# Bonus part

- 구현해야할 컨테이너
    • Deque
    • Set
    • Multiset
    • Multimap

# 필요한 지식

- namespace 만드는 법
- friend 사용법


# 알아야할 것들 정리
- std 이름공간의 구조
- std 컨테이너 구조
- 메모리를 할당하면 할당한 주소는 어디에 저장되는가?



# 각 컨테이너별 공통 구조
- 클래스 템플릿 구조 => 모든 타입의 데이터를 담을 수 있게됨
- 동적할당된 메모리를 대입, 복제할 때 어떤식으로 처리해야 할지
    > 예외처리의 안전성
    > 전문가를 위한 c++ 9 장 참고 : noexcept (c++11) 를 사용

- iterator 인터페이스 : 비슷한 방식으로 작동하도록 인터페이스 통일
    > 내부적으로 포인터로 구현됐을 수도 있음
    > Sequential container, Associative container, unordered associative container 만 iterator 제공
        > 각 컨테이너 별로 이터레이터의 모양이 다름 (양방향 컨테이너인지 단방향인지 등등)
    > Container adaptor, bitset 클래스는 iterator 제공하지 않음

- 각 컨테이너마다 자신만의 iterator type 을 가지고 있다.
    > iterator 를 통해서 요소에 접근하고 반복한다.

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
    반복자의 종류 정하기 (정,양방향, 임의 접근인지)
        (반복자마다 구현해야할 조건 확인 17장)
    컨테이너에 담길 원소의 정렬 방식
    반복자의 내부에서 표현하는 방식 
