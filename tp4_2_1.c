#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

int CargarEmpleados(void); // funcion que controla la cantidad empleados
int CargarCantTareas(void);
void CargarTareasEmpleado(Tarea *arregloTareasP, int cantidadTareas);
void ListarTareas(Tarea *arregloT, int cantT);
void ControlTareas(Tarea *arregloTP, Tarea *arregloTR, int cantT);

int main(int argc, char const *argv[])
{
    int cantidadTareas, cantidadEmpleados;
    Tarea *arregloTareasP, *arregloTareasR;
    //cantidadEmpleados = CargarEmpleados();
    cantidadTareas = CargarCantTareas();
    arregloTareasP = (Tarea *)malloc(sizeof(Tarea) * cantidadTareas);
    arregloTareasR = (Tarea *)malloc(sizeof(Tarea) * cantidadTareas);
    CargarTareasEmpleado(arregloTareasP, cantidadTareas);
    ControlTareas(arregloTareasP, arregloTareasR, cantidadTareas);
    printf("Tareas Realizadas\n");
    ListarTareas(arregloTareasR, cantidadTareas);
    printf("Tareas Pendientes\n");
    ListarTareas(arregloTareasP, cantidadTareas);

    return 0;
}

int CargarEmpleados(void)
{
    int cant;
    printf("Ingrese la cantidad de empleados:");
    scanf("%d", &cant);
    if (cant>=1)
    {
        return cant;
    }
    else
    {
        return CargarEmpleados();
    }    
}

int CargarCantTareas(void)
{
    int tareas;
    printf("Ingrese la cantidad de tareas a realizar:");
    scanf("%d", &tareas);
    getchar();
    if (tareas>=1)
    {
        return tareas;
    }
    else
    {
        return CargarCantTareas();
    }   
}

void CargarTareasEmpleado(Tarea *arregloTareasP, int cantidadTareas)
{
    char buff[100];
    srand(time(NULL));
    for (int i = 0; i < cantidadTareas; i++)
    {
        arregloTareasP[i].TareaID = i + 1;
        printf("Tarea: %d", arregloTareasP[i].TareaID);
        printf("Ingrese la descripcion de la tarea:");
        gets(buff);
        getchar();
        arregloTareasP[i].Descripcion = (char *)malloc(sizeof(char) * strlen(buff));
        strcpy(arregloTareasP[i].Descripcion, buff);
        arregloTareasP[i].Duracion = 10 + rand() % 90;
    }
    printf("\n");
}

void ListarTareas(Tarea *arregloT, int cantT)
{
    for (int i = 0; i < cantT; i++)
    {
        if (arregloT[i].TareaID)
        {
            printf("Tarea %d\n", arregloT[i].TareaID);
            printf("Descripcion de la tarea:");
            puts(arregloT[i].Descripcion);
            printf("Tiempo de ejecucion de la tarea: %d\n", arregloT[i].Duracion);
        }
        
    }    
}

void ControlTareas(Tarea *arregloTP, Tarea *arregloTR, int cantT)
{
    char realizada = 'n';
    for (int i = 0; i < cantT; i++)
    {
        printf("¿La tarea %d fue realizada?", arregloTP[i].TareaID);
        scanf("%c", &realizada);
        getchar();
        if (realizada == 's')
        {
            arregloTR[i].TareaID = arregloTP[i].TareaID;
            arregloTR[i].Descripcion = (char *)malloc(sizeof(char) * strlen(arregloTP[i].Descripcion));
            strcpy(arregloTR[i].Descripcion, arregloTP[i].Descripcion);
            arregloTR[i].Duracion = arregloTP[i].Duracion;
            arregloTP[i].TareaID = NULL;
            arregloTP[i].Descripcion = NULL;
            arregloTP[i].Duracion = NULL;
        }
        else
        {
            arregloTR[i].TareaID = NULL;
            arregloTR[i].Descripcion = NULL;
            arregloTR[i].Duracion = NULL;
        }
        
    }
    
}