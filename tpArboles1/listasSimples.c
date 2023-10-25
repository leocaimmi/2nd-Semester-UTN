#include <stdio.h>
#include <stdlib.h>
#include "listasSimples.h"

const char nombresFila[100][20] =
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


nodoSimple * inicLista()
{
    return NULL;
}

stPersona crearUnaPersona()
{

    stPersona aux;

    strcpy(aux.nombre,nombresFila[rand()%100]);
    aux.legajo = rand()%1000+1;
    aux.edad = rand()%80+1;

    return aux;
}

void mostrarPersona(stPersona aux)
{
    puts("..........................................");
    printf("\nNombre:|%s|\n",aux.nombre);
    printf("\nEdad:|%i|\n",aux.edad);
    printf("\nLegajo:|%i|\n",aux.legajo);
    puts("..........................................");

}

nodoSimple * crearUnNodoSimple(stPersona aux)
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


nodoSimple * agregarEnOrden(nodoSimple * lista,nodoSimple * nuevo)
{

    if(lista != NULL)
    {
        if(lista->dato.legajo > nuevo->dato.legajo)
        {
            lista = agregarAlPpio(lista,nuevo);
        }
        else
        {
            nodoSimple* seg = lista->siguiente;
            nodoSimple* ante= lista;

            while(seg != NULL && seg->dato.legajo < nuevo->dato.legajo)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;

        }

    }
    else
    {
        lista = nuevo;
    }

    return lista;
}

void mostrarListaSimple(nodoSimple * lista)
{


    while(lista != NULL)
    {

        mostrarPersona(lista->dato);
        lista= lista->siguiente;

    }



}






