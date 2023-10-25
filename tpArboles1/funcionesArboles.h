#ifndef FUNCIONESARBOLES_H_INCLUDED
#define FUNCIONESARBOLES_H_INCLUDED
#include "listasSimples.h"


typedef struct nodoArbol
{
    stPersona dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;


nodoArbol * inicArbol();


nodoArbol * crearUnNodoArbol(stPersona aux);
nodoArbol * insertarPorLegajo(nodoArbol * raiz,nodoArbol * nuevo);
void mostrarInorder(nodoArbol * raiz);
void mostrarPreOrder(nodoArbol * raiz);
void mostrarPosOrder(nodoArbol * raiz);

nodoSimple * arbolALista(nodoArbol * raiz,nodoSimple * lista);
nodoArbol * buscarNodoPorLegajoArbol(nodoArbol * raiz, int legajo);
nodoSimple * buscarNodoPorNombreLista(nodoSimple * lista,char nombreBuscar[]);

int  calcularAlturaDelArbol(nodoArbol * raiz);
int calcularCantidadDeNodosArbol(nodoArbol * raiz);
int calcularCantidadHojasArbol(nodoArbol * raiz);

nodoArbol * borrarUnNodo(nodoArbol * raiz,int auxLegajo);
int esHoja(nodoArbol * raiz);
int esHojaTernario(nodoArbol*raiz);

nodoArbol * NMD(nodoArbol * raiz);
nodoArbol * NMI(nodoArbol * raiz);


#endif // FUNCIONESARBOLES_H_INCLUDED
