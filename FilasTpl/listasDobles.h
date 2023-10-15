#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED
#include "listaSimple.h"
typedef struct{

stCliente dato;
struct nodoDoble * siguiente;
struct nodoDoble * anterior;

}nodoDoble;

nodoDoble * inicNodoDoble();
nodoDoble * crearUnNodoDoble(stCliente aux);
nodoDoble * agregarAlPpioFinal(nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * agregarAlFinalDoble(nodoDoble * listaDoble,nodoDoble * nuevo);
nodoDoble * buscarUltimoDoble(nodoDoble * listaDoble);
void mostrarListaDoble(nodoDoble * lista);
nodoDoble* agregarOrdenadoDoble(nodoDoble* lista, nodoDoble* nuevoNodo);
nodoDoble* borrarPrimero(nodoDoble* lista);
#endif // LISTASDOBLES_H_INCLUDED
