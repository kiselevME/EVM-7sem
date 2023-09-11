#include <iostream>
#include "header.h"
#include <cmath>
#include <unistd.h>


using namespace std;

int sgn(double x) // sgn
{
    if (x < 0)
        return -1;
    else if (x > 0)
        return 1;
    else    
        return 0;
}


double delta(int n, double* X_, double* Y_, double x, double y)
{
    double res = y;
    res -= Newton(n, X_, Y_, x);
    return res;
}


double calculate_h(int n, double* X_, double* Y_) // h(sigma)
{
    // Считаем максимум
    double max = fabs(delta(n, X_, Y_, X_[0], Y_[0]));

    for (int i = 1; i <= n+1; ++i)
    {
        if (fabs(delta(n, X_, Y_, X_[i], Y_[i])) > max)
            max = fabs(delta(n, X_, Y_, X_[i], Y_[i]));
    }

    return max;
}


double calculate_phi(int n, int N, double* X_, double* Y_, double* X, double* Y) // phi(sigma)
{
    // Считаем максимум
    double max = fabs(delta(n, X_, Y_, X[0], Y[0]));

    for (int i = 1; i <= N; ++i)
    {
        if (fabs(delta(n, X_, Y_, X[i], Y[i])) > max)
            max = fabs(delta(n, X_, Y_, X[i], Y[i]));
    }

    return max;
}


pair<double*, double*> find_basis(int n, int N, double* X, double* Y)
{
    double* X_;
    double* Y_;
    X_ = new double[n+2];
    Y_ = new double[n+2];

    for (int i = 0; i <= n+1; ++i)
    {
        X_[i] = X[i*(N/(n+1))];
        Y_[i] = Y[i*(N/(n+1))];
    }

    // for (int i = 0; i <= n+1; ++i)
    // {
    //     X_[i] = X[i];
    //     Y_[i] = Y[i];
    // }

    int i, v;
    double h, phi;
    int last1 = -1, last2 = -1;
    
    while (1)
    {
        for (int j = 0; j <= n+1; ++j)
            cout << "X_" << j << " = " << X_[j] << endl;
        h = calculate_h(n, X_, Y_); // Вычисляем h(sigma)
        phi = calculate_phi(n, N, X_, Y_, X, Y); // Вычисляем phi(sigma)
        cout << "h = " << h << endl;
        cout << "phi = " << phi << endl;
        // sleep(1);

        if ((phi-h)/phi < 1e-14) // Если h(sigma) = phi(sigma) ==> искомый базис найден
            break;
        
        for (i = 0; i <= N; ++i) // Находим i, при котором верно phi(sigma) = abs(delta(x_i))
        {
            if ( ((phi - fabs(delta(n, X_, Y_, X[i], Y[i]))) / phi) < 1e-16 )
                break;
        }

        // cout << "last2 = " << last2 << " i = " << i << endl;
        if (i == last2)
        {
            break;
        //     cout << "Сломалось, ищем новый i" << endl;
        //     for (i = N; i >= 0; --i) // Пробегаем, начиная с другой стороны
        //     {
        //         if ( fabs(phi - delta(n, X_, Y_, X[i], Y[i])) < 1e-16 )
        //             break;
        //     }
        }
        cout << "X_i: " << X[i] << endl;
        // Разбираем случаи
        if ((X_[0] < X[i]) && (X[i] < X_[n+1]))
        {
            cout << "Зашли в 1" << endl;
            for (v = 1; v <= n+1; ++v)
            {
                if (X_[v] > X[i])
                {
                    --v;
                    break;
                }
            }
            if (sgn(delta(n, X_, Y_, X[i], Y[i])) == sgn(delta(n, X_, Y_, X_[v], Y_[v])))
            {
                X_[v] = X[i];
                Y_[v] = Y[i];
            }
            else
            {
                X_[v+1] = X[i];
                Y_[v+1] = Y[i];
            }
        }

        else if (X[i] < X_[0])
        {
            cout << "Зашли в 2" << endl;
            if (sgn(delta(n, X_, Y_, X[i], Y[i])) == sgn(delta(n, X_, Y_, X_[0], Y_[0])))
            {
                X_[0] = X[i];
                Y_[0] = Y[i];
            }
            else
            {
                for (int j = n+1; j >= 1; --j)
                {
                    X_[j] = X_[j-1];
                    Y_[j] = Y_[j-1];
                }
                X_[0] = X[i];
                Y_[0] = Y[i];
            }
        }
        else
        {   
            cout << "Зашли в 3" << endl;
            if (sgn(delta(n, X_, Y_, X[i], Y[i])) == sgn(delta(n, X_, Y_, X_[n+1], Y_[n+1])))
            {
                X_[n+1] = X[i];
                Y_[n+1] = Y[i];
            }
            else
            {
                for (int j = 0; j <= n; ++j)
                {
                    X_[j] = X_[j+1];
                    Y_[j] = Y_[j+1];
                }
                X_[n+1] = X[i];
                Y_[n+1] = Y[i];
            }
        }
        cout << "i = " << i << endl << endl;;
        // sleep(0.01);
        last2 = last1;
        last1 = i;
    }

    return make_pair(X_, Y_);
}