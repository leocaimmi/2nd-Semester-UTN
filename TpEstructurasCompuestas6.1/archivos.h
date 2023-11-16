#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#define ARCHI_REGISTRO "archivoRegistros.bin"
#define ARCHI_APROBADOS "archivoAprovados.bin"

typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
   char materia[40];
   int idMateria;
} registroArchivo;

registroArchivo crearUnRegistro();
void cargarRegistro();
void mostrarUnRegistro(registroArchivo aux);
void mostrarArchivo();
void mostrarArchivoAprobados();


#endif // ARCHIVOS_H_INCLUDED
