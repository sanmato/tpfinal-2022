#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "pedidos.h"
#include "clientes.h"



void cargaUnAdmin(char nombreArchi[]);


int main()
{
    char NombrePedidos[] = {"pedidos1.dat"};
    char NombreClientes[] = {"clientes1.dat"};
    char NombreProductos[] = {"productos.dat"};

    FILE * archi = fopen(NombreClientes,"rb");
    // int i=cantidadClientesDelArchivo(NombreClientes);
    // cargaDeClientes(NombreClientes,i);

    if(!archi)
    {
        cargaUnAdmin(NombreClientes);
    }
    fclose(archi);

    //Menutesteo(NombreClientes,NombrePedidos,NombreProductos);

    MenuInicial(NombreClientes,NombrePedidos,NombreProductos);
    // BajaPedidoPorSoloCliente(NombrePedidos, 12);
    //mostrarListaDeClientes(NombreClientes);
    //MostrarTodosLosPedidos(NombrePedidos);

    return 0;
}


void cargaUnAdmin(char nombreArchi[])
{
    stCliente aux;

    FILE * archi = fopen(nombreArchi,"wb");

    if(archi)
    {

        aux.activo=1;
        strcpy(aux.apellido,"admin");
        strcpy(aux.nombre,"admin");
        strcpy(aux.mail,"admin@admin");
        strcpy(aux.password,"admin");
        strcpy(aux.userName,"admin");
        aux.genero = 'x';
        aux.idCliente = 0;
        aux.pedidos =NULL;
        aux.rol= 1;

        fwrite(&aux,sizeof(stCliente),1,archi);

        fclose(archi);

    }
}






