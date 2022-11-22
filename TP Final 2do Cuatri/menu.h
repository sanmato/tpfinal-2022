#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <windows.h>

#include "clientes.h"
#include "pedidos.h"///se podrian sacar
#include "ADL.h"

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
///MENU ESPECIAL PARA TESTEO
void Menutesteo(char NombreArchivoClientes[],char NombreArchivoPedidos[]);


#endif // MENU_H_INCLUDED
