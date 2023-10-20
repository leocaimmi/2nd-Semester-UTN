#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaSimple.h"

const char nombres[100][20] =
{
    "Carlos","Mariano","Jose", "Pedro", "Antonio",
    "Manuel", "Felipe", "Julia", "Marta", "Ines",
    "Eduardo", "Hector", "Mario", "Luis", "Oscar",
    "Sergio", "Rafael", "Fernando", "Javier", "Ricardo",
    "Victor", "Daniel", "Miguel", "Roberto", "Francisco",
    "Diego", "Bruno", "Gabriel", "Alejandro", "Gonzalo",
    "Ignacio", "Juan", "Adrian", "Martin", "David",
    "Isabel", "Carmen", "Ana", "Teresa", "Maria",
    "Laura", "Elena", "Cristina", "Beatriz", "Raquel",
    "Sandra", "Monica", "Rosa", "Silvia", "Patricia",
    "Clara", "Nuria", "Pilar", "Sonia", "Paula",
    "Diana", "Natalia", "Marta", "Ismael", "Ruben",
    "Ivan", "Angel", "Nicolas", "Pablo", "Alberto",
    "Joaquin", "Ernesto", "Rodrigo", "Federico", "Andres",
    "Samuel", "Ramon", "Emilio", "Guillermo", "Esteban",
    "Marcos", "Alfonso", "Enrique", "Lucas", "Gerardo",
    "Marcelo", "Horacio", "Tomas", "Agustin", "Elias",
    "Leonardo", "Matias", "Benjamin", "Gustavo", "Dante",
    "Valentin", "Humberto", "Lorenzo", "Facundo", "Maximo",
    "Damian", "Mauro", "Augusto", "Renato", "Leandro"
};

stCliente crearUnCliente()
{

    stCliente aux;

    aux.tipoCliente = rand()%4+1;
    aux.cantFacturas = rand()%20+1;
    strcpy(aux.nombre,nombres[rand()%100]);
    return aux;
}

nodoSimple * inicNodoSimple()
{
    return NULL;
}

nodoSimple * crearUnNodoSimple(stCliente aux)
{

    nodoSimple * nuevo = (nodoSimple*) malloc(sizeof(nodoSimple));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoSimple * agregarAlPpio(nodoSimple * lista,nodoSimple * nuevo)
{
    nuevo->siguiente = lista;
    return nuevo;
}
/**Cargar una lista simple con varios clientes. Tener en cuenta su tipo (regular, jubilado, persona gestante, empresario) y la cantidad de facturas que tiene.
Sugerencia: Tirar un número random que represente la cantidad de clientes. Randomizar el tipo de cliente (1-4) y el número de boletas a pagar. */
nodoSimple * cargarMuchosClientes(nodoSimple * lista)
{

    for(int i = 0; i<rand()%50; i++)
    {
        lista = agregarAlPpio(lista,crearUnNodoSimple(crearUnCliente()));
    }

    return lista;
}
///2.Mostrar la lista de clientes

void mostrarLista(nodoSimple * lista)
{

    while(lista != NULL)
    {
        mostrarUnCliente(lista->dato);
        lista = lista->siguiente;
    }

}

void mostrarUnCliente(stCliente aux)
{


    puts("\n--------------------------------------------------");
    printf("Nombre:|%s|\n",aux.nombre);
    mostrarTipoCliente(aux.tipoCliente);
    printf("Cantidad de facturas:|%i|\n",aux.cantFacturas);
    puts("--------------------------------------------------\n");



}
void mostrarTipoCliente(int op)
{

    switch(op)
    {
    case 1:
        printf("Tipo de cliente:|REGULAR|\n");
        break;
    case 2:
        printf("Tipo de cliente:|JUBILADO|\n");

        break;
    case 3:
        printf("Tipo de cliente:|PERSONA GESTANTE|\n");

        break;
    case 4:
        printf("Tipo de cliente:|EMPRESARIO|\n");
        break;

    default:
        puts("Dato invalido");
        break;

    }

}
nodoSimple * buscarUltimoSimple(nodoSimple * lista){

while(lista!= NULL && lista->siguiente == NULL){
    lista = lista->siguiente;
}

return lista;
}








