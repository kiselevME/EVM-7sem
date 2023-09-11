#include <iostream>
#include <math.h>
#include <cmath>
#include "header.h"
#include <unistd.h>

using namespace std;

void u2c(int Nx, int Ny, double* U, double* C, double* D)
{
    double sum = 0;


	for (int j0 = 0; j0 < Ny+1; ++j0)
    {
		for (int m = 0; m < Nx+1; ++m) 
        {
			sum = 0;
			for (int i = 0; i < Nx+1; ++i) 
            {
				sum += U[j0*(Nx+1) + i] * sqrt(2)*sin(m * (M_PI / Nx)*i); 
			}
			D[j0*(Nx+1) + m] = sum / Nx; // d_{m}^{j0}
		}
	}

	for (int m = 0; m < Nx+1; ++m) 
    {
		for (int n = 0; n < Ny+1; ++n) 
        {
			sum = 0;
			for (int j = 0; j < Ny+1; ++j) 
            {
				sum += D[j*(Nx+1) + m] * sqrt(2)*sin(n * (M_PI / Ny)*j);
			}
			C[n*(Nx+1) + m] = sum / Ny;
		}
	}
}


void c2u(int Nx, int Ny, double* U, double* C, double* D) 
{
	double sum;

	for (int j = 0; j < Ny+1; ++j) 
    {
		for (int m = 0; m < Nx+1; ++m) 
        {
			sum = 0;
			for (int n = 0; n < Ny+1; ++n)
				sum += C[n*(Nx+1) + m] * sqrt(2)*sin(n * (M_PI / Ny)*j);
			D[j*(Nx+1) + m] = sum; // d_{m0}^{j}
		}
	}
	
	for (int i = 0; i < Nx+1; ++i) 
    {
		for (int n = 0; n < Ny+1; ++n) 
        {
			sum = 0;
			for (int m = 0; m < Nx+1; ++m) 
            {
				sum += D[n*(Nx+1) + m] * sqrt(2)*sin(m * (M_PI / Nx)*i);
			}
			U[n*(Nx+1) + i] = sum;
		}
	}

	for (int i = 0; i < Ny+1; ++i)
	{
		for (int j = 0; j < Nx+1; ++j)
			cout << U[i*(Nx+1) + j] << ' ';
		cout << endl;
	}
}

