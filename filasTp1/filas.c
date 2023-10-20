#include <stdio.h>
#include <stdlib.h>
#include "filas.h"
const char nombresFila[100][20] =
{
    "Carlos","Mariano","Jose", "Pedro", "Antonio",
    "Manuel", "Felipe", "Julia", "Marta", "Ines",
    "Eduardo", "Hector", "Mario", "Luis", "Oscar",
    "Sergio", "Rafael", "Fernando", "Javier", "Ricardo",
    "Victor", "Daniel", "Miguel", "Roberto", "Francisco",
    "Diego", "Bruno", "Gabriel", "Alejandro", "Gonzalo",
    "Ignacio", "Juan", "Adrian", "Martin", "David",
    "Isabel", "Carmen", "Ana", "Teresa", "Maria",
    "Laura", "Elena", "Cristina", "Beatriz", "Raquel",
    "Sandra", "Monica", "Rosa", "Silvia", "Patricia",
    "Clara", "Nuria", "Pilar", "Sonia", "Paula",
    "Diana", "Natalia", "Marta", "Ismael", "Ruben",
    "Ivan", "Angel", "Nicolas", "Pablo", "Alberto",
    "Joaquin", "Ernesto", "Rodrigo", "Federico", "Andres",
    "Samuel", "Ramon", "Emilio", "Guillermo", "Esteban",
    "Marcos", "Alfonso", "Enrique", "Lucas", "Gerardo",
    "Marcelo", "Horacio", "Tomas", "Agustin", "Elias",
    "Leonardo", "Matias", "Benjamin", "Gustavo", "Dante",
    "Valentin", "Humberto", "Lorenzo", "Facundo", "Maximo",
    "Damian", "Mauro", "Augusto", "Renato", "Leandro"
};
void inicFila(Fila * fila)
{

    fila->primero =inicNodoDoble();
    fila->ultimo =inicNodoDoble();

}

///3.Crear un arreglo de filas cargando 5 cajas de atención con sus datos correspondientes

void inicializarArregloFilas(Fila cajas[])
{
    for(int i = 0; i<5; i++)
    {
        inicFila(&cajas[i]);

    }
}

void asignarDatosFila(Fila cajas[])
{
    cajas[0].numeroFila = 001;
    strcpy(cajas[0].nombreCajero,nombresFila[rand()%100]);
    cajas[1].numeroFila = 002;
    strcpy(cajas[1].nombreCajero,nombresFila[rand()%100]);
    cajas[2].numeroFila = 003;
    strcpy(cajas[2].nombreCajero,nombresFila[rand()%100]);
    cajas[3].numeroFila = 004;
    strcpy(cajas[3].nombreCajero,nombresFila[rand()%100]);
    cajas[4].numeroFila = 005;
    strcpy(cajas[4].nombreCajero,nombresFila[rand()%100]);

}

///4.Mostrar las filas para verificar la correcta creación
void mostrarCajas(Fila cajas[])
{
    for(int i = 0; i<5; i++)
    {
        printf("-------------------CAJA(%i)-----------------------\n",i+1);
        printf("Nombre|%s|\n",cajas[i].nombreCajero);
        printf("Numero de caja|%i|\n",cajas[i].numeroFila);
        printf(".................CLIENTES......................\n");
        mostrarListaDoble(cajas[i].primero);
    }
}

stCliente verPrimero(nodoDoble * lista)
{

    stCliente cliente;

    if(lista != NULL)
    {
        cliente = lista->dato;

    }
    return cliente;
}

stCliente extraer(Fila * caja)
{

    stCliente cliente;

    if(caja->primero != NULL)
    {
        cliente = verPrimero(caja->primero);
        caja->primero = borrarPrimero(caja->primero);
        if(caja->primero == NULL)
        {
            caja->ultimo = inicNodoDoble();

        }
    }


    return cliente;
}


/**5.Recorrer la lista simple (p1) y ubicar a los clientes en las cajas que correspondan.
Siempre elegir la caja con menos clientes ante la coincidencia de criterio (solo con los clientes regulares).
 Modularizar la función de contar cantidad de clientes dada una fila determinada.*/

int contarClientesFila(Fila caja)///le pase la fila individual del arreglo de cajas
{

    int cantClientes = 0;
    nodoDoble * aux = caja.primero;
    while(aux != NULL)
    {
        aux = aux->siguiente;
        cantClientes++;
    }

    return cantClientes;
}

void agregar(Fila* caja,stCliente aux)///al final agrega
{

    nodoDoble * nuevo = crearUnNodoDoble(aux);

    if(caja->primero != NULL)
    {

        caja->ultimo->siguiente = nuevo;
        nuevo->anterior = caja->ultimo;
        caja->ultimo = nuevo;


    }
    else
    {
        caja->primero = nuevo;
        caja->ultimo = nuevo;
    }

}


