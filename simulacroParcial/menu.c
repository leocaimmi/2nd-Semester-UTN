#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "clientes.h"

void limpiarPantalla()
{
    system("cls");
}

void menu()
{

    char op = 's';
    int opSw = 0;
    nodoConsola * lista = inicConsola();
    nodoCliente * listaDoble = inicCliente();
///variables auxiliares
    char marcaAux[15];
    char modeloAux[15];
    stCliente aux;
    int stockAux = 0;
    int flag = 0;
    int dato = 0;
    float valorTotalDinero = 0;


    do
    {

        opciones();
        opSw = preguntarDato();

        switch(opSw)
        {
        case 1:
            lista = crearNodoConsola(crearConsola());
            mostrarConsola(lista->dato);
            break;
        case 2:
            lista = agregarXStock(lista,crearNodoConsola(crearConsola()));
            mostrarLista(lista);

            break;
        case 3:
            if(lista!= NULL)
            {
                puts("----------------Ingrese el precio a buscar---------------");
                int dato = preguntarDato();
                lista = mostrarPrecioRecursivo(lista,dato);///el entero es el precio a mostrar
            }
            else
            {
                puts("Haga el inciso 1 para poder ejecutar esta opcion");
            }

            break;
        case 4:
            puts("--------------MARCA---------------");
            preguntarChar(marcaAux);
            puts("-------------MODELO---------------");
            preguntarChar(modeloAux);
            puts("--------------STOCK---------------");
            stockAux = preguntarDato();

            flag = consultarStockConsulta(lista,marcaAux,modeloAux,stockAux)?printf("Existe el stock...\n"):printf("No existe el stock...\n");

            break;
        case 5:
            if(lista!= NULL)
            {

                listaDoble = comprarProductoCliente(lista,listaDoble);
                mostrarLista(lista);
                mostrarListaDoble(listaDoble);

            }
            else
            {
                puts("Hacer inciso 1 y cargar cliente para realizar este punto");
            }
            break;
        case 6:
            if(listaDoble !=NULL)
            {
                valorTotalDinero = contarValorDeTodosLosClientes(listaDoble);
                printf("El total gastado de todos los cliente es:|%.2f|\n",valorTotalDinero);
            }
            else
            {
                puts("Hacer inciso 1-5 para realizar este punto");
            }

            break;
        case 7:
            listaDoble = agregarAlFinalCliente(listaDoble,crearNodoCliente(crearUnCliente()));
            mostrarListaDoble(listaDoble);
            break;
        case 8:
            listaDoble=atenderClientesYBorrarlos(listaDoble,lista);

            break;
        case 9:
            mostrarClientesRecursivo(listaDoble);
            break;
        case 10:
            mostrarLista(lista);
            break;
        case 11:
            mostrarListaDoble(listaDoble);
            break;
        default:
            puts("Error, opciones invalida. Reintente...");
            break;


        }


        puts("Ingrese (S) para continuar. (N) para finalizar");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();
    }
    while(op == 'S'||op == 's');



}


void opciones()
{

    puts("1.Crear un nodo de tipo consola");
    puts("2.Agregar por stock ordenado");
    puts("3.Mostrar precio recursivo");
    puts("4.Consultar stock");
    puts("5.Comprar un producto(Crear cliente)");
    puts("6.Mostrar total de ventas(De todos los clientes)");
    puts("7.Crear clientes");
    puts("8.Atender gente y borrarla luego de ser atendida");
    puts("9.Mostrar clientes recursivamente de atras hacia adelante");
    puts("10.Mostrar consolas");
    puts("11.Mostrar clientes");

}

int preguntarDato()
{

    int dato = 0;

    puts("Ingrese el dato que desea ingresar: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}

void preguntarChar(char aux[])
{

    puts("Ingrese el dato solicitado: ");
    fflush(stdin);
    gets(aux);

}


