#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void menu()
{
    ///auxiliares
    char op = 's';
    int opSw = 0, dato = 0;
    char nombreDirector[20];
    char peliAux[20];
    int validos  = 0;
    int dim = 10;
    int posDirector = 0;
    stPelicula aux;
    nodoArbolPeli * auxArbol;
    ///estructura compuesta
    celda arregloArboles[dim];


    do
    {

        opcionesMenu();
        puts("........................Ingrese una opcion...........................");
        opSw = preguntarDatoEntero();

        switch(opSw)
        {
        ///2 - Agregar un nuevo director o directora.
        case 1:
            validos  = inicArregloArboles(arregloArboles,validos,dim);
            mostrarTodasLasCeldas(arregloArboles,validos);

            break;
        case 2:
            ///3 - Buscar la celda de un director o directora de forma recursiva y devuelva su posición.

            printf("Que director desea buscar: ");
            fflush(stdin);
            scanf("%s",&nombreDirector);

            posDirector = buscarPosDirector(arregloArboles,nombreDirector,validos,0);
            if(posDirector>= 0)
            {
                printf("posicion del director:[%i]\n",posDirector);
                mostrarUnaCelda(arregloArboles[posDirector]);
            }
            else
            {
                puts("No existe el director");
            }

            break;
        case 3:
            ///4 - Insertar un nuevo elemento (Tenga en cuenta de que si la celda no existe debe ser creada).

            validos = altaNuevoDirector(arregloArboles,validos,dim);
            mostrarTodasLasCeldas(arregloArboles,validos);

            break;
        case 4:
            cargarPeliculas(arregloArboles,validos);
            mostrarTodasLasCeldas(arregloArboles,validos);

            break;
        case 5:
            do
            {
                aux = crearUnaPeli(arregloArboles,validos);
                printf("\n[S]para continuar\n");
                printf("[N]para finalizar\n");
                fflush(stdin);
                scanf("%c",&op);
            }
            while(op == 's'||op =='S');
            archiToArbol(arregloArboles,validos);
            mostrarTodasLasCeldas(arregloArboles,validos);
            break;
        case 6:
            mostrarTodasLasCeldas(arregloArboles,validos);
            break;
        case 7:
            printf("De que director es la pelicula: ");
            fflush(stdin);
            scanf("%s",&nombreDirector);
            printf("Como es el nombre de la pelicula: ");
            fflush(stdin);
            scanf("%s",&peliAux);

            aux = buscarPeliculaPorDirectorYNombre(arregloArboles,validos,nombreDirector,peliAux);
            mostrarInorder(crearUnNodoArbol(aux));
            break;
        case 8:
            printf("De que director es la pelicula: ");
            fflush(stdin);
            scanf("%s",&nombreDirector);
            printf("En que anio se hizo la pelicula: ");
            fflush(stdin);
            scanf("%i",&dato);


            mostrarPeliculasPorDirectorYAnio(arregloArboles,nombreDirector,dato,validos);
            break;
        default :
            puts("Ingrese una opcion correcta...");
            break;

        }
        printf("\n[S]para continuar\n");
        printf("[N]para finalizar\n");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }
    while(op == 's'|| op == 'S');


}

void opcionesMenu()
{
    printf("[1].Agregar directores\n");
    printf("[2].Mostrar posicion de un director\n");
    printf("[3].Insertar un nuevo director\n");
    printf("[4].Agregar peliculas a los directores(Directamente sin archivo)\n");
    printf("[5].Agregar peliculas hacia el archivo y cargar el arbol\n");
    printf("[6].Mostrar celdas\n");
    printf("[7].Buscar una pelicula por direccion y nombre.\n");
}

int preguntarDatoEntero()
{
    int dato = 0;
    printf("Ingrese el dato solicitado: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}


