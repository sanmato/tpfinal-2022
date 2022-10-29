#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "conio.h"

typedef struct {
   int idPedido;        // auto incremental
   int idCliente;       // este valor corresponde al id del cliente que realizó el pedido
   char fecha[12];      // dd/MM/aaaa
   char descripcion[300];
   float costo;
   int pedidoAnulado;    // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

typedef struct {
    int idProducto;
    char descripcion[300];
    float precio;

} stProductos;

typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20];
    char mail[30];
    char genero;
    int rol;                   // 1: es admin - 0: es común
    int activo;
    // indica 1 o 0 si el cliente está activo
} stCliente;


///FUNCIONES MENU

///MENU Programa
void MenuProgramaAdmin(char NombreArchivoClientes[],char NombreArchivoPedidos[],char NombreArchivoProductos[]);
void MenuInicial(char NombreArchivoClientes[],char NombreArchivoPedidos[],char NombreArchivoProductos[]);
void MenuProgramaUsuario(char NombreArchivoClientes[],char NombreArchivoPedidos[],char nombreArchivoProductos[]);
void MenuProgramaUsuarioExistente(char NombreArchivosPedidos[],char NombreArchivoClientes[],int idCliente,char nombreArchivoProductos[]);
///MENU Clientes
void MenuClientesUsuario(char NombreArchivo[],int idCliente);
void MenuClientesAdmin(char NombreArchivo[]);
///MENU Pedidos
void MenuPedidosAdmin(char nombreArchivo[],char NombreArchivoProducto[]);
void MenuMostrarPedidos(char nombreArchivo[]);
void MenuPedidosUsuario(char nombreArchivoPedidos[],int idCliente,char nombreArchivoProductos[]);
///FUNCIONES gotoxy
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
///Validacion Usuarios
int ValidarUserAdmin(char NombreArchivoClientes[]);
int ValidadUser(char NombreArchivoClientes[]);


///FUNCIONES CLIENTES

/// Carga Clientes
void cargarUnClienteEnArchivo(int i, char archivo[]);
int cargaDeClientes (char archivo[], int cantidadClientes);
/// Mostrar Clientes
void mostrarUnCliente(stCliente a);
void mostrarListaDeClientes (char archivo[]);
/// Operaciones Clientes
int comprobarExistenciaUserName (char archivo[],char  *user);
void menuDeModificacion (char archivo [],int posicion);
int buscarPosUserName(char archivo[],char * userName);
void modificarArchivoCliente (char archivo[]);
int cantidadClientesDelArchivo (char archivo[]);
void DarDeBajaCliente(char archivo[]);
void modificarArchivoClienteUser (char archivo[],int idCliente);
int buscarPosUserNamePorId(char archivo[],int idCliente);
void menuDeModificacionUsuario(char archivo[],int posicion);

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
///Carga de pedidos
void CargarUnPedido(char nombreArchivo[],char nombreArchivoProductos[],int idCliente);
int ContarPedidosArchivos(char nombreArchivo[]);

///FUNCIONES PRODUCTOS
void cargarArchivoProductos(char NombreArchivoProductos[]);
int contarProductosArchivo(char NombreArchivoProducto[]);
void MostrarUnProducto(stProductos a);
void MostrarProductos(char NombreArchivoProducto[]);
int ComprobarIdProducto(char nombreArchivoProductos[],int id);
float calcularPrecioSegundId(char nombreArchivoProductos[],int id);




