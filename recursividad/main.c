#include <stdio.h>
#include <stdlib.h>

///primer TP recursion, agosto

int factorialRecursiva(int dato);
int potenciaRecursiva(int dato, int pot);
void mostrarArregloRecursivo(int arr[],int validos, int i);
void mostrarArregloRecursivoInvertido(int arr[],int validos, int i);
int verificarArregloCapicuaRecursivo(int arreglo[],int validos,int i);
int suma (int arreglo[],int validos,int pos);
int buscarMenorRecursivo(int arr[], int validos, int i);

int menorDelArchivoRecursivo(char archivo[],FILE*buffer,int * flagFin);
void mostrarCaracterRecursivo();

int contarRegistro(char archivo[]);
void recorrerArchivoInvertidoRecursivo(FILE* buffer);
void buscarElementoRecursivo(int arr[],int validos,int pos,int dato);

void invertirElementosDeUnArchivoRecursivo(FILE* buffer, int i, int j);
void mostrarArchivo(char archivo[]);

int main()
{

    /*int datoFactorial = 15;
    int rta = factorialRecursiva(datoFactorial);
    printf("rta: |%i|",rta);*/

    /*int dato= 5, pot=5;///potencia
    int res=potenciaRecursiva(dato,pot);*/

    //int arr[10]={34,70,100,45,89,21,34,5,87};
    int arr[4]={1,0,5,1};
    //mostrarArregloRecursivo(arr,4,0);
    //mostrarArregloRecursivoInvertido(arr,4,0);

    int flag= verificarArregloCapicuaRecursivo(arr,4,0)? printf("El arreglo no es capicua") : printf("El arreglo SI es capicua");
    /*int resultado = buscarMenorRecursivo(arr,9,0);
    printf("menor: |%i|\n",resultado);*/

    /*char archivo[] = "enteros";
    int aux[10] = {1,2,3,4,5,6,7,8,9,10};
    int dato=0;
FILE* buffer =fopen(archivo,"wb");

    if(buffer != NULL)
    {
        for(int i = 0; i<10; i++)
        {
            dato = aux[i];
            fwrite(&dato,sizeof(int),1,buffer);
            printf("dato:%i \n",dato);
        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo 1");
    }*/

//    FILE* buffer =fopen(archivo,"rb");
//
//int flagFin = 0;
//    int menor = menorDelArchivoRecursivo(archivo,buffer,&flagFin);
//    fclose(buffer);
//    printf(" EL MAS MENOR:|%i|\n",menor);
//
   //mostrarCaracterRecursivo();
//
//    int total = contarRegistro(archivo);
//    FILE* buffer =fopen(archivo,"rb");
//    recorrerArchivoInvertidoRecursivo(buffer);
//    fclose(buffer);

//    int arr[10]={34,70,100,45,89,21,34,5,87};
//
//    buscarElementoRecursivo(arr,9,0,97);

    /*mostrarArchivo(archivo);

    int total = contarRegistro(archivo);


    buffer =fopen(archivo,"r+b");
    invertirElementosDeUnArchivoRecursivo(buffer,0,total);
    fclose(buffer);

    mostrarArchivo(archivo);*/

    return 0;
}


void mostrarArchivo(char archivo[])
{
    FILE*buffer=fopen(archivo,"rb");
    int aux;
    if(buffer != NULL)
    {
        while(fread(&aux,sizeof(int),1,buffer)>0)
        {
            printf("Numero: %i \n",aux);

        }
        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }


}


int contarRegistro(char archivo[])
{
    FILE*buffer=fopen(archivo,"rb");
    int total=0;
    if(buffer != NULL)
    {
        fseek(buffer,sizeof(int),SEEK_END);
        total=ftell(buffer)/sizeof(int);

        fclose(buffer);
    }
    else
    {
        puts("Error con el archivo");
    }
    return total - 1;

}

///Calcular el factorial de un número en forma recursiva.
int factorialRecursiva(int dato)
{

    int respuesta;

    if(dato != 0)
    {
        respuesta = dato* factorialRecursiva(dato-1);

    }
    else
    {
        respuesta = 1;
    }

    return respuesta;
}

///Calcular la potencia de un número en forma recursiva.
int potenciaRecursiva(int dato, int pot)
{
    int res=0;
    if(pot != 0)
    {
        pot--;
        res=dato*potenciaRecursiva(dato,pot);
        printf("La potencia de %i a la %i es: %i\n",dato,pot,res);

    }
    else
    {
        res=1;
    }
    return res;
}
///Recorrer un arreglo y mostrar sus elementos en forma recursiva.
void mostrarArregloRecursivo(int arr[],int validos, int i)
{
    if(i < validos)
    {
        printf("arr[%i] = %i \n",i,arr[i]);
        mostrarArregloRecursivo(arr,validos,i+1);

    }
    else
    {
        puts("FIN");
    }


}
///Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
///forma invertida (recursivo).

