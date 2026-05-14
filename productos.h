#ifndef PRODUCTOS_H
#define PRODUCTOS_H

typedef struct {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
} Producto;

void agregarProducto();
void mostrarProductos();
void buscarProducto();
void editarProducto();
void eliminarProducto();

#endif