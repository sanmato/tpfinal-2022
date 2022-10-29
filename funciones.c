#include "funciones.h"
#include "windows.h"

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

        printf("\nINGRESO AL MENU DE PEDIDOS ADMIN\n");
        printf("\n---------------------------");
        printf("\n 1. Mostrar Pedidos");
        printf("\n 2. Modificar un Pedido");
        printf("\n 3. Dar de Baja un Pedido");
        printf("\n 4. Modificar Archivo Productos");
        printf("\n 5. Mostrar Archivo Productos");
        printf("\n 6. Salir");
        printf("\n\n  Ingrese una opcion\n");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:

            MenuMostrarPedidos(nombreArchivo);

            break;
        case 2:
            MostrarTodosLosPedidos(nombreArchivo);
            printf("\nIngrese la id del pedido a modificar\t");
            fflush(stdin);
            scanf("%i",&idParaMod);
            flagMod=ModifcarPedidoAdmin(nombreArchivo,idParaMod,NombreArchivoProductos);
            if (flagMod==1)
            {
            printf("\nEl pedido se ha modificado con exito\n");
            }
            else
             if (flagMod==1)
            {
            printf("\nEl pedido no se ha modificado\n");
            }
            system("pause");
            break;
        case 3:
            printf("\nIngrese la id del pedido a dar de baja\t");
            fflush(stdin);
            scanf("%i",&idParaBaja);
            BajaPedido(nombreArchivo,idParaBaja);
            printf("\nEl pedido se dio de baja\n");
            system("pause");

            break;
        case 4:


            cargarArchivoProductos(NombreArchivoProductos);

            break;
        case 5:

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
        printf("----------------------------------------------------------\n");
        printf("\n1. Mostrar solo un pedido");
        printf("\n2. Mostrar todos los pedidos");
        printf("\n3. Mostrar los pedidos validos de un determinado cliente"); ///agregar funcion para mostrar los invalidos y todos
        printf("\n4. SALIR");

        printf("\n\nIngrese una opcion\t");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIngrese la id del pedido a mostrar\t"); ///Agregar funcion para uno solo
            fflush(stdin);
            scanf("%i",&idPedido);
            break;
        case 2:
            MostrarTodosLosPedidos(nombreArchivo);
            system("pause");
            break;
        case 3:
            printf("\nIngrese la id del cliente\t");
            fflush(stdin);
            scanf("%i",&idCliente);
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

        printf("\nINGRESO AL MENU DE CLIENTES ADMIN\n");
        printf("\n---------------------------");
        printf("\n 1. Mostrar Clientes");
        printf("\n 2. Modificar un Cliente");

        printf("\n 3. Cargar un Cliente");
        printf("\n 4. Salir");
        printf("\n\n  Ingrese una opcion\n");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:

            mostrarListaDeClientes(NombreArchivo);
            system("pause");

            break;
        case 2:
            modificarArchivoCliente(NombreArchivo);

            break;
        case 3:
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
        dibujarCuadro(1,1,77,3);
        gotoxy(20,2);
        printf("      Ingreso como ADMIN");
        gotoxy(10,4);
        printf("      1. para menu Cliente");
        gotoxy(10,5);
        printf("      2. para menu de Pedidos");
        gotoxy(10,6);
        printf("      3. para salir");
        gotoxy(10,7);
        printf ("     Que funcion desea hacer: ");
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
            printf("\nUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=3);
}

