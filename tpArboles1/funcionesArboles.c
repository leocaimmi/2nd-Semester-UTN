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

/**1.Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por legajo). */

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


/**2.Hacer tres funciones, una función que recorra el árbol y muestre su contenido en orden (verificar cual de los recorridos es conveniente: inorder, posorder o preorder)*/

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
/**3.Hacer una función que copie el contenido del árbol en una lista simplemente enlazada.*/

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
/**4.Hacer una función que busque un nodo por legajo y lo retorne.*/

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


/**5.Hacer una función que busque un nodo por nombre. Cuidado, el árbol está ordenado por legajo.*/

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

/**6.Hacer una función que calcule la altura que tiene el árbol.*/

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

/**7.Hacer una función que calcule la cantidad de nodos del árbol. */

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

/**8.Hacer una función que calcule la cantidad de hojas del árbol. */

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

/*9.Hacer una función que borre un nodo de un árbol.*/

nodoArbol * borrarUnNodo(nodoArbol * raiz,int auxLegajo)///premisa mentirosa, no borramos el nodo efectivamente, sino que solo el dato
{
    ///verificar hojas  true or false

    ///del lado izquierdo el mayor,el mayor de los menores a full(buscar mayor...)NMD(nodo mas derecho)
    ///del lado derecho el menor,el menor de los mayores a full(buscar menor...)NMI(nodo mas izquierda)
    ///reemplazo el que quiero borrar con el que encontre.
    ///ahora borra al dato
    if(raiz != NULL)
    {
        if(raiz->dato.legajo == auxLegajo)
        {
            nodoArbol*aux;
            if(esHojaTernario(raiz))
            {
                free(raiz);
                raiz=NULL;
            }
            else if(raiz->izq!= NULL)
            {
                aux= NMD(raiz->izq);
                raiz->dato = aux->dato;
                raiz->izq = borrarUnNodo(raiz->izq,aux->dato.legajo);

            }
            else if(raiz->der != NULL)
            {
                aux = NMI(raiz->izq);
                raiz->dato = aux->dato;
                raiz->der = borrarUnNodo(raiz->der,aux->dato.legajo);
            }

        }
        else if(auxLegajo< raiz->dato.legajo)
        {
            raiz->izq = borrarUnNodo(raiz->izq,auxLegajo);

        }
        else
        {
            raiz->der = borrarUnNodo(raiz->der,auxLegajo);
        }
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

int esHojaTernario(nodoArbol*raiz)
{
    return (raiz && !raiz->izq && !raiz->der);
}


nodoArbol * NMD(nodoArbol * raiz)
{

    if(raiz!= NULL)
    {
        if(raiz->der != NULL)
        {

            raiz = NMD(raiz->der);
        }
    }

    return raiz;
}

nodoArbol * NMI(nodoArbol * raiz)
{

    if(raiz!= NULL)
    {
        if(raiz->izq != NULL)
        {

            raiz = NMI(raiz->izq);
        }
    }

    return raiz;
}






