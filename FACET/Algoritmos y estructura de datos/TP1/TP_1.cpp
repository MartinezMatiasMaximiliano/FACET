#include <iostream>
#include <stdlib.h>

struct Nodo{
	int dato;
	Nodo *siguiente;
};
typedef struct Nodo *Lista;

Lista CrearLista ();
Lista *Insertar (Lista *l, int n);
Lista Borrar (Lista l);
bool EsListaVacia(Lista l);
void Mostrar (Lista l);
int Longitud(Lista l);
bool Pertenese(Lista l, int n);
int SumaMayores(Lista l, int n);
int PrimerElemento(Lista l);

int main(int argc, char** argv) {
	
	int Opcion,n,suma;
	Lista Numeros;
	bool t=false;
	do{
		printf("----MENU----\n");
		printf("1. Crear Lista\n");
		printf("2. Insertar a la lista\n");
		printf("3. Borrar\n");
		printf("4. Es una Lista vacia\n");
		printf("5. Mostrar Lista\n");
		printf("6. Longitud de lista\n");
		printf("7. Pertenece a la lista\n");
		printf("8. Primer elemento de la lista\n");
		printf("9. Suma\n");
		printf("0. Salir\n\n");
		scanf("%d",&Opcion);
		
		switch (Opcion){
			case 1:
				Numeros=CrearLista();
				break;
			case 2:
				//getchar();
				printf("Ingrese un numero: ");
				scanf("%d",&n);
				Numeros = *Insertar(&Numeros ,n);
				break;
			case 3:
				Numeros = Borrar(Numeros);
				break;
			case 4:
				if (Numeros == NULL) t=true;
				if(t) printf("La lista esta vacia\n\n");
				else printf("La lista contiene elementos");
				break;
			case 5:
				Mostrar(Numeros);
				printf("\n\n");
				break;
			case 6:
				printf("La longitud de la lista es: %d",Longitud(Numeros));
				break;
			case 7:
				//getchar();
				printf("Ingrese un numero para verificar: ");
				scanf("%d",&n);
				if(Pertenese(Numeros,n)) printf("El numero pertenese a la lista");
				else printf("El numero no pertenese a la lista");
				break;
			case 8:
				printf("El primer elemento es: %d\n\n",PrimerElemento(Numeros));
				break;
			/*case 9:
				getchar();
				printf("Ingrese un numero para verificar: ");
				scanf("%d",&n);
				suma=SumaMayores(Numeros,n);
				printf("la suma es: %d",suma);
				break;*/
		}
		
	}while(Opcion!=0);
		
	return 0;
}

Lista CrearLista(){
	return NULL;
}

Lista *Insertar (Lista *l, int n){
	Nodo *Nuevo;
	Nuevo = new Nodo;
	Nuevo->dato=n;
	Nuevo->siguiente=NULL;
	if(l==NULL){
		*l=Nuevo;
	}
	else{
		Nuevo->siguiente=*l;
		*l = Nuevo;	
	}
	return l;		
}

Lista Borrar (Lista l){
	if(l==NULL){
		return l;
	}
	else{
		Nodo *Aux=l;
		l=l->siguiente;
		free(Aux);
	}
	return l;
}

bool EsLIstaVacia(Lista l){
	if(l==NULL) return true;
	else return false;
}

void Mostrar (Lista l){
	Nodo *Aux=l;
	while(Aux!=NULL){
		printf("valor: %d\n",Aux->dato);
		Aux->siguiente;
	}
	
}

int Longitud(Lista l){
	int Longitud=0;
	Nodo *Aux=l;
	if (EsLIstaVacia(l)){
		printf("Lista vacia");
	}
	else{
		while(Aux!=NULL){
			Longitud++;
			Aux->siguiente;
		}
	}
	return Longitud;
}

bool Pertenese(Lista l, int n){
	Nodo *Aux=l;
	bool Pertenese=false;
	while (Aux!=NULL){
		if(Aux->dato == n){
			Pertenese=true;
		}
	}
	return Pertenese;
}

int PrimerElemento(Lista l){
	Nodo *Aux=l;
	return Aux->dato;
}

/*int SumaMayores(Lista l, int n){
	int suma=0;
	//bool f=EsListaVacia(l);
	if (l==NULL){
		printf("Lista vacia");
	}
	else{
		while(f !=true){
			if(PrimerElemento(l) > n) suma+=PrimerElemento(l);
			Borrar(l);
			f=EsListaVacia(l);
		}
	}
	return suma;
}*/


