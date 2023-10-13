#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    char nombre[50];
    char telefono[50];
    int DNI; // valores del 1 al 100
} stPersona;

typedef struct
{
    stPersona dato;
    struct nodoPersona* siguiente;
} nodoPersona;

stPersona crearUnaPersona(nodoPersona * lista);
void mostrarPersona(stPersona aux);

nodoPersona * inicNodoPersona();
nodoPersona * crearUnNodoPersona(stPersona aux);
nodoPersona * agregarAlPpio(nodoPersona * lista,nodoPersona * nuevo);
void mostrarListaSimpleRecursiva(nodoPersona * lista);
int verificarDniRecursivo(nodoPersona * lista,int dniABuscar);
nodoPersona * agregarAlFinalListaSimple(nodoPersona * lista,nodoPersona * nuevo);
nodoPersona * buscarUltimoEnLaListaSimple(nodoPersona * lista);

nodoPersona * cargarPersonasALaLista(nodoPersona * lista);

#endif // PERSONA_H_INCLUDED
