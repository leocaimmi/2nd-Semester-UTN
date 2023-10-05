#include <stdio.h>
#include <stdlib.h>
#include "listasDobles.h"
int main()
{

    nodoDoble * lista = inicListaDoble();
    lista = agregarEnOrden(lista,crearUnNodoDoble(1000000));
    lista = agregarEnOrden(lista,crearUnNodoDoble(1000));
    lista = agregarEnOrden(lista,crearUnNodoDoble(150));
    mostrarLista(lista);
    lista = borrarUnNodo(lista,-1);
    mostrarLista(lista);


    return 0;
}
