#ifndef LISTASDOBLES_H_INCLUDED
#define LISTASDOBLES_H_INCLUDED

typedef struct
{

    int dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;

} nodoDoble;

nodoDoble * inicListaDoble();
int preguntarUnDato();
void mostrarUnDatoEntero(int aux);
void mostrarLista(nodoDoble * lista);

nodoDoble * crearUnNodoDoble(int aux);

nodoDoble * agregarAlPpio(nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * agregarAlFinal(nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * buscarUltimoNodo(nodoDoble * lista);
nodoDoble * agregarEnOrden(nodoDoble * lista,nodoDoble * nuevo);

nodoDoble * borrarUnNodo(nodoDoble * lista,int datoBorrar);
#endif // LISTASDOBLES_H_INCLUDED
