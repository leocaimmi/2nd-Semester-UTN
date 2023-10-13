#include <stdio.h>
#include <stdlib.h>
#include "contactos.h"
#include "persona.h"

///5) Hacer una función para crear un nodoContacto.
///Hacer una función para cargar un stContacto. Validar tipoContacto que sea 1-2-3.
///Validar que el DNI exista en la lista personas simple.

stContacto crearUnContacto(nodoPersona* lista)
{

    stContacto aux;
    do
    {
        printf("Ingrese el Dni del contacto: ");
        fflush(stdin);
        scanf("%d",&aux.DNI);
    }
    while(verificarDniRecursivo(lista,aux.DNI) == 0);
    do
    {
        printf("Ingrese el tipo de contacto(1.familia-2.trabajo-3.amigos): ");
        fflush(stdin);
        scanf("%i",&aux.tipoContacto);
    }
    while(validarTipoDeContacto(aux.tipoContacto)== 0);

    printf("Ingrese 1 para activo, 0 para 0 para inactivo: ");
    fflush(stdin);
    scanf("%i",&aux.activo);


    return aux;
}

void mostrarUnContacto(stContacto aux)
{

    puts("................................................");
    printf("DNI:|%i|\n",aux.DNI);
    printf("Tipo de contacto:|%i|\n",aux.tipoContacto);
    printf("Estado del contacto:|%i|\n",aux.activo);
    puts("................................................");

}


int validarTipoDeContacto(int datoValidar)
{

    int flag = 0;

    if(datoValidar == 1)
    {
        flag = 1;
    }
    else if(datoValidar == 2)
    {
        flag = 1;
    }
    else if(datoValidar == 3)
    {
        flag = 1;
    }
    else
    {
        flag = 0;
    }
    return flag;
}

nodoContacto * inicNodoContacto()
{
    return NULL;
}

nodoContacto * crearUnNodoContacto(stContacto aux)
{

    nodoContacto * nuevo = (nodoContacto*) malloc(sizeof(nodoContacto));
    nuevo->dato = aux;
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoContacto * agregarAlPpioListaDoble(nodoContacto * listaDoble,nodoContacto * nuevo)
{

    nuevo->siguiente = listaDoble;
    if(listaDoble != NULL)
    {
        listaDoble->anterior = nuevo;
    }
    return nuevo;
}

void mostrarListaDoble(nodoContacto * listaDoble)
{

    while(listaDoble != NULL)
    {
        mostrarUnContacto(listaDoble->dato);
        listaDoble = listaDoble->siguiente;

    }

}

///6) Hacer una función que agregue los contactos de manera ordenada por DNI a la lista doble

nodoContacto * agregarEnOrdenListaDoble(nodoContacto * listaDoble,nodoContacto* nuevo)
{


    if(listaDoble!= NULL)
    {
        if(listaDoble->dato.DNI > nuevo->dato.DNI)
        {
            listaDoble = agregarAlPpioListaDoble(listaDoble,nuevo);
        }
        else
        {
            nodoContacto * ante = listaDoble;
            nodoContacto * seg = listaDoble->siguiente;
            while(seg != NULL && listaDoble->dato.DNI < nuevo->dato.DNI)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            if(seg!= NULL)
            {
                seg->anterior = nuevo;
            }
            ante->siguiente = nuevo;
            nuevo->anterior = ante;
            nuevo->siguiente = seg;
        }


    }
    else
    {
        listaDoble = nuevo;
    }





    return listaDoble;
}

/**7) Hacer una función que muestre la lista doble de manera recursiva.
Empezar desde final y mostrar desde el último al primero. */

void mostrarListaDobleRecursiva(nodoContacto * listaDoble)
{

    if(listaDoble != NULL)
    {
        mostrarListaDobleRecursiva(listaDoble->siguiente);
        mostrarUnContacto(listaDoble->dato);
    }

}

///8) Hacer una función que cuente los contactos activos

int contarContactosActivos(nodoContacto * listaDoble)
{

    int contador = 0;


    while(listaDoble != NULL)
    {
        if(listaDoble->dato.activo == 1)
        {
            contador++;
        }
        listaDoble = listaDoble->siguiente;
    }

    return contador;
}
