/*
 ============================================================================
 Name        : tp2_1.2.cpp
 Author      : Martinez Matias Maximiliano
 Version     : 
 Copyright   :
 Description : Trabajo Practico 2 de Taller de Lenguajes 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4 //filas
#define M 5 //columnas

int i,j;

double matriz[N][M];
double *numero = &matriz[0][0];

int main(){

for (i = 0; i<N; i++)
{
    for (j = 0; j < M; j++)
    {
        printf("%.2f   ", *(numero+i * M+j));
    }
    printf("\n");
}



return 0;
}