#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"

int main()
{


    srand(time(NULL));
    nodoArbol * arbol = inicArbol();

    //arbol=insertar(arbol, crearUnNodoArbol(50));

    /*for(int i = 0;i<5;i++)
    arbol = insertar(arbol,crearUnNodoArbol(rand()%100+1));*/

    /**arbol = insertar(arbol,crearUnNodoArbol(8));
    arbol = insertar(arbol,crearUnNodoArbol(3));
    arbol = insertar(arbol,crearUnNodoArbol(6));
    arbol = insertar(arbol,crearUnNodoArbol(1));
    arbol = insertar(arbol,crearUnNodoArbol(4));
    arbol = insertar(arbol,crearUnNodoArbol(7));
    arbol = insertar(arbol,crearUnNodoArbol(10));
    arbol = insertar(arbol,crearUnNodoArbol(14));
    arbol = insertar(arbol,crearUnNodoArbol(13));///NUMEROS DEL EJEMPLO
    arbol = insertar(arbol,crearUnNodoArbol(12));
    arbol = insertar(arbol,crearUnNodoArbol(20));*/


    arbol = insertar(arbol,crearUnNodoArbol(50));
    arbol = insertar(arbol,crearUnNodoArbol(51));
    arbol = insertar(arbol,crearUnNodoArbol(49));
  arbol = insertar(arbol,crearUnNodoArbol(52));
    arbol = insertar(arbol,crearUnNodoArbol(48));


    /*puts("\n................preOrder..............\n");
    preOrder(arbol);
    puts("\n................Inorder..............\n");
    inOrder(arbol);
    puts("\n................posOrder..............\n");
    posOrder(arbol);*/


    /**int cantHojas= 0;
    contarHojas(arbol,&cantHojas);*/

    /*int contador2 = contarHojas2(arbol);
    printf("Cant hojas :|%i|\n",contador2);*/

    //encontrarDato(arbol, 100)?printf("Se encontro el dato\n"): printf("No se encontro el dato\n");
    //buscarDatoRecursivoTernario(arbol,0)?printf("Se encontro el dato2\n"): printf("No se encontro el dato2\n");

    int altura = contarAltura(arbol);
    printf("Altura:|%i| \n",altura);

    puts("\n................Inorder..............\n");
    preOrder(arbol);
    return 0;
}
