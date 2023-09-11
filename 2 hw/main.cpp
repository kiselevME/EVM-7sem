#include <iostream>
#include "header.h"
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    double *A;
    double *X;
    double *Y;
    int n;
    double a, b;
    int type;
    int flag;
    double x;

    cout << "Введите число узлов: ";
    cin >> n;
    A = new double[n];
    X = new double[n];
    Y = new double[n];
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;

    cout << "Введите тип функции (sin(x) - 1, cos(x) - 2, |x| - 3, функция Рунге: 1/(1+x^2) - 4): ";
    cin >> type;
    cout << "Введите метод построения узлов (равноотстоящие - 1, узлы Чебышева - 2): ";
    cin >> flag;

    pair<double*, double*> XY = make_nodes(n, type, flag, a, b);
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

    cout << "Полученные узлы:" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << "x_" << i << " = " << X[i] << endl;
        cout << "f(x_" << i << ") = " << Y[i] << endl;
    }

    double *copy_Y; //Снимамем копию Y
    copy_Y = new double[n];
    for (int i = 0; i < n; ++i)
    {
        copy_Y[i] = Y[i];
    }
    A = polynom_ls(n, X, copy_Y);

    //Graphics
    double *X_;
    double *Y_1;
    double *Y_2;
    X_ = new double[10000];
    Y_1 = new double[10000];
    Y_2 = new double[10000];
    for (int i = 0; i < 10000; ++i)
    {
        X_[i] = a * (9999-i)/9999 + b * i/9999;
        Y_1[i] = calculate_ls(n, A, X_[i]);
        Y_2[i] = calculate_lagrange(n, X, Y, X_[i]);
    }

    fstream fout_1, fout_2, fout_error;
    fout_1.open("data_1.dat", fstream::out);
    fout_2.open("data_2.dat", fstream::out);
    fout_error.open("data_error.dat", fstream::out);
    if (!fout_1 && !fout_2)
    {
        cout << "Can't open file";
    }
    else
    {
        double sum = 0; //
        for (int i = 0; i < 10000; ++i)
        {
            fout_1 << X_[i] << ' ' << Y_1[i] << endl;
            fout_2 << X_[i] << ' ' << Y_2[i] << endl;
            fout_error << fabs((Y_1[i] - 1/(1+X_[i]*X_[i]))) << endl;
            sum += fabs((Y_1[i] - 1/(1+X_[i]*X_[i]))); //
        }
        cout << "avg_error = " << sum/10000;//
    }
    fout_1.close();
    fout_2.close();
    fout_error.close();


    delete A;
    delete X;
    delete Y;

    delete X_;
    delete Y_1;
    delete Y_2;

    return 0;
}