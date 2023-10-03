#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombreYapellido[40];
    char sector[30]; ///los sectores son (y estan escritos tal cual): "ropa","muebles","electro"
    int ventasDiarias;
} stVendedor;

typedef struct
{

    stVendedor dato;
    struct nodoSimple * siguiente;

} nodoSimple;

typedef struct
{

    stVendedor aux;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;


} nodoDoble;



void limpiarPantalla()
{
    system("cls");
}

/**1. Utilizando el archivo de Vendedores, hacer una función principal que recorra el mismo e invoque
las funciones auxiliares y estructuras que haga falta crear para construir una LISTA SIMPLE
de Vendedores.
• Deberá modularizarse de manera adecuada.
• Los nodos deberán ser agregados a la lista EN ORDEN decreciente de acuerdo al
campo “ventasDiarias” (los de mayor cantidad de ventas al inicio y los de menor cantidad
de ventas al final). La función debe ser ITERATIVA.*/

stVendedor crearUnVendedor(char archivoVendedor[])
{

    stVendedor aux;
    int op = 0;
    aux.id = buscarUltimaId(archivoVendedor)+1;

    printf("Ingrese el nombre y apellido: ");
    fflush(stdin);
    gets(aux.nombreYapellido);

    do
    {
        mostrarSector();
        printf("Ingrese el sector del vendedor: ");
        fflush(stdin);
        scanf("%i",&op);



        switch(op)
        {
        case 1:
            strcpy(aux.sector,"ropa");
            break;
        case 2:
            strcpy(aux.sector,"muebles");
            break;
        case 3:
            strcpy(aux.sector,"electro");
            break;
        default:
            puts("opcion invalida");
            break;

        }
    }
    while(validarSector(op)== 0);
    printf("Ingrese las ventas diarias del vendedor: ");
    fflush(stdin);
    scanf("%i",&aux.ventasDiarias);


    return aux;
}

void cargarArchivo(char archivoVendedor[])
{

    stVendedor aux;
    FILE * buffer = fopen(archivoVendedor,"ab");
    if(buffer != NULL)
    {

        aux = crearUnVendedor(archivoVendedor);
        fwrite(&aux,sizeof(stVendedor),1,buffer);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo1");
    }


}

void mostrarArchivoVendedores(char archivoVendedores[])
{

    stVendedor aux;
    FILE * buffer = fopen(archivoVendedores,"rb");
    if(buffer != NULL)
    {

        while(fread(&aux,sizeof(stVendedor),1,buffer)>0)
        {
            mostrarUnVendedor(aux);
        }

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }


}

int buscarUltimaId(char archivoVendedor[])
{
    stVendedor aux;
    int ulti = 0;
    FILE* buffer = fopen(archivoVendedor,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stVendedor),1,buffer)>0)
        {
            if(aux.id > ulti)
            {

                ulti = aux.id;
            }
        }
        fclose(buffer);
    }
    else
    {
        puts("Archivo nulo");
    }

    return ulti;
}


int validarSector(int dato)
{

    int flag = 0;
    if(dato >= 1 && dato <= 3)
    {

        flag = 1;
    }

    return flag;
}

void mostrarSector()
{

    puts("1.ropa");
    puts("2.muebles");
    puts("3.electro");

}

void mostrarUnVendedor(stVendedor p)
{
    puts("-------------------------------------------------------------------------------------");
    printf("\nId del Vendedor....................................: %d \n", p.id);
    printf("\nApellido y nombre..................................: %s \n", p.nombreYapellido);
    printf("\nSector.............................................: %s \n", p.sector);
    printf("\nVentas diarias.....................................: %d \n", p.ventasDiarias);
    puts("-------------------------------------------------------------------------------------");

}

nodoSimple * inicListaSimple()
{
    return NULL;
}

nodoSimple * crearNodoSimple(stVendedor aux)
{

    nodoSimple * nuevo =(nodoSimple*) malloc(sizeof(nodoSimple));
    nuevo->dato = aux;
    nuevo->siguiente = NULL;

    return nuevo;
}

