#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#define ARCHIVO_PELI "archivoPeli.bin"
///peliculas
stPelicula crearUnaPeli(celda arregloCelda[],int validos)
{
    stPelicula aux;
    aux.id = retornarIDPeli()+1;

    printf("Ingrese el nombre de la pelicula: ");
    fflush(stdin);
    scanf("%s",&aux.nombre);
    do
    {
        printf("Ingrese el nombre del director: ");
        fflush(stdin);
        scanf("%s",&aux.direccion);
    }
    while(verificarSiExisteUnDirector(arregloCelda,aux.direccion,validos)== 0);
    printf("Ingrese la duracion de la pelicula: ");
    fflush(stdin);
    scanf("%i",&aux.duracion);
    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    scanf("%s",&aux.genero);
    printf("Ingrese el anio de creacion de la pelicula: ");
    fflush(stdin);
    scanf("%i",&aux.anio);

    peliToArchi(aux);

    return aux;
}

int verificarSiExisteUnDirector(celda arregloCelda[],char auxNombre[],int validos)
{
    int flag = 0;
    for(int i = 0; i<validos; i++)
        if(strcmpi(arregloCelda[i].director,auxNombre)== 0)
            flag = 1;

    if(flag == 0)
    {
        puts("Ingrese un director valido");
    }
    return flag;
}


void mostrarUnaPeli(stPelicula aux)
{
    puts("------------------------------------------------");
    printf("[Id] %i\n",aux.id);
    printf("[Nombre] %s\n",aux.nombre);
    printf("[Direccion] %s\n",aux.direccion);
    printf("[Duracion] %i\n",aux.duracion);
    printf("[Anio] %i\n",aux.anio);
    puts("------------------------------------------------");
}
int retornarIDPeli()
{
    int id = 0;
    stPelicula aux;
    FILE * buffer = fopen(ARCHIVO_PELI,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stPelicula),1,buffer)>0)
        {

            id = aux.id;
        }
        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }


    return id;
}
nodoArbolPeli * inicArbol()
{
    return NULL;
}

nodoArbolPeli * crearUnNodoArbol(stPelicula peliAux)
{
    nodoArbolPeli * aux = (nodoArbolPeli * )malloc(sizeof(nodoArbolPeli));
    aux->dato = peliAux;
    aux->der = inicArbol();
    aux->izq = inicArbol();

    return aux;
}

nodoArbolPeli * insertar(nodoArbolPeli * raiz,stPelicula peliAux)
{
    if(raiz != NULL)
    {
        if(strcmpi(raiz->dato.nombre,peliAux.nombre)>0)
        {
            raiz->izq = insertar(raiz->izq,peliAux);
        }
        else
        {
            raiz->der = insertar(raiz->der,peliAux);

        }

    }
    else
    {
        raiz = crearUnNodoArbol(peliAux);
    }


    return raiz;
}




