#include<stdio.h>
#include <iostream>
#include <cmath>

int main()
{
    double x = -10; //enter x
    double h = 1;
    while (abs((exp(x+(h/2)) - exp(x-(h/2)))/h - (exp(x+h) - exp(x-h))/(2*h)) > 1e-16)
    {
        h /= 2;
    }
    std::cout << "my d/dx exp = " << (exp(x+h) - exp(x-h))/(2*h) << std::endl;
    std::cout << "real d/dx exp = " << exp(x);
    return 0;
}