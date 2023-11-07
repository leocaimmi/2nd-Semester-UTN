#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
typedef struct
{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;
///crear e inicializar
nodoArbol* inicArbol();
nodoArbol * crearUnNodoArbol(int aux);
nodoArbol * insertar(nodoArbol * raiz,int aux);
nodoArbol * buscarYretornar(nodoArbol * raiz,int datoAux);
///mostrar
void mostrarPreOrden(nodoArbol * raiz);
void mostrarInorden(nodoArbol * raiz);
void mostrarPosOrden(nodoArbol * raiz);
///borrar
nodoArbol * borrarUnNodo(nodoArbol * raiz,int dato);
nodoArbol * NMI(nodoArbol*  raiz);
nodoArbol * NMD(nodoArbol*  raiz);
///verificar
int esHoja(nodoArbol * raiz);

#endif // ARBOL_H_INCLUDED
