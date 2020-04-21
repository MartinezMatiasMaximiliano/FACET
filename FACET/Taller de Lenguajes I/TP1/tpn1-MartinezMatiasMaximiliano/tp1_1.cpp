/*
 ============================================================================
 Name        : tp1_1.c
 Author      : Martinez Matias Maximiliano
 Version     : 1.0
 Copyright   :
 Description : Trabajo Practico 1 de Taller de Lenguajes 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(){
    int Variable = 4;
    int *pVariable;
    pVariable = &Variable;
    printf("El contenido del puntero pVariable es %d \n",*pVariable);// 1.a) ok
    printf("La direccion de memoria almacenada por el puntero pVariable es %p \n",pVariable);//1.b) ok
    printf("La direccion de la Variable es %p\n",&Variable);//1.c) ok
    printf("La direccion del puntero es %p\n",&pVariable);//1.d) ok
    printf("El tama�o de memoria usado por Variable es %d\n",sizeof(Variable));//1.e) ok
    getchar();
    return 0;

}
