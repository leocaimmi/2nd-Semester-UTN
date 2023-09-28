#include <stdio.h>
#include <stdlib.h>
#include "auto.h"
/**1) nodoAuto * crearNodo (automovil auto).
Crea un nodo de tipo nodoAuto *.**/

stAutomovil crearUnAuto()
{

    stAutomovil aux;

    printf("ingrese la marca del auto: \n");
    fflush(stdin);
    scanf("%s",&aux.marca);

    printf("Ingrese la patente del auto: \n");
    fflush(stdin);
    scanf("%s",&aux.patente);

    printf("Ingrese el valor del auto: \n");
    fflush(stdin);
    scanf("%i",&aux.valor);

    return aux;
}

void mostrarAutomovil(stAutomovil aux)
{

    puts("----------------------------------------");
    printf("La marca del auto es:|%s|\n",aux.marca);
    printf("La patente del auto es:|%s|\n",aux.patente);
    printf("El valor del auto es:|%i|\n",aux.valor);

}

void mostrarListaAuto(nodoAuto * lista)
{


    if(lista != NULL)
    {

        while(lista!= NULL)
        {

            mostrarAutomovil(lista->dato);
            lista = lista->siguiente;
        }

    }

}


nodoAuto * inicAuto()
{
    return NULL;
}

nodoAuto * crearUnNodoDeAuto(stAutomovil aux)
{

    nodoAuto * nuevoNodo = (nodoAuto*)malloc(sizeof(nodoAuto));
    nuevoNodo->dato = aux;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

/**2) void agregarFinal(nodoAuto * * lista, nodoAuto * nuevo).
Agrega un nuevo nodo al final de la lista (utilizando puntero doble) */

void agregarFinal(nodoAuto ** lista,nodoAuto * nuevoNodo)
{


    if(*lista != NULL)
    {
        nodoAuto * ulti = buscarUltimoLista(*lista);
        ulti->siguiente = nuevoNodo;

    }
    else
    {
        *lista = nuevoNodo;
    }

}

nodoAuto* buscarUltimoLista(nodoAuto * lista)
{


    while(lista != NULL && lista->siguiente != NULL)
    {
        lista = lista->siguiente;
    }

    return lista;
}

/**3) int insertarCelda(automovil A [ ], int dim, automovil dato, int validos).
Inserta el nuevo automóvil en el arreglo, de manera de conservarlo ordenado por valor en forma creciente.
 válidos es la cantidad de datos que tiene el arreglo y retorna validos+1.
Al inicio validos vale 0. */

int insertarCelda(stAutomovil A [], int dim, stAutomovil dato, int validos)
{

    if(validos<dim)
    {
        int i = validos - 1;
        while(dato.valor < A[i].valor && i>= 0)
        {

            A[i+1] = A[i];
            i--;
        }
        A[i+1] = dato;
        validos++;
    }
    else
    {
        puts("El arreglo esta lleno...");
    }

    return validos;
}

void mostrarArregloAutos(stAutomovil arreglo[],int validos)
{
    for(int i = 0; i<validos; i++)
    {
        mostrarUnAutoArreglo(arreglo[i],i);

    }

}

void mostrarUnAutoArreglo(stAutomovil aux,int i)
{
    printf("-----------------Auto(%i)---------------\n",i);
    printf("Marca:|%s|\n",aux.marca);
    printf("Patente:|%s|\n",aux.patente);
    printf("Valor:|%i|\n",aux.valor);


}

/**4) void agregarMuchos(nodoAuto * * lista).
Esta función pide al usuario el ingreso de los datos de un automovil,
crea un nodo y lo agrega al final de la lista (invocando a la función 2). */

void agregarMuchosAutos(nodoAuto ** lista)
{

    char op = 's';

    do
    {
        agregarFinal(lista,crearUnNodoDeAuto(crearUnAuto()));
        puts("-----------------------------------------------");
        puts("Ingrese (S/N) para ingresar mas autos: ");
        fflush(stdin);
        scanf("%s",&op);


    }
    while(op == 's'||op == 'S');

}

/**5) int pasar(nodoAuto * lista, automovil A[ ], int dim).
Esta función pasa el contenido de la lista al arreglo A, de forma de crear un arreglo ordenado.
Para ello debe recorrer la lista e insertar los datos al arreglo usando la función 3. */

int pasarAlArreglo(nodoAuto * lista, stAutomovil A[],int dim)
{

    int validos = 0;

    while(lista != NULL)
    {

        validos = insertarCelda(A,dim,lista->dato,validos);
        lista = lista->siguiente;
    }

    return validos;
}
/**6) void mostrarArregloRecursivo(automovil A[ ], int i, int pos).
Muestra el arreglo en forma recursiva, desde la posición cero hasta la posición pos.
 El parámetro i representa la posición actual del arreglo a mostrar. */

void mostrarArregloRecursivo(stAutomovil A[],int i, int pos)
{

    if(i<pos)
    {
        mostrarUnAutoArreglo(A[i],i);
        mostrarArregloRecursivo(A,i+1,pos);

    }

}
/**7) Hacer una función recursiva que sume el valor de los automóviles de la lista que tengan patente “par”.
Además, deberá pensar una función que determine si la patente es par o no.
(Aclaración: las patentes tienen el formato “AAA123”,*/

int sumarPatente(nodoAuto* lista)
{

    int suma = 0;
    int flag = 0;
    if(lista != NULL)
    {
        flag = verificarPatentePar(lista->dato);
        if(flag == 1)
        {
            suma +=lista->dato.valor;
            suma+=sumarPatente(lista->siguiente);

        }else{

        lista = lista->siguiente;
        }
    }
        return suma;
}
    int verificarPatentePar(stAutomovil aux)
    {
        int flag = 0;
        if(aux.patente[5]%2 == 0)
        {
            flag =  1;
        }
        return flag;
    }
