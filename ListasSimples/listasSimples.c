#include <stdio.h>
#include <stdlib.h>
#include "listasSimples.h"

nodo * inicLista()
{
    return NULL;
}

nodo* crearUnNodo(int aux)
{

    nodo * nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;

    return nuevo;
}

int preguntarDatoYdevolverlo()
{

    int dato  = 0;
    printf("Ingrese un dato: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}

void mostrarUnDato(int dato)
{

    printf("....................................\n");
    printf("dato:|%i|\n",dato);
    printf("....................................\n");
}

void mostrarListaSimple(nodo* lista)
{

    while(lista!= NULL)
    {
        mostrarUnDato(lista->dato);
        lista = lista->siguiente;
    }

}

nodo * agregarAlPpio(nodo * lista, nodo * nuevo)
{
    nuevo->siguiente = lista;

    return nuevo;
}

nodo * agregarAlFinal(nodo* lista,nodo * nuevo)
{

    if(lista!= NULL)
    {
        nodo * ultimo = buscarUltimoYRetornar(lista);
        ultimo->siguiente = nuevo;

    }
    else
    {
        lista = nuevo;
    }



    return lista;
}

nodo * buscarUltimoYRetornar(nodo * lista)
{
    while(lista != NULL && lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }

    return lista;
}

nodo * borrarUnNodo(nodo * lista,int datoAux)
{


    if(lista != NULL)
    {
        nodo * seg;
        nodo * ante;
        if(lista->dato == datoAux)
        {
            seg = lista;
            lista = lista->siguiente;
            free(seg);
        }
        else
        {
            seg= lista;
            while(seg != NULL && seg->dato != datoAux)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            if(seg != NULL){
            ante->siguiente = seg->siguiente;
            free(seg);
            }else{
            puts("No existe el dato");
            }


        }

    }

    return lista;
}

nodo * agregarOrdenado(nodo * lista,nodo * nuevo)
{

    if(lista != NULL)
    {
        if(lista->dato > nuevo->dato)
        {
            lista = agregarAlPpio(lista,nuevo);
        }
        else
        {
            nodo * seg = lista;
            nodo * ante;

            while(seg != NULL && seg->dato < nuevo->dato)
            {

                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;
        }

    }
    else
    {
        lista = nuevo;
    }

    return lista;
}












