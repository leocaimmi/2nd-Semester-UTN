#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct
{
    int codigoProducto;
    char marca[50]; // Nintendo Switch, Xbox, Playstation
    float precioEnMiles;
    int stock;
    char modelo[50];// Común, Pro, Slim
} stConsola ;

typedef struct nodoConsola
{
    stConsola dato ;
    struct nodoConsola * siguiente;
} nodoConsola;



nodoConsola * inicConsola();
nodoConsola * crearNodoConsola(stConsola aux);
stConsola crearConsola();
void mostrarConsola(stConsola aux);
void mostrarLista(nodoConsola * lista);

nodoConsola * agregarAlPpio(nodoConsola * lista, nodoConsola * nodoNuevo);
nodoConsola* agregarXStock(nodoConsola* lista,nodoConsola * nuevaConsola);

nodoConsola * mostrarPrecioRecursivo(nodoConsola * lista,int precioAMostrar);

int consultarStockConsulta(nodoConsola* lista,char marcaAux[],char modeloAux[],int stockAux);

#endif // FUNCIONES_H_INCLUDED
