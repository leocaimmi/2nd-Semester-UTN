#include <stdio.h>
#include <stdlib.h>
#include "filas.h"


void menu(char archivo[])
{
///listas
    nodoSimple * listaSimple = inicNodoSimple();
    nodoDoble * listaDoble = inicNodoDoble();

///fila
    Fila cajas[5];
    inicializarArregloFilas(cajas);
    asignarDatosFila(cajas);
    ///auxiliares
    float menorPromedio = 0;
    char op;
    int opSw = 0;

    do
    {

        opciones();
        opSw = preguntarDato();
        system("cls");

        switch(opSw)
        {
        case 1:
            listaSimple = cargarMuchosClientes(listaSimple);
            mostrarLista(listaSimple);
            break;
        case 2:
            if(listaSimple != NULL)
            {
                asignarClientesALasCajas(cajas,listaSimple);
                mostrarCajas(cajas);
            }
            else
            {
                puts("Realizar inciso 1 para ejecutar esta opcion");
            }

            break;
        case 3:

            puts("\n\n....................Cajas al principio del dia...........................\n\n");
            mostrarCajas(cajas);
            atenderClientes(cajas,archivo);
            puts("\n\n.....................Archivo de clientes.................................\n\n");
            mostrarArchivo(archivo);
            puts("\n\n....................Cajas al final del dia...........................\n\n");
            atenderClientes(cajas,archivo);
            mostrarCajas(cajas);
            break;
        case 4:
            if(cajas[0].primero!= NULL)
            {
                menorPromedio = mostrarPromedioDeLasCajas(cajas);
            }
            else
            {
                puts("Realizar inciso 1 y 2 para ejecutar este punto");
            }
            break;
        case 5:
            if(menorPromedio != 0) ///atado con alambres
            {
                printf("El menor promedio es:|%.2f|\n",menorPromedio);
            }
            else
            {
                puts("Realizar inciso 1,2 y 4 para este punto");
            }
            break;
        case 6:
            if(archivo != NULL)
            mostrarArchivo(archivo);///clientes del archivo
            break;
        case 7:
            mostrarCajas(cajas);
            break;
        case 8:
            if(listaSimple != NULL)
            {
                mostrarLista(listaSimple);///clientes cargados aleatoriamente
            }
            else
            {
                puts("Realizar inciso 1 para ejecutar esta opcion");
            }

            break;
        default:
            puts("Opcion invalida");
            break;


        }

        printf("Si quiere continuar en el sistema(S),(N) para finalizar:  ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }
    while(op == 's'||op== 'S');


}

int preguntarDato()
{
    int dato = 0;

    printf("Ingrese el dato solicitado: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}

void opciones()
{


    puts("1.Cargar clientes");
    puts("2.Agregar clientes a la caja");
    puts("3.Atender y pasar al archivo");
    puts("4.Mostrar total de cada caja");
    puts("5.Mostrar menor promedio");
    puts("6.Mostrar solo el archivo de clientes");
    puts("7.Mostrar solo la caja");
    puts("8.Mostrar la lista simple");

}
