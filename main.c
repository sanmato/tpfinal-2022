#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "conio.h"
#include "funciones.h"
#include "windows.h"

int main()
{

    char NombrePedidos[] = {"pedidos1.dat"};
    char NombreClientes[] = {"clientes1.dat"};
    char NombreProductos[] = {"productos.dat"};

    MenuInicial(NombreClientes,NombrePedidos,NombreProductos);



    return 0;
}
