#include <stdio.h>
#include <stdlib.h>
#include "listas.h"
#include "string.h"
///alumnos
notaAlumno crearUnAlumno()
{
    notaAlumno aux;
    printf("Ingrese el nombre y apellido del alumno: ");
    fflush(stdin);
    gets(aux.nombreApe);
    aux.legajo = rand()%1000+1;
    aux.nota = rand()%10+1;

    return aux;
}
void mostrarUnAlumno(notaAlumno nn)
{

    printf("[Nombre y apellido]%s\n",nn.nombreApe);
    printf("[Legajo]%i\n",nn.legajo);
    printf("[Nota]%i\n",nn.nota);




}
///listas
nodo * inicLista()
{
    return NULL;
}

nodo * crearUnNodoSimple(notaAlumno auxNota)
{
    nodo * nuevo =(nodo*)malloc(sizeof(nodo));
    nuevo->dato = auxNota;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodo * agregarAlPpio(nodo * lista,nodo * nn)
{
    nn->siguiente = lista;
    return nn;
}

void mostrarLista(nodo * lista)
{

    while(lista!= NULL)
    {

        mostrarUnAlumno(lista->dato);

        lista = lista->siguiente;
    }


}

///celdas
void mostrarCeldas(celda arregloDeListas[],int validos)
{

    for(int i = 0; i<validos; i++)
    {
        puts("---------------------MATERIAS-------------------------");
        printf("[MATERIA]%s\n",arregloDeListas[i].materia);
        printf("[ID MATERIA]%i\n",arregloDeListas[i].idMateria);
        puts("---------------------alumnos---------------------");

        mostrarLista(arregloDeListas[i].listaDeNotas);

        puts("-----------------------------------------------");

    }

}
int alta(celda arregloDeListas[],registroArchivo aux,int validos)
{

    int pos = buscarPosMateria(arregloDeListas,aux.materia,validos);
    if(pos == -1)
    {
        validos = agregarMateria(arregloDeListas,aux.materia,validos);
        pos = validos-1;

    }
    notaAlumno nn;
    strcpy(nn.nombreApe,aux.nombreApe);
    nn.legajo= aux.legajo;
    nn.nota = aux.nota;

    nodo * nuevoNodo = crearUnNodoSimple(nn);
    arregloDeListas[pos].listaDeNotas =agregarAlPpio(arregloDeListas[pos].listaDeNotas,nuevoNodo);

    return validos;
}
int buscarPosMateria(celda arregloDeListas[],char materia[],int validos)
{
    int aux = -1;
    int i = 0;

    while(i<validos && aux == -1)
    {
        if(strcmpi(arregloDeListas->materia,materia)==0)
        {
            aux = i;
        }
        i++;

    }
    return aux;
}

int agregarMateria(celda arregloDeListas[],char materia[],int validos)
{
    strcpy(arregloDeListas[validos].materia,materia);
    arregloDeListas[validos].listaDeNotas = inicLista();
    arregloDeListas[validos].idMateria = validos+1;
    validos++;

    return validos;
}

int pasarArchivoALista(celda arregloLista[],int dim)
{
    int validos = 0;
    registroArchivo aux;
    FILE * buffer = fopen(ARCHI_REGISTRO,"rb");
    if(buffer != NULL && validos<dim)
    {
        while(fread(&aux,sizeof(registroArchivo),1,buffer)>0)
        {
            validos = alta(arregloLista,aux,validos);


        }
        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }





    return validos;
}

void aprobadosToArchivo(celda arregloDeListas[],int validos)
{
    FILE * buffer = fopen(ARCHI_APROBADOS,"ab");
    registroArchivo aux;
    if(buffer!= NULL)
    {
        for(int i = 0;i<validos;i++)
        {
            while(arregloDeListas[i].listaDeNotas!= NULL)
            {
                if(arregloDeListas[i].listaDeNotas->dato.nota>=6)
                {
                    aux.idMateria = arregloDeListas[i].idMateria;
                    strcpy(aux.materia,arregloDeListas[i].materia);
                    strcpy(aux.nombreApe,arregloDeListas[i].listaDeNotas->dato.nombreApe);
                    aux.nota = arregloDeListas[i].listaDeNotas->dato.nota;
                    aux.legajo = arregloDeListas[i].listaDeNotas->dato.legajo;
                    fwrite(&aux,sizeof(registroArchivo),1,buffer);
                }
                arregloDeListas[i].listaDeNotas = arregloDeListas[i].listaDeNotas->siguiente;
            }
        }

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }



}



