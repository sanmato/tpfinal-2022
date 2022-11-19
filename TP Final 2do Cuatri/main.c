#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    char NombrePedidos[] = {"pedidos1.dat"};
    char NombreClientes[] = {"clientes1.dat"};
    char NombreProductos[] = {"productos.dat"};

    MenuInicial(NombreClientes,NombrePedidos,NombreProductos);

    return 0;
}
