/*
 ============================================================================
 Name        : Tp1-Algoritmos.c
 Author      : Alejandro Nestor Arcucci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

//Estructuras
typedef struct Nodo
{
	//Tomo un dato de tipo entero para los nodos
	int dato;
	//Apunto al siguiente nodo
	struct Nodo *nodoSig;
}Nodo;

//Declaracion de funciones
Nodo *CrearLista();//OK
Nodo *CrearNodo();//OK
void EsVacia(Nodo *Inicio);//OK
void MostrarLista(Nodo *Inicio);//OK
Nodo *InsertarInicio(Nodo *Inicio);//OK
Nodo *EliminarPrimerElemento(Nodo *Inicio);//OK
void LongitudDeLista(Nodo *Inicio);//OK
void PerteneceALista(Nodo *Inicio, int parametro);//OK
Nodo *PrimerElemento(Nodo *Inicio);//OK
int SumaDeLista(Nodo *Inicio, int Tope);

//Main
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	srand(time(NULL));//Randomiza la seed
	//Creo una lista vacia
	Nodo *Inicio = CrearLista();
	//Verifico que la lista efectivamente esté vacía
	EsVacia(Inicio);
	//Inserto 5 elementos al inicio de la lista
	for(int i = 0;i<5;i++){
		Inicio = InsertarInicio(Inicio);
	}
	//Verifico la longitud de la lista
	LongitudDeLista(Inicio);
	//Verifico si el numero 5 está contenido en algun nodo
	PerteneceALista(Inicio,5);
	//Muestro la suma de los numeros mayores a 5 de los nodos de la lista
	printf("La suma de los numeros mayores a 5 es: %d", SumaDeLista(Inicio,5));
	//Muestro la lista
	MostrarLista(Inicio);
	Nodo *first = NULL;
	first = PrimerElemento(Inicio);
	printf("El valor del primer elemento es %d",first->dato);
	Inicio = EliminarPrimerElemento(Inicio);
	first = PrimerElemento(Inicio);
	printf("El valor del primer elemento es %d",first->dato);
	LongitudDeLista(Inicio);
	MostrarLista(Inicio);
	return 0;
}

//Definicion de funciones

Nodo *CrearLista(){
	//Pongo una lista en null y la devuelvo
	Nodo *Lista = NULL;
	return Lista;
}

Nodo *CrearNodo(){
	//Declaro un puntero de tipo nodo y lo pongo en NULL
	Nodo *nuevo = NULL;
	//Le asigno la memoria a nuevo
	nuevo = (Nodo*) malloc(sizeof(Nodo));
	//Verifico que nuevo no sea nulo
	if(nuevo != NULL){
		//Cargo el dato de forma aleatoria
		nuevo->dato = rand()%9 + 1;
		//Pongo en null el puntero al nodo siguiente
		nuevo->nodoSig = NULL;
	}
	//retorno nuevo
	return nuevo;
}

void EsVacia(Nodo *Inicio){
	//Verifico si la lista es nula
	if(Inicio == NULL){
		printf("La lista está vacía\n");
	}
	else{
		printf("La lista no está vacía\n");
	}
}

void MostrarLista(Nodo *Inicio){
	//Declaro una variable auxiliar para recorrer la lista
	Nodo *aux = Inicio;
	//Mientras que aux no sea nulo avanzo
	while(aux != NULL){
		//Voy mostrando el dato del nodo en cada iteracion
		printf("%d\n",aux->dato);
		//Avanzo al nodo siguiente
		aux = aux->nodoSig;
	}
}

Nodo *InsertarInicio(Nodo *Inicio){
	//Creo el nodo a insertar
	Nodo *nuevo = CrearNodo();
	//Si la lista es vacia, Inicio toma el valor del nuevo nodo y lo devuelvo
	if(Inicio == NULL){
		Inicio = nuevo;
	}
	//Si no es vacia
	else{
		//Hago que el inicio sea el nodo apuntado por nuevo
		nuevo->nodoSig = Inicio;
		//Igualo inicio a nuevo y lo devuelvo
		Inicio = nuevo;
	}
	return Inicio;
}

void EliminarNodo(Nodo *nodito){
	//Si el nodo no es nulo, libero la memoria
	if(nodito != NULL){
		free(nodito);
	}
}

Nodo *EliminarPrimerElemento(Nodo *Inicio){
	//Verifico que la lista no sea vacia
	if(Inicio != NULL){
		//Tomo un auxiliaar
		Nodo *aux= Inicio;
		//Hago que inicio sea ahora el segundo valor
		Inicio = Inicio->nodoSig;
		//Libero lo que quedo guardado en aux
		EliminarNodo(aux);
	}
	//Devuelvo el inicio
	return Inicio;
}

void LongitudDeLista(Nodo *Inicio){
	//Tomo una variable auxiliar para recorrer la lista
	Nodo *aux = Inicio;
	//Tomo un contador
	int contador = 0;
	//Si la lista no está vacia
	if(aux != NULL){
		//Recorro la lista y sumo 1 al contador con cada iteracion
		while(aux != NULL){
			contador = contador + 1;
			aux = aux->nodoSig;
		}
		printf("La longitud de la lista es de %d nodos.\n",contador);
	}
}

void PerteneceALista(Nodo *Inicio, int parametro){
	//Tomo un auxiliar para recorrer la lista
	Nodo *aux = Inicio;
	//Si la lista no está vacia
	if(aux != NULL){
		//Recorro la lista
		while(aux != NULL){
			//Verifico en cada iteracion si el valor del nodo es igual al parametro
			if(aux->dato == parametro){
				printf("El elemento se encuentra en la lista.\n");
				//Si se cumple la condicion salgo de la funcion
				return;
			}
			else{
				aux = aux->nodoSig;
			}
		}
		printf("El elemento no se encuentra en la lista.\n");
	}
}

Nodo *PrimerElemento(Nodo *Inicio){
	//Tomo el primer elemento y lo devuelvo
	Nodo *aux = Inicio;
	if(aux != NULL){
		printf(".");
	}
	return aux;
}

int SumaDeLista(Nodo *Inicio, int Tope){
	//Tomo un sumador
	int suma = 0;
	//Verifico que la lista no sea vacia
	if(Inicio != NULL){
		//Utilizo un aux para recorrer la lista
		Nodo *aux = Inicio;
			while(aux!= NULL){
				//Siempre que se cumpla la condicion sumo el dato del nodo a suma
				if(aux->dato > Tope){
					suma = suma + aux->dato;
				}
				aux = aux->nodoSig;
			}
	}
	//Retorno suma
	return suma;
}
