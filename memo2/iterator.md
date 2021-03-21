
- [참고](http://www.tcpschool.com/cpp/cpp_iterator_category)

### InputIterator, forwardIterator 의 차이점은?

    input, output < forward < bidrectional < random

    input (입력반복자)
        순차적, 단방향 입력 수행
        값을 읽는데 사용
        값을 읽기만 하고 변경 x => const
    forward (순방향반복자)
        input, output 의 기능을 다가지고 있음
        (입,출력 모두 가능)
    random access (임의 접근)
        최상위 레벨, 가장 많은 기능을 제공
        


### iterator_traits
- type trait class (타입 특성정보 클래스)
- iterator 에 대한 정보를 알고 싶을 때

- 사용법
    1. iterator_traits 클래스 템플릿에 원하는 iterator 의 타입을 지정해 해당 타입으로 인스턴스를 생성한다.
    2. value_type, difference_type, iterator_category, pointer, reference 다섯가지의 타입 alias 에 접근할 수 있다. 
    ```
    template <typename IteratorType>
    void iteratorTraitsTest(IteratorType it) // it (순서 1)
    {
        typename iterator_traits<IteratorType>::value_type temp; // 순서 2
        // IteratorType 이 가리키고 있는 데이터의 타입(value_type)으로 temp 변수를 선언하겠다.
        // iterator_tratis 에 IteratorType 을 집어넣어 IteratorType 의 value_type 정보를 빼올 수 있음

        temp = *it
        std::cout << temp << std::endl;
    }
    ```
