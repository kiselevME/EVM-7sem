#include <iostream>
#include "header.h"
#include <cmath>
#include <fstream>
#include <unistd.h>

using namespace std;

int main()
{
    double *X;
    double *Y;
    int N, n;
    double a, b;
    int type;
    int flag;
    double x;

    cout << "Введите N: ";
    cin >> N;
    X = new double[N+1];
    Y = new double[N+1];
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;

    cout << "Введите тип функции (sin(x) – 1, cos(x) – 2, |x| – 3, функция Рунге: 1/(1+x^2) – 4, x^2 – 5): ";
    cin >> type;
    cout << "Введите метод построения узлов (равноотстоящие - 1, узлы Чебышева - 2): ";
    cin >> flag;

    pair<double*, double*> XY = make_nodes(N+1, type, flag, a, b);
    X = XY.first;
    Y = XY.second;
    // for (int i = 0; i < n; ++i) //Ввод массива x
    // {
    //     cout << "Введите x_" << i << ": ";
    //     cin >> X[i];
    // }

    // for (int i = 0; i < n; ++i) //Ввод массива f(x)
    // {
    //     cout << "Введите f(x_" << i << "): ";
    //     cin >> Y[i];
    // }

    // double* X_;
    // double* Y_;
    // X_ = new double[n+2];
    // Y_ = new double[n+2];
    // for (int i = 0; i <= n+1; ++i)
    // {
    //     X_[i] = X[i];
    //     Y_[i] = Y[i];
    // }
    // cout << Newton(n, X_, Y_, X_[0]) << endl;
    // sleep(10);
//////////////////////////////////////////////////////////////////////////////////////////////////////;//////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Полученные узлы:" << endl;
    for (int i = 0; i <= N; ++i)
    {
        cout << "x_" << i << " = " << X[i] << endl;
        cout << "f(x_" << i << ") = " << Y[i] << endl;
    }


    // double* X_;
    // double* Y_;
    // X_ = new double[n+2];
    // Y_ = new double[n+2];
    // for (int i = 0; i <= n+1; ++i)
    // {
    //     X_[i] = X[i];
    //     Y_[i] = Y[i];
    // }
    
    // cout << delta(n, X_, Y_, X_[n+1], Y_[n+1]) << endl;
    // sleep(1);
    // cout << (Y_[n+1] - Newton(n, X_, Y_, X_[n+1])) << endl;
    // sleep(1);
    // double res = (Y_[n+1] - Newton(n, X_, Y_, X_[n+1]));
    // cout << res;
    double* X_;
    double* Y_;
    pair<double*, double*> XY_ = find_basis(n, N, X, Y);
    X_ = XY_.first;
    Y_ = XY_.second;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////;////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Graphics
    double *X__;
    double *Y__;
    X__ = new double[10000];
    Y__ = new double[10000];
    for (int i = 0; i < 10000; ++i)
    {
        X__[i] = a * (9999-i)/9999 + b * i/9999;
        Y__[i] = Newton(n, X_, Y_, X__[i]);
    }

    fstream fout_1;
    fout_1.open("data_1.dat", fstream::out);
    if (!fout_1)
    {
        cout << "Can't open file";
    }
    else
    {
        for (int i = 0; i < 10000; ++i)
        {
            fout_1 << X__[i] << ' ' << Y__[i] << endl;
        }
    }
    fout_1.close();

    delete []X;
    delete []Y;

    delete []X_;
    delete []Y_;

    delete []X__;
    delete []Y__;

    return 0;
}