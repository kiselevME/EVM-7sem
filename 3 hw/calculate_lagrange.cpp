#include <iostream>

using namespace std;

double Phi(int n, double* X, int i, double x)
{
    double prod = 1;
    for (int j = 0; j < n; ++j)
    {
        if (i != j)
        {
            prod *= ((x - X[j]) / (X[i] - X[j]));
        }
    }

    return prod;
}

double calculate_lagrange(int n, double* X, double* Y, double x)
{
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += Y[i] * Phi(n, X, i, x);
    }

    return sum;
}