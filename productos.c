#include <stdio.h>
#include <string.h>
#include "productos.h"

void agregarProducto() {
    FILE *archivo = fopen("productos.dat", "ab"); 
    if (archivo == NULL) return;

    Producto p;
    printf("\n--- Registrar Nuevo Producto ---\n");
    printf("Codigo: "); scanf("%d", &p.codigo);
    printf("Nombre: "); scanf(" %[^\n]", p.nombre); 
    printf("Precio: "); scanf("%f", &p.precio);
    printf("Stock: ");  scanf("%d", &p.stock);

    fwrite(&p, sizeof(Producto), 1, archivo);
    fclose(archivo);
    printf("Producto guardado exitosamente.\n");
}


void mostrarProductos() {
    FILE *archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    Producto p;
    printf("\n%-10s %-20s %-10s %-10s\n", "CODIGO", "NOMBRE", "PRECIO", "STOCK");
    while (fread(&p, sizeof(Producto), 1, archivo)) {
        printf("%-10d %-20s %-10.2f %-10d\n", p.codigo, p.nombre, p.precio, p.stock);
    }
    fclose(archivo);
}


void buscarProducto() {
    FILE *archivo = fopen("productos.dat", "rb");
    if (archivo == NULL) return;

    int opcion, codBusqueda;
    char nomBusqueda[50];
    Producto p;
    int encontrado = 0;

    printf("\nBuscar por: 1.Codigo 2.Nombre: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese codigo: "); scanf("%d", &codBusqueda);
    } else {
        printf("Ingrese nombre: "); scanf(" %[^\n]", nomBusqueda);
    }

    while (fread(&p, sizeof(Producto), 1, archivo)) {
        if ((opcion == 1 && p.codigo == codBusqueda) || 
            (opcion == 2 && strstr(p.nombre, nomBusqueda))) {
            printf("\nEncontrado: %s | Stock: %d | Precio: %.2f", p.nombre, p.stock, p.precio);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("\nProducto no encontrado.");
    fclose(archivo);
}


void editarProducto() {
    FILE *archivo = fopen("productos.dat", "rb+"); 
    if (archivo == NULL) return;

    int cod;
    Producto p;
    int encontrado = 0;

    printf("\nCodigo del producto a editar: ");
    scanf("%d", &cod);

    while (fread(&p, sizeof(Producto), 1, archivo)) {
        if (p.codigo == cod) {
            printf("Nuevo Nombre (actual: %s): ", p.nombre); scanf(" %[^\n]", p.nombre);
            printf("Nuevo Precio: "); scanf("%f", &p.precio);
            printf("Nuevo Stock: "); scanf("%d", &p.stock);

            fseek(archivo, -sizeof(Producto), SEEK_CUR); 
            fwrite(&p, sizeof(Producto), 1, archivo);
            encontrado = 1;
            break;
        }
    }
    fclose(archivo);
    if (encontrado) printf("Producto actualizado.");
}


void eliminarProducto() {
    FILE *archivo = fopen("productos.dat", "rb");
    FILE *temporal = fopen("temporal.dat", "wb");
    if (archivo == NULL || temporal == NULL) return;

    int cod;
    Producto p;
    int eliminado = 0;

    printf("\nCodigo del producto a eliminar: ");
    scanf("%d", &cod);

    while (fread(&p, sizeof(Producto), 1, archivo)) {
        if (p.codigo != cod) {
            fwrite(&p, sizeof(Producto), 1, temporal);
        } else {
            eliminado = 1;
        }
    }

    fclose(archivo);
    fclose(temporal);

    remove("productos.dat");             
    rename("temporal.dat", "productos.dat"); 

    if (eliminado) printf("Producto eliminado.");
}