#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"
#include "string.h"

registroArchivo crearUnRegistro()
{
    registroArchivo aux;
    int eleccion = 0;
    printf("Ingrese el nombre y apellido del alumno: ");
    fflush(stdin);
    gets(aux.nombreApe);
    aux.nota = rand()%10+1;
    aux.legajo = rand()%1000+1;

    do
    {
        puts("Ingrese 1 para cargar a la materia Programacion, 2 para cargar la materia Ingles y 3 para cargar la materia Estadistica");
        fflush(stdin);
        scanf("%i",&eleccion);
        aux.idMateria=eleccion;

    }
    while(switchEleccionMateria(aux.materia, eleccion)==0);

    return aux;
}
int switchEleccionMateria(char materia[], int eleccion)
{
    int flag=0;
    switch(eleccion)
    {
    case 1:
        strcpy(materia, "Programacion");

        flag=1;
        break;
    case 2:
        strcpy(materia, "Ingles");

        flag=1;
        break;
    case 3:
        strcpy(materia, "Estadistica");

        flag=1;
        break;
    default:
        puts("ERROR, dato ingresado no valido..");
        break;
    }


    return flag;


}



void mostrarUnRegistro(registroArchivo aux)
{
    puts("-----------------------------------------");
    printf("[Nombre y apellido]%s\n",aux.nombreApe);
    printf("[Legajo]%i\n",aux.legajo);
    printf("[Nota]%i\n",aux.nota);
    printf("[Materia]%s\n",aux.materia);
    printf("[Id de la materia]%i\n",aux.idMateria);


    puts("-----------------------------------------");


}


void cargarRegistro()
{

    char op = 's';
    registroArchivo aux;
    FILE * buffer = fopen(ARCHI_REGISTRO,"wb");
    if(buffer!= NULL)
    {
        do
        {
            aux = crearUnRegistro();
            fwrite(&aux,sizeof(registroArchivo),1,buffer);

            printf("[S]Para seguir cargando\n");
            printf("[N]Para finalizar la carga al archivo\n");
            fflush(stdin);
            scanf("%c",&op);

        }
        while(op == 's'|| op == 'S');

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }


}


void mostrarArchivo()
{
    registroArchivo aux;
    FILE * buffer = fopen(ARCHI_REGISTRO,"rb");
    if(buffer != NULL)
    {

        while(fread(&aux,sizeof(registroArchivo),1,buffer)>0)
        {
            mostrarUnRegistro(aux);
        }

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }



}
void mostrarArchivoAprobados()
{
    registroArchivo aux;
    FILE * buffer = fopen(ARCHI_APROBADOS,"rb");
    if(buffer != NULL)
    {

        while(fread(&aux,sizeof(registroArchivo),1,buffer)>0)
        {
            mostrarUnRegistro(aux);
        }

        fclose(buffer);
    }
    else
    {
        puts("Archivo vacio");
    }



}