nodoSimple * agregarAlPpio(nodoSimple * lista,nodoSimple * nuevo)
{

    nuevo->siguiente = lista;
    return nuevo;
}

nodoSimple * agregarEnOrden(nodoSimple * lista, nodoSimple * nuevo)
{

    if(lista != NULL)
    {
        if(lista->dato.ventasDiarias < nuevo->dato.ventasDiarias)
        {
            lista = agregarAlPpio(lista,nuevo);
        }
        else
        {
            nodoSimple * seg = lista;
            nodoSimple * ante = lista;
            while(seg != NULL && seg->dato.ventasDiarias > nuevo->dato.ventasDiarias)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente = nuevo;
            nuevo->siguiente = seg;

        }

    }
    else
    {
        lista = nuevo;
    }
    return lista;
}




nodoSimple * archivoALista(char archivoVendedores[],nodoSimple * lista)
{
    stVendedor aux;
    FILE * buffer = fopen(archivoVendedores,"rb");
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stVendedor),1,buffer)>0)
        {
            lista = agregarEnOrden(lista,crearNodoSimple(aux));
        }

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


    return lista;
}

/**Mostrar la LISTA SIMPLE de Vendedores del ejercicio 1.
• Deberá modularizarse de manera adecuada.
• La lista deberá ser mostrada DE ATRÁS HACIA ADELANTE (desde el último nodo hasta
el primer nodo). Pensar qué tipo de función utilizar para lograrlo.*/

void mostrarListaSimple(nodoSimple * lista)
{



    while(lista != NULL)
    {
        mostrarUnVendedor(lista->dato);
        lista = lista->siguiente;
    }
}


void mostrarRecursivoAlReves(nodoSimple * lista)
{

    if(lista!= NULL)
    {

        mostrarRecursivoAlReves(lista->siguiente);
        mostrarUnVendedor(lista->dato);
    }

}
/**3. Realizar una función RECURSIVA que retorne la cantidad de Vendedores que tiene la LISTA
SIMPLE pertenecientes a un sector a elección del usuario del sistema.*/

int contarPorSector(nodoSimple * lista,char sectorAContar[])
{

    int acumuludador = 0;

    if(lista!= NULL)
    {

        if(strcmpi(lista->dato.sector,sectorAContar)== 0)
        {
            acumuludador ++;
        }
        acumuludador += contarPorSector(lista->siguiente,sectorAContar);
    }
    return acumuludador;
}

/**La tienda abona un plus por ventas a los diez mejores vendedores de cada día. Para facilitar
esta tarea a nuestro cliente, debemos organizar un Top Ten de vendedores modularizando
de la siguiente manera:
a) Codificar las funciones auxiliares y estructuras necesarias para construir una LISTA
DOBLE.
• La lista doble debe quedar ordenada de manera ascendente, con los vendedores de
menor cantidad de ventas al inicio y los de mayor cantidad de ventas al final, pero para
ello NO debe utilizarse la función de agregar en orden, deberá pensarse si usar la de
agregar al principio o la de agregar al final. Esta función deberá utilizar PUNTERO
DOBLE.*/

nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble(stVendedor dato)
{

    nodoDoble * nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->aux = dato;

    nuevo->siguiente = NULL;
    nuevo->anterior= NULL;

    return nuevo;
}


nodoDoble * buscarUltimoIdListaDoble(nodoDoble * listaDoble)
{


    while(listaDoble != NULL && listaDoble->siguiente != NULL)
    {

        listaDoble = listaDoble->siguiente;
    }

    return listaDoble;
}
void agregarAlFinal(nodoDoble ** listaDoble, nodoDoble * nuevo)
{

    if(*listaDoble != NULL)
    {
        nodoDoble * ulti = buscarUltimoIdListaDoble(*listaDoble);
        ulti->siguiente = nuevo;
        nuevo->anterior = ulti;

    }
    else
    {
        *listaDoble = nuevo;
    }

}

