#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arboles.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearUnNodoArbol(int dato)
{
    nodoArbol*nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));

    nuevo->dato=dato;
    nuevo->derecha=NULL;
    nuevo->izquierda=NULL;

    return nuevo;
}

nodoArbol * insertar(nodoArbol*raiz,nodoArbol*nuevo)
{
    if(raiz != NULL)
    {
        if(nuevo->dato > raiz->dato)
        {
            raiz->derecha=insertar(raiz->derecha,nuevo);
        }
        else
        {
            raiz->izquierda=insertar(raiz->izquierda,nuevo);
        }
    }
    else
    {
        raiz=nuevo;
    }
}

void preOrder(nodoArbol * raiz)
{

    if(raiz != NULL)
    {
        mostrarDato(raiz->dato);
        preOrder(raiz->izquierda);
        preOrder(raiz->derecha);

    }

}

void inOrder(nodoArbol * raiz)
{

    if(raiz != NULL)
    {
        preOrder(raiz->izquierda);
        mostrarDato(raiz->dato);
        preOrder(raiz->derecha);

    }

}

void posOrder(nodoArbol * raiz)
{

    if(raiz != NULL)
    {
        preOrder(raiz->izquierda);
        preOrder(raiz->derecha);
        mostrarDato(raiz->dato);

    }

}



void mostrarDato(int dato)
{
    puts("----------------------------------------");
    printf("Dato:|%i|\n",dato);
    puts("----------------------------------------");

}

///1.a.Retornar la cantidad de nodos terminales. (hojas)

void contarHojas(nodoArbol* raiz, int* contador)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if (raiz->izquierda == NULL && raiz->derecha == NULL) ///VERSION CHATGPT
    {
        (*contador)++;
    }
    else
    {
        contarHojas(raiz->izquierda, contador);
        contarHojas(raiz->derecha, contador);
    }
}

int contarHojas2(nodoArbol* raiz)
{
    int contador = 0;

    if(raiz != NULL)
    {
        if (raiz->izquierda == NULL && raiz->derecha == NULL)///VERSION MIA(costo un poquito mas:) )
        {
            contador++;
        }
        else
        {
            contador+= contarHojas2(raiz->izquierda);
            contador+= contarHojas2(raiz->derecha);
        }
    }
    else
    {
        contador = 0;
    }
    return contador;
}

///1.b.Retornar la cantidad de nodos de grado 1.


///1.c.Informar si se encuentra un dato buscado en el árbol.

int encontrarDato(nodoArbol * raiz,int datoVerificar)
{

    int flag = 0;
    if(raiz != NULL)
    {
        if(raiz->dato == datoVerificar)
        {
            flag = 1;
        }
        flag += encontrarDato(raiz->izquierda,datoVerificar);
        flag += encontrarDato(raiz->derecha,datoVerificar);
    }


    return flag;
}



int buscarDatoRecursivoTernario(nodoArbol * raiz,int datoABuscar)
{
    return raiz ?(raiz->dato == datoABuscar ? 1 :(buscarDatoRecursivoTernario(raiz->izquierda, datoABuscar) || buscarDatoRecursivoTernario(raiz->derecha, datoABuscar))) : 0;
}

///1.d.Mostrar el contenido del árbol mediante el recorrido preorden.

///ya esta hecho
