void mostrarArregloRecursivoInvertido(int arr[],int validos, int i)
{


    if(i < validos)
    {
        mostrarArregloRecursivoInvertido(arr,validos,i+1);
        printf("arr[%i] = %i \n",i,arr[i]);

    }
    else
    {
        puts("FIN");
    }

}
///Determinar en forma recursiva si un arreglo es capicúa.
int verificarArregloCapicuaRecursivo(int arreglo[],int validos,int i)
{

    int flag = 0;
    int j = validos - 1;

    if(arreglo[i] == arreglo[j] && flag == 0)
    {
       if(i!=j){

        verificarArregloCapicuaRecursivo(arreglo,j-1,i+1);
       }
    }
    else
    {
        flag = 1;
    }

    return flag;
}
///Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma. }

int suma (int arreglo[],int validos,int pos)
{

    int total;
    int i = pos;
    if(i<validos)
    {

        total= arreglo[i];
        total = total+ suma(arreglo,validos,i+1);

    }
    else
    {
        total = 0;

    }

    return total;
}

///7. Buscar el menor elemento de un arreglo en forma recursiva.

int buscarMenorRecursivo(int arr[], int validos, int i)
{
    int menor;
    if(i < validos)
    {
        menor= buscarMenorRecursivo(arr,validos,i+1);
        if(arr[i]< menor)
        {

            menor = arr[i];
        }
    }
    else
    {
        menor=arr[i-1];
    }


    return menor;
}

///8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)

int menorDelArchivoRecursivo(char archivo[],FILE* buffer, int * flagFin)
{

    int menor,aux;




    if (fread(&aux,sizeof(int),1,buffer)>0)
    {
        menor=menorDelArchivoRecursivo(archivo,buffer,flagFin);

        if ((*flagFin) == 1)
        {
            menor = aux;
            (*flagFin) = 0;

        }
        else
        {
            if(aux < menor)
            {
                menor=aux;
            }
        }

    }
    else
    {
        (*flagFin) = 1;
    }







    return menor;
}

///9. Invertir los elementos de un archivo de números enteros de forma recursiva.
///  (si no te sale, primero proba con invertir los elementos de un arreglo de int)

void invertirElementosDeUnArchivoRecursivo(FILE* buffer, int i, int j)
{


    int auxInicio,auxFinal;

    if(i < j)
    {
        fseek(buffer,sizeof(int)*i,SEEK_SET);
        fread(&auxInicio,sizeof(int),1,buffer); //me muevo al del inicio y leo


        fseek(buffer,sizeof(int)*(j-1),SEEK_SET);
        fread(&auxFinal,sizeof(int),1,buffer); //me guardo el valor final


        fseek(buffer,sizeof(int)*(-1),SEEK_CUR);
        fwrite(&auxInicio,sizeof(int),1,buffer); //me muevo uno para atras para poder escribir

        fseek(buffer,sizeof(int)*i,SEEK_SET);
        fwrite(&auxFinal,sizeof(int),1,buffer);// escribo el del inicio en el del final


    invertirElementosDeUnArchivoRecursivo(buffer,i+1,j-1);
    }


}

///10.Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.

void recorrerArchivoInvertidoRecursivo(FILE* buffer)
{
    int aux;
    if(fread(&aux,sizeof(int),1,buffer)>0)
    {

        recorrerArchivoInvertidoRecursivo(buffer);
        printf("Fabri gay:|%i|",aux);
    }






}

///11. Ingresar valores a una variable de tipo char (por teclado)
///y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.

void mostrarCaracterRecursivo()
{
    char letra;
    //printf("Ingrese una letra: ");
    fflush(stdin);
    scanf("%c",&letra);
    if(letra != '*')
    {
        mostrarCaracterRecursivo();
        printf("Letra: %c\n",letra);
    }



}

///12.Determinar si un arreglo contiene un determinado elemento de forma recursiva.
///(Pueden intentarlo también con una función void)(Tener en cuenta para un arreglo desordenado y
///el caso para un arreglo ordenado)

void buscarElementoRecursivo(int arr[],int validos,int pos,int dato)
{
    int i=pos;
    if(i<validos)
    {

        if(dato == arr[i])
        {
            printf("ELEMENTO ENCONTRADO: %i",arr[i]);
        }
        else
        {
            buscarElementoRecursivo(arr,validos,pos+1,dato);

        }
    }




}




