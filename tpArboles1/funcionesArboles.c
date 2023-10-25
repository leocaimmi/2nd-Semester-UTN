#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionesArboles.h"



nodoArbol * inicArbol()
{
    return NULL;
}


nodoArbol * crearUnNodoArbol(stPersona aux)
{

    nodoArbol * nuevo = (nodoArbol*) malloc(sizeof(nodoArbol));
    nuevo->dato = aux;
    nuevo->der = NULL;
    nuevo->izq = NULL;

    return nuevo;
}

/**1.Hacer una funci�n que permita ingresar nuevos nodos manteniendo el �rbol ordenado (por legajo). */

nodoArbol * insertarPorLegajo(nodoArbol * raiz,nodoArbol * nuevo)
{


    if(raiz != NULL)
    {
        if(raiz->dato.legajo > nuevo->dato.legajo)
        {

            raiz->izq = insertarPorLegajo(raiz->izq,nuevo);
        }
        else
        {
            raiz->der = insertarPorLegajo(raiz->der,nuevo);
        }


    }
    else
    {
        raiz = nuevo;
    }


    return raiz;
}


/**2.Hacer tres funciones, una funci�n que recorra el �rbol y muestre su contenido en orden (verificar cual de los recorridos es conveniente: inorder, posorder o preorder)*/

void mostrarInorder(nodoArbol * raiz)
{

    if(raiz != NULL)
    {
        mostrarPersona(raiz->dato);
        mostrarInorder(raiz->izq);///llamado recursivo
        mostrarInorder(raiz->der);///llamado recursivo


    }


}

void mostrarPreOrder(nodoArbol * raiz)
{

    if(raiz != NULL)
    {
        mostrarInorder(raiz->izq);///llamado recursivo
        mostrarPersona(raiz->dato);
        mostrarInorder(raiz->der);///llamado recursivo


    }


}

void mostrarPosOrder(nodoArbol * raiz)
{

    if(raiz != NULL)
    {
        mostrarInorder(raiz->izq);///llamado recursivo
        mostrarInorder(raiz->der);///llamado recursivo
        mostrarPersona(raiz->dato);

    }

}
/**3.Hacer una funci�n que copie el contenido del �rbol en una lista simplemente enlazada.*/

nodoSimple * arbolALista(nodoArbol * raiz,nodoSimple * lista)
{

    if(raiz!=NULL)
    {
        lista = agregarEnOrden(lista,crearUnNodoSimple(raiz->dato));
        lista = arbolALista(raiz->izq,lista);
        lista = arbolALista(raiz->der,lista);

    }

    return lista;
}
/**4.Hacer una funci�n que busque un nodo por legajo y lo retorne.*/

nodoArbol * buscarNodoPorLegajoArbol(nodoArbol * raiz, int legajo)
{

    nodoArbol * nuevo = inicArbol();
    if(raiz!= NULL)
    {
        if(raiz->dato.legajo == legajo)
        {
            nuevo = raiz;
            nuevo->izq = NULL;
            nuevo->der = NULL;
        }
        raiz->izq = buscarNodoPorLegajoArbol(raiz->izq,legajo);

        raiz->der = buscarNodoPorLegajoArbol(raiz->der,legajo);
    }


    return nuevo;
}


/**5.Hacer una funci�n que busque un nodo por nombre. Cuidado, el �rbol est� ordenado por legajo.*/

nodoSimple * buscarNodoPorNombreLista(nodoSimple * lista,char nombreBuscar[])
{


    nodoSimple * nuevo = NULL;
    if(lista!=NULL)
    {
        while(lista!= NULL && strcmpi(lista->dato.nombre,nombreBuscar)!= 0)
        {

            lista = lista->siguiente;
        }

        nuevo = lista;
        nuevo->siguiente = NULL;


    }

    return nuevo;
}

/**6.Hacer una funci�n que calcule la altura que tiene el �rbol.*/

int calcularAlturaDelArbol(nodoArbol * raiz)
{

    int contadorIzq = 0;
    int contadorDer = 0;
    int altura = 0;

    if(raiz!= NULL)
    {


        contadorIzq += calcularAlturaDelArbol(raiz->izq);
        contadorDer += calcularAlturaDelArbol(raiz->der);

        if(contadorIzq > contadorDer)
        {
            altura = contadorIzq+1;
        }
        else
        {
            altura = contadorDer+1;
        }

    }

    return altura;
}

/**7.Hacer una funci�n que calcule la cantidad de nodos del �rbol. */

int calcularCantidadDeNodosArbol(nodoArbol * raiz)
{
    int contador = 0;

    if(raiz!= NULL)
    {
        contador+=1;
        contador += calcularCantidadDeNodosArbol(raiz->izq);
        contador += calcularCantidadDeNodosArbol(raiz->der);

    }
    return contador;
}

/**8.Hacer una funci�n que calcule la cantidad de hojas del �rbol. */

int calcularCantidadHojasArbol(nodoArbol * raiz)
{

    int cantHojas = 0;

    if(raiz != NULL)
    {
        if(raiz->izq == NULL&&raiz->der == NULL)
        {
            cantHojas= 1;
        }
        else
        {
            cantHojas+= calcularCantidadHojasArbol(raiz->izq);
            cantHojas+= calcularCantidadHojasArbol(raiz->der);
        }

    }

    return cantHojas;
}

/**Hacer una funci�n que borre un nodo de un �rbol.*////falta hacer






