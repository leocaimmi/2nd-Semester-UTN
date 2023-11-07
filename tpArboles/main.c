#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
int main()
{
nodoArbol * raiz = inicArbol();
///datos del campus
raiz = insertar(raiz,10);
raiz = insertar(raiz,5);
raiz = insertar(raiz,3);
raiz = insertar(raiz,1);
raiz = insertar(raiz,4);
raiz = insertar(raiz,7);
raiz = insertar(raiz,9);
raiz = insertar(raiz,15);
raiz = insertar(raiz,14);
raiz = insertar(raiz,17);
raiz = insertar(raiz,16);
raiz = insertar(raiz,20);
printf("\n......................Inorden.........................\n");
mostrarInorden(raiz);
printf("\n......................PreOrden.........................\n");
mostrarPreOrden(raiz);
printf("\n......................PosOrden.........................\n");
mostrarPosOrden(raiz);
puts("\n......................BORRADO.........................\n");
raiz = borrarUnNodo(raiz,20);
mostrarPosOrden(raiz);
    return 0;
}