void MenuInicial(char NombreArchivoClientes[],char NombreArchivoPedidos[],char NombreArchivoProductos[])
{
    int opcion;
    int ValidarUser=0;
    system("COLOR F2");


    do
    {
        system("cls");
        dibujarCuadro(0,0,80,20);
        dibujarCuadro(1,1,77,3);gotoxy(6,2);

        printf("-------------BIENVENIDOS A LA HAMBURGUESERIA PEDORRA-------------\n");
        gotoxy(6,6);

        printf("      1. Ingresar Como Admin");
        gotoxy(6,7);
        printf("      2. Ingresar Como Cliente");
        gotoxy(6,8);
        printf("      3. Salir");
        gotoxy(6,9);
        printf ("      >Que funcion desea hacer: \n");

        fflush(stdin);
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
                printf("\nUsuario o Contrasenia Incorrecto\n");
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
            printf("\nUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=3);



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

        gotoxy(6,2);printf("\nIngreso como CLIENTE\n");
        printf("\n1. Nuevo Usuario");
        printf("\n2. Usuario Existente");
        printf("\n3. Salir\n");
        printf ("\nQue funcion desea hacer: \n");
        fflush(stdin);
        scanf("%i",&opcion);

        switch (opcion)
        {
        case 1:
        {
            cantidadClientes=cantidadClientesDelArchivo(NombreArchivoClientes);
            cargaDeClientes(NombreArchivoClientes,cantidadClientes);

        }
        break;

        case 2:
        {

            IdCliente = ValidadUser(NombreArchivoClientes);

            if(IdCliente==10000)
            {
                printf("\nUsuario o Contrasenia Incorrecto\n");
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
            printf("\nUsted ha salido del menu\n");
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

        printf("\nINGRESO AL MENU DE CLIENTES USUARIO\n");
        printf("\n---------------------------");
        printf("\n 1. Modificar tu Cliente");
        printf("\n 2. Salir");
        printf("\n\n  Ingrese una opcion\n");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {

        case 1:
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

        printf("\nINGRESO AL MENU DE PEDIDOS USUARIO\n");
        printf("\n---------------------------");
        printf("\n 1. Mostrar Pedidos Realizados");
        printf("\n 2. Modificar un Pedido");///Falta
        printf("\n 3. Dar de Baja un Pedido");///Falta
        printf("\n 4. Cargar un Pedido");
        printf("\n 5. Salir");
        printf("\n\n  Ingrese una opcion\n");
        fflush(stdin);
        scanf("%i",&opcion);

        switch(opcion)
        {
        case 1:

            MostrarPedidosPorCliente(nombreArchivoPedidos,idCliente);

            system("pause");

            break;
        case 2:
            MostrarPedidosPorCliente(nombreArchivoPedidos,idCliente);

            printf("\nIngrese la id del pedido a modificar\t");
            fflush(stdin);
            scanf("%i",&idParaMod);

            flagMod = ModifcarPedidoUsuario(nombreArchivoPedidos,idParaMod,idCliente,nombreArchivoProductos);
            if(flagMod==1)
            {
            printf("\nEl pedido se ha modificado\n");
            }
            else
            {
             printf("\nEl pedido no se ha podido modificar, intente nuevamente\n");
            }
            system("pause");
            break;
        case 3:
            MostrarPedidosPorCliente(nombreArchivoPedidos,idCliente);


            printf("\nIngrese la id del pedido a dar de baja ");
            fflush(stdin);
            scanf("%i",&idParaBaja);
            flagBaja = BajaPedidoPorCliente(nombreArchivoPedidos,idParaBaja,idCliente);
            if(flagBaja==1)
            {
                printf("\nEl pedido se ha dado de baja exitosamente\n");

            }
            else
            {
                printf("\nEl pedido no se ha dado de baja id Incorrecto intentelo nuevamente\n");
            }
            system("pause");

            break;
        case 4:
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


        printf("\nIngreso como USUARIO\n");
        printf("\n1. Menu Cliente");
        printf("\n2. Menu Pedidos");
        printf("\n3. Salir\n");
        printf ("\nQue funcion desea hacer: \n");
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
            printf("\nUsted ha salido del menu\n");
        }
        break;

        }
    }
    while (opcion!=3);



}
///FUNCIONES GOTOXY
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }


void dibujarCuadro(int x1,int y1,int x2,int y2){
	int i;

    for (i=x1;i<x2;i++){
		gotoxy(i,y1); printf("\304"); //linea horizontal superior
		gotoxy(i,y2); printf("\304"); //linea horizontal inferior
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); printf("\263"); //linea vertical izquierda
		gotoxy(x2,i); printf("\263"); //linea vertical derecha
	}

    gotoxy(x1,y1); printf("\332");
    gotoxy(x1,y2); printf("\300");
    gotoxy(x2,y1); printf("\277");
    gotoxy(x2,y2); printf("\331");
}
///Validacion Usuarios
int ValidarUserAdmin(char NombreArchivoClientes[])
{
    char Usuario[30];
    char Contra[30];

    stCliente aux;

    int flagAdmin = 0;


    printf("\n      Ingrese su usuario ADMIN\n");
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
                printf("\n      Ingrese su contrasenia\n");
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

    stCliente aux;


    int flagUser = 0;
    int IdCliente = 10000;


    printf("\nIngrese su usuario \n");
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
                printf("\nIngrese su contrasenia\n");
                fflush(stdin);
                gets(Contra);
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

///FUNCIONES CLIENTES

void cargarUnClienteEnArchivo(int i, char archivo[])
{
    int flag=0;

    stCliente a;
    stCliente b;

    FILE *archi;
    archi=fopen(archivo,"ab");                              ///modificar
    printf("Carguemos sus datos\n");
    system("pause");
    if (archi!=NULL)
    {
        printf("\nIngrese su mail: ");
        fflush(stdin);
        scanf("%s", a.mail);

        printf("\nEl cliente sera identificado con el siguiente id: %i", i);
        a.idCliente=i;

        printf("\n     Ingrese nombre: ");
        scanf("%s", a.nombre);

        printf("\n   Ingrese apellido: ");
        scanf("%s", a.apellido);

        do
        {
            printf("\n   Ingrese UserName:");
            fflush(stdin);
            scanf("%s",b.userName);
            flag=comprobarExistenciaUserName(archivo,b.userName);               ///Modularizar estooooo
            if (flag==1)
            {
                strcpy(a.userName,b.userName);
            }
            else
            {
                printf("\nUserName ya existente, intente nuevamente");
            }
        }
        while (flag==0);

        printf("\nElija su contraseña (5 caracteres como maximo): ");
        fflush(stdin);
        scanf("%s", a.password);

        printf("\nGenero M-F-X: ");
        fflush(stdin);
        scanf("%c",&a.genero);

        a.rol = 0;

        a.activo=1;

        fwrite(&a,sizeof(stCliente),1,archi);

        fclose(archi);
    }
}

int cargaDeClientes (char archivo[], int cantidadClientes)
{
    char opcion='s';
    int i=cantidadClientes;
    do
    {
        cargarUnClienteEnArchivo(i,archivo);
        i++;
        system("cls");
        printf("Desea cargar otro cliente: s/n");
        fflush(stdin);
        scanf("%c",&opcion);
    }
    while (opcion=='s');
    return i;
}
int comprobarExistenciaUserName (char archivo[],char  *user)
{
    int flag=1;
    stCliente a;
    FILE *archi;
    archi=fopen(archivo,"rb");
    if (archi!=NULL)
    {
        while (fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if (strcmpi((a.userName),user)==0)
            {
                flag=0;
            }
        }
        fclose(archi);
    }
    return flag;
}

void mostrarUnCliente(stCliente a)
{
    printf("\n----------------------");
    printf("\n Idcliente: %i", a.idCliente);
    printf("\n    Nombre: %s",a.nombre);
    printf("\n  Apellido: %s",a.apellido);
    printf("\n  UserName: %s",a.userName);
    printf("\n  Password: %s",a.password);
    printf("\n      Mail: %s",a.mail);
    printf("\n    Genero: %c",a.genero);
    if (a.rol==1)
    {
        printf("\n       Rol: Admin");
    }
    else
    {
        printf("\n       Rol: Usuario");
    }
    if (a.activo==1)
    {
        printf("\n-------Cliente Activo-------");
    }
    else
    {
        printf("\n-------Cliente No activo------");
    }
}

void mostrarListaDeClientes (char archivo[])
{
    FILE *archi;
    archi=fopen(archivo,"rb");
    stCliente a;
    if (archi!=NULL)
    {
        printf("Lista de clientes: \n");
        while( fread(&a,sizeof(stCliente),1,archi)>0)
        {

            mostrarUnCliente(a);
        }
    }
    fclose(archi);
}


int buscarPosUserName(char archivo[],char * userName)
{
    int posicion=1000;
    FILE *archi;
    stCliente a;
    archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if (strcmpi((a.userName),userName)==0)
            {
                posicion=ftell(archi)/sizeof(stCliente);
            }

        }
        fclose(archi);
    }
    if (posicion==1000)
    {
        printf("\nNo existe ese UserName");
    }
    return posicion;
}
void modificarArchivoCliente (char archivo[])
{
    int flag=1,posicion=0;

    char opcion='s';
    FILE*archi;
    stCliente a;
    archi=fopen(archivo,"r+b");
    if (archi!=NULL)
    {
        do
        {

            do
            {
                printf("\nQue usuario desea modificar: ");
                fflush(stdin);
                scanf("%s", a.userName);
                flag=comprobarExistenciaUserName(archivo,a.userName);
                if (flag==1)
                {
                    printf("\nEl usurio no existe, intente nuevamente");
                }
            }
            while(flag==1);
            posicion=buscarPosUserName(archivo,a.userName);
            menuDeModificacion(archivo,posicion);

            printf("\nDesea modificar otro cliente: s-n");
            fflush(stdin);
            scanf("%c",&opcion);
        }
        while (opcion=='s');




        fclose(archi);
    }
}

int cantidadClientesDelArchivo (char archivo[])
{
    int cantidadClientes;
    FILE*archi;
    archi=fopen(archivo,"r");
    if (archi!=NULL)
    {
        fseek(archi,sizeof(stCliente),SEEK_END);
        cantidadClientes=(ftell(archi)/sizeof(stCliente))-1;
        fclose(archi);
    }
    return cantidadClientes;
}

void modificarArchivoClienteUser (char archivo[],int idCliente)
{
    int posicion=0;


    FILE*archi;
    archi=fopen(archivo,"r+b");
    if (archi!=NULL)
    {

        posicion=buscarPosUserNamePorId(archivo,idCliente);
        menuDeModificacionUsuario(archivo,posicion);



        fclose(archi);
    }
}
int buscarPosUserNamePorId(char archivo[],int idCliente)
{
    int posicion=1000;
    FILE *archi;
    stCliente a;
    archi=fopen(archivo,"rb");
    if(archi!=NULL)
    {
        while(fread(&a,sizeof(stCliente),1,archi)>0)
        {
            if (a.idCliente==idCliente)
            {
                posicion=ftell(archi)/sizeof(stCliente);
            }

        }
        fclose(archi);
    }
    if (posicion==1000)
    {
        printf("\nNo existe ese UserName");
    }
    return posicion;
}

void menuDeModificacion (char archivo [],int posicion)
{
    char opcion='s';
    char control='z';
    int flag=10;
    FILE * archi;
    archi=fopen(archivo,"r+b");
    stCliente a;
    stCliente b;
    if (archi!=NULL)
    {
        do
        {
            rewind(archi);
            printf("\nQue informacion desea modificar: ");
            printf("\n a-Nombre");
            printf("\n b-Apellido");
            printf("\n c-UserName");
            printf("\n d-Password");
            printf("\n e-Mail");
            printf("\n f-Genero");
            printf("\n g-Rol");
            printf("\n h-Dar de baja cliente\n");
            printf("\n Cualquier tecla para salir\n");
            fflush(stdin);
            scanf("%c",&opcion);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            fread(&a,sizeof(stCliente),1,archi);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            switch (opcion)
            {
            case 'a':
            {

                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(a.nombre);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'b':
            {

                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(a.apellido);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'c':
            {
                do
                {
                    printf("\n   Ingrese UserName:");
                    fflush(stdin);
                    scanf("%s",b.userName);
                    flag=comprobarExistenciaUserName(archivo,b.userName);               ///Modularizar estooooo
                    if (flag==1)
                    {
                        strcpy(a.userName,b.userName);
                    }
                    else
                    {
                        printf("\nUserName ya existente, intente nuevamente");
                    }

                }
                while (flag==0);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'd':
            {
                printf("\nIngrese nueva paswword: ");
                fflush(stdin);
                scanf("%s", a.password);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'e':
            {
                printf("\nIngrese nuevo mail: ");
                fflush(stdin);
                scanf("%s", a.mail);
                fwrite(&a,sizeof(stCliente),1,archi);


            }
            break;
            case 'f':
            {
                printf("\nIngrese nuevo genero M-F-X: ");
                fflush(stdin);
                scanf("%c", &a.genero);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'g':
            {
                printf("\n Si es admin ingrese 1 caso contrario 0: ");
                fflush(stdin);
                scanf("%i", &a.rol);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'h':
            {
                printf("\n Si desea dar de baja cliente presione 0 si lo desea mantener activo 1: ");
                fflush(stdin);
                scanf("%i", &a.activo);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            default:
            {
                printf("Usted salio del menu\n");
            }
            }
            printf("Desea modificar otra caracteristica de este usurio: s-n");
            fflush(stdin);
            scanf("%c",&control);
        }
        while(control=='s');

        fclose(archi);
    }
}

void menuDeModificacionUsuario(char archivo[],int posicion)
{
    char opcion='s';
    char control='z';
    int flag=10;
    FILE * archi;
    archi=fopen(archivo,"r+b");
    stCliente a;
    stCliente b;
    if (archi!=NULL)
    {
        do
        {
            rewind(archi);
            printf("\nQue informacion desea modificar: ");
            printf("\n a-Nombre");
            printf("\n b-Apellido");
            printf("\n c-UserName");
            printf("\n d-Password");
            printf("\n e-Mail");
            printf("\n f-Genero");
            printf("\n Cualquier tecla para salir\n");
            fflush(stdin);
            scanf("%c",&opcion);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            fread(&a,sizeof(stCliente),1,archi);
            fseek(archi,sizeof(stCliente)*(posicion-1),SEEK_SET);
            switch (opcion)
            {
            case 'a':
            {

                printf("\nIngrese nuevo nombre: ");
                fflush(stdin);
                gets(a.nombre);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'b':
            {

                printf("\nIngrese nuevo apellido: ");
                fflush(stdin);
                gets(a.apellido);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'c':
            {
                do
                {
                    printf("\n   Ingrese UserName:");
                    fflush(stdin);
                    scanf("%s",b.userName);
                    flag=comprobarExistenciaUserName(archivo,b.userName);               ///Modularizar estooooo
                    if (flag==1)
                    {
                        strcpy(a.userName,b.userName);
                    }
                    else
                    {
                        printf("\nUserName ya existente, intente nuevamente");
                    }

                }
                while (flag==0);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'd':
            {
                printf("\nIngrese nueva paswword: ");
                fflush(stdin);
                scanf("%s", a.password);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            case 'e':
            {
                printf("\nIngrese nuevo mail: ");
                fflush(stdin);
                scanf("%s", a.mail);
                fwrite(&a,sizeof(stCliente),1,archi);


            }
            break;
            case 'f':
            {
                printf("\nIngrese nuevo genero M-F-X: ");
                fflush(stdin);
                scanf("%c", &a.genero);
                fwrite(&a,sizeof(stCliente),1,archi);

            }
            break;
            default:
            {
                printf("Ah salido del menu\n");
            }
            }
            printf("Desea modificar otra caracteristica de este usurio: s-n");
            fflush(stdin);
            scanf("%c",&control);
        }
        while(control=='s');

        fclose(archi);
    }
}

///FUNCIONES PEDIDOS

///Mostrar Pedidos
void MostrarUnPedido(stPedido a)
{
    printf("idPedido--------- %i\n",a.idPedido);
    printf("IdCliente-------- %i\n",a.idCliente);
    printf("Fecha------------ %s\n",a.fecha);
    printf("Descripcion:-combo%s\n",a.descripcion);
    printf("Costo------------ %.2f\n",a.costo);
    printf("Pedido anulado--- %i\n",a.pedidoAnulado);
    printf("\n");
}

void MostrarTodosLosPedidos(char nombreArchivo[])
{
    FILE* archivin = NULL;

    archivin = fopen(nombreArchivo,"rb");

    stPedido aux;

    if(archivin!=NULL)
    {

        while(fread(&aux, sizeof(stPedido),1, archivin)>0)
        {


            MostrarUnPedido(aux);
        }
        fclose(archivin);
    }

}

void MostrarPedidosPorCliente(char nombreArchivo[],int idCliente)
{
    FILE* archivin = NULL;

    archivin = fopen(nombreArchivo,"rb");

    stPedido aux;

    if(archivin!=NULL)
    {
        printf("\nSe van a mostrar los pedidos validos del cliente %i\n",idCliente);

        while(fread(&aux, sizeof(stPedido), 1, archivin)>0)
        {

            if(aux.idCliente == idCliente && aux.pedidoAnulado == 0 )

                MostrarUnPedido(aux);
        }
        fclose(archivin);
    }

    else
    {
        printf("El archivo no pudo ser abierto\n");
    }
}
///Operaciones de Pedidos
void BuscarUnPedido(char nombreArchivo[], int idPedido)
{
    FILE * archivin = NULL;

    archivin = fopen(nombreArchivo,"rb");

    stPedido aux;

    int flag = 0;

    if(archivin!=NULL)

    {
        while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
        {

            if(aux.idPedido==idPedido)
            {
                printf("\nSe va a buscar el pedido con la id %i\n",idPedido);

                MostrarUnPedido(aux);

                flag = 1;
            }
        }
        fclose(archivin);

    }

}

int ModifcarPedidoAdmin(char nombreArchivo[],int idPedido,char nombreArchivoProducto[])
{
    int flag = 0,idFlag = 0;
    int num = -1;
    int id =0;

    FILE* archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivo,"r+b");


    while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
    {

        if(aux.idPedido == idPedido )
        {
            do
            {

                MostrarProductos(nombreArchivoProducto);
                printf("Ingrese ID del producto que desea:");
                fflush(stdin);
                scanf("%i",&id);
                idFlag = ComprobarIdProducto(nombreArchivoProducto,id);
                if(idFlag==1)
                {

                    sprintf(aux.descripcion,"%i",id);
                    aux.costo=calcularPrecioSegundId(nombreArchivoProducto,id);

                }
                else
                {
                    printf("el id ingresado es incorrecto\n");
                    system("pause");
                }

            }
            while(idFlag==0);


            flag = 1;

            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);
            fclose(archivin);
        }
    }
    fclose(archivin);

    return flag;
}

void BajaPedido(char nombreArchivo[],int idPedido)
{
    int flag = 0;
    int num = -1;

    FILE * archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivo,"r+b");


    while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
    {

        if(aux.idPedido == idPedido)
        {
            printf("El pedido %i se a dado de baja\n",idPedido);

            flag = 1;

            aux.pedidoAnulado=1;


            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);
            fclose(archivin);
        }
    }
    fclose(archivin);


}

int BajaPedidoPorCliente(char nombreArchivo[],int idPedido,int idCliente)
{
    int flag = 0;
    int num = -1;

    FILE * archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivo,"r+b");


    while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
    {

        if(aux.idPedido == idPedido && aux.idCliente == idCliente)
        {
            printf("El pedido %i se a dado de baja\n",idPedido);

            flag = 1;

            aux.pedidoAnulado=1;


            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);
            fclose(archivin);
        }
    }
    fclose(archivin);

    return flag;
}

int ModifcarPedidoUsuario(char nombreArchivoPedidos[],int idPedido,int idCliente,char nombreArchivoProductos[])
{
    int flag = 0,idFlag = 0;
    int num = -1;
    int id =0;

    FILE* archivin = NULL;

    stPedido aux;

    archivin = fopen(nombreArchivoPedidos,"r+b");


    while(fread(&aux,sizeof(stPedido),1,archivin)>0 && flag == 0 )
    {

        if(aux.idPedido == idPedido && aux.idCliente == idCliente)
        {
            do
            {
                system("cls");
                MostrarProductos(nombreArchivoProductos);
                printf("Ingrese ID del producto que desea:");
                fflush(stdin);
                scanf("%i",&id);
                idFlag = ComprobarIdProducto(nombreArchivoProductos,id);
                if(idFlag==1)
                {

                    sprintf(aux.descripcion,"%i",id);
                    aux.costo=calcularPrecioSegundId(nombreArchivoProductos,id);

                }
                else
                {
                    printf("el id ingresado es incorrecto\n");
                    system("pause");
                }

            }
            while(idFlag==0);


            flag = 1;

            fseek(archivin, (sizeof(stPedido)*num), SEEK_CUR);
            fwrite(&aux,sizeof(stPedido),1,archivin);
            fclose(archivin);
        }
    }
    fclose(archivin);







    return flag;
}

///Carga de Pedidos
void  CargarUnPedido(char nombreArchivo[],char nombreArchivoProductos[],int idCliente)
{
    FILE * archivin = NULL;
    int id = 0,idFlag =0;


    archivin = fopen(nombreArchivo,"ab");

    printf("Carga de un pedido \n");
    stPedido pedidos;

    pedidos.idCliente=idCliente;


    printf("Ingrese Fecha  DD/MM/AAAA \n");
    fflush(stdin);
    gets(pedidos.fecha);

    pedidos.pedidoAnulado=0;

    pedidos.idPedido = ContarPedidosArchivos(nombreArchivo) + 1;


    do
    {
        system("cls");
        MostrarProductos(nombreArchivoProductos);
        printf("Ingrese ID del producto que desea:");
        fflush(stdin);
        scanf("%i",&id);
        idFlag = ComprobarIdProducto(nombreArchivoProductos,id);
        if(idFlag==1)
        {

            sprintf(pedidos.descripcion,"%i",id);
        }
        else
        {
            printf("el id ingresado es incorrecto\n");
            system("pause");
        }

    }
    while(idFlag==0);

    pedidos.costo=calcularPrecioSegundId(nombreArchivoProductos,id);

    fwrite(&pedidos,sizeof(stPedido),1,archivin);

    fclose(archivin);

    MostrarUnPedido(pedidos);

    system("pause");

}

int ContarPedidosArchivos(char nombreArchivo[])
{
    int cantidad=0;
    FILE * archivin = NULL;
    archivin=fopen(nombreArchivo,"rb");

    if (archivin!= NULL)
    {
        fseek(archivin,0,SEEK_END);
        cantidad=ftell(archivin)/sizeof(stPedido);
        fclose(archivin);
    }

    return cantidad;
}

///Funciones productos ADMIN
void cargarArchivoProductos(char NombreArchivoProducto[])
{
    char opcion='s';
    int cantidadProductos=0;
    FILE*archi=NULL;
    archi=fopen(NombreArchivoProducto,"ab");
    stProductos a;


    do
    {
        cantidadProductos=contarProductosArchivo(NombreArchivoProducto)+1;
        printf("\nEl producto sera identificado con el id: %i\n",cantidadProductos);
        a.idProducto=cantidadProductos;

        printf("\nIngrese la descripcion del pedido\n");
        fflush(stdin);
        gets(a.descripcion);

        printf("\nIngrese coste del producto: $");
        fflush(stdin);
        scanf("%f", &a.precio);

        fwrite(&a,sizeof(stProductos),1,archi);

        printf("\nDesea agregar otro producto: s/n ");
        fflush(stdin);
        scanf("%c",&opcion);


    }
    while (opcion=='s');

    fclose(archi);
}

void MostrarUnProducto(stProductos a)
{
    printf("ID del producto:--------- %i \n",a.idProducto);
    printf("Descripcion de producto-- %s \n",a.descripcion);
    printf("Precio del producto:----- $ %.2f \n",a.precio);
    printf("\n\n");
}

void MostrarProductos(char NombreArchivoProducto[])
{
    FILE* archi;
    archi = NULL;

    stProductos a;

    archi = fopen(NombreArchivoProducto,"rb");

    while(fread(&a,sizeof(stProductos),1,archi)>0)
    {
        MostrarUnProducto(a);
    }

    fclose(archi);


}
int contarProductosArchivo(char NombreArchivoProducto[])
{
    int cantidad=0;
    FILE * archivin = NULL;
    archivin=fopen(NombreArchivoProducto,"rb");

    if (archivin!= NULL)
    {
        fseek(archivin,0,SEEK_END);
        cantidad=ftell(archivin)/sizeof(stProductos);
        fclose(archivin);
    }

    return cantidad;
}

///Funciones producto usuarios

int ComprobarIdProducto(char nombreArchivoProductos[],int id)
{
    FILE * archi = NULL;
    archi = fopen(nombreArchivoProductos,"rb");
    int flag = 0;
    stProductos a;

    while(fread(&a,sizeof(stProductos),1,archi)>0&& flag != 1)
    {
        if(a.idProducto==id)
        {

            flag = 1;
        }
    }
    return flag;
}

float calcularPrecioSegundId(char nombreArchivoProductos [],int id)
{
    FILE*archi=NULL;
    archi=fopen(nombreArchivoProductos,"rb");
    stProductos a;
    float costo=0;
    while(fread(&a,sizeof(stProductos),1,archi)>0)
    {
        if(a.idProducto==id)
        {
            costo=a.precio;
        }
    }
    fclose(archi);

    return costo;
}

