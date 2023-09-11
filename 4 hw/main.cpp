#include <iostream>
#include "header.h"
#include <cmath>

using namespace std;

int main()
{
    int n;
    cout << "Введите n: ";
    cin >> n;

    int form;
    cout << "Введите номер формулы (1 – стандартная): ";
    cin >> form;

    double* A;
    A = new double[n+1];
    double* B;
    B = new double[n+1];
    double* C;
    C = new double[n+1];
    double* F;
    F = new double[n+1];
    enter_matrix(n, form, A, B, C, F);

    // cout << "Введенная матрица: " << endl;
    // for (int i = 0; i <= n; ++i)
    // {
    //     for (int j = 0; j <= n; ++j)
    //     {
    //         if (i == j+1)
    //             cout << -A[i] << ' ';
    //         else if (i == j)
    //             cout << C[i] << ' ';
    //         else if (i == j-1)
    //             cout << -B[i] << ' ';
    //         else
    //             cout << 0 << ' ';
    //     }   
    //     cout << endl;
    // }

    double* Y = calculate_answer(n, A, B, C, F);

    // cout << "Полученный ответ: " << endl;
    // for (int i = 0; i <= n; ++i)
    // {
    //     cout << Y[i] << ' ';
    // }

    double norm = 0;
    for (int i = 0; i <= n; ++i)
    {
        norm += (1 - Y[i])*(1 - Y[i]);
    }
    norm = sqrt(norm);
    cout << "Норма разности: " << norm << endl;

    norm = 0;
    double cur_prod;
    for (int i = 0; i <= n; ++i)
    {
        cur_prod = 0;
        cur_prod += -A[i-1]*Y[i-1];
        cur_prod += C[i]*Y[i];
        cur_prod += -B[i+1]*Y[i+1];

        norm += (F[i] - cur_prod)*(F[i] - cur_prod);
    }
    norm = sqrt(norm);
    cout << "Норма невязки: " << norm;

    delete []A;
    delete []B;
    delete []C;
    delete []F;

    return 0;
}