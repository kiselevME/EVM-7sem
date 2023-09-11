#include <iostream>
#include "header.h"
#include <cmath>

using namespace std;

int main()
{
    int Nx;
    cout << "Введите Nx: ";
    cin >> Nx;
    int Ny;
    cout << "Введите Ny: ";
    cin >> Ny;
    int form;
    cout << "Введите номер формулы (1, 2 или 0 – из файла): ";
    cin >> form;

    double* U;
    U = new double[(Nx+1)*(Ny+1)];
    double* new_U;
    new_U = new double[(Nx+1)*(Ny+1)];
    double* D;
    D = new double[(Nx+1)*(Ny+1)];
    double* C;
    C = new double[(Nx+1)*(Ny+1)];

    enter_matrix(Nx, Ny, form, U, C, D);

	u2c(Nx, Ny, U, C, D);

    c2u(Nx, Ny, new_U, C, D);

    double sum;
	double max = 0;
	for (int j = 0; j < Ny+1; ++j)
    {
        sum = 0;
		for (int i = 0; i < Nx+1; ++i)
        {
			sum += fabs(U[j*(Nx+1) + i] - new_U[j*(Nx+1) + i]);
		}
		if (sum > max) 
            max = sum;
	}

    cout << "Строковая норма: " << max << endl;

    for (int j = 0; j < Ny+1; ++j)
	{
		for (int i = 0; i < Nx+1; ++i)
			cout << new_U[j*(Nx+1) + i] << ' ';
		cout << endl;
	}

    cout << endl;
    for (int j = 0; j < Ny+1; ++j)
	{
		for (int i = 0; i < Nx+1; ++i)
			cout << U[j*(Nx+1) + i] << ' ';
		cout << endl;
	}

    return 0;
}