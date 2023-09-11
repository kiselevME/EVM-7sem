#include<stdio.h>
#include <iostream>

int main()
{
    double q = 0.01;
    double cur = 1;
    double sum = 1;
    while (abs(cur*q) > 1e-16)
    {
        cur *= q;
        sum += cur;
    }
    std::cout << "my sum = " << sum << std::endl;
    std::cout << "real sum = " << 1/(1-q);
    return 0;
}