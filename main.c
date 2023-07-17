#include <stdio.h>
#include "funciones.h"

//Brandon Altamirano

int main() {
    FILE *Archi = fopen("productos_inventario.txt", "a+");
    if (Archi == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    int opcion;

    //MENU DE OPCIONES PRINCIPAL 

    do {
        printf("----- Menu de opciones -----\n");
        printf("1 Ver productos\n");
        printf("2. Ingresar producto\n");
        printf("3. Cambiar producto\n");
        printf("4. Borrar producto\n");
        printf("0. Cerrar\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                verProductos(Archi);
                break;
            case 2:
                ingresarProducto(Archi);
                break;
            case 3:
                modificarProducto(Archi);
                break;
            case 4:
                eliminarProducto(Archi);
                break;
            case 0:
                printf("Cerrando del programa...\n");
                break;
            default:
                printf("Opción no valida, de nuevo.\n"); //Si no se ingresa un valor adecuado el programa le indicara que no es valido.
        }
    } while (opcion != 0);

    fclose(Archi);

    return 0;
}
