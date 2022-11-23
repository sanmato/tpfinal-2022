#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED
#include "productos.h"

typedef struct {
   int idPedido;        // auto incremental
   int idCliente;       // este valor corresponde al id del cliente que realizó el pedido
   char fecha[12];
   int anio;
   int mes;
   int dia;
   char descripcion[300];
   float costo;
   int pedidoAnulado;    // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

///PEDIDOS
///Mostrar Pedidos
void MostrarUnPedido(stPedido a);
void MostrarTodosLosPedidos(char nombreArchivo[]);
void MostrarPedidosPorCliente(char nombreArchivo [],int idCliente);
///Operaciones de Pedidos
void BuscarUnPedido(char nombreArchivo[],int idPedido);
int ModifcarPedidoAdmin(char nombreArchivo[],int idPedido,char nombreArchivoProducto[]);
int  ModifcarPedidoUsuario(char nombreArchivoPedidos[],int idPedido,int idCliente,char nombreArchivoProducto[]);
void BajaPedido(char nombreArchivo[],int idPedido);
int BajaPedidoPorCliente(char nombreArchivo[],int idPedido,int idCliente);
void BajaPedidoPorClienteArbol(char nombreArchivo[],int idCliente);
///Carga de pedidos
void CargarUnPedido(char nombreArchivo[],char nombreArchivoProductos[],int idCliente);
int ContarPedidosArchivos(char nombreArchivo[]);
stProductos ObtenerNombreProducto(char nombreArchivo[],int id);
///
void validarFecha (int *dia, int *mes,int *anio);
void int2fecha(int dia, int mes, int anio, char fecha[20]);

#endif // PEDIDOS_H_INCLUDED
