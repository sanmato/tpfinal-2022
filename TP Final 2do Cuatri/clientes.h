#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5

typedef struct
{
    int idCliente;
    char nombre[30];
    char apellido[30];
    char userName[20];
    char password[20]; ///ver lo de arroba y esconder contra
    char mail[30];
    char genero;
    int rol;                   // 1: es admin - 0: es com?n
    int activo;
    struct nodoListaPedidos * pedidos;
} stCliente;



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
void DarDeBajaCliente(char archivo[],int idCliente);                     /// no existe
void modificarArchivoClienteUser (char archivo[],int idCliente);
int buscarPosUserNamePorId(char archivo[],int idCliente);
void menuDeModificacionUsuario(char archivo[],int posicion);
///
int iDeCaracterEnCadena(char *cadena, char caracter);
int ultimoiDeCaracterEnCadena(char *cadena, char caracter);
int esCorreoElectronico(char correo[]);
void actualizaCliente2file(char archivoClientes[],int idCliente);


#endif // CLIENTES_H_INCLUDED
