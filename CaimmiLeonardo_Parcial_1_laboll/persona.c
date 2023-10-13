#include <stdio.h>
#include <stdlib.h>
#include "persona.h"



///2) Hacer una función para crear un nodoPersona.
///Hacer una función para que un usuario cargue una stPersona. Validar rango del DNI.

stPersona crearUnaPersona(nodoPersona * lista)
{

    stPersona aux;

    printf("Ingrese el nombre de la persona: ");
    fflush(stdin);
    scanf("%s",&aux.nombre);
    do
    {
        printf("Ingrese el DNI de la persona: ");
        fflush(stdin);
        scanf("%i",&aux.DNI);
    }
    while(verificarDniRecursivo(lista,aux.DNI)== 1||validarRangoDNI(aux.DNI)== 0);
    printf("Ingrese el telefono de la persona: ");
    fflush(stdin);
    scanf("%s",&aux.telefono);


    return aux;
}

int validarRangoDNI(int datoValidar)
{

    int flag = 0;
    if(datoValidar>0 && datoValidar <= 100)
    {
        flag = 1;
    }

    return flag;
}

void mostrarPersona(stPersona aux)
{

    puts("..............................................");
    printf("Nombre:|%s|\n",aux.nombre);
    printf("DNI:|%i|\n",aux.DNI);
    printf("Nro de telefono:|%s|\n",aux.telefono);
    puts("..............................................");


}

void mostrarListaSimple(nodoPersona * lista)
{

    while(lista!= NULL)
    {
        mostrarPersona(lista->dato);
        lista = lista->siguiente;
    }

}



nodoPersona * inicNodoPersona()
{
    return NULL;
}

nodoPersona * crearUnNodoPersona(stPersona aux)
{

    nodoPersona * nuevo = (nodoPersona*)malloc(sizeof(nodoPersona));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoPersona * agregarAlPpio(nodoPersona * lista,nodoPersona * nuevo)
{

    nuevo->siguiente = lista;

    return nuevo;
}
/**4) Hacer una función que agregue un nodoPersona al final de una lista de personas.
Hacer una función para cargar varias personas.
Verificar antes si está repetida en la lista usando el punto 1. */

nodoPersona * agregarAlFinalListaSimple(nodoPersona * lista,nodoPersona * nuevo)
{
    if(lista!= NULL)
    {

        nodoPersona * ultimo = buscarUltimoEnLaListaSimple(lista);
        ultimo->siguiente = nuevo;

    }
    else
    {
        lista = nuevo;
    }

    return lista;
}

nodoPersona * buscarUltimoEnLaListaSimple(nodoPersona * lista)
{

    while(lista != NULL && lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }
    return lista;
}

nodoPersona * cargarPersonasALaLista(nodoPersona * lista)
{
    char op = 's';
    nodoPersona * nuevo = NULL;
    stPersona aux;

    do
    {

        do
        {
            nuevo = crearUnNodoPersona(crearUnaPersona(lista));
        }
        while(verificarDniRecursivo(lista,nuevo->dato.DNI)== 1);
        lista = agregarAlFinalListaSimple(lista,nuevo);

        printf("(S)Si desea cargar otra persona,(N)para finalizar: ");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op == 'S'||op == 's');

    return lista;
}

///3) Hacer una función que muestre las personas de la lista. Tiene que ser recursiva.

void mostrarListaSimpleRecursiva(nodoPersona * lista)
{

    if(lista!= NULL)
    {
        mostrarListaSimpleRecursiva(lista->siguiente);
        mostrarPersona(lista->dato);

    }
}
///1) Hacer una función que dado un DNI evalúe si se encuentra en la lista de personas. Tiene que ser recursiva.

int verificarDniRecursivo(nodoPersona * lista,int dniABuscar)
{

    int flag = 0;
    if(lista!= NULL)
    {
        if(lista->dato.DNI != dniABuscar)
        {
            flag = verificarDniRecursivo(lista->siguiente,dniABuscar);
        }
        else
        {
            flag= 1;
        }

    }
    return flag;
}




