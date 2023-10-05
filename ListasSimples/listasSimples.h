#ifndef LISTASSIMPLES_H_INCLUDED
#define LISTASSIMPLES_H_INCLUDED

typedef struct{

int dato;
struct nodo * siguiente;

}nodo;

nodo * inicLista();
nodo* crearUnNodo(int aux);
int preguntarDatoYdevolverlo();
void mostrarUnDato(int dato);

nodo * agregarAlPpio(nodo * lista, nodo * nuevo);
nodo * agregarAlFinal(nodo* lista,nodo * nuevo);
nodo * agregarOrdenado(nodo * lista,nodo * nuevo);
nodo * buscarUltimoYRetornar(nodo * lista);

nodo * borrarUnNodo(nodo * lista,int datoAux);

#endif // LISTASSIMPLES_H_INCLUDED
