#include <iostream>

using namespace std;

double calculate_ls(int n, double* A, double x)
{
    double sum = 0;
    double cur_x = 1;
    for (int i = 0; i < n; ++i)
    {
        sum += A[i] * cur_x;
        cur_x *= x;
    }

    return sum;
}