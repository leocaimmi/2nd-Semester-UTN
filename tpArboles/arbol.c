#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

nodoArbol *  inicArbol()
{
    return NULL;
}

nodoArbol * crearUnNodoArbol(int aux)
{
    nodoArbol * nuevo = (nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->dato = aux;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

nodoArbol * insertar(nodoArbol * raiz,int aux)
{
    if(raiz!= NULL)
    {

        if(raiz->dato > aux)
        {
            raiz->izq = insertar(raiz->izq,aux);
        }
        else
        {
            raiz->der = insertar(raiz->der,aux);
        }
    }
    else
    {
        raiz = crearUnNodoArbol(aux);
    }
    return raiz;
}

nodoArbol * buscarYretornar(nodoArbol * raiz,int datoAux)
{
    nodoArbol * aux = NULL;
    if(raiz!=NULL)
    {
        if(raiz->dato == datoAux)
        {
            aux = raiz;
        }
        else
        {
            if(raiz->dato<datoAux)
            {
                aux= buscarYretornar(raiz->izq,datoAux);

            }
            else
            {
                aux = buscarYretornar(raiz->der,datoAux);
            }
        }

    }

    return aux;
}

void mostrarPreOrden(nodoArbol * raiz)
{
    if(raiz!= NULL)
    {
        printf("|%i|",raiz->dato);
        mostrarPreOrden(raiz->izq);
        mostrarPreOrden(raiz->der);
    }
}

void mostrarInorden(nodoArbol * raiz)
{
    if(raiz!= NULL)
    {
        mostrarInorden(raiz->izq);
        printf("|%i|",raiz->dato);
        mostrarInorden(raiz->der);
    }
}

void mostrarPosOrden(nodoArbol * raiz)
{
    if(raiz!= NULL)
    {
        mostrarPosOrden(raiz->izq);
        mostrarPosOrden(raiz->der);
        printf("|%i|",raiz->dato);
    }

}


nodoArbol * borrarUnNodo(nodoArbol * raiz,int dato)
{
    nodoArbol * aux= inicArbol();
    if(raiz!= NULL)
    {
        if(raiz->dato == dato)
        {

            if(esHoja(raiz)==1)
            {
                free(raiz);
                raiz = NULL;
            }

            else if(raiz->izq != NULL)
            {
                aux = NMD(raiz->izq);
                raiz->dato = aux->dato;
                raiz->izq = borrarUnNodo(raiz->izq,aux->dato);
            }
            else if(raiz->der != NULL)
            {
                aux = NMI(raiz->der);
                raiz->dato = aux->dato;
                raiz->der = borrarUnNodo(raiz->der,aux->dato);
            }
        }
        else if(dato > raiz->dato)
        {
            raiz->der = borrarUnNodo(raiz->der,dato);
        }
        else
        {
            raiz->izq = borrarUnNodo(raiz->izq,dato);
        }
    }

    return raiz;
}

nodoArbol * NMI(nodoArbol*  raiz)
{
    if(raiz->izq!= NULL)
    {
        raiz = NMI(raiz->izq);

    }


    return raiz;
}

nodoArbol * NMD(nodoArbol*  raiz)
{
    if(raiz->der!= NULL)
    {
        raiz = NMD(raiz->der);

    }

    return raiz;
}

int esHoja(nodoArbol * raiz)///agregar a la libreria de arboles
{

    if(raiz!= NULL)
    {
        if(raiz->izq == NULL && raiz->der == NULL)
        {
            return 1;
        }
        else
        {
            return 0;

        }
    }
}


















