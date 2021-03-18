#include "Vector.hpp"
#include <iostream>
int main()
{
    ft::Vector<int> vec(10,10);

    int *da = vec.getData();
    for (size_t i = 0; i < 10; i++)
    {
        std:: cout << *(da + i) << std::endl;
    }
    
    return (0);
}