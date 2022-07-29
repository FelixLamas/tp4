#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}Tarea;

int CargarEmpleados(void); // funcion que controla la cantidad empleados

int main(int argc, char const *argv[])
{
    int cantidadTareas, cantidadEmpleados;
    Tarea **arregloTareas;
    cantidadEmpleados = CargarEmpleados();
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