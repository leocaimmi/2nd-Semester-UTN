#ifndef LISTASIMPLE_H_INCLUDED
#define LISTASIMPLE_H_INCLUDED

typedef struct{

char nombre[15];
int tipoCliente;///(1.regular, 2.jubilado, 3.persona gestante, 4.empresario)
int cantFacturas;

}stCliente;

typedef struct{

stCliente dato;
struct nodo * siguiente;

}nodoSimple;

stCliente crearUnCliente();
nodoSimple * inicNodoSimple();
nodoSimple * crearUnNodoSimple(stCliente aux);
nodoSimple * agregarAlPpio(nodoSimple * lista,nodoSimple * nuevo);
nodoSimple * cargarMuchosClientes(nodoSimple * lista);

void mostrarUnCliente(stCliente aux);
void mostrarLista(nodoSimple * lista);
void mostrarTipoCliente(int op);
nodoSimple * buscarUltimoSimple(nodoSimple * lista);


#endif // LISTASIMPLE_H_INCLUDED
