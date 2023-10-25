#include <stdio.h>
#include <stdlib.h>
#include "menu.h"


void menu()
{
    ///var aux
    char op = 's';
    int opSw = 0;
    int legajo = 0;
    int cantArbol = 0;
    char nombreBuscar[15];
    nodoArbol * auxArbol = inicArbol();
    nodoSimple * auxLista = inicLista();
    ///punteros al principio
    nodoArbol * raiz = inicArbol();
    nodoSimple * lista = inicLista();

    do
    {
        opcionesSw();
        opSw = preguntarDato();

        switch(opSw)
        {
        case 1:
            for(int i = 0; i<rand()%10+1; i++)
            {
                raiz = insertarPorLegajo(raiz,crearUnNodoArbol(crearUnaPersona()));
            }
            if(raiz != NULL)
            {
                puts("Carga exitosa");
            }
            break;
        case 2:
            if(raiz!= NULL)
                mostrarInorder(raiz);
            break;
        case 3:
            if(raiz!= NULL)
            {
                lista = arbolALista(raiz,lista);
                mostrarListaSimple(lista);
            }
            else
            {
                puts("Realizar el punto 1.");
            }
            break;
        case 4:
            if(raiz!= NULL)
            {
                puts("..................INGRESE EL NRO DE LEGAJO A BUSCAR....................");
                legajo = preguntarDato();
                auxArbol = buscarNodoPorLegajoArbol(raiz,legajo);
                if(auxArbol!= NULL)
                {
                    mostrarInorder(auxArbol);
                }
                else
                {
                    puts("No se encontro el Nro de legajo...");
                }
            }
            else
            {
                puts("Realizar el inciso 1");
            }
            break;
        case 5:
            if(lista != NULL)
            {
                printf("Ingrese el nombre a buscar: ");
                fflush(stdin);
                scanf("%s",&nombreBuscar);

                auxLista =  buscarNodoPorNombreLista(lista,nombreBuscar);
                if(auxLista!= NULL)
                {
                    mostrarPersona(auxLista->dato);
                }
                else
                {
                    puts("No se encontro el nombre...");
                }
            }
            else
            {
                puts("Realizar el inciso 1 y el 3");
            }
            break;
        case 6:
            if(raiz!= NULL)
            {


                cantArbol = calcularAlturaDelArbol(raiz);
                printf("\nLa altura del arbol es:|%i| \n",cantArbol);
            }
            else
            {
                puts("Realizar inciso 1");
            }
            break;
        case 7:
            if(raiz!= NULL)
            {
                cantArbol = calcularCantidadDeNodosArbol(raiz);

                printf("\nLa cantidad de nodos del arbol es:|%i| \n",cantArbol);
            }
            else
            {
                puts("Realizar inciso 1");
            }
            break;
        case 8:
            if(raiz != NULL)
            {

                cantArbol= calcularCantidadHojasArbol(raiz);
                printf("\nLa cantidad de hojas del arbol es:|%i| \n",cantArbol);
            }
            else
            {
                puts("Realizar inciso 1");
            }

            break;
        case 9:

            break;

        default:
            puts("Opcion invalida,Reintente...");
            break;

        }


        puts("....................................................");
        printf("\nIngrese (S) para continuar,(N) para finalizar: ");
        fflush(stdin);
        scanf("%c",&op);
        system("cls");

    }
    while(op == 's'||op == 'S');


}
void opcionesSw()
{

    printf("1.Agregar nodos al arbol(Por legajos) \n");
    printf("2.Mostrar en orden el arbol(Inorder) \n");
    printf("3.Agregar los datos de un arbol a una lista simple \n");
    printf("4.Buscar nodo por legajo y retornarlo(arbol) \n");
    printf("5.Buscar nodo por nombre y retornarlo(lista) \n");
    printf("6.Calcular altura del arbol \n");
    printf("7.Calcular la cantidad de nodos de un arbol \n");
    printf("8.Calcular la cantidad de hojas de un arbol \n");
    printf("9.Borrar un nodo de un arbol \n");

}

int preguntarDato()
{

    int dato = 0;
    printf("Ingrese el dato solicitado: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}

