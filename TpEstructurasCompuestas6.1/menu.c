#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "menu.h"


void menu()
{

    char op = 's';
    int opSw = 0;

    ///arreglo de listas
    int dim = 50;
    int validos = 0;
    celda arregloDeListas[dim];

    do
    {
        opciones();
        opSw = preguntarDatoEntero();
        switch(opSw)
        {
    case 1:
    cargarRegistro();
    mostrarArchivo();
        break;
    case 2:
    validos = pasarArchivoALista(arregloDeListas,dim);
    mostrarCeldas(arregloDeListas,validos);
        break;
    case 3:
     aprobadosToArchivo(arregloDeListas,validos);
      mostrarArchivoAprobados();
        break;
    default:
    puts("Opcion invalida");
        break;
        }

        printf("[S]Para continuar en el menu\n");
        printf("[N]Para finalizar el programa\n");
        fflush(stdin);
        scanf("%c",&op);


    }while(op == 'S'|| op == 's');



}

void opciones()
{
    printf("[1]Cargar archivo\n");
    printf("[2]Archivo a lista\n");
    printf("[3]Aprobados al archivo\n");



}

int preguntarDatoEntero()
{
    int dato = 0;
    printf("Ingrese el dato solicitado: ");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;
}
