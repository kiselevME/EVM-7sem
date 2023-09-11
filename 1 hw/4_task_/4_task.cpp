#include<stdio.h>
#include <iostream>
#include <cmath>

int main()
{
    double x = 1;
    double cur = 1;
    double sum = 1;
    int n_iter = 1;
    while (abs((cur*x)/n_iter) > 1e-16)
    {
        cur = (cur*x)/n_iter;
        sum += cur;
        n_iter += 1;
    }

    std::cout << "my exp = " << sum << std::endl;
    std::cout << "real exp = " << exp(x);
    return 0;
}