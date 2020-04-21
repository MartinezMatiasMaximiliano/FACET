#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Punto 1
typedef int numero;

typedef struct Nodo{
	numero datito;
	Nodo* siguiente;
}Nodo;
typedef struct Nodo* Lista;

//Punto 2
//A
Lista crearLista();
//B
int esListaVacia(Lista L);
//C
void mostrar(Nodo *datito);
//D
Lista insertar(Lista L, numero X);
//E
numero primerElemento(Lista L);
//F
Lista borrar(Lista L);
//G
numero longitud(Lista L);
//H
numero pertenece(Lista L, numero x);
//Punto 3
numero Sumatoria(Lista L, numero maximo);

int main (void){
	numero ListaVacia;
	numero elemento;
	numero longi;
	numero perte;
	numero suma;
	Nodo*L;
	L = crearLista();
	L = insertar(L, 1);
	L = insertar(L, 2);
	L = insertar(L, 3);
	L = insertar(L, 4);
	ListaVacia = esListaVacia(L);
	mostrar(L);
	elemento = primerElemento(L);
	printf("El primer elemento es: %d\n", elemento);
	L=borrar(L);
	longi = longitud(L);
	printf("La longitud es: %d\n", longi);
	perte = pertenece(L, 3);
	if(perte == 1){
		printf("El numero si pertenece a la lista\n");
	}
	else{
		printf("El numero no pertenece a la lista\n");
	}
	suma = Sumatoria(L, 2);
	printf("La suma es: %d\n", suma);
	return 0;
}

Lista crearLista(){
  Lista L;
  L = NULL;
  return L;
}

int esListaVacia(Lista L){
	if(L == NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void mostrar(Lista L){
	Nodo *aux = L;
	while(aux != NULL){
		printf("El numero es: %d\n", aux->datito);
		aux = aux->siguiente;
	}
}

Lista insertar(Lista L, numero X){
	Nodo*nuevonodo;
   	nuevonodo = (Nodo*) malloc(sizeof(Nodo));
  	nuevonodo->datito = X;
   	nuevonodo->siguiente = L;
   	L = nuevonodo;
   	return L;
} 

numero primerElemento(Lista L){
	numero E=0;
	if(esListaVacia(L) == 0){
		E = L->datito;
	}
	else{
		printf("La lista esta vacia");
	}
	return E;
}

Lista borrar(Lista L){
	Nodo*aux;
	aux = (Nodo*) malloc(sizeof(Nodo));
	aux->siguiente=L;
	L=L->siguiente;
	free(aux);
	printf("Al borrarse el nodo, la lista queda de la siguiente manera:\n");
	mostrar(L);
	return L;
}

numero longitud(Lista L){
	numero i = 0;
	while(esListaVacia(L) == 0){
		i++;
		L= L->siguiente;
	}
	return i;
}

numero pertenece(Lista L, numero x){
	Nodo*comprueba = L;
	while(comprueba != NULL){
		if(comprueba->datito == x){
			return 1;
		}
		else{
			return 0;
		}
		
	}
}

//Punto 3
numero Sumatoria(Lista L, numero maximo){
    int suma = 0;
    if(L != NULL){
        Nodo *aux3 = L;
            while(aux3 != NULL){
                if(aux3->datito > maximo){
                    suma = suma + aux3->datito;
                }
                aux3 = aux3->siguiente;
            }
    }
    return suma;
}
