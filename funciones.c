#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarProducto(FILE *Archi) {
    printf("Ingrese el nombre del producto: ");
    char nombre[100];
    scanf("%s", nombre);

    printf("Ingrese la descripción del producto: ");
    char descripcion[100];
    scanf("%s", descripcion);

    printf("Ingrese la cantidad de productos: ");
    int cantidad;
    scanf("%d", &cantidad);

    printf("Ingrese el precio del producto: ");
    float precio;
    scanf("%f", &precio);

    fprintf(Archi, "%s %s %d %.2f\n", nombre, descripcion, cantidad, precio);

    printf("Producto ingresado correctamente.\n\n");
}

void verProductos(FILE *Archi) {
    fseek(Archi, 0, SEEK_SET);
    printf("Productos:\n");
    char nombre[50];
    char descripcion[100];
    int cantidad;
    float precio;

    while (fscanf(Archi, "%s %s %d %f", nombre, descripcion, &cantidad, &precio) == 4) {
        printf("Nombre: %s\n", nombre);
        printf("Descripción: %s\n", descripcion);
        printf("Cantidad: %d\n", cantidad);
        printf("Precio: %.2f\n", precio);
        printf("\n");
    }
}

void modificarProducto(FILE *Archi) {
    printf("Ingrese el nombre del producto a modificar: ");
    char nombre[50];
    scanf("%s", nombre);

    FILE *architem = fopen("temp.txt", "w");
    if (architem == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        return;
    }

    char nombretempo[50];
    char descripcion[100];
    int cantidad;
    float precio;
    int encontrado = 0;

    while (fscanf(Archi, "%s %s %d %f", nombretempo, descripcion, &cantidad, &precio) == 4) {
        if (strcmp(nombretempo, nombre) == 0) {
            encontrado = 1;
            printf("Ingrese la nueva descripción del producto: ");
            scanf("%s", descripcion);
            printf("Ingrese la nueva cantidad de productos: ");
            scanf("%d", &cantidad);
            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precio);
        }

        fprintf(architem, "%s %s %d %.2f\n", nombretempo, descripcion, cantidad, precio);
    }

    fclose(Archi);
    fclose(architem);

    if (encontrado) {
        remove("productos_inventario.txt");
        rename("temp.txt", "productos_inventario.txt");
        printf("Producto modificado correctamente.\n\n");
    } else {
        remove("temp.txt");
        printf("Producto no encontrado.\n\n");
    }

    Archi = fopen("productos_inventario.txt", "a+");
    if (Archi == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
}

void eliminarProducto(FILE *Archi) {
    printf("Ingrese el nombre del producto a eliminar: ");
    char nombre[50];
    scanf("%s", nombre);

    FILE *architem = fopen("temp.txt", "w");
    if (architem == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        return;
    }

    char nombretempo[50];
    char descripcion[100];
    int cantidad;
    float precio;
    int encontrado = 0;

    while (fscanf(Archi, "%s %s %d %f", nombretempo, descripcion, &cantidad, &precio) == 4) {
        if (strcmp(nombretempo, nombre) == 0) {
            encontrado = 1;
            continue;
        }

        fprintf(architem, "%s %s %d %.2f\n", nombretempo, descripcion, cantidad, precio);
    }

    fclose(Archi);
    fclose(architem);

    if (encontrado) {
        remove("productos_inventario.txt");
        rename("temp.txt", "productos_inventario.txt");
        printf("Producto eliminado correctamente.\n\n");
    } else {
        remove("temp.txt");
        printf("Producto no encontrado.\n\n");
    }
}
