/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gihwan-kim <kgh06079@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:20:18 by gihwan-kim        #+#    #+#             */
/*   Updated: 2021/03/16 22:30:16 by gihwan-kim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "./utils/iterator.hpp"


int main()
{
    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    
    ft::reverse_iterator<std::vector<int>::iterator> end(vec.begin());
    ft::reverse_iterator<std::vector<int>::iterator> start(vec.end());
    
    while (start != end)
    {
        std::cout<< ' ' << *start++;
    }
    
        
}