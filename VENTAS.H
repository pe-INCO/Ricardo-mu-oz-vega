#ifndef VENTAS_H
#define VENTAS_H

typedef struct {
    int idVenta;
    int idCliente;
    int codigoProducto;
    int cantidad;
    float total;
} Venta;

void registrarVenta();
void mostrarVentas();

#endif
