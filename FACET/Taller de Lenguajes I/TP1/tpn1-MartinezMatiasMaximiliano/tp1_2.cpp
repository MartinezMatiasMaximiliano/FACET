/*
 ============================================================================
 Name        : tp1_2.cpp
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

int Cuadrado(int x){ //ok
    int aux = x*x;
    return aux;
}

void CuadradoVoid(int x){ //ok
    int aux = x*x;
    printf("-----FUNCION mostrar cuadrado con Void: %d-----\n",aux);
}

void Direcciones(int aux){
    printf("-----FUNCION mostrar contenido y direccion de %d-----\n",aux);
    printf("La direccion de memoria de la variable es: %p\n",&aux);
    printf("El contenido de la variable es: %d\n",aux);
}

void Invertir(int primero,int segundo){//ok
	int aux;
	aux = primero;
	primero = segundo;
	segundo = aux;
    printf("-----FUNCION invertir el orden-----\n");
    printf("Invirtiendo el orden resulta en %d y %d \n",primero,segundo);
}

void Mayor(int a, int b){ //ok
    if(a != b){
    printf("-----FUNCION ordenar de forma Creciente-----\n");
        if(a > b){
            printf("Ordenados: %d, %d\n",b,a);
        }else{
            printf("Ordenados: %d, %d\n",a,b);
        }
    }else{
        printf("Los numeros ingresados son iguales\n");
    }
}

void OrdenarPar(){ //ok
	int a, b;
    printf("Ingrese un numero: ");
    scanf("%d", &a);
    printf("Ingrese otro numero: ");
    scanf("%d", &b);
    
    if(a != b){
    printf("-----FUNCION ordenar par de forma Creciente con -----\n");
        if(a > b){
            printf("Ordenados: %d, %d\n",b,a);
        }else{
            printf("Ordenados: %d, %d\n",a,b);
        }
    }else{
        printf("Los numeros ingresados son iguales\n");
    }
}

int main(){
    int numero,numeroCuad,primero,segundo;
    printf("Ingrese un numero para elevarlo al cuadrado:");
    scanf("%d",&numero);
    numeroCuad = Cuadrado(numero);
    printf("el cuadrado de %d es %d \n",numero,numeroCuad);
    CuadradoVoid(numero);
    Direcciones(numero);

    printf("-----FUNCIONES PARA DOS NUMEROS------\n");
    printf("Ingrese el primer numero que quiere comparar:");
    scanf("%d",&primero);
    //Direcciones(*primero);

    printf("Ingrese un segundo numero para comparar con %d:",primero);
    scanf("%d",&segundo);
    //Direcciones(*segundo);
    Invertir(primero,segundo);
    Mayor(primero,segundo);
    OrdenarPar();

    getchar();
    return 0;
}