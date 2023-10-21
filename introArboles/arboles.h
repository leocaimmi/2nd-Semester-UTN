#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

typedef struct{

int dato;
struct nodoArbol * izquierda;
struct nodoArbol * derecha;

}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearUnNodoArbol(int dato);
nodoArbol * insertar(nodoArbol*raiz,nodoArbol*nuevo);

void mostrarDato(int dato);
void preOrder(nodoArbol * raiz);
void inOrder(nodoArbol * raiz);
void posOrder(nodoArbol * raiz);
void contarHojas(nodoArbol* raiz, int* contador);///GPT

int contarHojas2(nodoArbol* raiz);///MIA

int encontrarDato(nodoArbol * raiz,int datoVerificar);
int buscarDatoRecursivoTernario(nodoArbol * raiz,int datoABuscar);
#endif // ARBOLES_H_INCLUDED
