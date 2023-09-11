#include <iostream>
#include "header.h"

using namespace std;

double* calculate_answer(int n, double* A, double* B, double* C, double* F)
{
    // Считаем полином
    double* alpha;
    alpha = new double [n+1];
    double* beta;
    beta = new double [n+1];

    alpha[1] = B[0]/C[0];
    beta[1] = F[0]/C[0];
    for (int k = 1; k < n; ++k)
    {
        alpha[k+1] = B[k] / (C[k] - A[k]*alpha[k]);
        beta[k+1] = (F[k] + A[k]*beta[k]) / (C[k] - A[k]*alpha[k]);
    }
        
    double* Y;
    Y = new double[n+1];

    Y[n] = (F[n] + A[n]*beta[n]) / (C[n] - A[n]*alpha[n]);
    for (int k = n-1; k >= 0; --k)
    {
        Y[k] = alpha[k+1]*Y[k+1] + beta[k+1];
    }

return Y;
}
