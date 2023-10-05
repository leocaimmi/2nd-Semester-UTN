#include <stdio.h>
#include <stdlib.h>
#include "listasDobles.h"

nodoDoble * inicListaDoble()
{
    return NULL;
}

int preguntarUnDato()
{

    int dato = 0;

    printf("Ingrese un dato entero: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}

void mostrarUnDatoEntero(int aux)
{

    printf("\n.............................................\n");
    printf("Dato:|%i|\n",aux);
    printf(".............................................\n");

}

void mostrarLista(nodoDoble * lista)
{

    while(lista!= NULL)
    {
        mostrarUnDatoEntero(lista->dato);
        lista = lista->siguiente;
    }


}


nodoDoble * crearUnNodoDoble(int aux)
{


    nodoDoble * nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    return nuevo;
}

nodoDoble * agregarAlPpio(nodoDoble * lista, nodoDoble * nuevo)
{

    nuevo->siguiente = lista;
    if(lista!= NULL)
    {
        lista->anterior = nuevo;
    }
    return nuevo;
}

nodoDoble * agregarAlFinal(nodoDoble * lista, nodoDoble * nuevo)
{

    if(lista!=NULL)
    {
        nodoDoble * ultimo = buscarUltimoNodo(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;

    }
    else
    {
        lista = nuevo;
    }




    return lista;
}

nodoDoble * buscarUltimoNodo(nodoDoble * lista)
{

    while(lista!= NULL && lista->siguiente != NULL)
    {

        lista = lista->siguiente;
    }
    return lista;
}

nodoDoble * agregarEnOrden(nodoDoble * lista,nodoDoble * nuevo)
{

    if(lista != NULL)
    {
        if(lista->dato > nuevo->dato)
        {
            lista = agregarAlPpio(lista,nuevo);
        }
        else
        {
            nodoDoble * ante = lista;
            nodoDoble * seg = lista;
            while(seg!= NULL && seg->dato < nuevo->dato)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            if(seg != NULL)
            {
                seg->anterior = nuevo;
            }
            ante->siguiente = nuevo;
            nuevo->anterior = ante;
            nuevo->siguiente = seg;

        }

    }
    else
    {
        lista = nuevo;
    }

    return lista;
}

nodoDoble * borrarUnNodo(nodoDoble * lista,int datoBorrar)
{
    if(lista!= NULL)
    {
        nodoDoble * seg = lista;
        nodoDoble * ante = lista;
        if(seg->dato == datoBorrar)
        {
            lista = lista->siguiente;
            seg->siguiente = NULL;
            free(seg);

        }
        else
        {

            nodoDoble * aux = lista;
            while(seg!= NULL && seg->dato != datoBorrar)
            {
                ante = seg;
                seg = seg->siguiente;
                if(seg != NULL)
                {
                    aux = seg->siguiente;
                }

            }
            if(seg!= NULL)
            {
                aux = seg->siguiente;
                ante->siguiente = aux;
                if(aux != NULL)
                {
                    aux->anterior = ante;
                }
                free(seg);

            }
            else
            {
                puts("No se encontro el dato");
            }

        }

    }

    return lista;
}
