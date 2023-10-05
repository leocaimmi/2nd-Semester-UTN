#include <stdio.h>
#include <stdlib.h>
#include "listasSimples.h"
int main()
{

nodo * lista = inicLista();
lista = agregarOrdenado(lista,crearUnNodo(preguntarDatoYdevolverlo()));
lista = agregarOrdenado(lista,crearUnNodo(preguntarDatoYdevolverlo()));
lista = agregarOrdenado(lista,crearUnNodo(preguntarDatoYdevolverlo()));
mostrarListaSimple(lista);

puts("-------------------DATO BORRADO------------------------");
lista = borrarUnNodo(lista,4);
mostrarListaSimple(lista);

    return 0;
}
