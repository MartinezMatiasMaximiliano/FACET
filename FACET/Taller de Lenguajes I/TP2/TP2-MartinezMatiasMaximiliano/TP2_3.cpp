/*
 ============================================================================
 Name        : tp2_3.cpp
 Author      : Martinez Matias Maximiliano
 Version     : 
 Copyright   :
 Description : Trabajo Practico 2 de Taller de Lenguajes 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int Filas = 15,Columnas = rand()% 11+5 ,i,j,contPares; //15 filas, 5-15 cols, variables auxiliares

    int matriz[Filas][Columnas]; //matriz principal
    int *auxMatriz = &matriz[0][0]; //puntero a matriz principal y le cargo la DIR del primer elemento

    int pares[Filas]; //matriz para pares
    int *auxPares = pares;//puntero a matriz pares y le cargo la DIR del primer elemento

    for (i = 0; i<Filas; i++){
        contPares=0;
        for (j = 0; j < Columnas; j++){   
            *auxMatriz = rand()%900+100; //(intervalo + 1) + minimo   (899+1)+100
            printf("%d  ", *auxMatriz);
            if(*auxMatriz%2 == 0){
                contPares++;
            }
            auxMatriz++;
        }
    *auxPares = contPares; //agregar la cantidad de pares al arreglo Pares
    auxPares++;//avanzar arreglo de pares
    printf("\n");
    }

    for (i = 0; i < Filas; i++)
    {
        printf("Cantidad de pares en la fila %d: %d \n",i,pares[i]);
    }
    

    getchar();
    return 0;
}