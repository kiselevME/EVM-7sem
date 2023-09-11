#include<stdio.h>
#include <iostream>

int main()
{
    double q = 0.09;
    double cur = 1;
    int N = 0;
    while (cur*q > 1e-16)
    {
        cur *= q;
        N += 1;
    }
    double sum = cur;
    while(N > 0)
    {
        cur /= q;
        sum += cur;
        N -= 1;
    }
    std::cout << "my sum = " << sum << std::endl;
    std::cout << "real sum = " << 1/(1-q);
    return 0;
}