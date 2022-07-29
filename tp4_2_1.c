#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

int CargarEmpleados(void); // funcion que controla la cantidad empleados
int CargarCantTareas(void);

int main(int argc, char const *argv[])
{
    int cantidadTareas, cantidadEmpleados;
    Tarea **arregloTareasP;
    //cantidadEmpleados = CargarEmpleados();
    cantidadTareas = CargarCantTareas();
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
    if (tareas>=1)
    {
        return tareas;
    }
    else
    {
        return CargarCantTareas();
    }   
}