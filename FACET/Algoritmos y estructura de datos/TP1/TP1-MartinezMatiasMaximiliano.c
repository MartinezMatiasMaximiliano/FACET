/*
 ============================================================================
 Name        : TP1.c
 Author      : Martinez Matias Maximiliano
 Version     : 2.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item; //CW: OK

typedef struct nodo{  //CW: Obs. No hace falta usar typedef aca
	item dato;
	struct nodo *siguiente;
}nodo;

typedef struct nodo* Lista; //CW: OK

Lista crearListaVacia();
bool esListaVacia(Lista L);
Lista Insertar(Lista L, item x);
void mostrar(Lista L);
int primerElemento (Lista L);
int Longitud(Lista L);
Lista borrar(Lista L);
bool pertenece (Lista L,item x);
int Suma(Lista L, item umbral);

int main(void) {
	Lista H;
	item auxPertenece;
	item umbral;
	item auxSuma;
	int prim;
	int cant;

	H = crearListaVacia();
	H= Insertar(H,1);
	H= Insertar(H,2);
	H= Insertar(H,3);
	H= Insertar(H,4);
	H= Insertar(H,5);
	H= Insertar(H,6);
	H= Insertar(H,7);
	H= Insertar(H,8);
	H= Insertar(H,9);

	//mensaje de lista vacia
	if(esListaVacia(H) == true){
		printf("La Lista esta vacia!\n");
	}else{
		printf("La Lista NO esta vacia!\n");
	}


	mostrar(H);

	prim = primerElemento(H);
	printf("El primer elemento de la lista es: %d\n",prim);

	cant = Longitud(H);
	printf("La cantidad de elementos de la lista: %d\n",cant);


	printf("Ingrese un numero para preguntar si pertenece:");
	scanf("%d",&auxPertenece);

	if(pertenece(H,auxPertenece)== true){
		printf("El numero %d pertenece a la lista!\n",auxPertenece);
	}else{
		printf("El numero %d NO pertenece a la lista!\n",auxPertenece);
	}

	borrar(H);

	printf("Ingrese un numero que sera el maximo para la suma:");
	scanf("%d",&umbral);

	auxSuma = Suma(H,umbral);
	printf("La suma de todos los numeros mayores a %d es:%d\n",umbral,auxSuma);

	getchar();
	return 0;
}

Lista crearListaVacia(){ //ok //CW: OK
	Lista L;
	L = NULL;
	return L;
}

bool esListaVacia(Lista L){ //ok //CW: OK
	if(L == NULL){
		return true;
	}else{
		return false;
	}
}

Lista Insertar(Lista L, item x){ //ok //CW: OK
	nodo *nuevo;
	nuevo = (nodo*) malloc(sizeof(nodo));
	nuevo->dato = x;
	nuevo->siguiente = L;
	L = nuevo;
	return L;
}

void mostrar(Lista L){ //ok //CW: OK
	nodo* show=L;
	while(show !=NULL){
		printf("dato: %d\n",show->dato);
		show = show->siguiente;
	}

}

int primerElemento(Lista L){ //CORREGIDO //CW: Error. La funcion DEBE retornar un valor no escribir un mensaje por pantalla
	int N;
	if(esListaVacia(L) == false){
		N = L->dato;
		return N;
	}else{
		return 0;
	}
	
}

int Longitud(Lista L){ //CORREGIDO  //CW: Error. La funcion DEBE retornar un valor no escribir un mensaje por pantalla
	nodo* aux = L;
	int cont=0;
	while(aux != NULL){
		cont = cont+1;
		aux = aux->siguiente;
	}
	return cont;
}

Lista borrar(Lista L){ //CORREGIDO
	
	if(esListaVacia(L)==false){
	Lista aux;
	aux=L->siguiente;
	free(L); //preguntar
	L = aux;
	}
	return L;
}

bool pertenece(Lista L, item x){//ok //CW: OK
	while(esListaVacia(L)==false){
		if(L->dato == x){
			return true;
		}
		L=L->siguiente;
	}
	return false;
}


int Suma(Lista L, int umbral){//CORREGIDO
	int resultado = 0;
	
	
	return resultado;
}
