#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED
#include "listasDobles.h"
typedef struct
{
    nodoDoble * primero; //primer cliente
    nodoDoble * ultimo; //ultimo cliente
    int numeroFila;
    char nombreCajero[50];
} Fila;

void inicFila(Fila * fila);
void inicializarArregloFilas(Fila cajas[]);

void asignarDatosFila(Fila cajas[]);
void mostrarCajas(Fila cajas[]);
void agregar(Fila * caja,stCliente aux);

int contarClientesFila(Fila caja);
stCliente verPrimero(nodoDoble * lista);
stCliente extraer(Fila * caja);

void asignarClientesALasCajas(Fila cajas[],nodoSimple * listaSimple);

void atenderClientes(Fila cajas[],char archivo[]);
void mostrarArchivo(char archivo[]);

float calcularPromedioDeFacturasXCaja(Fila caja);
void promedios(float promedioCaja);
float buscarMenor(float arreglo[]);
float mostrarPromedioDeLasCajas(Fila cajas[]);
#endif // FILAS_H_INCLUDED
