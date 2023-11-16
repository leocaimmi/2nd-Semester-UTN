#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "archivos.h"

typedef struct
{
    int nota;
    int legajo;
    char nombreApe[40];
} notaAlumno;

typedef struct
{
    notaAlumno dato;
    struct nodo *siguiente;
} nodo;

typedef struct
{
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;
///nota alumno
notaAlumno crearUnAlumno();
void mostrarUnAlumno(notaAlumno nn);

///lista simple
nodo * inicLista();
nodo * crearUnNodoSimple(notaAlumno auxNota);
nodo * agregarAlPpio(nodo * lista,nodo * nn);
void mostrarLista(nodo * lista);

///celdas
int alta(celda arregloDeListas[],registroArchivo aux,int validos);
int buscarPosMateria(celda arregloDeListas[],char materia[],int validos);
int agregarMateria(celda arregloDeListas[],char materia[],int validos);
int pasarArchivoALista(celda arregloLista[],int validos);
void mostrarCeldas(celda arregloDeListas[],int validos);
void aprobadosToArchivo(celda arregloDeListas[],int validos);
#endif // LISTAS_H_INCLUDED
