#ifndef CONTACTOS_H_INCLUDED
#define CONTACTOS_H_INCLUDED
typedef struct
{
    int DNI;
    int tipoContacto; //1-familia 2-trabajo 3-amigos
    int activo; //1-true 0-false
} stContacto ;

typedef struct nodoCliente
{
    stContacto dato;
    struct nodoContacto* siguiente;
    struct nodoContacto* anterior;
} nodoContacto;

stContacto crearUnContacto();
int validarTipoDeContacto(int datoValidar);
void mostrarUnContacto(stContacto aux);


nodoContacto * inicNodoContacto();
nodoContacto * crearUnNodoContacto(stContacto aux);
void mostrarListaDoble(nodoContacto * listaDoble);
nodoContacto * agregarAlPpioListaDoble(nodoContacto * listaDoble,nodoContacto * nuevo);
nodoContacto * agregarEnOrdenListaDoble(nodoContacto * listaDoble,nodoContacto* nuevo);
void mostrarListaDobleRecursiva(nodoContacto * listaDoble);
int contarContactosActivos(nodoContacto * listaDoble);
#endif // CONTACTOS_H_INCLUDED
