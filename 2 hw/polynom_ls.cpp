#include <iostream>

using namespace std;

double* gauss(int n, double* A, double* B)
{
    for (int i = 0; i < n; ++i) //Прямой ход гаусса
    {    
        double max = A[i*n+i];
        int l = i;
        for (int j = i+1; j < n; ++j)
        {
            if (A[j*n+i] > max)
            {
                max = A[j*n+i];
                l = j;
            }
        }    

        for (int j = 0; j < n; ++j)
            {
                swap(A[i*n+j], A[l*n+j]);
            }
        swap(B[i], B[l]);

        for (int j = i+1; j < n; ++j) //Вычитание строк
        {
            double coef = A[j*n+i]/A[i*n+i];
            for (int h = i; h < n; ++h)
            {
                A[j*n+h] -= coef * A[i*n+h];
            }
            B[j] -= coef * B[i];
        }
    }

    for (int i = n-1; i >= 0; --i) //Обратный ход гаусса
    {
        double coef = 1/A[i*n+i];
        for (int j = i; j < n; ++j) //Нормировка
        {
            A[i*n+j] *= coef;
        }
        B[i] *= coef;

        for (int j = 0; j < i; ++j) //Вычитание строк
        {
            double coef = A[j*n+i];
            A[j*n+i] -= coef * A[i*n+i];
            B[j] -= coef * B[i];
        }
    }

    return B;
}

double* polynom_ls(int n, double *X, double *Y)
{
    double *A;
    A = new double[n*n];

    for (int j = 0; j < n; ++j)
        A[j*n] = 1;

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            A[j*n+i] = A[j*n+i-1] * X[j];
        }
    }

    
    double *coefs_ls;
    coefs_ls = new double[n];

    coefs_ls = gauss(n, A, Y);

    // for (int i = 0; i < n; ++i)
    //     cout << coefs_ls[i] << ' ';

    return coefs_ls;
}