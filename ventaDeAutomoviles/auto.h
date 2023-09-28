#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED


typedef struct
{
    char patente[6];
    int valor;
    char marca[10];
}stAutomovil;

typedef struct
{
    stAutomovil dato;
    struct nodoAuto * siguiente;
} nodoAuto;

stAutomovil crearUnAuto();
nodoAuto * inicAuto();
nodoAuto * crearUnNodoDeAuto(stAutomovil aux);
void mostrarAutomovil(stAutomovil aux);
void mostrarListaAuto(nodoAuto * lista);

void agregarFinal(nodoAuto ** lista,nodoAuto * nuevoNodo);
nodoAuto* buscarUltimoLista(nodoAuto * lista);

int insertarCelda(stAutomovil A [], int dim, stAutomovil dato, int validos);
void mostrarArregloAutos(stAutomovil arreglo[],int validos);
void mostrarUnAutoArreglo(stAutomovil aux,int i);

void agregarMuchosAutos(nodoAuto ** lista);
int pasarAlArreglo(nodoAuto * lista, stAutomovil A[],int dim);

int sumarPatente(nodoAuto* lista);
int verificarPatentePar(stAutomovil aux);
#endif // AUTO_H_INCLUDED
