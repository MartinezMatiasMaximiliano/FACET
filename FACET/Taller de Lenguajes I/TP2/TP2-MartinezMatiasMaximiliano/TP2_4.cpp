#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//declarar tipo de estructura "PC"
typedef struct{
    int velocidad;
    int anio;
    int cantidad;
    char *tipo_cpu;
}PC;
char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

//declarar funciones
void CargarPC(PC *auxCargar,int cantEquipos);
void MostrarPC(PC *auxMostrar, int cantEquipos);
void Antigua(PC *auxAntigua,int cantEquipos);
void Veloz(PC *auxVeloz,int cantEquipos);

int main()
{
    srand(time(NULL));
    int cantEquipos;
    printf("Ingrese una cantidad de PCs a cargar: ");
    scanf("%d",&cantEquipos);
    PC *Comps = (PC*)malloc(cantEquipos * sizeof(PC)); // (tipo)malloc(veces * tamaño de (tipo))...preguntar

    //cargar
    CargarPC(Comps,cantEquipos);

    //mostrar
    MostrarPC(Comps,cantEquipos);

    //buscar la mas vieja
    Antigua(Comps,cantEquipos);

    //la mas veloz
    Veloz(Comps,cantEquipos);

    getchar();
    return 0;
}


void CargarPC(PC *auxCargar,int cantEquipos)
{
    int aux;    

    for (int i = 0; i < cantEquipos; i++)
    {
        (*(auxCargar+i)).velocidad = rand()%3 +1;
        (*(auxCargar+i)).anio = rand()%18 +2000;
        (*(auxCargar+i)).cantidad = rand()%4 +1;
        (*(auxCargar+i)).tipo_cpu = *(tipos + (rand()%6));
        
    }
    
}

void MostrarPC(PC *auxMostrar, int cantEquipos)
{
    for (int i = 0; i < cantEquipos; i++)
    {
        printf("");
        printf("Velocidad de procesamiento: %d GHz\n",(*(auxMostrar+i)).velocidad);
        printf("Anio de fabricacion: %d\n",(*(auxMostrar+i)).anio);
        printf("Cantidad de nucleos: %d\n",(*(auxMostrar+i)).cantidad);
        printf("Tipo de procesador: %s\n",(*(auxMostrar+i)).tipo_cpu);
        printf("\n");
    }
}

void Antigua(PC *auxAntigua,int cantEquipos){
   int i;
   PC aux;
   for (i = 0; i < cantEquipos; i++)
   {
        if(i == 0)
        {
            aux = *(auxAntigua+i); //cargarle el arreglo entero una vez
        }else
        {
            if((*(auxAntigua+i)).anio < aux.anio)
            {
                aux = *(auxAntigua+i);
            }
        }
   }
    printf("La computadora mas antigua es: \n");
    MostrarPC(&aux,1);
}

void Veloz(PC *auxVeloz,int cantEquipos){
   int i;
   PC aux;
   for (i = 0; i < cantEquipos; i++)
   {
        if(i == 0)
        {
            aux = *(auxVeloz+i);
        }else
        {
            if((*(auxVeloz+i)).anio < aux.velocidad)
            {
                aux = *(auxVeloz+i);
            }
        }
   }
    printf("La computadora mas Veloz es: \n");
    MostrarPC(&aux,1);
}
