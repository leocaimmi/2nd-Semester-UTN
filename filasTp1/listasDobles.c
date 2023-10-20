#include <stdio.h>
#include <stdlib.h>
#include "listasDobles.h"

nodoDoble * inicNodoDoble()
{
    return NULL;
}

nodoDoble * crearUnNodoDoble(stCliente aux)
{

    nodoDoble * nuevo = (nodoDoble*) malloc(sizeof(nodoDoble));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}
nodoDoble * agregarAlPpioFinal(nodoDoble * lista, nodoDoble * nuevo)
{

    nuevo->siguiente = lista;
    if(lista!= NULL)
    {
        lista->anterior = nuevo;
    }
    return nuevo;
}
nodoDoble * agregarAlFinalDoble(nodoDoble * listaDoble,nodoDoble * nuevo)
{

    if(listaDoble!= NULL)
    {
        nodoDoble * ulti  = buscarUltimoDoble(listaDoble);
        ulti->siguiente = nuevo;
        nuevo->anterior = ulti;

    }
    else
    {
        listaDoble = nuevo;
    }

    return listaDoble;
}

nodoDoble * buscarUltimoDoble(nodoDoble * listaDoble)
{


    while(listaDoble != NULL && listaDoble->siguiente != NULL)
    {
        listaDoble = listaDoble->siguiente;
    }

    return listaDoble;
}

void mostrarListaDoble(nodoDoble * lista)
{

    if(lista != NULL)
    {
        while(lista != NULL)
        {
            mostrarUnCliente(lista->dato);
            lista= lista->siguiente;
        }
    }
    else
    {
        puts("Caja vacia");
    }

}

nodoDoble* agregarOrdenadoDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    if(lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(lista->dato.cantFacturas > nuevoNodo->dato.cantFacturas)
        {
            lista=agregarAlPpioFinal(lista, nuevoNodo);
        }
        else
        {
            nodoDoble* seg=lista;
            nodoDoble* ante;
            while(seg!=NULL && seg->dato.cantFacturas < nuevoNodo->dato.cantFacturas)
            {
                ante=seg;
                seg=seg->siguiente;
            }

            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
            if(seg!=NULL)
            {
                nuevoNodo->anterior=ante;
                seg->anterior=nuevoNodo;
            }

        }
    }

    return lista;
}
nodoDoble* borrarPrimero(nodoDoble* lista)
{
    nodoDoble* aux=lista;

    if(lista!=NULL)
    {
        lista=lista->siguiente;

        if(lista!=NULL)

            lista->anterior=NULL;

        free(aux);
    }
    return lista;
}
