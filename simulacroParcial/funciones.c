#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funciones.h"
///1) Hacer una función que cree un nodo con una stConsola, inicialice sus datos y retorne un puntero al mismo.

nodoConsola * inicConsola()
{
    return NULL;
}
stConsola crearConsola()
{

    stConsola aux;

    puts("Ingrese el ID del producto");
    fflush(stdin);
    scanf("%i",&aux.codigoProducto);

    puts("Ingrese la marca del producto");
    fflush(stdin);
    gets(aux.marca);

    puts("Ingrese el modelo del producto");
    fflush(stdin);
    scanf("%s",&aux.modelo);

    puts("Ingrese el precio del producto");
    fflush(stdin);
    scanf("%f",&aux.precioEnMiles);

    puts("Ingrese el stock del producto");
    fflush(stdin);
    scanf("%i",&aux.stock);

    return aux;
}

void mostrarConsola(stConsola aux)
{
    puts("------------------------CONSOLA---------------------");
    printf("ID del producto:%i\n",aux.codigoProducto);
    printf("Marca del producto:%s\n",aux.marca);
    printf("Modelo del producto:%s\n",aux.modelo);
    printf("Precio del producto:%.2f.\n",aux.precioEnMiles);
    printf("Stock del producto:%i\n",aux.stock);
    puts("--------------------------------------------------------");

}

void mostrarLista(nodoConsola * lista)
{

    if(lista != NULL)
    {
        while(lista != NULL)
        {
            mostrarConsola(lista->dato);
            printf("\n");
            lista = lista->siguiente;
        }

    }
}
nodoConsola * crearNodoConsola(stConsola aux)
{

    nodoConsola * nuevo = (nodoConsola*)malloc(sizeof(nodoConsola));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;

    return nuevo;
}
///2) Hacer una función que agregue un nuevo nodo ordenado por stock a la lista de consolas..
nodoConsola * agregarAlPpio(nodoConsola * lista, nodoConsola * nodoNuevo)
{

    if(lista != NULL)
    {
        nodoNuevo->siguiente = lista;
        lista = nodoNuevo;
    }
    else
    {
        lista = nodoNuevo;
    }
    return lista;
}

nodoConsola* agregarXStock(nodoConsola* lista,nodoConsola * nuevaConsola)
{

    if(lista != NULL)
    {

        nodoConsola * seg = lista;
        nodoConsola * ante = lista;
        if(seg->dato.stock > nuevaConsola->dato.stock)
        {
            lista = agregarAlPpio(lista,nuevaConsola);
        }
        else
        {
            while(seg != NULL && seg->dato.stock < nuevaConsola->dato.stock)
            {

                ante = seg;
                seg = seg->siguiente;

            }

            ante->siguiente = nuevaConsola;
            nuevaConsola->siguiente = seg;
        }
    }
    else
    {
        lista = nuevaConsola;
    }

    return lista;
}
///3) Hacer una función que muestre las consolas de un precio  en particular de forma recursiva..

nodoConsola * mostrarPrecioRecursivo(nodoConsola * lista,int precioAMostrar)
{

    if(lista != NULL)
    {

        if(lista->dato.precioEnMiles == precioAMostrar)
        {
            mostrarConsola(lista->dato);
        }
        lista = mostrarPrecioRecursivo(lista->siguiente,precioAMostrar);
    }

    return lista;
}

/**4) Generar una función para controlar el stock de una consola en particular según su marca y modelo y la
 cantidad pedida por el usuario. Debe retornar 1 o 0 según el caso. */

int consultarStockConsulta(nodoConsola* lista,char marcaAux[],char modeloAux[],int stockAux)
{
    int flag = 0;

    if(lista != NULL)
    {

        while(lista != NULL)
        {
            if(strcmpi(lista->dato.marca,marcaAux)== 0 &&strcmpi(lista->dato.modelo,modeloAux)== 0)
            {
                if(lista->dato.stock >=stockAux)
                {
                    flag = 1;
                }
            }
            lista = lista->siguiente;
        }


    }
    return flag;
}



