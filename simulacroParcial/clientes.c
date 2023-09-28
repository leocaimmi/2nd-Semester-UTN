#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funciones.h"
#include "clientes.h"


stCliente crearUnCliente()
{

    stCliente aux;

    puts("Ingrese el nombre del cliente: ");
    fflush(stdin);
    scanf("%s",&aux.Nombre);

    puts("Ingrese el medio de pago del cliente: ");
    fflush(stdin);
    scanf("%i",&aux.mediodepago);
    aux.totalCompra = 0;

    return aux;
}

void mostrarUnCliente(stCliente aux)
{

    puts("\n----------------------CLIENTE------------------------");
    printf("Nombre del cliente:.......%s\n",aux.Nombre);
    printf("Medio de pago del cliente:%i\n",aux.mediodepago);
    if(aux.totalCompra > 0)
    {
        printf("El total de la compra es:.%.2f\n",aux.totalCompra);
    }
    puts("........................................................");
}

void mostrarListaDoble(nodoCliente * lista)
{

    if(lista != NULL)
    {
        while(lista != NULL)
        {
            mostrarUnCliente(lista->dato);
            lista = lista->siguiente;
        }
    }


}

nodoCliente * inicCliente()
{
    return NULL;
}

nodoCliente * crearNodoCliente(stCliente aux)
{

    nodoCliente * nuevo = (nodoCliente*)malloc(sizeof(nodoCliente));
    nuevo->anterior = NULL;
    nuevo->siguiente = NULL;
    nuevo->dato = aux;

    return nuevo;
}

nodoCliente * agregarAlPpioCliente(nodoCliente * lista,nodoCliente * nuevo)
{

    nuevo->siguiente = lista;
    if(lista != NULL)
    {
        lista->anterior = nuevo;
    }

    return lista;
}

nodoCliente * agregarAlFinalCliente(nodoCliente* lista,nodoCliente * nuevo)
{

    if(lista != NULL)
    {
        nodoCliente * ulti = buscarUltimoNodo(lista);

        ulti->siguiente = nuevo;
        nuevo->anterior = ulti;

    }
    else
    {
        lista = nuevo;
    }

    return lista;
}

nodoCliente * buscarUltimoNodo(nodoCliente * lista)
{

    while(lista != NULL && lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }
    return lista;
}
/**5) Hacer una función dado el nombre de un cliente y su medio de pago, compre varios productos.
 Revise el stock antes de comprar y luego reste la cantidad comprada.Estos clientes se añadirán al FINAL de la lista doble.
 Guardar el total de la compra en su estructura.*/


nodoCliente* comprarProductoCliente(nodoConsola* lista,nodoCliente* listaDoble)
{

    char marcaAux[15];
    char modeloAux[15];
    int stockAux = 0;
    float compraTotal = 0;
    if(lista != NULL)
    {
        mostrarLista(lista);
        puts("Ingrese la marca de lo que desea comprar: ");
        fflush(stdin);
        scanf("%s",&marcaAux);

        puts("Ingrese el modelo de lo que desea comprar: ");
        fflush(stdin);
        scanf("%s",&modeloAux);

        puts("Ingrese la cantidad que desea comprar: ");
        fflush(stdin);
        scanf("%i",&stockAux);

        int flag = consultarStockConsulta(lista,marcaAux,modeloAux,stockAux);
        if(flag == 1)
        {

            compraTotal = modificarStockYRetonarTotal(lista,marcaAux,modeloAux,stockAux);

            listaDoble->dato.totalCompra = compraTotal;


        }
        else
        {
            puts("No se puede realizar la compra,Stock insuficiente");
        }
    }
    else
    {
        puts("No hay consolas disponibles");
    }
    return listaDoble;
}

float modificarStockYRetonarTotal(nodoConsola* lista,char marcaAux[],char modeloAux[],int stockAux)
{
    float totalCompra = 0;


    if(lista != NULL)
    {

        while(lista != NULL)
        {

            if(strcmpi(lista->dato.marca,marcaAux)== 0 &&strcmpi(lista->dato.modelo,modeloAux)== 0)
            {

                if(lista->dato.stock >= stockAux)
                {

                    totalCompra = stockAux * (lista->dato.precioEnMiles);
                    lista->dato.stock -= stockAux;
                }
            }
            lista = lista->siguiente;
        }

    }
    return totalCompra;
}


///6) Hacer una función que cuente el total vendido por todos los clientes

float contarValorDeTodosLosClientes(nodoCliente* listaDoble)
{

    float valorTotal = 0;

    if(listaDoble != NULL)
    {
        while(listaDoble != NULL)
        {
            valorTotal += (float)listaDoble->dato.totalCompra;
            listaDoble = listaDoble->siguiente;
        }

    }

    return valorTotal;
}

///7) Simular el proceso de “atender” a los clientes.
/// Los clientes atendidos se deben borrar de la lista. Piense en una fila de personas y quien es el primero (guiño guiño) en atender e irse. Modularizar

void borrarPrimeroDeLaFila(nodoCliente ** listaDoble)
{

    if(*listaDoble != NULL)
    {
        nodoCliente * seg = *listaDoble;

        *listaDoble = (*listaDoble)->siguiente;
        free(seg);

    }

}


nodoCliente * atenderClientesYBorrarlos(nodoCliente * listaDoble,nodoConsola* lista)
{

    if(listaDoble != NULL)
    {
        puts("CLIENTES DE DE ATRAR HACIA ADELANTE RECURSIVO");
        mostrarClientesRecursivo(listaDoble);

        puts("---------------CLIENTE-PARA-SER-ATENDIDO---------------");
        mostrarUnCliente(listaDoble->dato);
        listaDoble = comprarProductoCliente(lista,listaDoble);
        mostrarUnCliente(listaDoble->dato);
        borrarPrimeroDeLaFila(&listaDoble);

    }

    return listaDoble;
}

///8) Antes de atender a todos los clientes, muestrelos de manera recursiva pero de atrás hacia adelante.

void mostrarClientesRecursivo(nodoCliente * listaDoble)
{

    if(listaDoble != NULL)
    {
        mostrarClientesRecursivo(listaDoble->siguiente);
        mostrarUnCliente(listaDoble->dato);

    }

}
















