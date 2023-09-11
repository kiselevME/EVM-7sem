#include<stdio.h>
#include <iostream>

int main()
{
    double eps = 1;
    while (1 + eps > 1)
    {
        eps /= 2;
    }
    std::cout << "eps = " << eps << std::endl;
    return 0;
}