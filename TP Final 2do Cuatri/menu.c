#include "menu.h"
///FUNCIONES MENU

///MENU De Pedidos
void MenuPedidosAdmin(char nombreArchivo[],char NombreArchivoProductos[])
{
    int opcion;
    int flag = 0,flagMod=0;
    int idParaMod;
    int idParaBaja = 0;


    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);///

        printf("\n\tINGRESO AL MENU DE PEDIDOS ADMIN\n\n");

        printf("\n\t1.Mostrar Pedidos");
        printf("\n\t2.Modificar un Pedido");
        printf("\n\t3.Dar de Baja un Pedido");
        printf("\n\t4.Modificar Archivo Productos");
        printf("\n\t5.Mostrar Archivo Productos");
        printf("\n\t6.Salir");
        printf("\n\n\t Ingrese una opcion\n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:

            MenuMostrarPedidos(nombreArchivo);

            break;
        case 2:
            system("cls");
            MostrarTodosLosPedidos(nombreArchivo);
            printf("\n\tIngrese la id del pedido a modificar\t");
            fflush(stdin);
            scanf("%i",&idParaMod);
            flagMod=ModifcarPedidoAdmin(nombreArchivo,idParaMod,NombreArchivoProductos);
            if (flagMod==1)
            {
                printf("\n\tEl pedido se ha modificado con exito\n");
            }
            else if (flagMod==1)
            {
                printf("\n\tEl pedido no se ha modificado\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            printf("\n\tIngrese la id del pedido a dar de baja\t");
            fflush(stdin);
            scanf("%i",&idParaBaja);
            BajaPedido(nombreArchivo,idParaBaja);
            printf("\n\tEl pedido se dio de baja\n");
            system("pause");

            break;
        case 4:
            system("cls");
            cargarArchivoProductos(NombreArchivoProductos);
            break;
        case 5:

            system("cls");
            MostrarProductos(NombreArchivoProductos);
            system("pause");
            break;

        case 6:

            flag = 1;
            break;

        }

    }
    while(flag!=1);
}

void MenuMostrarPedidos(char nombreArchivo[])
{
    int opcion;
    int flag = 0;
    int idPedido = 1;
    int idCliente = 0;

    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);///

        printf("\n\n\t1.Mostrar solo un pedido");
        printf("\n\t2.Mostrar todos los pedidos");
        printf("\n\t3.Mostrar los pedidos validos de un determinado cliente"); ///agregar funcion para mostrar los invalidos y todos
        printf("\n\t4.SALIR");

        printf("\n\n\tIngrese una opcion:\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:
            printf("\n\tIngrese la id del pedido a mostrar\t"); ///Agregar funcion para uno solo
            fflush(stdin);
            scanf("%i",&idPedido);
            break;
        case 2:
            system("cls");
            MostrarTodosLosPedidos(nombreArchivo);
            system("pause");
            break;
        case 3:
            printf("\n\tIngrese la id del cliente\n\t");
            fflush(stdin);
            scanf("%i",&idCliente);
            system("cls");
            MostrarPedidosPorCliente(nombreArchivo,idCliente);
            system("pause");
            break;
        case 4:
            flag = 1;
            break;
        }

    }
    while(flag!=1);
}
void MenuClientesAdmin(char NombreArchivo[])
{
    int opcion;
    int flag = 0;
    int cantidadCLientes =0;
    do
    {

        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);

        printf("\n\tINGRESO AL MENU DE CLIENTES ADMIN\n");

        printf("\n\t1. Mostrar Clientes");
        printf("\n\t2. Modificar un Cliente");

        printf("\n\t3. Cargar un Cliente");
        printf("\n\t4. Salir");
        printf("\n\n\t Ingrese una opcion:\n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");

            mostrarListaDeClientes(NombreArchivo);
            system("pause");

            break;
        case 2:
            system("cls");
            mostrarListaDeClientes(NombreArchivo);
            modificarArchivoCliente(NombreArchivo);

            break;
        case 3:
            system("cls");
            cantidadCLientes = cantidadClientesDelArchivo(NombreArchivo);
            cargaDeClientes(NombreArchivo,cantidadCLientes);
            break;
        case 4:

            flag = 1;
            break;

        }

    }
    while(flag!=1);
}

