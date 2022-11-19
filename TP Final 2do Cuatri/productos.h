#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>



typedef struct {
    int idProducto;
    char descripcion[300];
    float precio;

} stProductos;


///FUNCIONES PRODUCTOS
void cargarArchivoProductos(char NombreArchivoProductos[]);
int contarProductosArchivo(char NombreArchivoProducto[]);
void MostrarUnProducto(stProductos a);
void MostrarProductos(char NombreArchivoProducto[]);
int ComprobarIdProducto(char nombreArchivoProductos[],int id);
float calcularPrecioSegundId(char nombreArchivoProductos[],int id);

#endif // PRODUCTOS_H_INCLUDED
