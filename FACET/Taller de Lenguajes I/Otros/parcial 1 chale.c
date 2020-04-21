/*
 ============================================================================
 Name        : 0.c
 Author      : Alejandro Nestor Arcucci
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

//Utilizo un enum
enum clases {A,B,C};
//Agrego los arreglos de caracteres
char nombres[5][10] = {"Jorge ", "Pepe ","Mario ","Skere "};
char apellidos[5][10] = {"Boldo", "Queso", "Bro", "Peep"};
//Mi estructura de sistema
typedef struct Datos{
	char *Nombre;
	char *Apellido;
	int Edad;
	enum clases clase;
}Datos;
typedef struct Notas{
	double ingles;
	double literatura;
	double matematicas;
	double recreo;
}Notas;
typedef struct Alumno{
	Datos *datos;
	Notas *notas;
}Alumno;
typedef struct Nodo{
	Alumno *alumno;
	struct Nodo *nodosig;
}Nodo;
//Declaracion de funciones
void Cargar_Datos(Datos *puntero);
void Cargar_Notas(Notas *puntero);
Nodo *Crear_Nodo();
void Insertar_Final(Nodo **Inicio);
void Insertar_Inicio(Nodo **Inicio);
void Mostrar_Lista(Nodo *Inicio);
void Mover_Elementos(Nodo *Inicio1,Nodo **Inicio2);
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	srand(time(NULL));//Randomiza la seed
	Nodo *Inicio1 = NULL;
	Nodo *Inicio2 = NULL;
	Insertar_Inicio(&Inicio1);
	Insertar_Final(&Inicio1);
	Mostrar_Lista(Inicio1);
	Mover_Elementos(Inicio1,&Inicio2);
	printf("\n");
	Mostrar_Lista(Inicio2);
	return 0;
}

//Definicion de funciones
void Cargar_Datos(Datos *puntero){
	//Creo dos arreglos auxiliares para tomar la longitud de las palabras y asignar correctamente la memoria
	char aux1[10];
	char aux2[10];
	//Defino cual de los nombres y apellidos se toman aleatoriamente
	strcpy(aux1,nombres[rand()%4]);
	strcpy(aux2,apellidos[rand()%4]);
	//Asigno la memoria necesaria para guardar los datos
	puntero->Nombre = (char*) malloc(sizeof(char) * strlen(aux1));
	puntero->Apellido = (char*) malloc(sizeof(char) * strlen(aux2));
	//Copio los datos de los arreglos auxiliares a los campos de la estructura
	strcpy(puntero->Nombre,aux1);
	strcpy(puntero->Apellido,aux2);
	//defino la edad
	puntero->Edad = rand()%17 +1;
	//tomo la clase a la que pertenece
	switch(rand()%2){
	case 0:
		puntero->clase = A;
		break;
	case 1:
		puntero->clase = B;
		break;
	case 2:
		puntero->clase = C;
		break;
	}
}
void Cargar_Notas(Notas *puntero){
	puntero->ingles = rand()%9 + 1;
	puntero->literatura = rand()%9 + 1;
	puntero->matematicas = rand()%9 + 1;
	puntero->recreo = rand()%9 + 1;
}
void Mostrar_Datos(Datos *puntero){
	printf("Nombre: %s\n",puntero->Nombre);
	printf("Apellido: %s\n",puntero->Apellido);
	printf("Edad: %d\n",puntero->Edad);
	switch(puntero->clase){
	case 0:
		printf("Clase: A\n");
		break;
	case 1:
		printf("Clase: B\n");
		break;
	case 2:
		printf("Clase: C\n");
		break;
	}
}
void Mostrar_Notas(Notas *puntero){
	printf("Inglés: %.2f\n",puntero->ingles);
	printf("Literatura: %.2f\n",puntero->literatura);
	printf("Matematicas: %.2f\n",puntero->matematicas);
	printf("Recreo: %.2f\n",puntero->recreo);
}
Nodo *Crear_Nodo(){
	Nodo *nuevo = NULL;
	nuevo = (Nodo*) malloc(sizeof(Nodo));
	if(nuevo != NULL){
		nuevo->alumno = (Alumno*) malloc(sizeof(Alumno));
		nuevo->alumno->datos = (Datos*) malloc(sizeof(Datos));
		nuevo->alumno->notas = (Notas*) malloc(sizeof(Notas));
		Cargar_Datos(nuevo->alumno->datos);
		Cargar_Notas(nuevo->alumno->notas);
		nuevo->nodosig = NULL;
	}
	return nuevo;
}
void Insertar_Final(Nodo **Inicio){
	Nodo *nuevo = Crear_Nodo();
	Nodo *aux = *Inicio;
	if(aux != NULL){
		while(aux->nodosig != NULL){
			aux = aux->nodosig;
		}
	}
	aux->nodosig = nuevo;
}
void Insertar_Inicio(Nodo **Inicio){
	Nodo *nuevo = Crear_Nodo();
	if(nuevo != NULL){
		nuevo->nodosig = *Inicio;
		*Inicio = nuevo;
	}
}
void Mostrar_Lista(Nodo *Inicio){
	Nodo *aux = Inicio;
	while(aux != NULL){
		Mostrar_Datos(aux->alumno->datos);
		Mostrar_Notas(aux->alumno->notas);
		aux = aux->nodosig;
	}
}
void Eliminar_Nodo(Nodo *nodo){
	if(nodo != NULL){
		free(nodo);
	}
}
void Mover_Elementos(Nodo *Inicio1,Nodo **Inicio2){
	Nodo *aux1 = Inicio1;
	Nodo *anterior = NULL;
	Nodo *nuevo = NULL;
	while(aux1 != NULL){
		////paso toda la info al nuevo nodo
		nuevo = (Nodo*) malloc(sizeof(Nodo));
		nuevo->alumno = (Alumno*) malloc(sizeof(Alumno));
		nuevo->alumno->datos = (Datos*) malloc(sizeof(Datos));
		nuevo->alumno->notas = (Notas*) malloc(sizeof(Notas));
		nuevo->alumno->datos->Nombre = (char*) malloc(sizeof(char) * strlen(aux1->alumno->datos->Nombre));
		strcpy(nuevo->alumno->datos->Nombre,aux1->alumno->datos->Nombre);
		nuevo->alumno->datos->Apellido= (char*) malloc(sizeof(char) * strlen(aux1->alumno->datos->Apellido));
		strcpy(nuevo->alumno->datos->Apellido,aux1->alumno->datos->Apellido);
		nuevo->alumno->datos->Edad = aux1->alumno->datos->Edad;
		nuevo->alumno->datos->clase = aux1->alumno->datos->clase;
		nuevo->alumno->notas->ingles = aux1->alumno->notas->ingles;
		nuevo->alumno->notas->literatura = aux1->alumno->notas->literatura;
		nuevo->alumno->notas->matematicas = aux1->alumno->notas->matematicas;
		nuevo->alumno->notas->recreo = aux1->alumno->notas->recreo;
		nuevo->nodosig = NULL;
		//Ya con el nodo creado y lleno lo paso a la lista
		nuevo->nodosig = *Inicio2;
		*Inicio2 = nuevo;
		anterior = aux1;
		aux1 = aux1->nodosig;
		Eliminar_Nodo(anterior);
	}
}