void asignarClientesALasCajas(Fila cajas[],nodoSimple * listaSimple)
{

    if(listaSimple != NULL)
    {

        int contadorCaja1 = 0;
        int contadorCaja3 = 0;
        int contadorCaja4 = 0;

        mostrarLista(listaSimple);
        while(listaSimple != NULL)
        {

            contadorCaja1 = contarClientesFila(cajas[0]);

            contadorCaja3 = contarClientesFila(cajas[2]);

            contadorCaja4 = contarClientesFila(cajas[3]);


            if(listaSimple->dato.tipoCliente == 2) ///solo jubilados
            {
                agregar(&cajas[1],listaSimple->dato);

            }
            else if(listaSimple->dato.tipoCliente == 4)   ///solo empresarios
            {
                agregar(&cajas[4],listaSimple->dato);

            }
            else if(listaSimple->dato.tipoCliente == 3||(listaSimple->dato.tipoCliente == 1 &&(contadorCaja3<= contadorCaja1) && (contadorCaja3 <= contadorCaja4))) ///personas gestantes al principio y personas regulares al final
            {
                if(listaSimple->dato.tipoCliente== 3)
                {

                    cajas[2].primero= agregarAlPpioFinal(cajas[2].primero,crearUnNodoDoble(listaSimple->dato));
                }
                else
                {

                    agregar(&cajas[2],listaSimple->dato);
                }

            }
            else if(listaSimple->dato.tipoCliente == 1 && (contadorCaja1<= contadorCaja3) && (contadorCaja1 <= contadorCaja4))///regulares por orden de llegada
            {
                agregar(&cajas[0],listaSimple->dato);

            }
            else if(listaSimple->dato.tipoCliente == 1 && (contadorCaja4<= contadorCaja3) && (contadorCaja4 <= contadorCaja1))///regulares por orden de cant de facturas a pagar
            {
                cajas[3].primero = agregarOrdenadoDoble(cajas[3].primero,crearUnNodoDoble(listaSimple->dato));

            }

            listaSimple = listaSimple->siguiente;
        }
    }

}

/**6.Atender a los clientes de todas las filas. Una por vez. El cliente atendido se borra de la fila y luego va a un único archivo. Opcional: mostrar el archivo luego. */

void atenderClientes(Fila cajas[],char archivo[])
{


    stCliente aux;
    FILE * buffer = fopen(archivo,"wb");
    if(buffer != NULL)
    {

        for(int i = 0; i <5; i++)
        {
            while(cajas[i].primero != NULL)
            {
                if(cajas[4].primero->dato.cantFacturas >=10)
                {
                    cajas[4].primero->dato.cantFacturas = cajas[4].primero->dato.cantFacturas - 10;
                    agregar(&cajas[4],cajas[4].primero->dato);
                }
                else
                {

                    aux =  extraer(&cajas[i]);
                    fwrite(&aux,sizeof(stCliente),1,buffer);
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
void mostrarArchivo(char archivo[])
{

    FILE * buffer = fopen(archivo,"rb");
    stCliente aux;
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(stCliente),1,buffer)>0)
        {
            mostrarUnCliente(aux);
        }

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }


}

/**7.Se debe calcular la cantidad promedio de facturas por cada caja y el tiempo de espera. Por ejemplo.
Si una caja tiene dos clientes (10 y 5 facturas correspondientes), el primer cliente espera 0 tiempo pero el segundo espera 10 facturas.
El tiempo promedio es 10/2 = 5. Ahora si hay un tercero, este deberá esperar los 10 del primero más los 5 del segundo. Sumar todo y dividir.*/

float mostrarPromedioDeLasCajas(Fila cajas[])
{

    float menorEspera[5];
    float dato = 0;
    float promedioCaja = 0;
    for(int i = 0; i<5; i++)
    {


        if(cajas[i].primero!=NULL)
        {
            promedioCaja = calcularPromedioDeFacturasXCaja(cajas[i]);
            printf("\n....................CAJA(%i)........................\n",i+1);
            promedios(promedioCaja);
        }
        else
        {
            printf("\n....................CAJA(%i)........................\n",i+1);
            printf("La caja se encuentra sin clientes por el momento\n",i);
        }
        menorEspera[i] = promedioCaja;

    }
    dato = buscarMenor(menorEspera);
    return dato;
}
///8.Mostrar la caja donde se espero menos.
float buscarMenor(float arreglo[])
{

    int i = 0;
    float datoMenor = arreglo[i];

    for(i= 0; i<5; i++)
    {
        if(arreglo[i]<datoMenor)
        {
            datoMenor = arreglo[i];
        }
    }
    return datoMenor;
}


void promedios(float promedioCaja)
{
    puts(".....................PROMEDIO DE FACTURAS Y TIEMPO POR CAJA...........................");
    printf("Promedio de la caja:|%.2f|\n",promedioCaja);

}
float calcularPromedioDeFacturasXCaja(Fila caja)
{

    float promedioFacturas = 0;
    int i = 0;

    while(caja.primero != NULL)
    {

        promedioFacturas += caja.primero->dato.cantFacturas;
        caja.primero = caja.primero->siguiente;
        i++;
    }

    promedioFacturas = promedioFacturas/i; /// i = cantidad de clientes, promedio facturas es igual a la cantidad total de facturas

    return promedioFacturas;
}