void mostrarInorder(nodoArbolPeli * raiz)
{
    if(raiz!= NULL)
    {
        mostrarInorder(raiz->izq);
        mostrarUnaPeli(raiz->dato);
        mostrarInorder(raiz->der);
    }
}
///celda
int inicArregloArboles(celda arregloArboles[],int validos,int dim)
{

    char op = 's';
    do
    {

        do
        {
            printf("Ingrese el nombre del director: ");
            fflush(stdin);
            scanf("%s",&arregloArboles[validos].director);
        }
        while(verificarDirectorExistente(arregloArboles,arregloArboles[validos].director,validos)== 1);
        arregloArboles[validos].posArbol = inicArbol();
        validos++;

        printf("[S] para seguir cargando \n");
        printf("[N] para finalizar la carga \n");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(validos<dim && (op == 's'||op == 'S'));
    return validos;
}

void mostrarUnaCelda(celda stCompuesta)
{

    puts("------------------------------------------------");
    mostrarUnDirector(stCompuesta);
    mostrarInorder(stCompuesta.posArbol);
    puts("------------------------------------------------\n");


}

void mostrarTodasLasCeldas(celda arregloArboles[],int validos)
{
    for(int i = 0; i<validos; i++)
    {
        mostrarUnaCelda(arregloArboles[i]);
    }
}
void mostrarUnDirector(celda celdita)
{

    printf("[Director]:%s\n",celdita.director);

}

///3 - Buscar la celda de un director o directora de forma recursiva y devuelva su posición.

int buscarPosDirector(celda arregloArboles[],char directorBuscar[],int validos,int pos)
{
    int i = pos, aux = -1;
    if(i<validos)
    {
        if(strcmpi(arregloArboles[i].director,directorBuscar)== 0)
        {
            aux =  i;
        }
        else
        {
            aux = buscarPosDirector(arregloArboles,directorBuscar,validos,i+1);
        }
    }
    return aux;//es la posicion actual
}

///4 - Insertar un nuevo elemento (Tenga en cuenta de que si la celda no existe debe ser creada).
int verificarDirectorExistente(celda arregloArboles[],char nombre[],int validos)
{
    int flag = 0;
    for(int i = 0; i<validos && flag == 0; i++)
        if(strcmpi(arregloArboles[i].director,nombre)== 0)
            flag = 1;

    if(flag == 1)
    {
        puts("Ingrese un director nuevo");
    }


    return flag;
}

int altaNuevoDirector(celda arregloArboles[],int validos,int dim)
{
    int i = 0;
    char nombre[20];

    do
    {
        printf("Ingrese el nombre del nuevo director: ");
        fflush(stdin);
        scanf("%s",&nombre);
    }
    while(verificarDirectorExistente(arregloArboles,nombre,validos) == 1);
    if(verificarDirectorExistente(arregloArboles,nombre,validos) == 0)
    {
        strcpy(arregloArboles[validos].director,nombre);
        arregloArboles[validos].posArbol = inicArbol();
        validos++;
    }

    return validos;
}

void cargarPeliculas(celda arregloArboles[],int validos)
{
    char op = 's';
    stPelicula aux;
    do
    {

        aux = crearUnaPeli(arregloArboles,validos);       ///creo una pelicula para ingresarla con el director que corresponda

        for(int i = 0; i<validos; i++)
        {
            if(strcmpi(arregloArboles[i].director,aux.direccion)== 0)
            {
                arregloArboles[i].posArbol = insertar(arregloArboles[i].posArbol,aux);
            }
        }
        printf("[S]Para continuar cargando peliculas\n");
        printf("[N]Para finalizar la carga\n");
        fflush(stdin);
        scanf("%c",&op);

    }
    while(op == 's'|| op =='S');

}


///5 - Pasar todos los elementos desde el origen de datos(archivo), al arreglo de árboles.
void peliToArchi (stPelicula aux)
{
    FILE * buffer = fopen(ARCHIVO_PELI,"ab");
    if(buffer != NULL)
    {
        fwrite(&aux,sizeof(stPelicula),1,buffer);
        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }
}

void archiToArbol(celda arregloArbol[],int validos)
{
    FILE * buffer = fopen(ARCHIVO_PELI,"rb");
    stPelicula aux;
    nodoArbolPeli * nn;
    if(buffer != NULL)
    {
        for(int i = 0; i<validos; i++)
        {
            while(fread(&aux,sizeof(stPelicula),1,buffer)>0)
            {
                if(strcmpi(arregloArbol[i].director,aux.direccion)==0)
                {
                    arregloArbol[i].posArbol = insertar(arregloArbol[i].posArbol,aux);
                }
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }

}

///7 - Buscar una película por dirección y nombre.
stPelicula buscarPeliculaPorDirectorYNombre(celda arregloDeArboles[], int validos,char directorAux[],char nombrePeliAux[])
{
    stPelicula aux;
    for(int i = 0; i<validos; i++)
    {
        if(strcmpi(arregloDeArboles[i].director,directorAux)==0)
        {
            aux = buscarPorNombre(arregloDeArboles[i].posArbol,nombrePeliAux);
        }

    }


    return aux;
}

stPelicula buscarPorNombre(nodoArbolPeli * raiz,char nombrePeli[])
{
    stPelicula aux;
    if(raiz!= NULL)
    {
        if(strcmpi(raiz->dato.nombre,nombrePeli)== 0)
        {
            aux = raiz->dato;
        }
        else
        {
            aux = buscarPorNombre(raiz->izq,nombrePeli);
            aux = buscarPorNombre(raiz->der,nombrePeli);

        }
    }

    return aux;
}
///8 - Hacer una función que busque a una película por director y año, dentro del árbol.
///(Tenga en cuenta que están ordenadas por nombre)
void mostrarPeliculasPorDirectorYAnio(celda arregloDeArboles[],char directorAux[],int anio,int validos)
{
    int pos = buscarPosDirector(arregloDeArboles,directorAux,validos,0);
    mostrarUnaPeliDelArbol(arregloDeArboles[pos].posArbol,directorAux,anio);
}

void mostrarUnaPeliDelArbol(nodoArbolPeli * raiz,char directorAux[],int anio)
{
    if(raiz != NULL)
    {
        if(raiz->dato.anio == anio)
        {
            mostrarUnaPeli(raiz->dato);
        }
        mostrarUnaPeliDelArbol(raiz->izq,directorAux,anio);
        mostrarUnaPeliDelArbol(raiz->der,directorAux,anio);
    }
}