///MENUDELPROGRAMA
void MenuProgramaAdmin(char NombreArchivoClientes[],char NombreArchivoPedidos[],char NombreArchivoProductos[])
{
    int opcion;

    do
    {
        system("cls");

        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);///
        //gotoxy(20,2);
        printf("\n\tIngreso como ADMIN\n");
        //gotoxy(10,4);
        printf("\n\t1.para menu Cliente");
        // gotoxy(10,5);
        printf("\n\t2.para menu de Pedidos");
        printf("\n\t3.Estructuras Compuestas y borrado");
        // gotoxy(10,6);
        printf("\n\t4.para salir");
        // gotoxy(10,7);
        printf ("\n\tQue funcion desea hacer:\n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:
        {
            MenuClientesAdmin(NombreArchivoClientes);

        }
        break;

        case 2:
        {
            MenuPedidosAdmin(NombreArchivoPedidos,NombreArchivoProductos);
        }
        break;

        case 3:
        {
            Menutesteo(NombreArchivoClientes,NombreArchivoPedidos,NombreArchivoProductos);
        }
        break;

        case 4:
        {
            printf("\n\tUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=4);
}

void MenuInicial(char NombreArchivoClientes[],char NombreArchivoPedidos[],char NombreArchivoProductos[])
{
    int opcion;
    int ValidarUser=0;

    SMALL_RECT WinRect  = {0, 0, 80, 20};  ///tamanio de ventana
    SMALL_RECT* WinSize = &WinRect; /// lo pongo en la variable
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), 1, WinSize); ///seteo tamanio

    system("COLOR 04");///color


    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);
        gotoxy(6,2);

        printf("-------------BIENVENIDOS A LA HAMBURGUESERIA PEDORRA-------------\n");
        gotoxy(6,6);

        printf("\t1.Ingresar Como Admin");
        gotoxy(6,7);
        printf("\t2.Ingresar Como Cliente");
        gotoxy(6,8);
        printf("\t3.MENU TESTEO");
        gotoxy(6,9);
        printf("\t4. Salir");
        gotoxy(6,10);
        printf ("\tQue funcion desea hacer: \n");

        fflush(stdin);
        printf("\t");
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:
        {

            ValidarUser = ValidarUserAdmin(NombreArchivoClientes);
            if(ValidarUser == 1)
            {
                MenuProgramaAdmin(NombreArchivoClientes,NombreArchivoPedidos,NombreArchivoProductos); ///Modularizar
            }
            else
            {
                printf("\n\tUsuario o Contrasenia Incorrecto\n");
                system ("pause");
            }
        }
        break;

        case 2:
        {
            MenuProgramaUsuario(NombreArchivoClientes,NombreArchivoPedidos,NombreArchivoProductos);///Verificar q es un usuario
        }
        break;

        case 3:
        {
            Menutesteo(NombreArchivoClientes,NombreArchivoPedidos,NombreArchivoProductos);
        }
        break;

        case 4:
        {
            printf("\n\tUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=4);



}
void MenuProgramaUsuario(char NombreArchivoClientes[],char NombreArchivoPedidos[],char nombreArchivoProductos[])
{
    int opcion;
    int cantidadClientes = 0;
    int IdCliente=10000;
    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);

        gotoxy(6,2);
        printf("\n\tIngreso como CLIENTE\n\n");
        printf("\n\t1.Nuevo Usuario");
        printf("\n\t2.Usuario Existente");
        printf("\n\t3.Salir\n");
        printf ("\n\tQue funcion desea hacer: \n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:
        {
            system("cls");
            cantidadClientes=cantidadClientesDelArchivo(NombreArchivoClientes);
            cargaDeClientes(NombreArchivoClientes,cantidadClientes);

        }
        break;

        case 2:
        {

            IdCliente = ValidadUser(NombreArchivoClientes);

            if(IdCliente==10000)
            {
                printf("\n\tUsuario o Contrasenia Incorrecto\n");
                system ("pause");
            }
            else
            {
                MenuProgramaUsuarioExistente(NombreArchivoPedidos,NombreArchivoClientes,IdCliente,nombreArchivoProductos);
            }

        }
        break;

        case 3:
        {
            printf("\n\tUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=3);
}
void MenuClientesUsuario(char NombreArchivoClientes[],int idCliente)
{
    int opcion;
    int flag = 0;

    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);///

        printf("\n\tINGRESO AL MENU DE CLIENTES USUARIO\n");
        printf("\n\t1. Modificar tu Cliente");
        printf("\n\t2. Salir");
        printf("\n\n  Ingrese una opcion\n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {

        case 1:
            system("cls");
            modificarArchivoClienteUser(NombreArchivoClientes,idCliente);

            break;

        case 2:

            flag = 1;
            break;

        }

    }
    while(flag!=1);
}
void MenuPedidosUsuario(char nombreArchivoPedidos[],int idCliente,char nombreArchivoProductos[])
{
    int opcion;
    int flag = 0;
    int idParaMod;
    int idParaBaja = 0;
    int flagBaja = 0;
    int flagMod = 0;


    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);///

        printf("\n\tINGRESO AL MENU DE PEDIDOS USUARIO\n");

        printf("\n\t1.Mostrar Pedidos Realizados");
        printf("\n\t2.Modificar un Pedido");///Falta
        printf("\n\t3.Dar de Baja un Pedido");///Falta
        printf("\n\t4.Cargar un Pedido");
        printf("\n\t5.Salir");
        printf("\n\n\tIngrese una opcion\n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:

            system("cls");
            MostrarPedidosPorCliente(nombreArchivoPedidos,idCliente);

            system("pause");

            break;
        case 2:
            system("cls");
            MostrarPedidosPorCliente(nombreArchivoPedidos,idCliente);

            printf("\n\tIngrese la id del pedido a modificar\t");
            fflush(stdin);
            scanf("%i",&idParaMod);

            flagMod = ModifcarPedidoUsuario(nombreArchivoPedidos,idParaMod,idCliente,nombreArchivoProductos);
            if(flagMod==1)
            {
                printf("\n\tEl pedido se ha modificado\n");
            }
            else
            {
                printf("\n\tEl pedido no se ha podido modificar, intente nuevamente\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            MostrarPedidosPorCliente(nombreArchivoPedidos,idCliente);


            printf("\n\tIngrese la id del pedido a dar de baja ");
            fflush(stdin);
            scanf("%i",&idParaBaja);
            flagBaja = BajaPedidoPorCliente(nombreArchivoPedidos,idParaBaja,idCliente);
            if(flagBaja==1)
            {
                printf("\n\tEl pedido se ha dado de baja exitosamente\n");

            }
            else
            {
                printf("\n\tEl pedido no se ha dado de baja id Incorrecto intentelo nuevamente\n");
            }
            system("pause");

            break;
        case 4:
            system("cls");

            CargarUnPedido(nombreArchivoPedidos,nombreArchivoProductos,idCliente);


            break;
        case 5:

            flag = 1;
            break;

        }

    }
    while(flag!=1);

}

void MenuProgramaUsuarioExistente(char NombreArchivosPedidos[],char NombreArchivoClientes[],int idCliente,char nombreArchivoProductos[])
{
    int opcion;

    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);///


        printf("\n\tIngreso como USUARIO\n");
        printf("\n\t1.Menu Cliente");
        printf("\n\t2.Menu Pedidos");
        printf("\n\t3.Salir\n");
        printf ("\n\tQue funcion desea hacer: \n\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:
        {
            MenuClientesUsuario(NombreArchivoClientes,idCliente);

        }
        break;

        case 2:
        {
            MenuPedidosUsuario(NombreArchivosPedidos,idCliente,nombreArchivoProductos);
        }
        break;

        case 3:
        {
            printf("\n\tUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=3);



}

///FUNCIONES GOTOXY
void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}


void dibujarCuadro(int x1,int y1,int x2,int y2)
{
    int i;

    for (i=x1; i<x2; i++)
    {
        gotoxy(i,y1);
        printf("\304"); //linea horizontal superior
        gotoxy(i,y2);
        printf("\304"); //linea horizontal inferior
    }

    for (i=y1; i<y2; i++)
    {
        gotoxy(x1,i);
        printf("\263"); //linea vertical izquierda
        gotoxy(x2,i);
        printf("\263"); //linea vertical derecha
    }

    gotoxy(x1,y1);
    printf("\332");
    gotoxy(x1,y2);
    printf("\300");
    gotoxy(x2,y1);
    printf("\277");
    gotoxy(x2,y2);
    printf("\331");
}
///Validacion Usuarios
int ValidarUserAdmin(char NombreArchivoClientes[])
{
    char Usuario[30];
    char Contra[30];


    stCliente aux;

    int flagAdmin = 0;


    printf("\tIngrese su usuario ADMIN\n\t");
    fflush(stdin);
    gets(Usuario);

    FILE* archivin = NULL;

    archivin = fopen(NombreArchivoClientes,"rb");
    if (archivin!=NULL)
    {
        while((fread(&aux, sizeof(stCliente), 1, archivin)>0) && flagAdmin ==0)
        {
            if( (strcmpi((aux.userName),Usuario)==0) && aux.rol ==1)
            {
                printf("\tIngrese su contrasenia\n\t");
                fflush(stdin);
                gets(Contra);

                if((strcmpi((aux.password),Contra)==0))
                {
                    flagAdmin = 1;
                }

            }
        }
        fclose(archivin);
    }
    return flagAdmin;
}
int ValidadUser(char NombreArchivoClientes[])
{

    char Usuario[30];
    char Contra[30];

    char caracter;
    int c=0;

    stCliente aux;


    int flagUser = 0;
    int IdCliente = 10000;


    printf("\n\tIngrese su usuario \n\t");
    fflush(stdin);
    gets(Usuario);

    FILE* archivin = NULL;

    archivin = fopen(NombreArchivoClientes,"rb");
    if (archivin!=NULL)
    {
        while((fread(&aux, sizeof(stCliente), 1, archivin)>0) && flagUser ==0)
        {
            if( (strcmpi((aux.userName),Usuario)==0) && aux.rol ==0)
            {
                printf("\n\tIngrese su contrasenia\n\t");
                fflush(stdin);

            while (caracter = getch()) {
			if (caracter == TECLA_ENTER) {
				Contra[c] = '\0';
				break;

			} else if (caracter == TECLA_BACKSPACE) {
				if (c > 0) {
					c--;
					printf("\b \b");
				}

			} else {
				if (c < 8) {
					printf("*");
					fflush(stdin);
					Contra[c] = caracter;
					c++;
				}
			}
		}

                if((strcmpi((aux.password),Contra)==0))
                {
                    flagUser = 1;

                    IdCliente = aux.idCliente;

                }

            }
        }
        fclose(archivin);
    }
    return IdCliente;



}
///MENU TESTEO

void Menutesteo(char NombreArchivoClientes[],char NombreArchivoPedidos[],char NombreArchivoProductos[])
{

    int opcion = 0;
    int id = 0;
    int anio =0;
    int mes = 0;
    int flag = 0;

    nodoArbolCliente * arbol = inicArbol();

    arbol = CargaClientes(arbol,NombreArchivoClientes);
    arbol = CargaConsumos(arbol,NombreArchivoPedidos);


    do
    {
        system("cls");
        printf("\n\tMENU ESTRUCTURAS COMPUESTAS\n");
        printf("\n\tLas estructuras ya fueron cargadas\n");

        printf("\n\t1.Mostrar Estructura Compuesta");
        printf("\n\t2.Modificar Estructura Compuesta");
        printf("\n\t3.Dar Baja Cliente o Pedido");
        printf("\n\t4.Mostrar un periodo determinado de un cliente");
        printf("\n\t5.Para salir");

        printf("\n\tIngrese una opcion:\n\t");
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:
        {
            system("cls");
            mostrarArbolInorder(arbol);
            system("pause");
        }
        break;

        case 2:
        {
            system("cls");
            submenuModificacion(arbol,NombreArchivoClientes,NombreArchivoPedidos,NombreArchivoProductos);
            opcion = 5;

        }
        break;

        case 3:
        {
            system("cls");
            submenuBaja(arbol,NombreArchivoClientes,NombreArchivoPedidos);
            opcion = 5;
        }
        break;

        case 4:
        {
            system("cls");
            nodoArbolCliente * seg = NULL;

            mostrarArbolInorderSoloClientes(arbol);
            printf("\n\tIngrese el id cliente a liquidar\n\t");
            scanf("%i",&id);


            while(flag == 0)
            {
                seg = buscarUnNodoArbol(arbol,id);

                if(seg!= NULL)
                {

                    printf("\n\tIngrese el anio\n\t");
                    scanf("%i",&anio);
                    printf("\n\tIngrese el mes\n\t");
                    scanf("%i",&mes);

                    flag =1;

                    imprimePedidosXfecha(arbol,id,mes,anio,NombreArchivoPedidos);

                }
                else
                {
                    system("cls");
                    mostrarArbolInorderSoloClientes(arbol);
                    printf("\n\tID incorrecto,ingrese uno valido\n\t");
                    scanf("%i",&id);
                }
            }
            system("pause");
        }
        break;

        case 5:
        {
            printf("\n\tUsted ha salido del menu,cambios guardados\n");

            borrarADL(arbol);

            opcion = 5;
            system("pause");


        }
        break;

        }

    }
    while(opcion != 5);

}

void submenuModificacion(nodoArbolCliente * arbol,char archiClientes[],char archiPedidos[],char archiProductos[])
{
    int opcion = 0;

    do
    {
        system("cls");
        printf("\n\tMODIFICAR DATOS ESTRUCTURA COMPUESTA\n\n");
        printf("\n\t1.Modificar un Cliente");
        printf("\n\t2.Modificar un Pedido");
        printf("\n\t3.Salir");

        printf("\n\tIngrese una opcion\n\t");
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:
        {
            system("cls");

            ModificarClienteArbol(arbol,archiClientes);

        }
        break;

        case 2:
        {
            system("cls");
            ModificarPedidoArbol(arbol,archiClientes,archiPedidos,archiProductos);
        }
        break;

        case 3:
        {
            printf("\n\tSalio del menu\n");
            opcion = 3;

        }
        break;

        }
    }
        while(opcion != 3);

}
void submenuBaja(nodoArbolCliente * arbol,char archiClientes[],char archiPedidos[])
{   nodoArbolCliente* seg;
    int opcion = 0;
    int id = 0;
    do
    {

        system("cls");
        printf("\n\tSUBMENUBAJA\n\n");

        printf("\n\t1.Dar de baja un Cliente");
        printf("\n\t2.Dar de baja un Pedido");
        printf("\n\t3.Salir\n\t");
        scanf("%i",&opcion);


        switch(opcion)
        {
        case 1:
            {
                system("cls");
                mostrarArbolInorderSoloClientes(arbol);

                printf("\n\tIngrese la id del cliente para eliminar sus pedidos\n");
                scanf("%i",&id);

                ///llamar funcion borrar nodo en arbol tiempo de ejecucion
                seg=buscarUnNodoArbol(arbol, id);
                if(seg){
                        arbol = borrarNodoArbol(arbol,id);
                        actualizaCliente2file(archiClientes, id);//borrado logico - update del campo activo solamente
                        BajaPedidoPorSoloCliente(archiPedidos, id);
                        printf("\n\tCliente dado de baja correctamente\n");
                        system("pause");

                        }
                  else {
                        printf("\n\tCliente No existe en la Base de Datos...\n");
                        system("pause");
                       }

            }
            break;
        case 2:
            {
                nodoArbolCliente * aux = inicArbol();

                system("cls");
                mostrarArbolInorderSoloClientes(arbol);

                printf("\n\tIngrese la id del cliente para eliminar sus pedidos\n");
                scanf("%i",&id);

                aux = buscarUnNodoArbol(arbol,id);

                system("cls");
                printf("%p",aux->pedidos);

                MostrarListaValidos(aux->pedidos);

                printf("\n\tIngrese la id del pedido a borrar\n");
                scanf("%i",&id);

                BajaPedido(archiPedidos,id);

                printf("\n\tPedido dado de baja correctamente\n");
                system("pause");
            }
            break;
        case 3:
            {
                opcion = 3;

            }
            break;
        }

    }while(opcion != 3);
}

void BajaPedidoPorSoloCliente(char nombreArchivo[], int idCliente)
{
    int flag=1;
    int num = -1;
    int pos;

    FILE * archivin = NULL;

    stPedido aux,actualizado;

    archivin = fopen(nombreArchivo,"r+b");
    if (archivin)
    {

        while((fread(&aux,sizeof(stPedido),1,archivin)>0))
        {
            if((aux.idCliente == idCliente)&&(aux.pedidoAnulado==0))
            {
                pos=ftell(archivin)/sizeof(stPedido);
                aux.pedidoAnulado=1;
                fseek(archivin,sizeof(stPedido)*(pos-1),SEEK_SET);
                fwrite(&aux, sizeof(stPedido),1,archivin);
                fseek(archivin,sizeof(stPedido)*(-1),SEEK_CUR);
            }

        }
        fclose(archivin);
    }
}
