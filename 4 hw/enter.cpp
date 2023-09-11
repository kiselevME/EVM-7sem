#include <iostream>
#include "header.h"

using namespace std;


void enter_matrix(int n, int form, double* A, double* B, double* C, double* F) //Функция, вызываемая из main. Возваращает 3 массива со значениями a, b, c
{
    switch (form) 
    {
        case 1:
        {
            double h = 1.0/n;
            for (int i = 0; i < n+1; ++i)
            {
                A[i] = 1/(h*h);
                B[i] = 1/(h*h);
                C[i] = 2/(h*h);
                F[i] = 0;
            }
            F[0] = 1/(h*h);
            F[n] = 1/(h*h);
        break;
        }
        default:
            cout << "Error: incorrect formule";
        break;
    }
}