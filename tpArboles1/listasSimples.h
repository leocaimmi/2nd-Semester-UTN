#ifndef LISTASSIMPLES_H_INCLUDED
#define LISTASSIMPLES_H_INCLUDED

typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} stPersona;


typedef struct
{
    stPersona dato;
    struct nodoSimple * siguiente;

} nodoSimple;

nodoSimple * inicLista();
stPersona crearUnaPersona();
void mostrarPersona();
nodoSimple * crearUnNodoSimple(stPersona aux);
nodoSimple * agregarAlPpio(nodoSimple * lista,nodoSimple * nuevo);
nodoSimple * agregarEnOrden(nodoSimple * lista,nodoSimple * nuevo);
void mostrarListaSimple(nodoSimple * lista);
#endif // LISTASSIMPLES_H_INCLUDED
