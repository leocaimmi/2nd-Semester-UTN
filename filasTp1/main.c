#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
int main()
{
    srand(time(NULL));
    char archivo[25] = "clientesBorrados";///archivo clientes borrados(esta en WB)
    menu(archivo);
    return 0;
}