nodoDoble * agregarAlPpioListaDoble(nodoDoble ** listaDoble,nodoDoble * nuevo)
{

   nuevo->siguiente = (*listaDoble);
   if(*listaDoble != NULL){
    (*listaDoble)->anterior = nuevo;
   }
    return nuevo;
}



void mostrarListaDoble(nodoDoble * listaDoble)
{

    while(listaDoble != NULL)
    {
        mostrarUnVendedor(listaDoble->aux);
        listaDoble = listaDoble->siguiente;
    }
}

nodoDoble * pasarDeSimpleADoble(nodoDoble * listaDoble,nodoSimple * lista){

if(lista != NULL){
    int i = 0;
    while(lista!= NULL && i<10){
        listaDoble = agregarAlPpioListaDoble(&listaDoble,crearNodoDoble(lista->dato));
        lista = lista->siguiente;
        i++;
    }

}

return listaDoble;
}





void menu(char archivoVendedor[],nodoSimple * lista,nodoDoble * listaDoble)
{
    char op = 's';
    int opSw = 0;
    int vendedoresXsector = 0;
    int dato = 0;
    char aux[10];
    do
    {

        opciones();
        opSw = preguntarDato();

        switch(opSw)
        {
        case 1:
            do
            {
                cargarArchivo(archivoVendedor);
                printf("\nIngrese (S) para seguir cargando vendedores,(N) para finalizar: ");
                fflush(stdin);
                scanf("%c",&op);


            }
            while(op == 'S'|| op == 's');
            mostrarArchivoVendedores(archivoVendedor);
            break;
        case 2:

            lista = archivoALista(archivoVendedor,lista);
            puts("-------------NORMAL-----------------");

            mostrarListaSimple(lista);
            puts("-------------RECURSIVO-----------------");
            mostrarRecursivoAlReves(lista);
            puts("----------------------------------------");


            break;
        case 3:

            do
            {

                puts("---------------------------Elija un sector para buscar--------------------------------");
                mostrarSector();
                printf("Elija una opciones: ");
                fflush(stdin);
                scanf("%i",&dato);


            }
            while(validarSector(dato) == 0);
            copiarString(aux,dato);

            vendedoresXsector = contarPorSector(lista,aux);
            printf("Cantidad de vendedores:|%i|\n",vendedoresXsector);
            break;
        case 4:

            listaDoble = pasarDeSimpleADoble(listaDoble,lista);
            mostrarListaDoble(listaDoble);

            break;
        case 5:
            puts("\n......................Lista Simple..............................\n");

            if(lista != NULL){
                mostrarListaSimple(lista);
            }else{
            puts("Lista vacia");
            }
            puts("\n\n......................Lista Doble..............................\n");
            if(listaDoble != NULL){
                mostrarListaDoble(listaDoble);
            }else{
            puts("Lista doble vacia");
            }

            break;
        default:
            puts("Opcion invalida,Reintente...");
            break;

        }

        printf("Ingrese (S) para seguir,(N) para finalizar:");
        fflush(stdin);
        scanf("%c",&op);
        limpiarPantalla();

    }
    while(op == 's'|| op == 'S');

}

void copiarString(char aux[],int dato)
{

    if(dato == 1)
    {
        strcpy(aux,"ropa");

    }
    else if(dato == 2)
    {
        strcpy(aux,"mueble");

    }
    else if(dato == 3)
    {
        strcpy(aux,"electro");

    }
    else
    {
        puts("Opcion invalido");
    }


}

int preguntarDato()
{

    int dato = 0;

    printf("Ingrese el dato solicitado: ");
    fflush(stdin);
    scanf("%i",&dato);

    return dato;
}


void opciones()
{

    puts("1.Cargar vendedores");
    puts("2.Pasar del archivo a la lista por vendedores");
    puts("3.Contar vendedores por un sector especifico");
    puts("4.Agregar a listas dobles");
    puts("5.Mostrar ambas listas");

}


int main()
{
    char archivoVendedor[15] = "Vendedores";
    nodoSimple * lista = inicListaSimple();
    nodoDoble * listaDoble = inicListaDoble();
    menu(archivoVendedor,lista,listaDoble);
    return 0;
}

