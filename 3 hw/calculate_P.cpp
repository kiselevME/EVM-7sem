#include <iostream>
#include "header.h"
#include <cmath>
#include <math.h>

using namespace std;

double Newton(int n, double* X, double* Y, double x)
{
    double del;

    // Считаем h
    double numerator = 0;
    double denominator = 0;
    for (int i = 0; i <= n+1; ++i)
    {
        del = 1;
        for (int j = 0; j <= n+1; ++j)
        {
            if (i != j)
                del *= (X[i] - X[j]);
        }

        numerator += Y[i] / del;
        denominator += pow(-1, i) / del;
    }
    double h = numerator / denominator;
    // cout << "Newton numerator = " << numerator << endl;
    // cout << "Newton denominator = " << denominator << endl;
    // cout << "Newton h = " << h << endl;

    // Считаем полином
    double res = Y[0] - h;
    double y, phi, F;
    for (int k = 1; k <= n; ++k) // мб тут k < N-1
    {
        y = 0;
        phi = 0;
        // Считаем y(x_0; ...; x_k) - h * phi(x_0; ...; x_k)
        for (int i = 0; i <= k; ++i)
        {
            del = 1;
            for (int j = 0; j <= k; ++j)
            {
                if (i != j)
                    del *= (X[i] - X[j]);
            }

            y += Y[i] / del;
            phi += pow(-1, i) / del;
        }
        F = y - h*phi;
        
        // Домножаем на (x-x_0)(x-x_1)...(x-x_[k-1])
        for (int i = 0; i <= k-1; ++i)
            F *= (x - X[i]);

        res += F;
    }
return res;
}
