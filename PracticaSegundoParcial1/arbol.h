#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    int duracion;
    char direccion[30];
    char genero[20];
    int anio;
}stPelicula;

typedef struct //nodoArbolPeli
{
    stPelicula dato;
    struct nodoArbolPeli * izq;
    struct nodoArbolPeli * der;
} nodoArbolPeli;

///1 - Diseñar una estructura compuesta de arreglo de árboles, donde cada celda contenga un árbol con todas las películas de un director, y desarrollar la función que permita inicializar el arreglo.
typedef struct
{

    char director[20];
    struct nodoArbolPeli * posArbol;

}celda;
///funciones peliculas
stPelicula crearUnaPeli(celda arregloCelda[],int validos);
void mostrarUnaPeli(stPelicula aux);
int retornarIDPeli();
int verificarSiExisteUnDirector(celda arregloCelda[],char auxNombre[],int validos);


///funciones arboles
nodoArbolPeli * inicArbol();

nodoArbolPeli * crearUnNodoArbol(stPelicula peliAux);
nodoArbolPeli * insertar(nodoArbolPeli * raiz,stPelicula peliAux);
void mostrarInorder(nodoArbolPeli * raiz);

///funciones de celdas
int inicArregloArboles(celda arregloArboles[],int validos,int dim);

void mostrarUnaCelda(celda stCompuesta);
void mostrarTodasLasCeldas(celda arregloArboles[],int validos);
void mostrarUnDirector(celda celdita);
int buscarPosDirector(celda arregloArboles[],char directorBuscar[],int validos,int pos);
int altaNuevoDirector(celda arregloArboles[],int validos,int dim);

void cargarPeliculas(celda arregloArboles[],int validos);

///verificaciones
int verificarDirectorExistente(celda arregloArboles[],char nombre[],int validos);

///archivos
void peliToArchi (stPelicula aux);
void archiToArbol(celda arregloArbol[],int validos);

stPelicula buscarPeliculaPorDirectorYNombre(celda arregloDeArboles[], int validos,char directorAux[],char nombrePeliAux[]);
stPelicula buscarPorNombre(nodoArbolPeli * raiz,char nombrePeli[]);


void mostrarPeliculasPorDirectorYAnio(celda arregloDeArboles[],char directorAux[],int anio,int validos);
void mostrarUnaPeliDelArbol(nodoArbolPeli * raiz,char directorAux[],int anio);
#endif // ARBOL_H_INCLUDED
