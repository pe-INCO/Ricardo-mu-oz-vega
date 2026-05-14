#include <stdio.h>
#include <string.h>

#include "ventas.h"
#include "productos.h"

typedef struct {
    int idVenta;
    int idCliente;
    int codigoProducto;
    int cantidad;
    float total;
} Venta;

void registrarVenta() {

    FILE *archivoProductos = fopen("productos.dat", "rb+");
    FILE *archivoVentas = fopen("ventas.dat", "ab");

    if (archivoProductos == NULL || archivoVentas == NULL) {
        printf("\nError al abrir archivos.\n");
        return;
    }

    Venta v;
    Producto p;

    int encontrado = 0;

    printf("\n--- Registrar Venta ---\n");

    printf("ID Venta: ");
    scanf("%d", &v.idVenta);

    printf("ID Cliente: ");
    scanf("%d", &v.idCliente);

    printf("Codigo Producto: ");
    scanf("%d", &v.codigoProducto);

    printf("Cantidad: ");
    scanf("%d", &v.cantidad);

    while (fread(&p, sizeof(Producto), 1, archivoProductos)) {

        if (p.codigo == v.codigoProducto) {

            encontrado = 1;

            if (p.stock >= v.cantidad) {

                p.stock -= v.cantidad;

                v.total = p.precio * v.cantidad;

                fseek(archivoProductos,
                       -sizeof(Producto),
                       SEEK_CUR);

                fwrite(&p, sizeof(Producto), 1, archivoProductos);

                fwrite(&v, sizeof(Venta), 1, archivoVentas);

                printf("\nVenta registrada exitosamente.\n");
                printf("Total: %.2f\n", v.total);

            } else {

                printf("\nStock insuficiente.\n");
            }

            break;
        }
    }

    if (!encontrado) {
        printf("\nProducto no encontrado.\n");
    }

    fclose(archivoProductos);
    fclose(archivoVentas);
}

void mostrarVentas() {

    FILE *archivo = fopen("ventas.dat", "rb");

    if (archivo == NULL) {
        printf("\nNo hay ventas registradas.\n");
        return;
    }

    Venta v;

    printf("\n%-10s %-10s %-10s %-10s %-10s\n",
           "VENTA",
           "CLIENTE",
           "PRODUCTO",
           "CANTIDAD",
           "TOTAL");

    while (fread(&v, sizeof(Venta), 1, archivo)) {

        printf("%-10d %-10d %-10d %-10d %-10.2f\n",
               v.idVenta,
               v.idCliente,
               v.codigoProducto,
               v.cantidad,
               v.total);
    }

    fclose(archivo);
}
