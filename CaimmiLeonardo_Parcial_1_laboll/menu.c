#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "persona.h"
#include "contactos.h"

void limpiarPantalla(){
system("cls");
}


void menu()
{

    char op = 's';
    int opSw = 0;
    int flag = 0;
    int contactosActivos = 0;
    nodoPersona * listaSimple = inicNodoPersona();
    nodoContacto * listaDoble = inicNodoContacto();
    stPersona aux;
    stContacto auxContacto;
    nodoContacto * nodoDobleAux = NULL;
    do
    {
        opcionesMenu();
        opSw = preguntarDato();
        switch(opSw)
        {
        case 1:
            listaSimple = agregarAlPpio(listaSimple,crearUnNodoPersona(crearUnaPersona(listaSimple)));
            mostrarListaSimple(listaSimple);

            break;
        case 2:
            if(listaSimple != NULL)
            {
                puts(".....................Ingrese el Dni a buscar.........................");
                flag =  verificarDniRecursivo(listaSimple,preguntarDato());
                if(flag == 1)
                {
                    printf("Se encontro el DNI en la lista\n");
                }
                else
                {
                    printf("El Dni no se ha encontrado en la lista");
                }
            }
            else
            {
                puts("Cargue la lista antes de realizar este punto");
            }

            break;
        case 3:
            mostrarListaSimpleRecursiva(listaSimple);
            break;
        case 4:
            if(listaSimple != NULL)
            {
                listaSimple = cargarPersonasALaLista(listaSimple);
            }
            else
            {
                puts("Haga el inciso uno antes de realizar este");
            }
            break;
        case 5:
            if(listaSimple != NULL)
            {
                auxContacto = crearUnContacto(listaSimple);
                nodoDobleAux = crearUnNodoContacto(auxContacto);
                listaDoble = agregarAlPpioListaDoble(listaDoble,nodoDobleAux);
                mostrarListaDoble(listaDoble);
            }
            else
            {
                puts("Cargar la lista simple de personas para realizar este punto");
            }


            break;
        case 6:

        listaDoble = agregarEnOrdenListaDoble(listaDoble,crearUnNodoContacto(crearUnContacto(listaSimple)));
        mostrarListaDoble(listaDoble);
            break;
        case 7:
            mostrarListaDobleRecursiva(listaDoble);
            break;
        case 8:
            contactosActivos = contarContactosActivos(listaDoble);
            mostrarCantDeContactosActivos(contactosActivos);
            break;
        default:
puts("Ingrese una opcion valida...REINTENTE");
            break;


        }


        printf("\nIngrese(S) para continuar o (N) para finalizar: ");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();


    }
    while(op == 's'|| op == 'S');




}

void mostrarCantDeContactosActivos(int dato){
puts(".........................................");
printf("cantidad de contactos activos:|%i|\n",dato);
puts(".........................................");

}


void opcionesMenu()
{

    puts("1.Cargar una persona a la lista");
    puts("2.Mostrar si existe un DNI");
    puts("3.Mostrar lista de forma recursiva");
    puts("4.Cargar personas");
    puts("5.Cargar un contacto");
    puts("6.Agregar contactos ordenados por DNI");
    puts("7.Mostrar lista doble al reves recursivo");
    puts("8.Mostrar contactos activos");


}

int preguntarDato()
{

    int dato = 0;

    printf("Ingrese la opcion o dato solicitada: ");
    fflush(stdin);
    scanf("%i",&dato);
    return dato;
}
