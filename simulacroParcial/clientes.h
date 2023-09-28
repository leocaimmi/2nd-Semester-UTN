#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include "funciones.h"
typedef struct
{

    char Nombre[50];
    int mediodepago; //1 efectivo, 2 patacones, 3 dolar     ahorro
    float totalCompra;
} stCliente ;

typedef struct nodoCliente
{
    stCliente dato;
    struct nodoCliente* siguiente;
    struct nodoCliente* anterior;
} nodoCliente;

stCliente crearUnCliente();
nodoCliente * inicCliente();
nodoCliente * crearNodoCliente(stCliente aux);

nodoCliente * agregarAlPpioCliente(nodoCliente * lista,nodoCliente * nuevo);
nodoCliente * agregarAlFinalCliente(nodoCliente* lista,nodoCliente * nuevo);
nodoCliente * buscarUltimoNodo(nodoCliente * lista);

nodoCliente* comprarProductoCliente(nodoConsola* lista,nodoCliente* listaDoble);
float modificarStockYRetonarTotal(nodoConsola* lista,char marcaAux[],char modeloAux[],int stockAux);

float contarValorDeTodosLosClientes(nodoCliente* listaDoble);
void borrarPrimeroDeLaFila(nodoCliente ** listaDoble);
nodoCliente * atenderClientesYBorrarlos(nodoCliente * listaDoble,nodoConsola* lista);
#endif // CLIENTES_H_INCLUDED
