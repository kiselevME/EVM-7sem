#include <iostream>
#include <stdio.h>
#include "header.h"

using namespace std;


void enter_matrix(int Nx, int Ny, int form, double* U, double* C, double* D) //Функция, вызываемая из main. Возваращает 3 массива со значениями a, b, c
{
    // заполнение границ сетки
    for (int i = 0; i < Nx+1; ++i) 
        U[i] = 0;
    for (int i = 0; i < Nx+1; ++i) 
        U[Ny*(Nx+1) + i] = 0;
    for (int j = 0; j < Ny+1; ++j) 
        U[j*(Nx+1)] = 0;
    for (int j = 0; j < Ny+1; ++j) 
        U[j*(Nx+1) + Nx] = 0;

    // заполняем C и D нулями
    for (int j = 0; j < Nx+1; ++j) 
    {
        for (int i = 0; i < Ny+1; ++i)
        {
            C[j*(Ny+1) + i] = 0;
            D[j*(Ny+1) + i] = 0;
        }
    }

    // заполнение внутренней части
    switch (form) 
    {
        case 0:
        {
            FILE* f;
            int a;
            f = fopen("input.txt", "r");

            for (int j = 0; j < Ny+1; ++j) 
            {
                for (int i = 0; i < Nx+1; ++i)
                {
                    a = fscanf(f, "%lf", &U[j*(Nx+1) + i]);
                }
            }
            fclose(f);
        break;
        }
        case 1:
        {
            for (int j = 1; j < Ny; ++j) 
            {
                for (int i = 1; i < Nx; ++i)
                {
                    if (i == j)
                        U[j*(Nx+1) + i] = 1;
                    else
                        U[j*(Nx+1) + i] = 0;
                }
            }
        break;
        }
        case 2:
        {
            for (int j = 1; j < Ny; ++j) 
            {
                for (int i = 1; i < Nx; ++i)
                {
                    U[(Nx+1)*j + i] = 1;
                }
            }
        break;
        }
        default:
            cout << "Error: incorrect formule";
        break;
    }
}