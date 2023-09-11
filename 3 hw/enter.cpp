#include <iostream>
#include "header.h"
#include <cmath>
#include <math.h>
//#include <cstdlib>

using namespace std;

double* make_random(int, double, double);
double* make_cheb(int, double, double);
double* make_Y(int, int, double, double, double*);


double* make_random(int n, double a, double b)
{
    double* X;
    X = new double[n];

    for (int i = 0; i < n; ++i)
        X[i] = a + (b-a)/(n-1) * i;
    return X;
}


double* make_cheb(int n, double a, double b)
{
    double* X;
    X = new double[n];

    for (int i = 0; i < n; ++i)
    {
        X[i] = (a+b)/2 + (b-a)/2 * cos( (double)(2*i+1)/(2*n) * M_PI );
    }
    return X;
}


double* make_Y(int n, int type, double a, double b, double* X)
{
    double* Y;
    Y = new double[n];

    switch (type) 
    {
        case 0:
            srand(time(0));
            for (int i = 0; i < n; ++i)
                Y[i] = a + (b-a) * (double) rand()/RAND_MAX;
        break;
        case 1:
            for (int i = 0; i < n; ++i)
                Y[i] = sin(X[i]);
        break;
        case 2:
            for (int i = 0; i < n; ++i)
                Y[i] = cos(X[i]);
        break;
        case 3:
            for (int i = 0; i < n; ++i)
                Y[i] = fabs(X[i]);
        break;
        case 4:
            for (int i = 0; i < n; ++i)
                Y[i] = 1/(1+X[i]*X[i]);
        break;
        case 5:
            for (int i = 0; i < n; ++i)
                Y[i] = X[i]*X[i];
        break;
        default:
            cout << "Error: incorrect type";
        break;
    }

    return Y;
}


pair<double*, double*> make_nodes(int n, int type, int flag, double a, double b) //Функция, вызываемая из main
{
    double* X;
    X = new double[n];
    switch (flag) 
    {
        case 1:
            X = make_random(n, a, b);
        break;
        case 2:
            X = make_cheb(n, a, b);
        break;
        default:
            cout << "Error: incorrect flag";
        break;
    }

    sort(X, X + n);

    double* Y;
    Y = new double[n];
    Y = make_Y(n, type, a, b, X);

    return make_pair(X, Y); 
}