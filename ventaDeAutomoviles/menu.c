#include <stdio.h>
#include <stdlib.h>
#include "auto.h"

void limpiarPantalla(){
system("cls");
}


void menu()
{
    ///variables auxiliares
    int opSw = 0;
    char op = 's';
    int dim = 10;
    int suma = 0;
    stAutomovil arregloDeAutos[dim];
    int validos = 0;
    nodoAuto* auxNodo = inicAuto();
    ///lista
    nodoAuto* lista = inicAuto();



    do
    {
        opciones();
        opSw = preguntarDato();


        switch(opSw)
        {
        case 1:
        auxNodo = crearUnNodoDeAuto(crearUnAuto());
        mostrarAutomovil(auxNodo->dato);
            break;
        case 2:

            agregarFinal(&lista,auxNodo);
            mostrarListaAuto(lista);
            break;
        case 3:
            validos = insertarCelda(arregloDeAutos,dim,lista->dato,validos);
            mostrarArregloAutos(arregloDeAutos,validos);
            break;
        case 4:
        agregarMuchosAutos(&lista);
        mostrarListaAuto(lista);
            break;
        case 5:
        mostrarListaAuto(lista);
        validos = pasarAlArreglo(lista,arregloDeAutos,dim);
        mostrarArregloAutos(arregloDeAutos,validos);
            break;
        case 6:
        mostrarArregloRecursivo(arregloDeAutos,0,validos);
            break;
        case 7:
        suma = sumarPatente(lista);
        printf("Suma total de patentes pares:|%i|\n",suma);
            break;

        default:
            puts("Error, opcion invalida.REINTENTE...");
            break;

        }
        puts("Desea realizar otra operacion?(S/N)");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();

    }
    while(op == 's'|| op == 'S');







}

void opciones()
{

    puts("1.Crear un auto");
    puts("2.Agregar el auto al final de la lista");
    puts("3.Insertar un auto a un arreglo por valor");
    puts("4.Agregar la cantidad de autos que desee");
    puts("5.Pasar de la lista al arreglo de forma ordenada");
    puts("6.Mostrar arreglo de forma recursiva");
    puts("7.Sumar de forma recursiva los valores de las patentes pares");
    puts("-----------------------------------------");




}

int preguntarDato()
{
    int dato = 0;
    puts("Ingrese el dato solicitado: ");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;

}
